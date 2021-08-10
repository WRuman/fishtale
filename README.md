# Fishtale
Track aquarium metrics cheaply and efficiently.

## Prerequisites
- Raspberry Pi with Raspberry Pi OS.
- 1Wire kernel module activated, either via `dtoverlay=w1-gpio` in `/boot/config.txt` or using `raspi-config` (the latter updates the file for you).
- 1Wire temperature sensor, such as the DS18B20 module. 
- A 4.7 kΩ pull-up resistor between your GPIO pin and one of the available 3.3v supply pins.
- A user in the `gpio` group. You can create new users via `useradd` or add an existing one to the `gpio` group via `usermod`. Be sure to use the `--append` mode of `usermod` so you don't remove the user from their current set of groups by accident.

## Building
- C++ compiler, C++17 or higher.
- `libgpiod-dev` installed. Despite the name, with a "d" suffix, this is not a daemon but a set of development headers.
  + Also consider `libgpiod-doc` if you're developing so you can generate nice, browseable docs.
- `libsqlite3` installed.

