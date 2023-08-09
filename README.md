# Rogue 3.6 for Linux

Taken [from_bsd_usenix87_rogue3.6.zip](https://britzl.github.io/roguearchive/files/from_bsd_usenix87_rogue3.6.zip)
from [https://britzl.github.io/roguearchive/](https://britzl.github.io/roguearchive/).

Modified to compile and run in Ubuntu (18.04, should work with others too).

### Some typical issues

C89 used and K&R notation, functions default to return int, declaration is not necessary.

VARARGS in ancient style using mismatched signature on call (prohibited in later versions).

`CTRL(ch)` expanded with `'ch'`, i.e. quotes added inside expansion

Signals signature should be `void f(int)`

`cfree` instead of `free`

`remove` renamed to `remove_mon` to avoid collision with library function

`tty` params dependent fragments - mostly removed or replaced

`sprintf` doesn't return pointer anymore, strings generally split in two

`gets` should be changed to fgets

some vars from `rogue.h` moved to `globals.c` (header shouldn't declare variables)

`NSIG` defines to `_NSIG` if not defined

Corrected string literal modifications in `init.c` (this do not work on platforms where code
memory is protected).

