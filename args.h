#ifndef __ARGS_H__
#define __ARGS_H__
#include <stdlib.h>
#include <string.h>
#include <argp.h>
#include <stdbool.h>
#include <hidapi/hidapi.h>
#include "effects.h"

/* This structure is used by main to communicate with parse_opt. */
struct arguments {
    settings arg_settings;
    void (*effect)(hid_device*, settings*);
};

/*
   OPTIONS.  Field 1 in ARGP.
   Order of fields: {NAME, KEY, ARG, FLAGS, DOC}.
*/
static struct argp_option options[] = {
    {"brightness",  'b', "STRING", 0, "Maximum key brightness from 00-ff in hexadecimal. (Default: 80, i.e. 50\%)"},
    {"speed",  's', "STRING", 0, "Breathe speed from 00-ff in hexadecimal. Set to 0xff to have one cycle every minute. (Default: 20)"},
    {"help", 'h', NULL, 0, "Print this help message."},
    {0}
};

/*
   PARSER. Field 2 in ARGP.
   Order of parameters: KEY, ARG, STATE.
*/
static error_t parse_opt (int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    bool ishex;
    char* c = arg;
    int nxdig = 0;
    switch (key) {
        case 'b':
            while(*c != '\0') {
                if(!isxdigit(*c)) {
                    ishex = false;
                    break;
                } else {
                    ++nxdig;
                }
                ++c;
            }
            if(ishex && nxdig >= 0 && nxdig <= 2) {
                arguments->arg_settings.brightness = strtoul(arg, NULL, 16);
            }
            break;
        case 's':
            while(*c != '\0') {
                if(!isxdigit(*c)) {
                    ishex = false;
                    break;
                } else {
                    ++nxdig;
                }
                ++c;
            }
            if(ishex && nxdig >= 0 && nxdig <= 2) {
                arguments->arg_settings.speed = strtoul(arg, NULL, 16);
            }
            break;
        case 'h':
            argp_state_help(state, stdout, ARGP_HELP_USAGE | ARGP_HELP_LONG | ARGP_HELP_DOC);
            exit(EXIT_SUCCESS);
        case ARGP_KEY_ARG:
            if(state->arg_num > 0) {
                argp_usage(state);
            }
            if(strncmp(arg, "breathe", 8) == 0) {
                arguments->effect = breathe;
            } else if(strncmp(arg, "level", 8) == 0) {
                arguments->effect = set_brightness;
            }
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

/*
   ARGS_DOC. Field 3 in ARGP.
   A description of the non-option command-line arguments
     that we accept.
*/
static char args_doc[] = "effect (resets to mid-brightness if empty)";

/*
  DOC.  Field 4 in ARGP.
  Program documentation.
*/
static char doc[] = "Carbon -- Control LEDs on the Logitech G413 Carbon gaming keyboard";

/*
   The ARGP structure itself.
*/
static struct argp argp = {options, parse_opt, args_doc, doc};
#endif // __ARGS_H__
