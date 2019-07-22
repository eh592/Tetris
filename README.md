# Tetris
C++ recreation of Tetris. built on Visual Studio with Bordland Graphics API (see http://www.cs.colorado.edu/~main/cs1300/doc/bgi/bgi.html)

Tetris Design Document 

Objects:  

The Square Object:  

Methods 

This is the fundamental building block (literally) of our Tetris Project. This object will be one that can draw and move (left, right, and down).  

Data Members 

This object will also have a (x, y) position on the play field, its state, and its color. The state of the object will be predefined as being either FALLING or HIT which means it is the block continues to be FALLING until it HITS either another block or the bottom of the game field. This state is only for the sole purpose of easily tracking the state of the current block and using its state as a means to keep my code readable.   

The Tetrimino: 

Pure Virtual Functions 

This is the Abstract Base Class (ABC) that is constructed to allow all the other shapes of the tetrimino to follow a common structure further exemplifying the idea of . It will have two pure virtual functions, the first being rotate clockwise and the other rotate counter clockwise. The first reason for these to be pure virtual is so that it can make the class an ABC, meaning we need at least one function to be a pure virtual to make this an ABC. Secondly, all the other tetriminos rotate in their own unique way such that it would be most appropriate to override this “place holder” function in one of its derived classes (Oshape or Jshape).  

Other methods 

This class will also have its own draw function, but, rather than it being also a pure virtual, it should just be a regular method because it should not be overridden in the derived class. All the shapes essentially draw in the same way via square’s draw function. It is a matter of keeping track of the position, which could be dealt with in the storage of the 4 square objects in the class. All in all, draw is fundamentally the same for all tetriminos and it should remain a regular method for the sake of not writing extra code.  

Set and Get functions for Outline and Fill color [Symbol] the usual definitions.  

Data members 

Outline and Fill color 

Static array of Square objects 

Since all of the tetriminos have 4 square objects that compose them, it is most appropriate to store them in the ABC since it would preserve the abstraction concept we build on with inheritance. This array simply stores 4 square objects.  

Other Tetriminos (O, J, I, T, Z, S, L) 

Methods 

Overriding the Rotate Clockwise and Counter Clock wise functions 

Since each tetrimino only has a maximum of four rotational states, it would make sense to make these states enums.  

Constructor 

Each tetrimino needs to be constructed with the correct placement of Squares and colors.  

The Background (Gamefield) 

Methods 

This object is used for the purpose of keeping track of set blocks and drawing the background.  

Appropriate set and get functions 

Data Members 

This object will keep track of the state (OCCUPIED or UNOCCUPIED) of each block space of the background via static array stored as a data member. We will check this array via loop in the main to see if a row is due for deletion. 

A top left (x, y) coordinate position, outline color, and fill color.  

Timer  

Methods 

This object can return passed time and resets the reference time. 

Data Members 

It will store the reference time in which the timer starts counting. 

Major Algorithms: 

The major algorithm I have in my project is deleting my squares from a vector stored in main. I did this in my Lab 8 by first constructing a loop that finds a full row in my background’s static array that keeps track of the different states of each of the block spaces on the game field (OCCUPIED or UNOCCUPIED). Once a full row is found (counted 10 unoccupied) I mark that particular row for deletion by storing its index in another vector of integers from which I use to delete my square objects.  

if (background.getGameFieldState(i, j) == OCCUPIED) 

{ 

occuranceCount++; 

} 

 

After that I loop through my vector of stored square objects and check each of their y-coordinates match the square index multiplied by my width plus width. And loop backwards to avoid changing the indices while looping and deleting the squares. The vector of stored row indexes is cleared and I proceed to check for more full rows.  

for (int i = storedSquareIndex.size() - 1; i >= 0; i--) 

{ 

storedSquare.erase(storedSquare.begin() + storedSquareIndex[i]); 

} 

 

In order to ensure that the rotation of the blocks do not cause overlap or extend outside of the background, we probably should think about the tetrimino not as the shape itself, but rather as the entire area for which its rotational state can occupy. For example, I would try to make my detection account for the 3x3 block area that the Zshape can occupy in its two rotational state. 
