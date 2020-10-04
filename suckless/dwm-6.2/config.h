/* See LICENSE file for copyright and license deta*/

//includes
#include <X11/XF86keysym.h> // for mediakey codes

/** appearance **/
static const unsigned int snap      = 4;        /* snap pixel */
/* gaps */
static const unsigned int gappx		= 24;		/* gap pixel between windows */
static const int corner_radius		= 0;		/* corner radius of clients */
static const int onegap				= 0;		/* 1: diff gappx if one client
													0: no gap if one client */
static const unsigned int onegappx = 100;		/* single window gap px */
/* window border */
static const int borderalpha		= 0xe6;		/* border alpha for windows */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
//static const unsigned int blinksel  = 1;		/* blink selected window */
/* bar */
static const int showtitle			= 0;		/* 0: disable title */
static const int showbar            = 1;        /* 0 means no bar */
static const int showlts            = 1;        /* 0 means no layout symbol */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 12;        /* vert bar padding */
static const int sidepad            = 12;        /* side bar padding */
static const int baralpha			= 0xcc;		/* bar alpha */
static const float titlepos			= 0.25;		/* title position (decimal), */
static const float statuspos		= 0.50;		/* title position (decimal), */
/* dmenu */
static const char dmenulines[]		= "7";		/* number of lines in dmenu */
static const char dmwc[]			= "600";	/* width of dmenu char */
static const int dmenuwidth			= 600;		/* width of dmenu int (should match above)*/
/* fonts */
static const char *fonts[]          = { "hack:pixelsize=18", "Symbola:style=Regular" };
static const char dmenufont[]       = "hack:pixelsize=22:style=italic:style=bold";
/* palette */
// shades - keep for dmenu
static const char col_dark[]		= "#141414"; // background
static const char col_dim[]			= "#aaaaaa"; // dim text
static const char col_li_dim[]		= "#555555"; // light variant
static const char col_hi[]			= "#f1f1f1"; // bright text
//// colours
//static const char col_red[]			= "#a14042"; // red
//static const char col_blue[]		= "#064575"; // blue
//static const char col_green[]		= "#5d9451"; // green
//static const char col_cream[]		= "#efe7d5"; // cream
//static const char col_cream[]		= "#fffdd0";

//** colours handled by pywal now **
#include "/home/knary/.cache/wal/colors-wal-dwm.h"

/* themes */
//static const char *themes[][5][3]      = {
//	[ThemeDefault] =	{
//		/*				fg			bg			border */
//		// main
//		[SchemeNorm] = { col_dim, col_dark, col_li_dim },	// unselected
//		[SchemeSel]  = { col_hi, col_red,  col_red },	// selected
//		// misc.
//		[SchemeTitle] = { col_hi, col_dark, col_red },	// title
//		[SchemeStat] = { col_dim, col_dark, col_red },	// status
//		[SchemeLts] = { col_dim, col_dark, col_dark },	// layout symbol
//	},
//
//	// mono light
//	{
//		[SchemeNorm] = { col_li_dim, col_cream, col_cream },
//		[SchemeSel]  = { col_cream, col_dark,  col_dark },
//		[SchemeTitle] = { col_dark, col_cream, col_dark },
//		[SchemeStat] = { col_dark, col_cream, col_dark },
//		[SchemeLts] = { col_dark, col_cream, col_hi },
//	},
///*	// blue, dark
//	{
//		[SchemeNorm] = { col_dim, col_dark, col_li_dim },
//		[SchemeSel]  = { col_hi, col_blue,  col_blue },
//		[SchemeTitle] = { col_hi, col_dark, col_blue },
//		[SchemeStat] = { col_dim, col_dark, col_blue },
//		[SchemeLts] = { col_dim, col_dark, col_dark },
//	},
//	// blue, light
//	{
//		[SchemeNorm] = { col_li_dim, col_cream, col_li_dim },
//		[SchemeSel]  = { col_dark, col_blue,  col_blue },
//		[SchemeTitle] = { col_dark, col_cream, col_blue },
//		[SchemeStat] = { col_dark, col_cream, col_blue },
//		[SchemeLts] = { col_li_dim, col_cream, col_hi },
//	},
//	// green, dark
//	{
//		[SchemeNorm] = { col_dim, col_dark, col_li_dim },
//		[SchemeSel]  = { col_hi, col_green,  col_green },
//		[SchemeTitle] = { col_hi, col_dark, col_green },
//		[SchemeStat] = { col_dim, col_dark, col_green },
//		[SchemeLts] = { col_dim, col_dark, col_dark },
//	},
//	// green, light
//	{
//		[SchemeNorm] = { col_li_dim, col_cream, col_li_dim },
//		[SchemeSel]  = { col_dark, col_green,  col_green },
//		[SchemeTitle] = { col_dark, col_cream, col_green },
//		[SchemeStat] = { col_dark, col_cream, col_green },
//		[SchemeLts] = { col_li_dim, col_cream, col_hi },
//	},*/
//};

