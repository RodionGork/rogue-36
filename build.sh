gcc --std=c89 -orogue \
  armor.c chase.c command.c daemon.c daemons.c fight.c globals.c init.c \
  io.c list.c main.c misc.c monsters.c move.c new_level.c options.c pack.c \
  passages.c potions.c rings.c rip.c rooms.c save.c scrolls.c sticks.c \
  things.c vers.c weapons.c wizard.c \
  -lcurses -lcrypt
