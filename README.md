# arm-rockchip830-linux-uclibcgnueabihf
Cross compiler for Rockchip armhf for Linux kernel 6.12

This is the cross-compiler used for certain Rockchip armhf/armv7-a chips, such as the Luckfox Pico series. The only prebuilt version of that tool was built for Linux 5.10, and is unusable for newer kernels/u-boot. This is built on the same platform as the one distributed by Luckfox (crosstool-ng), built against Linux 6.12, so may be used as a drop-in replacement for the Luckfox SDK or similar applications where users hope to build a more recent kernel/u-boot/etc.
