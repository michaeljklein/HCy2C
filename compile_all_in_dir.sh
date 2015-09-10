find . -name '*.c' | parallel --joblog --progress -j6 gcc -O3 {} -o {.}.run

# You might need to modify '-j6' to '-j4' for four parallel processes, or however many you'd like to use.
