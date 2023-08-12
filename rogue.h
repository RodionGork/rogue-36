/*
 * Rogue definitions and variable declarations
 *
 * @(#)rogue.h        3.38 (Berkeley) 6/15/81
 */

/*
 * Maximum number of different things
 */
#define MAXROOMS 9
#define MAXTHINGS 9
#define MAXOBJ 9
#define MAXPACK 23
#define MAXTRAPS 10
#define        NUMTHINGS 7        /* number of types of things (scrolls, rings, etc.) */

/*
 * return values for get functions
 */
#define        NORM        0        /* normal exit */
#define        QUIT        1        /* quit option setting */
#define        MINUS        2        /* back up one option */

/*
 * All the fun defines
 */
#define next(ptr) (*ptr).l_next
#define prev(ptr) (*ptr).l_prev
#define ldata(ptr) (*ptr).l_data
#define inroom(rp, cp) (\
    (cp)->x <= (rp)->r_pos.x + ((rp)->r_max.x - 1) && (rp)->r_pos.x <= (cp)->x \
 && (cp)->y <= (rp)->r_pos.y + ((rp)->r_max.y - 1) && (rp)->r_pos.y <= (cp)->y)
#define winat(y, x) (mvwinch(mw,y,x)==' '?mvwinch(stdscr,y,x):winch(mw))
#define debug if (wizard) msg
#define RN (((seed = seed*11109+13849) & 0x7fff) >> 1)
#define unc(cp) (cp).y, (cp).x
#define cmov(xy) move((xy).y, (xy).x)
#define DISTANCE(y1, x1, y2, x2) ((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))
#define when break;case
#define otherwise break;default
#define until(expr) while(!(expr))
#define ce(a, b) ((a).x == (b).x && (a).y == (b).y)
#define draw(window) wrefresh(window)
#define hero player.t_pos
#define pstats player.t_stats
#define pack player.t_pack
#define attach(a,b) _attach(&a,b)
#define detach(a,b) _detach(&a,b)
#define free_list(a) _free_list(&a)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define on(thing, flag) (((thing).t_flags & flag) != 0)
#define off(thing, flag) (((thing).t_flags & flag) == 0)
#define CTRL(ch) (ch & 037)
#define ALLOC(x) malloc((unsigned int) x)
#define FREE(x) free((void *) x)
#define EQSTR(a, b, c)        (strncmp(a, b, (unsigned int) (c)) == 0)
#define GOLDCALC (rnd(50 + 10 * level) + 2)
#define ISRING(h,r) (cur_ring[h] != NULL && cur_ring[h]->o_which == r)
#define ISWEARING(r) (ISRING(LEFT, r) || ISRING(RIGHT, r))
#define newgrp() ++group
#define o_charges o_ac
#define ISMULT(type) (type == POTION || type == SCROLL || type == FOOD)

/*
 * Things that appear on the screens
 */
#define PASSAGE '#'
#define DOOR '+'
#define FLOOR '.'
#define PLAYER '@'
#define TRAP '^'
#define TRAPDOOR '>'
#define ARROWTRAP '{'
#define SLEEPTRAP '$'
#define BEARTRAP '}'
#define TELTRAP '~'
#define DARTTRAP '`'
#define SECRETDOOR '&'
#define STAIRS '%'
#define GOLD '*'
#define POTION '!'
#define SCROLL '?'
#define MAGIC '$'
#define FOOD ':'
#define WEAPON ')'
#define ARMOR ']'
#define AMULET ','
#define RING '='
#define STICK '/'
#define CALLABLE -1

/*
 * Various constants
 */
#define        PASSWD        "mTcTtUJ57exqY"
/* #define PASSWD "mTUPAHIUXEmyQ" */
/* #define        PASSWD "mTmZcVjBEccKk" */
#define BEARTIME 3
#define SLEEPTIME 5
#define HEALTIME 30
#define HOLDTIME 2
#define STPOS 0
#define WANDERTIME 70
#define BEFORE 1
#define AFTER 2
#define HUHDURATION 20
#define SEEDURATION 850
#define HUNGERTIME 1300
#define MORETIME 150
#define STOMACHSIZE 2000
#define ESCAPE 27
#define LEFT 0
#define RIGHT 1
#define BOLT_LENGTH 6

