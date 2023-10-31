// Kone has finally graduated and being passionate about art, wants to celebrate by visiting art galleries. Kone finds there are n art galleries in his area and wants to visit as many as he can within k days. Now, the ith
//  art gallery has wi
//  paintings and Kone wants to see the maximum number of paintings in each art gallery. Therefore, if Kone sees ai
//  paintings at the ith
//  art gallery, he wants wi−ai
//  to be minimum for all art galleries.

// To come up with an efficient strategy, he seeks the wisdom of his pals Lawrence and TarS. The group can visit atmost 1 art gallery per day. They propose an algorithm - if the paintings left to be seen for a given art gallery are w, then Kone only sees ceil(w2)
//  paintings and hope to revisit the art gallery later.

// Now, TarS knows that Lawrence dreads paintings and if the group sees ai
//  paintings for the ith
//  art gallery, Lawrence will be bored by bi∗ai
//  units. But Kone would still prefer seeing maximum number of paintings, however, if there are multiple optimal ways to go about it, he would be considerate of Lawrence's feelings and take the approach which bores Lawrence the least.

// Now, it is up to you to help Kone, Lawrence and TarS. Formally, you have to maximise the total number of paintings they can see and if there are multiple answers, choose the one which minimises Lawrence's boredom.

// Input
// the first line contains the number of test cases (1≤t≤5
// )
// the first line of each test case contains two integers n and k indicating the number of art galleries and days available (1≤n,k≤10^5
// )
// the second line of each test case contains n space separated integers indicating the number of paintings in each art gallery (1≤wi≤10^6
// )
// the third line of each test case contains n space separated integers indicating Lawrence's boredom for completing 1 painting in the ith
//  art gallery (1≤bi≤10^6
// )
// Output
// For each test case, print two space separated integers - the total number of paintings left to be seen and the total boredom acquired by Lawrence.

// Example
// input
// 1
// 4 4
// 1 2 3 4
// 5 3 1 1
// output
// 4 6
// Note
// In the above sample case: On day 1, they see ceil(3/2) = 2 paintings of art gallery 3. On day 2, they see ceil(4/2) = 2 paintings of art gallery 4. On day 3, they see ceil(2/2) = 1 paintings of art gallery 4. On day 4, they see ceil(1/2) = 1 paintings of art gallery 3.

// Total paintings seen are 2+2+1+1 = 6 and paintings left are 1+2+3+4-6 = 4. The corresponding boredom value is 2*1 + 2*1 + 1*1 + 1*1 = 6 units.

