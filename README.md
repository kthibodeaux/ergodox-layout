# My ErgoDox EZ configuration.

## Building

```
$ git clone git@github.com:zsa/qmk_firmware.git
$ cd qmk_firmware
$ git clone git@github.com:kthibodeaux/ergodox-layout.git \
    keyboards/zsa/ergodox_ez/keymaps/kthibodeaux
$ ./util/docker_build.sh zsa/ergodox_ez/stm32/base:kthibodeaux
$ dfu-util -a 0 -d 3297:2002 -s 0x08002000:leave -D zsa_ergodox_ez_stm32_base_kthibodeaux.bin
```
