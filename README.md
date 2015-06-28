### Storm Launcher

Its a controller for Rocket Launcher '[!StormLauncher](http://dreamcheeky.com/thunder-missile-launcher)' to easily embed with your software. To use just add 'stormlauncher.c' to your tree.


#### Build

```
cc main.c stormlauncher.c -I. -lusb-1.0 -o launcher_test
```

#### Dependencies

libusb1.0
