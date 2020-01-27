# My ErgoDox EZ configuration.

## Special
* T and N act as CTRL when held
* R and I act as ALT when held
* A and O act as LSFT when held
* E activates a tmux layer when held
* Space tap dances to _

## Misc
* LED indicators show layer number in binary and light brightly when a modifier
  is pressed

## Building

To build it you will need [qmk_firmware][qmk] checked out and this repo checked
out to something like `keyboards/ergodox/keymaps/kthibodeaux`.

 [qmk]: https://github.com/jackhumbert/qmk_firmware

```
$ git clone git@github.com:qmk/qmk_firmware
$ cd qmk_firmware
$ make git-submodule
$ git clone git@github.com:kthibodeaux/ergodox-layout.git \
            layouts/community/ergodox/kthibodeaux
$ make KEYBOARD=ergodox_ez KEYMAP=kthibodeaux
$ teensy-loader-cli -mmcu=atmega32u4 -w ergodox_ez_kthibodeaux.hex
```
