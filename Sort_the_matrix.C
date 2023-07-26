#include <stdio.h>

#define print(arr, n) for (int i = 0 ; i < n ; i ++) {printf("%d ", arr[i]) ;}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high, int m, int n, int mat[], int index[])
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
    {
		if (arr[j] < pivot)
        {
			i++;
			swap(&arr[i], &arr[j]);
            swap(&index[i], &index[j]) ;
            for (int q = 0 ; q < m ; q ++)
            {
                swap(&mat[q*n + i], &mat[q*n + j]) ;
            }
		}
	}
	swap(&arr[i + 1], &arr[high]);
    swap(&index[i + 1], &index[high]) ;
    for (int q = 0 ; q < m ; q ++)
    {
        swap(&mat[q*n + i + 1], &mat[q*n + high]) ;
    }
	return (i + 1);
}

void quickSort(int arr[], int low, int high, int m, int n, int mat[], int index[])
{
	if (low < high)
    {
		int pi = partition(arr, low, high, m, n,mat, index);
		quickSort(arr, low, pi - 1, m, n, mat, index);
		quickSort(arr, pi + 1, high, m, n, mat, index);
	}
}

int main()
{
    int m,n ;
    scanf("%d%d", &m, &n) ;
    int mat[m*n] ;
    int su[n] ;
    int index[n] ;
    for (int i = 0 ; i < n ; i ++)
    {
        index[i] = i ;
        su[i] = 0 ;
    }
    for (int i = 0 ; i < m*n ; i ++)
    {
        scanf("%d", &mat[i]) ;
        su[i%n] += mat[i] ;
    }
    quickSort(su, 0, n-1, m, n, mat, index) ;
    int i = 0 ;
    while (i < n)
    {
        int j = i ;
        while (su[i] == su[i+1])
        {
            i ++ ;
        }
        quickSort(index, j, i , m, n, mat, su ) ;
        if (i == j)
        {
            i ++ ;
        }
    }
    for (int i = 0; i < n * m; i += n)
    {
        for (int j = i; j < i + n; j++)
        {
            printf("%d ", mat[j]);
        }
        printf("\n");
    }
}