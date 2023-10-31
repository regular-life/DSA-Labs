// Kone recently joined forces with Melon Tusk and went to the first ever mission on Mars, and much to his delight he made friends with aliens over there. Now Kone has to rank all these aliens based on their hostility and humour. Kone collects this data for 𝑛
//  aliens and sends it over to Earth for his friend Lawrence to analyze. To be specific, Kone sends 𝑞
//  queries to Lawrence, where each query contains a single integer 𝑞𝑖
//  and he's supposed to report the 𝑞𝑖𝑡ℎ
//  alien in the increasing order of the sum of hostility + humour values. Help Lawrence and Kone with this task and play a role in strengthening Earth-Mars ties.

// Update: the sum to be considered corresponds to all possible combinations of hostility and humour.

// Input
// the first line contains two space separated integers - the number of aliens 𝑛
//  and the number of queries 𝑞
//  (1≤𝑛≤20000
//  and 1≤𝑞≤500
// )
// the second line contains 𝑛
//  elements representing the hostility value of each alien (1≤𝑎𝑖≤1018
// )
// the third line contains 𝑛
//  elements representing the humour value of each alien (1≤𝑏𝑖≤1018
// )
// then 𝑞
//  lines follow where each line contains a single integer 𝑞𝑖
//  (1≤𝑞𝑖≤20000
// )
// Output
// For each query, report the 𝑞𝑖𝑡ℎ
//  value of hostility + humour sum in increasing order


// input
// 3 2
// 1 2 3
// 6 7 8
// 3
// 4

// output
// 8
// 9

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
