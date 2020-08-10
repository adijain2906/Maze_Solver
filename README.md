# Maze_Solver
This program checks whether a maze is possible to solve or not.
It takes input, the rows and column of the maze, and the starting position.
Then the maze is entered with the help of the following characters:
'@' represents the final destination
'.' represnts the path which can be traced through
'#' represents walls
Capital Letters are the locked doors
Small letters are the keys to the corresponding Capital Letter Doors

A sample maze mein look like this:
....##
..#a#@
...##.
..A...

This is a 4x6 size maze.
This is maze is possible to solve as the key 'a' will be able to open the locked door A and pass through that.
If the starting location is inside the door, then there is no need to open the door.
