# allocators

This repository houses two programs that work together:
- A C program to allocate memory on the heap and output the value of all the pointers along with their sizes and ops
- A Ruby script that uses `ruby2d` to visualize the output of the C program.

## Dependencies

For the C program, no dependencies needed, besides some standard `libc` installed on your system. The makefile uses gcc
by default, so if you are on a Windows system then you may want to install the mingw suite.

For the Ruby program, you will need `ruby2d`. `ruby2d` depends on `SDL2`. Follow its installation guide [here](https://www.ruby2d.com/learn/linux/#install-packages).

## Installation

Run the makefile.
```
git clone https://github.com/cultureshocked/allocators
cd allocators
make
```
No further action needed for the Ruby script.

## Usage

The easiest way to see the output is to run the following command:
`./allocators -rm log.txt && ruby visualizer.rb`

I can't offer any actual support for Windows at this time.

In later versions, the Ruby programw will also be able to read from `stdin`.

## License

GPLv3

## Inspiration

I initially got the idea to build this program from a [YouTube video by Jacob Sorber.](https://www.youtube.com/watch?v=GIWeQ2I67rk)

In that video, he builds the allocator differently, and does not show the Ruby code for very long, or walk through it.
I built this entire project over the course of a week without internet in rural Poland. I took screenshots of `ruby2d`
documentation and taught myself how to use it during that time as well.

While I credit my inspiration for this project to Jacob Sorber, the code in this repository is still entirely my own.

## Code Quality

The Ruby portion of the code is still very messy and can be improved drastically.

I am satisfied with the code for the C portion, but I will eventually come back to it and likely optimize or refactor it
at a later date.
