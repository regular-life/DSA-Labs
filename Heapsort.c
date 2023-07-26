#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define print(arr, n) for (int i = 0  ; i < n  ; i ++) {printf("%d ", arr[i])  ;}
#define fr(a,b) for (int i = a  ; i > b  ; i --)

void swap(int *a, int *b)
{
    int temp = *a  ;
    *a = *b  ;
    *b = temp  ;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a ;
    }
    return b ;
}

int min(int a, int b)
{
    if (a > b)
    {
        return b  ;
    }
    return a  ;
}

void heapify(int arr[], int N, int i)
{
	int largest = i ;
	int left = 2 * i + 1 ;
	int right = 2 * i + 2 ;
	if (left < N && arr[left] > arr[largest])
    {
		largest = left ;
    }
	if (right < N && arr[right] > arr[largest])
    {
		largest = right ;
    }
	if (largest != i)
    {
		swap(&arr[i], &arr[largest]) ;
		heapify(arr, N, largest) ;
	}
}

void heapSort(int arr[], int N)
{
    fr(N / 2 - 1, -1)
    {
		heapify(arr, N, i) ;
    }
	fr(N - 1, -1)
    {
		swap(&arr[0], &arr[i]) ;
		heapify(arr, i, 0) ;
	}
}

signed main()
{
    int N ;
    scanf("%d", &N) ;
    int arr[N] ;
    for (int i = 0 ; i < N ; i ++)
    {
        scanf("%d", &arr[i]) ;
    }
    heapSort(arr, N) ;
    print(arr, N) ;
}