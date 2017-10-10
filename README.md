Carbon
====

Linux command line program to control the Logitech G413 Carbon gaming keyboard LEDs.


Usage
----

~~~
Usage: carbon [-?h] [-b STRING] [-s STRING] [--brightness=STRING]
            [--speed=STRING] [--help] [--help] [--usage]
            effect (resets to mid-brightness if empty)
Carbon -- Control LEDs on the Logitech G413 Carbon gaming keyboard

  -b, --brightness=STRING    Maximum key brightness from 00-ff in hexadecimal.
                             (Default: 80, i.e. 50%)
  -s, --speed=STRING         Breathe speed from 00-ff in hexadecimal. Set to
                             0xff to have one cycle every minute. (Default:
                             20)
  -?, --help                 Give this help list
  -h, --help                 Print this help message.
      --usage                Give a short usage message

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.
~~~


Dependencies
----

Requires:

* [hidapi](http://www.signal11.us/oss/hidapi/)
* [Linux Hidraw Driver](https://www.kernel.org/doc/Documentation/hid/hidraw.txt)


Thanks
----

[MatMoul's g810-led](https://github.com/MatMoul/g810-led) is an arguably
better-engineered and more comprehensive implementation of the same idea.

_Carbon_ is aimed at G413 specifically, and also discards C++ cruft in favour of pure C.
It has extra features such as "breathing" that have not been enabled in g810-led, and a cleaner interface.

However, it was only possible to create the current project by being able to pull apart MatMoul's existing code.
