# My ErgoDox EZ configuration.

## Special
* T and N act as CTRL when held
* R and I act as ALT when held
* E activates a tmux layer when held
* Space tap dances to _
* Enter is shift when held

## Misc
* LED indicators show layer number in binary and light brightly when a modifier
  is pressed

## Building

To build it you will need [qmk_firmware][qmk] checked out and this repo checked
out to something like `keyboards/ergodox/keymaps/kthibodeaux`.

 [qmk]: https://github.com/jackhumbert/qmk_firmware

```
$ git clone https://github.com/jackhumbert/qmk_firmware.git
$ cd qmk_firmware
$ git clone git@github.com:kthibodeaux/ergodox-layout.git \
            keyboards/ergodox/keymaps/kthibodeaux
$ make KEYBOARD=ergodox_ez KEYMAP=kthibodeaux
```
