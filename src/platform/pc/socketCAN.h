#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#define CANCON

void launchSocketCAN();
void *runCAN (void *);

void socketCANConfiguration();
void printFrame(struct can_frame *f);
int configureBaudRate(int s, char * interface,unsigned int baudrate);
int configureSocketCan(unsigned int baudrate,char * interface,int rcvbuf_size);
void run();


