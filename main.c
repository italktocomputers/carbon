#include <stdio.h>
#include <hidapi/hidapi.h>
#include "effects.h"
#include "args.h"

const char *argp_program_version = "Carbon 0.1";
const char *argp_program_bug_address = "cryptarch@github";

int main(int argc, char* argv[]) {
    struct arguments args;
    args.arg_settings.brightness = 0x80;
    args.arg_settings.speed = 0x10;
    args.effect = set_brightness;
    argp_parse(&argp, argc, argv, 0, 0, &args);
    s.brightness = args.arg_settings.brightness;
    s.speed = args.arg_settings.speed;

    hid_device *handle;
    handle = hid_open(0x046d, 0xc33a, NULL);
    if(handle == 0) {
        fprintf(stderr, "No Logitech G413 Carbon keyboards found.\n");
        goto cleanup;
    }
    args.effect(handle, &s);

cleanup:
    hid_close(handle);
    handle = NULL;
    hid_exit();
    return 0;
}
