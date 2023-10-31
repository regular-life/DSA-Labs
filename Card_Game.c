// Rohu and Ishu are playing a card game. They have a deck of n cards, each with some value. In each round of the game, they perform the following steps:

// They draw K cards from the top of the deck.
// They note the highest value among the drawn cards.
// They remove the first card from the drawn set.
// Steps 1-3 are repeated until there are fewer than K cards left in the deck.
// Once the game has ended, the winner is determined as follows-

// The total score for the Player is calculated as the sum of the highest values noted by him during the game.

// The player with the highest total score is declared the winner. If both players have the same total score, the game is declared a draw.

// Note: The game Always starts with Ishu

// Input
// The first line of input consists of two integers 𝑛
//  and 𝑘
//  where 𝑛
//  is The number of cards in the deck (1≤𝑛≤105)
//  and K is The number of cards drawn in each round (1≤𝐾≤𝑛)
//  and the second line contains n space-separated numbers 𝑎1
// , 𝑎2
// , ..., 𝑎𝑛
// , where 𝑎𝑖
//  is the value of the i-th card in the deck (1≤𝑎𝑖≤109)
// Output
// Print "Rohu" if Rohu wins, "Ishu" if Ishu wins, or "draw" if the scores are equal.


// input
// 6 3
// 4 6 2 8 1 7
// output
// rohu

// input
// 10 2
// 3 7 1 9 4 8 2 6 5 10
// output
// ishu

#include <conio.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define pass (void)0
#define print(arr, n) for (int i = 0 ; i < n ; i ++) {printf("%d ", arr[i]) ;}

int main()
{
    int n, k ;
    scanf("%d%d", &n, &k) ;
    long int arr[n] ;
    long int mx = 0 ;
    long int rohu = 0, ishu = 0 ;
    int ind ;
    for (int i = 0 ; i < n ; i ++)
    {
        scanf("%ld", &arr[i]) ;
    }
    int i = 0, j = k - 1 ;
    for (int p = i ; p <= j ; p ++)
    {
        if (arr[p] > mx)
        {
            mx = arr[p] ;
            ind = p ;
        }
    } 
    while (i <= n - k && j < n)
    {
        while (i <= ind && j < n)
        {
            if (arr[j] > mx)
            {
                mx = arr[j] ;
                ind = j ;
            }
            if (i % 2 == 0)
            {
                ishu += mx ;
            }
            else
            {
                rohu += mx ;
            }
            i ++ ; j ++ ;
        }
        mx = 0 ;
        if (j != n)
        {
            for (int p = i ; p <= j ; p ++)
            {
                if (arr[p] > mx)
                {
                    mx = arr[p] ;
                    ind = p ;
                }
            }
        }
    }
    if (ishu > rohu)
    {
        printf("ishu") ;
    }
    else if (ishu == rohu)
    {
        printf("draw") ;
    }
    else 
    {
        printf("rohu") ;
    }
}
