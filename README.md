# Hcy2C: A library for counting, finding, and maximizing the number of cycles in graphs

[Project Haddock Documentation](http://michaeljklein.github.io/HCy2C/)


The primary goal of this project is to find an orientation of a given graph with the maximum possible number of cycles.
-See [this](https://en.wikipedia.org/wiki/Orientation_(graph_theory) Wikipedia article for some basics

The project is implemented in Haskell and C, with the main features tested on OSX (Macbook Pro, Late 2011) and the automatically generated C code tested on the Raspberry Pi 1, Model B (though there have been some tweaks since then, so it might take a little fiddling to get up and running).

See [TODO](https://github.com/michaeljklein/HCy2C/blob/master/TODO) for implemented and planned features.

The program flow goes: graph -> path finding, input graph specific C code -> compiled/optimized -> imported by Haskell -> pre-processed -> desired number of portable, independent, and parallel pieces in C code -> run in parallel or sequentially -> results reaped and consolidated (unimplemented/buggy) -> results output as orientations

Besides batch processing of a list of graphs, most everything needed has been implemented. Look [here](http://michaeljklein.github.io/HCy2C/Main.html) for cursory test documentation.
