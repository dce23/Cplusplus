Path Search

In this homework, we have an intrepid adventurer trying to find their lost dog in a maze. The program is going to find a path from their position to the dog.

The map class is ability to read in a text map file, store the information from the map and let you ask questions about it. Each map is a complete rectangle.

The questions you can ask are:
•	The width and height of the map
•	The position of the adventurer (the start position)
•	The position of the dog (the end position)
•	Whether a certain position is blocked or not

Positions in the map are specified by row and column, using the position class. Rows and columns are counted from 0, like we always do in code.

•	Positions that are blocked should be shown as X

•	Position that are open should be shown as empty space

•	The start position should be shown as an A

•	The end position should be shown as a D

The algorithm for Breadth First Search implemented with a queue.

  1.	Push the start position onto the queue
  2.	While the queue is not empty...
    
      1.	Pop the front position off the queue
      2.	If it is the end, we're there! Declare success!
      3.	Otherwise, push all the unblocked, unvisited neighbors of that position onto the back of the queue
  3.	If the queue empties and we haven't found the end, there is no path

The key detail is in step 2.3, that we only add unvisited neighbors. That is, positions you can move to from the current position which we haven't checked yet. In our adventurer and dog problem, we'll say that the adventurer can only move left, right, up or down. That means that each position has up to 4 neighbors (the positions on the edges have 2 or 3).

The reason a queue works here is that all the one-step-away positions get in line first, then the two-step-away positions and so on.
