#include <stdio.h>

#define print(arr, n) for (long long i = 0; i < n; i++) { printf("%lld ", arr[i]); }
#define fr(a,b) for (long long i = a; i < b; i++)

void swap(long long *a, long long *b)
{
    long long temp = *a;
    *a = *b;
    *b = temp;
}

long long max(long long a, long long b)
{
    if (a > b) {
        return a;
    }
    return b;
}

long long min(long long a, long long b)
{
    if (a > b) {
        return b;
    }
    return a;
}

void merge(long long arr[], long long l, long long m, long long r)
{
    long long temp[r - l + 1];
    long long pointer = 0;
    long long v1 = l;
    long long v2 = m + 1;
    while (v1 <= m && v2 <= r) {
        if (arr[v1] > arr[v2]) {
            temp[pointer] = arr[v2];
            v2++;
        }
        else {
            temp[pointer] = arr[v1];
            v1++;
        }
        pointer++;
    }
    while (v1 <= m) {
        temp[pointer] = arr[v1];
        v1++;
        pointer++;
    }
    while (v2 <= r) {
        temp[pointer] = arr[v2];
        v2++;
        pointer++;
    }
    for (long long i = 0; i < r - l + 1; i++) {
        arr[l + i] = temp[i];
    }
}

void mergeSort(long long arr[], long long l, long long r)
{
    if (l >= r) {
        return;
    }
    long long m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main()
{
    long long n, q;
    scanf("%lld%lld", &n, &q);
    long long hostility[n];
    long long humour[n];
    fr(0, n) {
        scanf("%lld", &hostility[i]);
    }
    fr(0, n) {
        scanf("%lld", &humour[i]);
    }
    long long sq = n * n;
    long long values[sq];
    long long poi = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            values[poi] = hostility[i] + humour[j];
            poi++;
        }
    }
    mergeSort(values, 0, sq - 1);
    while (q--) {
        scanf("%lld", &poi);
        printf("%lld\n", values[poi - 1]);
    }
    return 0;
}