/*
 * Save against things
 */
#define VS_POISON 00
#define VS_PARALYZATION 00
#define VS_DEATH 00
#define VS_PETRIFICATION 01
#define VS_BREATH 02
#define VS_MAGIC  03

/*
 * Various flag bits
 */
#define ISDARK        0000001
#define ISCURSED 000001
#define ISBLIND 0000001
#define ISGONE        0000002
#define ISKNOW  0000002
#define ISRUN        0000004
#define ISFOUND 0000010
#define ISINVIS 0000020
#define ISMEAN  0000040
#define ISGREED 0000100
#define ISBLOCK 0000200
#define ISHELD  0000400
#define ISHUH   0001000
#define ISREGEN 0002000
#define CANHUH  0004000
#define CANSEE  0010000
#define ISMISL  0020000
#define ISCANC        0020000
#define ISMANY  0040000
#define ISSLOW        0040000
#define ISHASTE 0100000

/*
 * Potion types
 */
#define P_CONFUSE 0
#define P_PARALYZE 1
#define P_POISON 2
#define P_STRENGTH 3
#define P_SEEINVIS 4
#define P_HEALING 5
#define P_MFIND 6
#define P_TFIND 7
#define P_RAISE 8
#define P_XHEAL 9
#define P_HASTE 10
#define P_RESTORE 11
#define P_BLIND 12
#define P_NOP 13
#define MAXPOTIONS 14

/*
 * Scroll types
 */
#define S_CONFUSE 0
#define S_MAP 1
#define S_LIGHT 2
#define S_HOLD 3
#define S_SLEEP 4
#define S_ARMOR 5
#define S_IDENT 6
#define S_SCARE 7
#define S_GFIND 8
#define S_TELEP 9
#define S_ENCH 10
#define S_CREATE 11
#define S_REMOVE 12
#define S_AGGR 13
#define S_NOP 14
#define S_GENOCIDE 15
#define MAXSCROLLS 16

/*
 * Weapon types
 */
#define MACE 0
#define SWORD 1
#define BOW 2
#define ARROW 3
#define DAGGER 4
#define ROCK 5
#define TWOSWORD 6
#define SLING 7
#define DART 8
#define CROSSBOW 9
#define BOLT 10
#define SPEAR 11
#define MAXWEAPONS 12

/*
 * Armor types
 */
#define LEATHER 0
#define RING_MAIL 1
#define STUDDED_LEATHER 2
#define SCALE_MAIL 3
#define CHAIN_MAIL 4
#define SPLINT_MAIL 5
#define BANDED_MAIL 6
#define PLATE_MAIL 7
#define MAXARMORS 8

/*
 * Ring types
 */
#define R_PROTECT 0
#define R_ADDSTR 1
#define R_SUSTSTR 2
#define R_SEARCH 3
#define R_SEEINVIS 4
#define R_NOP 5
#define R_AGGR 6
#define R_ADDHIT 7
#define R_ADDDAM 8
#define R_REGEN 9
#define R_DIGEST 10
#define R_TELEPORT 11
#define R_STEALTH 12
#define MAXRINGS 13

/*
 * Rod/Wand/Staff types
 */

#define WS_LIGHT 0
#define WS_HIT 1
#define WS_ELECT 2
#define WS_FIRE 3
#define WS_COLD 4
#define WS_POLYMORPH 5
#define WS_MISSILE 6
#define WS_HASTE_M 7
#define WS_SLOW_M 8
#define WS_DRAIN 9
#define WS_NOP 10
#define WS_TELAWAY 11
#define WS_TELTO 12
#define WS_CANCEL 13
#define MAXSTICKS 14

#ifndef _NSIG
#define _NSIG NSIG
#endif

/*
 * Now we define the structures and types
 */

/*
 * Help list
 */

struct h_list {
    char h_ch;
    char *h_desc;
};

/*
 * Coordinate data type
 */
typedef struct {
    int x;
    int y;
} coord;

typedef struct {
    short st_str;
    short st_add;
} str_t;

/*
 * Linked list data type
 */
struct linked_list {
    struct linked_list *l_next;
    struct linked_list *l_prev;
    char *l_data;                        /* Various structure pointers */
};

/*
 * Stuff about magic items
 */

