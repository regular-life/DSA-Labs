// NOTE: You are allowed to use only stdlib.h and stdio.h . Your submission will not be graded if there is use of any other library.

// There are N
//  cities which are connected in the form an n-ary
//  tree. The city at the root of the tree is numbered as city 1. You will be given the list of cities which are interconnected to each other. Say s-t
//  is the shortest path between city s
//  and city t
// . We define the connectivity of the city as the distance of the shortest path be D(s−t)=d
// . You will be given T
//  test-cases where in each test-case contains 2 integers V
//  and D
// . You need to compute the number of cities having connectivity D
//  with the city 1 such that V
//  lies in the shortest path from that particular city to the city 1
// . Constraints:

// 1≤T≤200000
// 2≤N≤200000
// 2≤V≤N
// 0≤D≤(N−1)
// Input
// The first line contains 2 spaced integers N
//  and T
//  denoting the number of cities and number of test-cases. Each of the following N−1
//  lines contains 2 spaced integers u
//  and v
//  denoting the connection between city u,v
// . Each of the following T
//  lines contains 2 spaced integers V
//  and D
//  as defined in the problem statement.

// Output
// Print the number of cities having connectivity D
//  with the city 1 such that V
//  lies in the shortest path from that particular city to the city 1
// .

// Example
// input
// 7 3
// 5 1
// 7 1
// 6 1
// 3 1
// 4 5
// 2 5
// 6 6
// 7 1
// 2 3
// output
// 0
// 1
// 0
