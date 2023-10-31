// NOTE: Please note that to solve the problem you would need to implement mergesort algorithm from scratch. Otherwise, your submission will not be graded. Use of any other libraries apart from "stdio.h" is not allowed. Otherwise, your submission will not be graded.

// Ishu has plenty of deadlines to complete by the end of the day. But, she also needs to dress up for a friend's birthday party, because of which she can't focus on deadlines. Luckily, she got a close "friend" Rohu who would happily help her. So, Rohu decides to take on the deadlines, and for this, he comes up with the idea of arranging the deadlines first based on preference (easiness in Rohu's words).

// However, it is not as simple as it appears as Rohu is quite lazy and would want to make this arrangement using the minimum number of swaps. Help Rohu arrange the deadlines as this might be the only chance he would have of impressing Ishu.

// Formally, given 𝑁
//  distinct integers 𝑑1,𝑑2,...𝑑𝑖,...𝑑𝑁
// . You must report the minimum number of swaps required to order 𝐷1,𝐷2,...𝐷𝑖,...𝐷𝑁
// , where 𝐷1<𝐷2<...<𝐷𝑁
// .

// Input
// The first line contains a single integer 𝑛
//  (1≤𝑛≤105
// ) — the number of elements in the array.
//
// The second line contains 𝑛
//  distinct integers 𝑑1,𝑑2,…,𝑑𝑛
//  (1≤𝑎𝑖≤106
// ).

// Output
// Print minimum numbers of swaps.

// example input
// 4
// 1 2 4 3
// example output
// 1

#include <stdio.h>

void merge(int arr[], int l, int m, int r, int arrPos[])
{
    int temp[r - l + 1];
    int temp2[r - l + 1];
    int pointer = 0;
    int v1 = l;
    int v2 = m + 1;
    while (v1 <= m && v2 <= r)
    {
        if (arr[v1] > arr[v2])
        {
            temp[pointer] = arr[v2];
            temp2[pointer] = arrPos[v2];
            v2++;
        }
        else
        {
            temp[pointer] = arr[v1];
            temp2[pointer] = arrPos[v1];
            v1++;
        }
        pointer++;
    }
    while (v1 <= m)
    {
        temp[pointer] = arr[v1];
        temp2[pointer] = arrPos[v1];
        v1++;
        pointer++;
    }
    while (v2 <= r)
    {
        temp[pointer] = arr[v2];
        temp2[pointer] = arrPos[v2];
        v2++;
        pointer++;
    }
    for (int i = 0; i < r - l + 1; i++)
    {
        arr[l + i] = temp[i];
        arrPos[l + i] = temp2[i];
    }
}

void mergeSort(int arr[], int l, int r, int arrPos[])
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m, arrPos);
    mergeSort(arr, m + 1, r, arrPos);
    merge(arr, l, m, r, arrPos);
}

int minSwaps(int arr[], int n)
{
    int arrPos[n] ;
    int vis[n] ;
    for (int i = 0 ; i < n ; i ++)
    {
        arrPos[i] = i ;
        vis[i] = 0 ;
    }
    mergeSort(arr, 0, n - 1, arrPos) ;
    int ans = 0 ;
    for (int i = 0 ; i < n ; i ++)
    {
        if (vis[i] == 1 || arrPos[i] == i)
        {
            continue ;
        }
        int cyc_sz = 0 ;
        int j = i ;
        while (vis[j] == 0)
        {
            vis[j] = 1 ;
            j = arrPos[j] ;
            cyc_sz ++ ;
        }
        if (cyc_sz > 0)
        {
            ans += cyc_sz - 1 ;
        }
    }
    return ans ;
}

int main()
{
    int N;
    scanf("%d", &N) ;
    int arr[N] ;
    for (int i = 0 ; i < N ; i++)
    {
        scanf("%d", &arr[i]) ;
    }
    printf("%d", minSwaps(arr, N)) ;
    return 0;
}
