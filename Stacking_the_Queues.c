#include <stdio.h>
#include <string.h>

#define MAX_Q 1000000
#define MAX_STACK 1000000

int main()
{
    long int q;
    scanf("%d", &q);
    long int arr[MAX_STACK] = {0};
    long int st_qu[MAX_Q] = {0};
    long int no_qu = 0;
    long int pointer = 0;
    while (q--)
    {
        getchar();
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "Push") == 0)
        {
            long int k;
            scanf("%d", &k);
            st_qu[no_qu] = pointer;
            arr[pointer] = k;
            no_qu++;
            pointer++;
        }
        else if (strcmp(op, "Enqueue") == 0) 
        {
            long int k;
            scanf("%d", &k);

            if (pointer == 0) {
                st_qu[no_qu] = 0;
                no_qu++;
            }
            arr[pointer] = k;
            pointer++;
        }
        else if (strcmp(op, "Pop") == 0)
        {
            if (pointer != 0)
            {
                no_qu--;
                for (long int p = st_qu[no_qu]; p < pointer; p++)
                {
                    arr[p] = 0;
                }
                pointer = st_qu[no_qu];
            }
        }
        else if (strcmp(op, "Dequeue") == 0) 
        {
            int fl = 1 ;
            if (pointer == 0)
            {
                printf("-1\n");
                fl = 0 ;
            }
            else
            {
                long int st = st_qu[no_qu - 1];
                printf("%d\n", arr[st]);

                if (pointer - st != 1)
                {
                    pointer--;

                    if (pointer != st)
                    {
                        for (long int p = st; p < pointer; p++)
                        {
                            arr[p] = arr[p + 1];
                        }
                    }
                }
                arr[pointer] = 0;
            }
            if (pointer == 0 && fl == 1)
            {
                printf("-1\n") ;
            }
        }
        else if (strcmp(op, "MaxSumPairs") == 0)
        {
            long int k;
            scanf("%d", &k);
            long int st = st_qu[no_qu - 1];
            long int cnt = 0;
            if (pointer - st == 2 && arr[st] + arr[st + 1] >= k)
            {
                cnt++;
            }
            else
            {
                for (long int p = st; p < pointer - 1; p++)
                {
                    if (arr[p] + arr[p + 1] >= k)
                    {
                        cnt++;
                    }
                }
            }
            printf("%d\n", cnt);
            no_qu--;
            for (long int p = st_qu[no_qu]; p < pointer; p++)
            {
                arr[p] = 0;
            }
            pointer = st_qu[no_qu];
        }
        // print(arr, pointer) ;
        // printf("\n") ;
        // print(st_qu, no_qu) ;
        // printf("\n") ;
    }
    return 0;
}
