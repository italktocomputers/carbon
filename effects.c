#include "effects.h"

void set_brightness(hid_device* dev, settings *s) {
    unsigned char data[] = {
        0x11 /* Report number */,
        0xff /* Not sure what this is */,
        0x0c /* Protocol */,
        0x3c /* Not sure what this is */,
        0x00 /* Which part of the keyboard, or something? */,
        0x01 /* Which effect? */,
        s->brightness /* Amount of red */,
        0x00 /* Amount of green (not useful for G413 Carbon) */,
        0x00 /* Amount of blue (not useful for G413 Carbon) */,
        0x02 /* Not sure what this is */,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // There needs to be 20 bytes in total, apparently.
    };
    hid_write(dev, data, 20);
}

void breathe(hid_device* dev, settings *s) {
    unsigned char data[] = {
        0x11 /* Report number */,
        0xff /* Not sure what this is */,
        0x0c /* Protocol */,
        0x3c /* Not sure what this is */,
        0x00 /* Which part of the keyboard, or something? */,
        0x02 /* Which effect? */,
        s->brightness /* Amount of red */,
        0x00 /* Amount of green (not useful for G413 Carbon) */,
        0x00 /* Amount of blue (not useful for G413 Carbon) */,
        s->speed /* Speed */,
        0x10 /* Not sure what this is */,
        0x00 /* Not sure what this is */,
        0x64 /* Not sure what this is */,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // There needs to be 20 bytes in total, apparently.
    };
    hid_write(dev, data, 20);
}
