#include <stdio.h>
#include <hidapi/hidapi.h>
#include "effects.h"
#include "args.h"

int main(int argc, char* argv[]) {
    settings s;
    s.brightness = 0x80;
    s.speed = 0x10;

    struct arguments args;
    args.arg_settings.brightness = 0x80;
    args.arg_settings.speed = 0x10;
    args.effect = set_brightness;
    argp_parse(&argp, argc, argv, 0, 0, &args);
    s.brightness = args.arg_settings.brightness;
    s.speed = args.arg_settings.speed;

    hid_device *handle;
    handle = hid_open(0x046d, 0xc33a, NULL);
    args.effect(handle, &s);
    hid_close(handle);
    handle = NULL;
    hid_exit();
    return 0;
}
