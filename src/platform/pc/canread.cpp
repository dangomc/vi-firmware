extern "C" {
	#include "socketCAN.h"
}

#include "can/canread.h"
#include "signals.h"
#include "util/log.h"

using openxc::util::log::debug;
using openxc::signals::getCanBusCount;
using openxc::signals::getCanBuses;

int skt; // Socket CAN variable
bool CANthreadCreated = 0; // Variable used as flag

extern "C" {

void CAN_Handler(CanMessage message);

void *runCAN (void *parametro)
{
	fd_set              canSktDesc;
	struct can_frame 	frame;
	int                 ret,nbytes;

	FD_ZERO(&canSktDesc);
	FD_SET (skt, &canSktDesc);

	for(;;) { //The work loop
		if ((ret = select(skt+1, &canSktDesc, NULL, NULL, NULL)) < 0) //Waiting for events in CAN socket layer
		{
			perror("Select Socket Error");
			//return;
		}

		if ((nbytes = recv(skt,&frame, sizeof(frame),0)) < 0 )
		{
			perror("Error reading socket");
			//return;
		}

		if (nbytes < (int) sizeof(struct can_frame))
		{
			fprintf(stderr, "read: incomplete CAN frame\n");
			//return;
		}

		printFrame(&frame); //TODO: Only for debug

		// Conversion of received frame to CanMessage format
		CanMessage result = {
				id: frame.can_id,
				format: CanMessageFormat::STANDARD,
				data: {0},
				length: frame.can_dlc
		};
		memcpy(result.data, frame.data, sizeof(result.data));

		CAN_Handler(result); // Send incomming message to the CAN handler
	}
}

void launchSocketCAN()
{
	// Create CAN thread
	if (!CANthreadCreated) {
		//Configure socket CAN
		socketCANConfiguration();

		//Create new thread to incoming CAN messages
		pthread_t idThreadCAN;
		pthread_create(&idThreadCAN, NULL, runCAN, NULL);
		CANthreadCreated = 1;
	}
}

void CAN_Handler(CanMessage message) {
	for(int i = 0; i < getCanBusCount(); i++) {
		CanBus* bus = &getCanBuses()[i];
		if(!QUEUE_PUSH(CanMessage, &bus->receiveQueue, message)) {
			// An exception to the "don't leave commented out code" rule,
			// this log statement is useful for debugging performance issues
			// but if left enabled all of the time, it can can slown down
			// the interrupt handler so much that it locks up the device in
			// permanent interrupt handling land.
			//
			// debug("Dropped CAN message with ID 0x%02x -- queue is full",
			// message.id);
			++bus->messagesDropped;
		}
	}
}

void socketCANConfiguration()
{
	/* Set can interface (name, baudrate) */
	configureSocketCan(500000,"all",0);
}

void printFrame(struct can_frame *f)
{
	unsigned int i=0;

	printf("id=%08x  dlc=%d data= ",f->can_id,f->can_dlc);
	for (i=0;i<f->can_dlc;i+=1) printf("%02x ",f->data[i]);
	printf("\n");
	fflush(stdout);
}

/**
 * @brief Configure baudrate to a CAN interface
 * @param s: socket to bind the app
 * @param interface: interface to configure
 * @param baudrate: baudrate to set in the interface
 * @return int
 */
int configureBaudRate(int s, char * interface,unsigned int baudrate)
{
	struct ifreq ifr;

	//*((can_baudrate_t*)&ifr.ifr_ifru)  =  baudrate;

	strcpy(ifr.ifr_name, interface);

	if(ioctl(s,0x8933,&ifr) !=0 )
	{
		perror("Setting BaudRate Error");
		return -1;
	}

	return 0;
}

/**
 * @brief Configure a socket bind to a CAN interface
 * Configure the baudrate
 * Configure Socket size
 * Bind to socket
 * @param void
 * @return int
 */
int configureSocketCan(unsigned int baudrate,char * interface,int rcvbuf_size)
{
#ifdef CANCON
	struct sockaddr_can addr;
	struct ifreq ifr;

	/* Open Socket and configure interface */
	if((skt = socket(PF_CAN, SOCK_RAW, CAN_RAW)) != -1)
	{
		if ((strcmp(interface,"all")) != 0)  /* Listening only in a specific interface */
		{
			strcpy(ifr.ifr_name, interface);

			if(ioctl(skt, SIOCGIFINDEX, &ifr) != 0)
			{
				perror("Opening CAN Socket error");
				return -1;
			}

			configureBaudRate(skt,"interface",baudrate);
		}

		else   /* Listen in each interface */
		{
			ifr.ifr_ifindex  =  0;

			configureBaudRate(skt,"can0",baudrate);
			configureBaudRate(skt,"can1",baudrate);
		}


		addr.can_family = AF_CAN;
		addr.can_ifindex = 	ifr.ifr_ifindex;

		/* Configure size rx_buffer */
		if(rcvbuf_size > 0)
		{
			if (setsockopt(skt,SOL_SOCKET, SO_RCVBUF,&rcvbuf_size, sizeof(rcvbuf_size)) < 0)
			{
				perror("setsockopt SO_RCVBUF");
				return -1;
			}
		}

		/* Bind to the socket */
		if(bind(skt, (struct sockaddr*)&addr, sizeof(addr)) < 0)
		{
			perror("Binding CAN Socket error");
			return -1;
		}
	}

	else
	{
		perror("Opening CAN Socket error");
		return -1;
	}
#endif
	return 0;
}

}



