# magic-squares
Magic squares are square grids containing different integers such that each row, column and diagonal has an equal sum.
Normal magic squares are filled with distinct positive integers in the range `1, 2, ..., n^2` where `n * n` is the size of the square grid.

## Context

I heard of this concept for the first time while playing Professor Layton on the Nintendo DS. It featured the following magic square in which the sum is 15:
```
+---+---+---+
| 2 | 9 | 4 |
+---+---+---+
| 7 | 5 | 3 |
+---+---+---+
| 6 | 1 | 8 |
+---+---+---+
```
I then decided to learn more about it and as soon as I knew there was an algorithm to generate them, I coded an implementation of it in C in 2013

## Algorithm

The following algorithm enables us to create magic squares of `n * n` elements where `n` is odd (indeed, it doesn't work if `n` is even).

### Terminology

- `n` is called the order of the magic square
- `n * n` is called the size of the magic square

### Steps of the algorithm

```
All cells get the `0` value (this is an indicator of a cell that still needs to be filled)
The cell located right below the central cell of the magic square gets the `1` value
WHILE at least one cell is 0
	Move one step to the right and one step down
	IF the cell is 0
		Set it to the next value
	ELSE
		Go back to the last filled cell
		Move two steps down
		Set this new cell to the next value
	END OF IF
	NOTE: if one of the movements make us be outside the magic square, we have to go to the opposite edge
	(e.g. if we go one step down and it makes us be outside the magic square, we consider that the active cell is now the one at the very top of the magic square)
END OF WHILE
```

### Illustration

Here is an illustration of the previously mentioned algorithm in order to create a `3 * 3` magic square, by detailing each iteration:
```
 Iteration 1    Iteration 2    Iteration 3    Iteration 4
+---+---+---+  +---+---+---+  +---+---+---+  +---+---+---+
| 0 | 0 | 0 |  | 0 | 0 | 2 |  | 0 | 0 | 2 |  | 4 | 0 | 2 |
+---+---+---+  +---+---+---+  +---+---+---+  +---+---+---+
| 0 | 0 | 0 |  | 0 | 0 | 0 |  | 3 | 0 | 0 |  | 3 | 0 | 0 |
+---+---+---+  +---+---+---+  +---+---+---+  +---+---+---+
| 0 | 1 | 0 |  | 0 | 1 | 0 |  | 0 | 1 | 0 |  | 0 | 1 | 0 |
+---+---+---+  +---+---+---+  +---+---+---+  +---+---+---+

 Iteration 5    Iteration 6    Iteration 7    Iteration 8
+---+---+---+  +---+---+---+  +---+---+---+  +---+---+---+
| 4 | 0 | 2 |  | 4 | 0 | 2 |  | 4 | 0 | 2 |  | 4 | 0 | 2 |
+---+---+---+  +---+---+---+  +---+---+---+  +---+---+---+
| 3 | 5 | 0 |  | 3 | 5 | 0 |  | 3 | 5 | 7 |  | 3 | 5 | 7 |
+---+---+---+  +---+---+---+  +---+---+---+  +---+---+---+
| 0 | 1 | 0 |  | 0 | 1 | 6 |  | 0 | 1 | 6 |  | 8 | 1 | 6 |
+---+---+---+  +---+---+---+  +---+---+---+  +---+---+---+

Iteration 9:
- the current active cell is 8
- we move one step to the right (active cell is 1)
- we move one step down (we are outside the magic square so we go to the very top)
- as the cell is 0 we set it to the next value which is 9
```

## Limitations of this project

This project is only a proof of concept. Here is what I can think of that could be done in order to improve it:
- have an algorithm that handles even orders (i.e. in order to create magic squares with a `4 * 4` size for example as `4` is even)
- replace static memory allocation with dynamic memory allocation in C for the 2D array representing the magic square
- find all combinations of a magic square for a fixed n order. Indeed there are several solutions and it's actually visible on this `README.md` file as the `3 * 3` magic square mentioned in the "Context" section above is different than the one mentioned in the "Algorithm" section