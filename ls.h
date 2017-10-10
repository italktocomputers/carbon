#ifndef __LS_H__
#define __LS_H__
#include <stdbool.h>
#include "settings.h"
bool libusb_ls(hid_device* dev, settings *s);
#endif // __REPOWER_H__
