Carbon
====

Linux command line program to control the Logitech G413 Carbon gaming keyboard LEDs.


Design goals
----

Carbon aims to:

* Offer a clean user interface.
* Implement all the features available on the G413 Carbon.
* Be written in pure C.


Usage
----

~~~
Usage: carbon [-?hV] [-b STRING] [-p STRING] [-s STRING] [-v STRING]
            [--brightness=STRING] [--product=STRING] [--speed=STRING]
            [--vendor=STRING] [--help] [--help] [--usage] [--version]
            (level|breathe|ls)
Carbon -- Control LEDs on the Logitech G413 Carbon gaming keyboard

  -b, --brightness=STRING    Maximum key brightness from 00-ff in hexadecimal.
                             (Default: 80, i.e. 50%)
  -p, --product=STRING       Product ID in hexadecimal (c33a for G413 Carbon).
  -s, --speed=STRING         Breathe speed from 00-ff in hexadecimal. Set to
                             0xff to have one cycle every minute. (Default:
                             20)
  -v, --vendor=STRING        Vendor ID in hexadecimal (046d for Logitech).
  -?, --help                 Give this help list
  -h, --help                 Print this help message.
      --usage                Give a short usage message
  -V, --version              Print program version

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.
~~~


Dependencies
----

Requires:

* [hidapi](http://www.signal11.us/oss/hidapi/)
* [Linux Hidraw Driver](https://www.kernel.org/doc/Documentation/hid/hidraw.txt)


Installation
----

~~~
make
ln -sv $PWD/carbon ~/bin/
~~~


Known Problems
----

### Keyboard not detected

On reboot, the keyboard might not be detected correctly by hidraw.
A work around is to unplug the keyboard and plug it back in again.

Ideally, Carbon should offer a command to power-cycle the keyboard to avoid wear-and-tear on the USB plugs.
However, initial tests suggest this might be hard to implement.
The G413 Carbon keyboard does not listen to sysfs power settings, and unbinding/rebinding the device driver doesn't seem to do anything either.


Thanks
----

[MatMoul's g810-led](https://github.com/MatMoul/g810-led) is an arguably more comprehensive implementation of the same idea, except focused on more featureful keyboards.
It was only possible to create Carbon by pulling apart the code from g810-led.
Compared to g810-led, Carbon is written in pure C and implements features for the G413 not available in g810-led.
