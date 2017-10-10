#ifndef __EFFECTS_H__
#define __EFFECTS_H__
#include <stdbool.h>
#include <hidapi/hidapi.h>
#include "settings.h"
bool set_brightness(hid_device* dev, settings *s);
bool breathe(hid_device* dev, settings *s);
bool ls(hid_device* dev, settings *s);
#endif // __EFFECTS_H__
