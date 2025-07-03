#!/bin/bash

export USER=root
export DISPLAY=:1

rm -f /tmp/.X1-lock /tmp/.X11-unix/X1

mkdir -p /root/.vnc
echo "cub3dpass" | vncpasswd -f > /root/.vnc/passwd
chmod 600 /root/.vnc/passwd

/usr/bin/supervisord -c /etc/supervisor/conf.d/supervisord.conf
