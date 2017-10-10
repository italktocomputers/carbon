#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <hidapi/hidapi.h>
#include "ls.h"

bool libusb_ls(hid_device* dev, settings *s) {
	struct hid_device_info *devs, *cur_dev;
	devs = hid_enumerate(0x0, 0x0);
	cur_dev = devs;	
    bool found = false;
	while (cur_dev) {
        if(cur_dev->vendor_id == s->vendor && cur_dev->product_id == s->product) {
            printf("%s: %ls %ls (%ls)\n", cur_dev->path, cur_dev->manufacturer_string, cur_dev->product_string, cur_dev->serial_number);
            found = true;
            break;
        }
		cur_dev = cur_dev->next;
	}
	hid_free_enumeration(devs);
    if(!found) {
        printf("Device not found.\n");
    }
    return found;
}
