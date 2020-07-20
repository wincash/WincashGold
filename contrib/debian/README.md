
Debian
====================
This directory contains files used to package wincashgoldd/wincashgold-qt
for Debian-based Linux systems. If you compile wincashgoldd/wincashgold-qt yourself, there are some useful files here.

## wincashgold: URI support ##


wincashgold-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install wincashgold-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your wincashgold-qt binary to `/usr/bin`
and the `../../share/pixmaps/wincashgold128.png` to `/usr/share/pixmaps`

wincashgold-qt.protocol (KDE)

