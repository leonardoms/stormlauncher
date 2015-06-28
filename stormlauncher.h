#ifndef	_STORMLAUNCHER_H_
#define _STORMLAUNCHER_H_

#include <libusb.h>

#define	VENDOR_ID	0x2123
#define	PRODUCT_ID	0x1010
#define TRUE	1
#define FALSE	0

unsigned char
stormlauncher_cmd_ledon[8];

unsigned char
stormlauncher_cmd_ledoff[8];

unsigned char
stormlauncher_cmd_stop[8];

unsigned char
stormlauncher_cmd_left[8];

unsigned char
stormlauncher_cmd_right[8];

unsigned char
stormlauncher_cmd_up[8];

unsigned char
stormlauncher_cmd_down[8];

unsigned char
stormlauncher_cmd_fire[8];

typedef struct {
	libusb_device_handle* 	hnd;
	libusb_context*		ctx;
} stormLauncher_t;


// led ON = 1; led OFF = 0;
#define	stormlauncher_setled(sl, led)	stormlauncher_send( sl, ( led == 0 ) ? stormlauncher_cmd_ledoff : stormlauncher_cmd_ledon )

#define	stormlauncher_stop(sl)	stormlauncher_send( sl, stormlauncher_cmd_stop )

#define	stormlauncher_fire(sl)					\
	stormlauncher_send( sl, stormlauncher_cmd_fire );	\
	sleep(4);

#define stormlauncher_left(sl)	stormlauncher_send( sl, stormlauncher_cmd_left )

#define stormlauncher_right(sl)	stormlauncher_send( sl, stormlauncher_cmd_right )

#define stormlauncher_up(sl)	stormlauncher_send( sl, stormlauncher_cmd_up )

#define stormlauncher_down(sl)	stormlauncher_send( sl, stormlauncher_cmd_down )

#define STORMLAUNCHER_STEP 30000

#define stormlauncher_left_step(sl)		\
		stormlauncher_left(sl);		\
		usleep(STORMLAUNCHER_STEP);		\
		stormlauncher_stop(sl);


#define stormlauncher_right_step(sl)		\
		stormlauncher_right(sl);	\
		usleep(STORMLAUNCHER_STEP);	\
		stormlauncher_stop(sl);


#define stormlauncher_up_step(sl)		\
		stormlauncher_up(sl);		\
		usleep(STORMLAUNCHER_STEP);	\
		stormlauncher_stop(sl);


#define stormlauncher_down_step(sl)		\
		stormlauncher_down(sl);		\
		usleep(STORMLAUNCHER_STEP);	\
		stormlauncher_stop(sl);

unsigned char
stormlauncher_open(stormLauncher_t*);

#endif
