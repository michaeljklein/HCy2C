find . -name '*.run' | parallel --joblog -j6 ./{}

# You might want to modify the '-j6' option for the number of cores you'd like to use to process the inputs.
