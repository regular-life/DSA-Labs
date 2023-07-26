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