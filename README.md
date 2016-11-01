# My ErgoDox EZ configuration.

## Special
* T and N act as CTRL when held
* ; tap dances to :
* Space tap dances to _
* Z tap dances to one shot modifier CMD

## Misc
* LED indicators show layer number in binary and light brightly when a modifier
  is pressed

## Todo
* A new layer that is easy to toggle should allow common symbols to be pressed
  from the home row.  This will likely be done by making backspace and tab act
  as a toggle to the layer when held.

## Building

To build it you will need [qmk_firmware][qmk] checked out and this repo checked
out to something like `keyboards/ergodox/keymaps/kthibodeaux`.

 [qmk]: https://github.com/jackhumbert/qmk_firmware

```
$ git clone https://github.com/jackhumbert/qmk_firmware.git
$ cd qmk_firmware
$ git clone https://github.com/kthibodeaux/ergodox-layout.git \
            keyboards/ergodox/keymaps/kthibodeaux
$ make KEYBOARD=ergodox KEYMAP=kthibodeaux
```
