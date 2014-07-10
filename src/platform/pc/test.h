#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include <time.h>
 
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
 
#include <linux/can.h>
#include <linux/can/raw.h>

#define CANCON

//extern int skt;
extern int var1;

//void start_can_read(void); 
void myfc(void);
