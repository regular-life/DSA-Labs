// NOTE: You are allowed to use only stdlib.h and stdio.h . Your submission will not be graded if there is use of any other library.

// King John has decided to acquire the nearby kingdoms. He has gotten along with his troops to accomplish this mission. There are total of N
//  cities. The path to each kingdom goes from city 1. The kingdoms are in the last city of each path from city 1. Along each path there are some cities where soldiers have been deployed to protect the kingdoms. So if ith
//  city has soldiers deployed, then it'll be denoted by Si=1
// , otherwise Si=0
// . Note that there can be soldiers deployed in the cities containing kingdoms. Unfortunately the King's troops have power to defend soldiers in at most K
//  consecutive cities along the path. Your task is to tell the number of kingdoms that the King can conquer.

// Constraints:

// 2≤N≤100000
// 1≤K≤N
// Input
// The first line contains two spaced integers N
//  and K
//  where N
//  is the number of cities. The second line contains N
//  spaced integers where Si=1
//  or Si=0
// , denoting whether soldiers are deployed in the ith
//  city or not. Each of the following N−1
//  lines contains 2 spaced integers u
//  and v
//  (u≠v
// ). denoting that city u
//  and v
//  are connected to each other.

// NOTE: it is guaranteed that there is no cyclic paths.

// Output
// Print the number of kingdoms that the King can conquer.

// Example
// input
// 5 2
// 1 1 0 1 1
// 1 2
// 2 3
// 3 4
// 4 5
// output
// 1
// Note
// Here we have 5 cities. The path to each city goes via the city 1. There are soldiers in city 1, 2, 4, 5. We start from city 1. The kingdom is present in city 5 only as there is no city that we can travel from city 5 further once we go from 1 -> 2 -> -> 3 -> 4 -> 5. In this path we have maximum of 2 consecutive cities that have soldiers deployed. Hence only 1 kingdom will be acquired.