struct magic_item {
    char *mi_name;
    int mi_prob;
    int mi_worth;
};

/*
 * Room structure
 */
struct room {
    coord r_pos;                        /* Upper left corner */
    coord r_max;                        /* Size of room */
    coord r_gold;                        /* Where the gold is */
    int r_goldval;                        /* How much the gold is worth */
    int r_flags;                        /* Info about the room */
    int r_nexits;                        /* Number of exits */
    coord r_exit[4];                        /* Where the exits are */
};

/*
 * Array of all traps on this level
 */
struct trap {
    coord tr_pos;                        /* Where trap is */
    char tr_type;                        /* What kind of trap */
    int tr_flags;                        /* Info about trap (i.e. ISFOUND) */
};

/*
 * Structure describing a fighting being
 */
struct stats {
    str_t s_str;                        /* Strength */
    long s_exp;                                /* Experience */
    int s_lvl;                                /* Level of mastery */
    int s_arm;                                /* Armor class */
    int s_hpt;                                /* Hit points */
    char *s_dmg;                        /* String describing damage done */
};

/*
 * Structure for monsters and player
 */
struct thing {
    coord t_pos;                        /* Position */
    bool t_turn;                        /* If slowed, is it a turn to move */
    char t_type;                        /* What it is */
    char t_disguise;                        /* What mimic looks like */
    char t_oldch;                        /* Character that was where it was */
    coord *t_dest;                        /* Where it is running to */
    short t_flags;                        /* State word */
    struct stats t_stats;                /* Physical description */
    struct linked_list *t_pack;                /* What the thing is carrying */
};

/*
 * Array containing information on all the various types of mosnters
 */
struct monster {
    char *m_name;                        /* What to call the monster */
    short m_carry;                        /* Probability of carrying something */
    short m_flags;                        /* Things about the monster */
    struct stats m_stats;                /* Initial stats */
};

/*
 * Structure for a thing that the rogue can carry
 */

struct object {
    int o_type;                                /* What kind of object it is */
    coord o_pos;                        /* Where it lives on the screen */
    char *o_text;                        /* What it says if you read it */
    char o_launch;                        /* What you need to launch it */
    char *o_damage;                        /* Damage if used like sword */
    char *o_hurldmg;                        /* Damage if thrown */
    int o_count;                        /* Count for plural objects */
    int o_which;                        /* Which object of a type it is */
    int o_hplus;                        /* Plusses to hit */
    int o_dplus;                        /* Plusses to damage */
    int o_ac;                                /* Armor class */
    int o_flags;                        /* Information about objects */
    int o_group;                        /* Group number for this object */
};

/*
 * Now all the global variables
 */

#define X extern

X struct h_list helpstr[];
X struct trap traps[];
X struct room rooms[MAXROOMS];                /* One for each room -- A level */
X struct room *oldrp;                        /* Roomin(&oldpos) */
X struct linked_list *mlist;                /* List of monsters on the level */
X struct thing player;                        /* The rogue */
X struct stats max_stats;                        /* The maximum for the player */
X struct monster monsters[26];                /* The initial monster states */
X struct linked_list *lvl_obj;                /* List of objects on this level */
X struct object *cur_weapon;                /* Which weapon he is weilding */
X struct object *cur_armor;                /* What a well dresssed rogue wears */
X struct object *cur_ring[2];                /* Which rings are being worn */
X struct magic_item things[NUMTHINGS];        /* Chances for each type of item */
X struct magic_item s_magic[MAXSCROLLS];        /* Names and chances for scrolls */
X struct magic_item p_magic[MAXPOTIONS];        /* Names and chances for potions */
X struct magic_item r_magic[MAXRINGS];        /* Names and chances for rings */
X struct magic_item ws_magic[MAXSTICKS];        /* Names and chances for sticks */

