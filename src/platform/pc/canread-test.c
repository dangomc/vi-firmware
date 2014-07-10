#include "canread-test.h"

int skt;

void start_can_read(void)
{
	printf("\n\nTest CAN\n\n");

    	/* Set can interface (name, baudrate) */
    	configureSocketCan(500000,"all",0);

	
	run();


	//return 0;
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
/*    struct ifreq ifr;

    *((can_baudrate_t*)&ifr.ifr_ifru)  =  baudrate;

    strcpy(ifr.ifr_name, interface);

    if(ioctl(s,SIOCSCANBAUDRATE,&ifr) !=0 )
    {
        perror("Setting BaudRate Error");
        return -1;
    }*/

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



/**
  * @brief Is the thread execution that is listening the CAN layer in a socket. It is excuted forever
  * @param
  * @return
  */

void run()
{
#ifdef CANCON

    fd_set              canSktDesc;
    struct can_frame 	frame;
    int                 ret,nbytes;

    FD_ZERO(&canSktDesc);
    FD_SET (skt, &canSktDesc);



    for(;;) { //The work loop
	printf("\nrun\n");
        if ((ret = select(skt+1, &canSktDesc, NULL, NULL, NULL)) < 0) //Waiting for events in CAN socket layer
        {
            perror("Select Socket Error");
            return;
        }

        if ((nbytes = recv(skt,&frame, sizeof(frame),0)) < 0 )
        {
            perror("Error reading socket");
            return;
        }

        if (nbytes < (int) sizeof(struct can_frame))
        {
            fprintf(stderr, "read: incomplete CAN frame\n");
            return;
        }

        printFrame(&frame); //TODO: Borrar esto. Solo para Debug
    }

#endif

}
