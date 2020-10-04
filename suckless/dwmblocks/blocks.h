//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/							/*Update Interval*/	/*Update Signal*/
	
	{" 🔉", "echo -n $(pamixer --get-volume) && echo -n %",			0,		10},

	{" 📧", "~/.scripts/unreadmail",									1200,	0},

	{" 🐏", "free -m | awk 'NR==2{printf \"%.1fG\", $3/1024 }'",	60,		0},
	
	{" ", "date '+ %b %d %H:%M'",								30,		0},

	{" 📁", "~/.scripts/dwm-status home_avail",											120,	0},

	{" 💾", "~/.scripts/dwm-status root_avail",											120,	0},

	{" ☀", "~/.scripts/dwm-status wttr",									1200,	0},

	//{" 🎶", "~/.scripts/getspotify",										1,	0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = ' ';

// unused
//{"", "ip route get 1 | awk '{print $(NF-2);exit}'",			120,	0},
