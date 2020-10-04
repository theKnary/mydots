#!/bin/sh
# runs when startx is called
#wallpaper='/home/knary/pics/wallpapers/misc/field.jpg'
# start composite manager - picom, run in background
#picom --experimental-backends
# start notification daemon
#dunst

# connect keyboard
#bluetoothctl power on && connect 90:9A:77:F9:ED:AC

# hide cursor when there is keyboard input (not if mod key)
#xbanish -i mod4

# set auto keyboard repeat to shorter delay and higher speed
#xset r rate 220 40

#bash /home/knary/.fehbg
#&& bash /home/knary/.scripts/lockscreen
# finally, start the WM
exec dwm
