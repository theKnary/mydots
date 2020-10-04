#!/bin/sh
# dwm runs this when it starts

# increase char repeat rate
xset r rate 220 40 &
# hide cursor on keyboard input
xbanish -i mod4 &
# dual monitor
bash /home/knary/.screenlayout/monitorlayout.sh &
# wallpaper
bash /home/knary/.fehbg &
# status bar
dwmblocks &
# compositor
picom -b &
# start notification daemon
dunst &
# swap caps and ecape
xmodmap /home/knary/.swapcaps
