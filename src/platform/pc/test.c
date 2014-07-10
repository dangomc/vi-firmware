#include "test.h"

int var1;

void myfc(void)
{
	var1 = 0;

	printf("\n\nHello world from c %d\n", var1);
	start_can_read();
}

//int skt;

/*void start_can_read(void)
{
	printf("\n\nTest CAN\n\n");

    	/* Set can interface (name, baudrate) */
    	//configureSocketCan(500000,"all",0);

	
	//run();


	//return 0;
//}
