# EucWorldPebble

2 New versions, one with Current & Voltage display (1.0cv) and one with Time & Voltage and Big speed gauge.

![Demo Gif](https://i.imgur.com/xRyoUo7.gif) ![Demo 2 Gif](https://i.imgur.com/X7Hm6im.gif) <img src="https://i.imgur.com/tVHcP6w.png" border="0" alt="Demo 3 All Arch"> <img src="https://i.imgur.com/pVIC82A.png" border="0" alt="round pebble">

Android companion app source for

https://euc.world app!

created by [Sebastian Łastowski](https://github.com/slastowski)

# How to install

First you need to have Pebble app installed on your Android phone

Latest mirror of the apk can be found in ApkMirror.com [HERE](https://www.apkmirror.com/apk/pebble-technology-corp/pebble/pebble-4-4-2-1405-62d45d7d7-endframe-release/pebble-4-4-2-1405-62d45d7d7-endframe-android-apk-download/) cause Pebble is discontinued.

And set it up using [Rebble.io](https://rebble.io/)

Then download the EucWorldPebble.pbw of your choice from [Releases](https://github.com/Somnius/EucWorldPebble/releases). To install it use [Cx File Explorer](https://play.google.com/store/apps/details?id=com.cxinventor.file.explorer&hl=en_US)

And open the pbw file with Pebble app to be able to load external app on your pebble watch.

# Useful commands for pebble development

Build a pebble project:

	pebble build

Install a .pbw on a phone (must enable dev mode on phone)

	pebble install --phone {IP_ADDRESS_OF_PHONE} path/to/app.pbw

Run a .pbw in an emulator

	pebble install --emulator <aplite/basalt/chalk/diorite> path/to/app.pbw

You can find example projects at https://github.com/pebble/pebble-sdk-examples and https://github.com/pebble-examples/

Source, Pebble-Dev Virtual Machine at https://willow.systems/pebble/
