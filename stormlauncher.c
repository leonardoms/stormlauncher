
#include "stormlauncher.h"
#include <stdio.h>

unsigned char
stormlauncher_cmd_ledon[] = { 0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00 };

unsigned char
stormlauncher_cmd_ledoff[] = { 0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };

unsigned char
stormlauncher_cmd_stop[] = { 0x02,0x20,0x00,0x00,0x00,0x00,0x00,0x00 };

unsigned char
stormlauncher_cmd_left[] = { 0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00 };

unsigned char
stormlauncher_cmd_right[] = { 0x02,0x08,0x00,0x00,0x00,0x00,0x00,0x00 };

unsigned char
stormlauncher_cmd_up[] = { 0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x00 };

unsigned char
stormlauncher_cmd_down[] = { 0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x00 };

unsigned char
stormlauncher_cmd_fire[] = { 0x02,0x10,0x00,0x00,0x00,0x00,0x00,0x00 };

unsigned char
stormlauncher_open(stormLauncher_t* sl) {
	int err;

	libusb_init( &sl->ctx );
	sl->hnd = libusb_open_device_with_vid_pid( sl->ctx, VENDOR_ID, PRODUCT_ID );

	if( sl->hnd == NULL )
		return FALSE;

	if( libusb_kernel_driver_active( sl->hnd, 0 ) ) {
		err = libusb_detach_kernel_driver(sl->hnd, 0);
		if( err ) {
			printf("** ERROR: libusb_detach_kernel_driver() - %s\n", libusb_error_name(err));
			return FALSE;
		}
	}

//	err = libusb_reset_device(sl->hnd);
//	if( err ) {
//		printf("** ERROR: libusb_reset_device() - %s\n", libusb_error_name(err));
//		return FALSE;
//	}

	err = libusb_set_configuration( sl->hnd, 1 );
	if( err ) {
		printf("** ERROR: libusb_set_configuration() - %s\n", libusb_error_name(err));
		return FALSE;
	}

	err = libusb_claim_interface(sl->hnd, 0);
	if( err ) {
		printf("** ERROR: libusb_claim_interface() - %s\n", libusb_error_name(err));
		return FALSE;
	}

	return TRUE;
}

void
stormlauncher_send(stormLauncher_t* sl, unsigned char* cmd) {
	libusb_control_transfer( sl->hnd, 0x21, 0x09, 0, 0, cmd, 8, 1000 );
}