/* alphas */
static const unsigned alphas[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel] = { OPAQUE, baralpha, OPAQUE },
	[SchemeTitle] = { OPAQUE, baralpha, borderalpha },
	[SchemeStat] = { OPAQUE, baralpha, borderalpha },
	[SchemeLts] = { OPAQUE, OPAQUE, borderalpha },
};

//static char const *colors[LENGTH(themes[0])][LENGTH(themes[0][0])];

/* tagging */
static const char *tags[] = { "💻", "⌨", "🖋", "🌐", "♪", "🪟", "🖥", "🎨", "🚀" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	// -1 mask for all tags
	/* class					     instance    title       tags mask     isfloating   monitor */
	{ "firefoxdeveloperedition",     NULL,       NULL,       1 << 3,            0,           -1 },
	{ "code-oss",					 NULL,       NULL,       1 << 1,            0,           -1 },
	{ "Gimp",					     NULL,       NULL,       1 << 7,            0,           -1 },
	{ "discord",					 NULL,       NULL,       1 << 8,            1,           -1 },
	{ "Steam",						 NULL,       NULL,       1 << 7,            1,           -1 },
	{ "Spotify",					 NULL,       NULL,       1 << 4,            0,           -1 },
	{ "Pavucontrol",				 NULL,       NULL,			 -1,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
// changed to 0 because st has gap when = 1
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "🪟",      tile },    /* first entry is default */
	{ "▱",      NULL },    /* no layout function means floating behavior */
	{ "❐",      monocle },
	{ "▥",       col },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// dmenu
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
// x and y handled in spawn() (reason for 2 nulls)
static const char *dmenucmd[] = { "dmenu_run", "-l", dmenulines, "-w", dmwc, "-i", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL, NULL, NULL, NULL, NULL };

// terminal
// dark term
//static char *term_da_cmd[]  = { "st", "-g", "+500+250", NULL };
// light term
//static char *term_li_cmd[]  = { "st", "-g", "+500+250", "-p", NULL };
static char *termcmd[] = {"st", "-g", "+500+250", NULL, NULL};
static char *pavucontrol[] = {"pavucontrol", NULL};
static char *htopcmd[] = {"st", "-g", "50x20", "htop", NULL};

// scratchpad
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "40x25", NULL };
// browser
static const char *browser[] = { "qutebrowser", NULL };
// lock screen
//static const char *slock[] = { "slock", NULL };
// power commands
static const char *poweroff[] = { "poweroff", NULL };
//static const char *hibernate[] = { "hibernate", NULL };
// Multimedia keys
static const char *volup[] = { "volup", NULL };
static const char *voldown[] = { "voldown", NULL };
static const char *volmute[] = { "volmute", NULL };
static const char *micmute[] = { "micmute", NULL };
//static const char *briup[] = { "xbacklight", "-inc", "10", NULL };
//static const char *bridown[] = { "xbacklight", "-dec", "10", NULL };

// keys
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ 0,							XF86XK_AudioRaiseVolume, spawn, {.v = volup } },
	{ 0,							XF86XK_AudioLowerVolume, spawn, {.v = voldown } },
	{ 0,							XF86XK_AudioMute, spawn, {.v = volmute } },
	{ 0,							XF86XK_AudioMicMute, spawn, {.v = micmute } },
  //{ 0,							XF86XK_MonBrightnessUp, spawn, {.v = briup } },
  //{ 0,							XF86XK_MonBrightnessDown, spawn, {.v = bridown } },
  //{ 0,							XF86XK_Launch1,	   spawn,		   {.v = slock } },
	{ MODKEY,						XK_b,      spawn,          {.v = browser } },
	{ MODKEY,						XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY,						XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,						XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY|ControlMask,           XK_g,      togglegaps,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ControlMask,		    XK_k,      incgappx,       {.i = +2 } },
	{ MODKEY|ControlMask,           XK_j,      incgappx,	   {.i = -2 } },
	{ MODKEY|ControlMask,           XK_equal,  incgappx,	   {.i = 0 } },
//	{ MODKEY|ControlMask,           XK_s,	   cyclethemes,		{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.025} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.025} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_c,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = -1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ControlMask|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask,             XK_r,      quit,           {1} }, // restart dwm
	{ MODKEY|ControlMask|ShiftMask,             XK_p,      spawn, {.v = poweroff } },
	//{ MODKEY|ControlMask|ShiftMask,             XK_h,      spawn, {.v = hibernate } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkWinTitle,          0,              Button3,        spawn,           {.v = pavucontrol} },
	{ ClkStatusText,			0,              Button3,        spawn,           {.v = pavucontrol} },
	{ ClkWinTitle,			0,              Button2,        spawn,           {.v = htopcmd} },
	{ ClkStatusText,		0,              Button2,        spawn,           {.v = htopcmd} },

	{ ClkRootWin,			0,              Button2,        spawn,           {.v = termcmd} },

	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkClientWin,         0,              Button2,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
