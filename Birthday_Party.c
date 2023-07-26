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