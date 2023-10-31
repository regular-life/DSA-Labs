// After exploring all the art galleries, Kone has now set off on an expedition to Egypt in order to find the pharaoh's hidden treasure. He is navigating inside the Scooby-Doo pyramid and after hours of hard work, finds the hidden treasure. But alas, as soon as he touches the treasure chest, a series of mummies come to life and run to capture Kone. It is upto you to help Kone escape the pyramid alive, or report that there's no way out and he too, shall become a mummy. The pyramid is represented as a 2D matrix. Each cell can be of the following type -

// '.' implies that Kone can freely move through this cell
// '#' implies that the cell is blocked
// 'M' implies that a mummy is present in this cell (there can be multiple mummies)
// 'A' implies Kone's initial location
// Note that both Kone and mummies can move in following directions - up (U), down (D), left (L) and right (R). Kone can safely escape the pyramid if he reaches any free boundary cell without ever sharing a cell with any mummy. All the mummies are free to move in any way possible (in the available 4 directions).

// Your task is to find out if it is possible for Kone to escape, even if the mummies chase directly after Kone. In other words, find if it is possible for Kone to escape if all the mummies move optimally.

// If yes, print "YES" in the first line, followed by the number of moves in the second line, followed by the sequence of moves (in terms of U, D, L, R as a single string) in the third line (see example for more clarity).

// If no, and Kone has to become a mummy, just print "NO"

// Input
// the first line contains two integers m
//  and n
// , the height and width of the pyramid (1≤m,n≤1000
// )
// then there are m
//  lines with a string of length n
//  in each line indicating the layout of the pyramid.
// Examples
// input
// 4 4
// #.#M
// #.#.
// #A..
// ####
// output
// YES
// 2
// UU
// input
// 4 4
// #..M
// #.#.
// #A..
// ####
// output
// NO
// Note
// In test case-1, Kone can move up two times and escape the only mummy. In test case-2, the mummy can catch up to Kone whether he moves up or right.