X int level;                                /* What level rogue is on */
X int purse;                                /* How much gold the rogue has */
X int mpos;                                /* Where cursor is on top line */
X int ntraps;                                /* Number of traps on this level */
X int no_move;                                /* Number of turns held in place */
X int no_command;                                /* Number of turns asleep */
X int inpack;                                /* Number of things in pack */
X int max_hp;                                /* Player's max hit points */
X int total;                                /* Total dynamic memory bytes */
X int a_chances[MAXARMORS];                /* Probabilities for armor */
X int a_class[MAXARMORS];                        /* Armor class for various armors */
X int lastscore;                                /* Score before this turn */
X int no_food;                                /* Number of levels without food */
X int seed;                                /* Random number seed */
X int count;                                /* Number of times to repeat command */
X int dnum;                                /* Dungeon number */
X int fung_hit;                                /* Number of time fungi has hit */
X int quiet;                                /* Number of quiet turns */
X int max_level;                                /* Deepest player has gone */
X int food_left;                                /* Amount of food in hero's stomach */
X int group;                                /* Current group number */
X int hungry_state;                        /* How hungry is he */

X char take;                                /* Thing the rogue is taking */
X char prbuf[80];                                /* Buffer for sprintfs */
X char outbuf[BUFSIZ];                        /* Output buffer for stdout */
X char runch;                                /* Direction player is running */
X char *s_names[MAXSCROLLS];                /* Names of the scrolls */
X char *p_colors[MAXPOTIONS];                /* Colors of the potions */
X char *r_stones[MAXRINGS];                /* Stone settings of the rings */
X char *w_names[MAXWEAPONS];                /* Names of the various weapons */
X char *a_names[MAXARMORS];                /* Names of armor types */
X char *ws_made[MAXSTICKS];                /* What sticks are made of */
X char *release;                                /* Release number of rogue */
X char whoami[80];                        /* Name of player */
X char fruit[80];                                /* Favorite fruit */
X char huh[80];                                /* The last message printed */
X char *s_guess[MAXSCROLLS];                /* Players guess at what scroll is */
X char *p_guess[MAXPOTIONS];                /* Players guess at what potion is */
X char *r_guess[MAXRINGS];                /* Players guess at what ring is */
X char *ws_guess[MAXSTICKS];                /* Players guess at what wand is */
X char *ws_type[MAXSTICKS];                /* Is it a wand or a staff */
X char file_name[80];                        /* Save file name */
X char home[80];                                /* User's home directory */

X WINDOW *cw;                                /* Window that the player sees */
X WINDOW *hw;                                /* Used for the help command */
X WINDOW *mw;                                /* Used to store mosnters */

X bool running;                                /* True if player is running */
X bool playing;                                /* True until he quits */
X bool wizard;                                /* True if allows wizard commands */
X bool after;                                /* True if we want after daemons */
X bool notify;                                /* True if player wants to know */
X bool fight_flush;                        /* True if toilet input */
X bool terse;                                /* True if we should be short */
X bool door_stop;                                /* Stop running when we pass a door */
X bool jump;                                /* Show running as series of jumps */
X bool slow_invent;                        /* Inventory one line at a time */
X bool firstmove;                                /* First move after setting door_stop */
X bool waswizard;                                /* Was a wizard sometime */
X bool askme;                                /* Ask about unidentified things */
X bool s_know[MAXSCROLLS];                /* Does he know what a scroll does */
X bool p_know[MAXPOTIONS];                /* Does he know what a potion does */
X bool r_know[MAXRINGS];                        /* Does he know what a ring does */
X bool ws_know[MAXSTICKS];                /* Does he know what a stick does */
X bool amulet;                                /* He found the amulet */
X bool in_shell;                                /* True if executing a shell */

X coord oldpos;                                /* Position before last look() call */
X coord delta;                                /* Change indicated to get_dir() */

X FILE *debugfifo;

#undef X

struct linked_list *find_mons(), *find_obj(), *get_item(), *new_item();
struct linked_list *new_thing(), *wake_monster();

char *getenv(), *tr_name(), *new();
char *vowelstr(), *inv_name(), *strcpy(), *strcat(), *brk();
char *ctime(), *num(), *ring_num();

struct room *roomin();

coord *rndmove();

void auto_save(int);
void endit(int);
void quit(int);

int nohaste(), doctor(), runners(), swander();
int unconfuse(), unsee(), rollwand(), stomach(), sight();

#ifdef CHECKTIME
int checkout();
#endif


void abort(void);
void free(void*);
long long lseek(int, long long, int);
void* malloc(size_t);
void exit(int);
int sprintf(char*, const char*, ...);
size_t strlen(const char*);

struct trap *trap_at();
