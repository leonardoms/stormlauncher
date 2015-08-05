### Storm Launcher

Its a controller for Rocket Launcher '[StormLauncher](http://dreamcheeky.com/thunder-missile-launcher)' to easily embed with your software. To use just add 'stormlauncher.c' to your tree.


#### Build

build as embedded code:
```
cc test.c stormlauncher.c -I. -I/usr/include/libusb-1.0/ -lusb-1.0 -o launcher_test
```

build as lib:
```
cc stormlauncher.c -I. -I/usr/include/libusb-1.0/ -lusb-1.0 -shared -fPIC -o libstormlauncher.so
```

#### Dependencies

libusb1.0

#### Functions & Types

```C
stormLauncher_t // basic type for Rocket Launcher

// open the device, return TRUE for Sucess, FALSE to Fail
unsigned char stormlauncher_open(stormLauncher_t*);

// sl = stormLauncher_t; led = 1 - ON, 0 - Off
stormlauncher_setled(sl, led);

// sl = stormLauncher_t - stop launcher movement
stormlauncher_stop(sl);

// move launcher until stormlauncher_stop a call
stormlauncher_left(sl);
stormlauncher_right(sl);
stormlauncher_up(sl);
stormlauncher_down(sl);

// move launcher by a small step
stormlauncher_left_step(sl);
stormlauncher_right_step(sl);
stormlauncher_up_step(sl);
stormlauncher_down_step(sl);

// fires a rocket
stormlauncher_fire(sl);

```
