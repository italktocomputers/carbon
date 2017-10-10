#ifndef __EFFECTS_H__
#define __EFFECTS_H__
#include <hidapi/hidapi.h>
typedef struct settings {
    unsigned char brightness;
    unsigned char speed;
} settings;
void set_brightness(hid_device* dev, settings *s);
void breathe(hid_device* dev, settings *s);
#endif // __EFFECTS_H__
