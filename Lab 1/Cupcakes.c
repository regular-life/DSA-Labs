// NOTE: the easy and the hard version of the problem vary on the basis of the constraints given. Use of any other libraries apart from "stdio.h" is not allowed. Otherwise, your submission will not be graded.

// Lawrence has bought 𝑁
//  cupcakes for Kone. But it turns out that Kone doesn't want to eat them. Kone will eat the cupcakes only if Lawrence solves the problem given by him. Kone arranges the cupcakes in a row and assigns a random value 𝐴𝑖
//  to the 𝑖𝑡ℎ
//  cupcake. The values assigned to the cupcakes will be given to you in the form of an array 𝐴
// . He asks Lawrence to arrange the cupcakes in the ascending order of their values. Now he gives him 𝑄
//  queries to answer. In each query Kone gives three integers 𝐿,𝑅,𝐾
//  where 𝐿,𝑅
//  are indices of the array. Lawrence needs to print the number of subarrays in the subarray 𝐴[𝐿..𝑅]
//  which have 𝐾
//  distinct elements.

// Constraints:

// 1≤𝐴𝑖≤100
// 1≤𝑁≤3∗103
// 1≤𝑄≤50
// 0≤𝐿≤𝑅≤𝑁−1
// 1≤𝐾≤𝑁
// Input
// The first line contains two spaced integers 𝑁
//  and 𝑄
// . The next line contains 𝑁
//  spaces integers 𝐴𝑖
//  denoting the values of the cupcakes. Each of the next 𝑄
//  lines contain 3 integers 𝐿,𝑅,𝐾
// .

// Output
// Print the number of subarrays in the subarray 𝐴[𝐿..𝑅]
//  which have 𝐾
//  distinct elements for every query in separate line.
// input

// 7 2
// 60 66 94 56 59 8 67
// 4 5 7
// 5 6 6


// output

// 0
// 0

#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int temp[r - l + 1];
    int pointer = 0;
    int v1 = l;
    int v2 = m + 1;
    while (v1 <= m && v2 <= r)
    {
        if (arr[v1] > arr[v2])
        {
            temp[pointer] = arr[v2];
            v2++;
        }
        else
        {
            temp[pointer] = arr[v1];
            v1++;
        }
        pointer++;
    }
    while (v1 <= m)
    {
        temp[pointer] = arr[v1];
        v1++;
        pointer++;
    }
    while (v2 <= r)
    {
        temp[pointer] = arr[v2];
        v2++;
        pointer++;
    }
    for (int i = 0; i < r - l + 1; i++)
    {
        arr[l + i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int subarraysWithKDistinct(int A[], int n, int K)
{
    int mapp[100005] = {0};
    int begin = 0, end = 0, prefix = 0, cnt = 0, res = 0;
    while (end < n)
    {
        mapp[A[end]]++;
        
        if (mapp[A[end]] == 1)
        {
            cnt++;
        }
        end++;
        if (cnt > K)
        {
            mapp[A[begin]]--;
            begin++;
            cnt--;
            prefix = 0;
        }
        while (mapp[A[begin]] > 1)
        {
            mapp[A[begin]]--;
            begin++;
            prefix++;
        }
        if (cnt == K)
        {
            res += prefix + 1;
        }
    }
    return res;
}

int main()
{
    int N, Q ;
    scanf("%d %d", &N, &Q) ;
    int arr[N] ;
    for (int i = 0 ; i < N ; i ++)
    {
        scanf("%d", &arr[i]) ;
    }
    mergeSort(arr, 0, N-1) ;
    int dis[N] ;
    dis[0] = 1 ;
    int y = 1 ;
    for(int i = 1 ; i < N ; i ++)
    {
        if(arr[i-1] != arr[i])
        {
            y ++ ;
        }
        dis[i] = y ;
    }
    while (Q --)
    {
        int L, R, K ;
        scanf("%d %d %d", &L, &R, &K) ;
        int cnt = 0 ;
        if (R - L + 1 < K)
        {
            printf("%d\n", cnt) ;
        }
        else if (R - L + 1 == K)
        {
            if (dis[R] - dis[L] + 1 == K)
            {
                cnt = 1 ;
                printf("%d\n", cnt) ;
            }
            else
            {
                printf("%d\n", cnt) ;
            }
        }
        else
        {
            int lst[R - L + 1] ;
            for (int i = L ; i < R + 1; i ++)
            {
                lst[i - L] = arr[i] ;
            }
            cnt = subarraysWithKDistinct(lst, R - L + 1, K) ;
            printf("%d\n", cnt) ;
        }
    }
    return 0;
}
