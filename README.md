# AdventCode
https://adventofcode.com/2018/day/10
Solution description
Etracts position points x,y and velocities Vx and Vy from the given input string and store them into a collection of object.
Find the boundary coordinates by finding xMin, ymin, xMax and yMax because plotting starts from (xMin, yMin) to (xMax, yMax).
Sort the points in a way that it starts from (xMin yMin) to (xMax, yMax). Therefore it will in the same order of the 2-D array indices.
Then print '#' if first element of sorted array matches with the array index, otherwise print '.'

Output
Print when time is 10634

# # # # # . . . # . . . . # . . # # # # # # . . # # # # # # . . . # # # # . . . # # # # # # . . # # # # # # . . # . . . . # 
# . . . . # . . # . . . . # . . # . . . . . . . . . . . . # . . # . . . . # . . # . . . . . . . . . . . . # . . # . . . . #
# . . . . # . . # . . . . # . . # . . . . . . . . . . . . # . . # . . . . . . . # . . . . . . . . . . . . # . . . # . . # . 
# . . . . # . . # . . . . # . . # . . . . . . . . . . . # . . . # . . . . . . . # . . . . . . . . . . . # . . . . # . . # .
# # # # # . . . # # # # # # . . # # # # # . . . . . . # . . . . # . . . . . . . # # # # # . . . . . . # . . . . . . # # . .
# . . . . . . . # . . . . # . . # . . . . . . . . . # . . . . . # . . . . . . . # . . . . . . . . . # . . . . . . . # # . .
# . . . . . . . # . . . . # . . # . . . . . . . . # . . . . . . # . . . . . . . # . . . . . . . . # . . . . . . . # . . # .
# . . . . . . . # . . . . # . . # . . . . . . . # . . . . . . . # . . . . . . . # . . . . . . . # . . . . . . . . # . . # .
# . . . . . . . # . . . . # . . # . . . . . . . # . . . . . . . # . . . . # . . # . . . . . . . # . . . . . . . # . . . . #
# . . . . . . . # . . . . # . . # . . . . . . . # # # # # # . . . # # # # . . . # # # # # # . . # # # # # # . . # . . . . # 
