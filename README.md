# Rogue version from 1981 revived

It was taken as a source "Rogue 3.6 (Source) - from_bsd_usenix87_rogue3.6.zip" from [https://britzl.github.io/roguearchive/](https://britzl.github.io/roguearchive/).

Number of small fixes was applied (most caused by minor language evolution and incompatibility, with some bug(s) fixed in auxiliary functions) - you can
trace them by commits history - they are intentionally small, each one about some fix.

Build files are provided so the thing is playable under Linux or BSD - you'll need to install (n)curses library before building of course. E.g.

    sudo apt install libncurses-dev

should work in ubuntu.

Saving the game is not functional - it was relying on storing the whole data memory area into the file, which seems not quite portable way - and also
the game relies on screen geometry (COLS and LINES variables) so when run from terminal emulators in GUI one may easily get to situation when
the game should be continued with different screen size. Instead there is a wizard mode (Ctrl-P and "Xyzzy" as password) with some useful
commands (which could be found in `commands.c` file).

Overall the game is different - in monsters and somewhat in difficulty - to the modern open-source variant. Old version from DOS seems most close to this one.
