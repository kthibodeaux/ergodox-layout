# My ErgoDox EZ configuration.

## Layout
* F and J act as CTRL when held
* D and K act as LSHIFT when held
* S and L act as LGUI when held
* ; tap dances to :
* LED indicators show layer number in binary

### Todo
* A new layer that is easy to toggle should allow common symbols to be pressed from the home row.

## Building

To build it you will need [qmk_firmware][qmk] checked out and this repo checked
out to something like `keyboards/ergodox_ez/keymaps/kthibodeaux`.

 [qmk]: https://github.com/jackhumbert/qmk_firmware

```
$ git clone https://github.com/jackhumbert/qmk_firmware.git
$ cd qmk_firmware
$ git clone https://github.com/kthibodeaux/ergodox-layout.git \
            keyboards/ergodox_ez/keymaps/kthibodeaux
$ make KEYBOARD=ergodox_ez KEYMAP=kthibodeaux
```
