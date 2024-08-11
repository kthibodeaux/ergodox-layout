# My ErgoDox EZ configuration.

## Building

```
$ git clone git@github.com:qmk/qmk_firmware
$ cd qmk_firmware
$ make git-submodule
$ git clone git@github.com:kthibodeaux/ergodox-layout.git \
            layouts/community/ergodox/kthibodeaux
$ ./util/docker_build.sh ergodox_ez:kthibodeaux
$ teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_base_kthibodeaux.hex
```
