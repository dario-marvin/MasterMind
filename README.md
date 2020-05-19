# MasterMind
MasterMind is a simple color guessing game, here implemented in Smalltalk for Pharo 6.1 and in C++ for the Ubuntu terminal. Not tested on other distributions.

### Instructions

The rules of the game are as follows:

1. You have to guess the combination of five non repeating colors between red, green, blue, yellow, white, black, magenta and brown.

<p align="center">
  <img src="https://github.com/dario-marvin/MasterMind/blob/master/MM1.png">
</p>

<p align="center">
  <img src="https://github.com/dario-marvin/MasterMind/blob/master/MM2.png">
</p>

2. The response symbol ⬢ means one color is in the combination at the right place, while ⬡ means a color is in the combination, but at the wrong place.

<p align="center">
  <img src="https://github.com/dario-marvin/MasterMind/blob/master/MM4.png">
</p>

3. You have 12 attempts. If you've not guessed the right combination by then, you will lose.

<p align="center">
  <img src="https://github.com/dario-marvin/MasterMind/blob/master/MM5.png">
</p>


### How to compile and execute the game
Save the source code file [`MasterMind.cc`](https://github.com/dario-marvin/MasterMind/blob/master/MasterMind.cc) in a folder on your computer. Open a terminal and navigate to you folder with the command `cd`, then run the commands
```
g++ MasterMind.cc -std=c++0x -o MasterMind
```
and
```
./MasterMind
```
