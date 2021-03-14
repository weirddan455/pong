# pong
Pong clone written in C using the SDL2 library.

No assets are required for this game. Sound is simple square waves generated at run-time and all graphics are rendered using SDL primatives.

## Prerequisites
You will need to have gcc and SDL2 installed as well as the header files (some distros package these seperately as "-devel" packages.)
You will also need git unless you feel like copy-pasting the files manually. On Arch Linux, the following packages should be all you need.

```
# pacman -S gcc sdl2 git
```

If you run into issues, try installing the base-devel package group:

```
# pacman -S base-devel
```

TODO: Write instructions for Windows and other popular Linux distros (Ubuntu, Debian, Fedora, etc.)

Windows users should be able to compile this in Visual Studio or something like MinGW.  Will have to test this at a later date.

## Get the code
If you have git installed, clone the repo with:

```
git clone https://github.com/weirddan455/pong.git
```

You can then pull down any future updates with

```
git pull
```

## Compiling
build.sh is included as a build script. Make sure it's executable and then run it:

```
chmod +x build.sh
./build.sh
```

## Running
To run the program type the following or double-click the executable from a GUI file browser:

```
./pong
```

GCC should make the binary executable by default but if not:

```
chmod +x pong
```
