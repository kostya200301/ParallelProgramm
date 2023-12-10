#!/bin/bash

for i in {1..5}; do
    gnome-terminal --title="Router $i" -- ./router &
    # или использовать xterm вместо gnome-terminal
    # xterm -e "./router" &
done
