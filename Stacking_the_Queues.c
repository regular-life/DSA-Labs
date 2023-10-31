// Kirdah is preparing for EDOBE's interview. He has asked Lawrence to take his mock interview. Lawrence was exploring some DSA problems which he could ask in the interview. He has surprisingly come up with a new problem of his own. The problem is as follows -

// Let 𝐒
//  be a stack. Each element in the stack 𝐒
//  is going to be a queue. You can perform the following operations:

// 𝐏𝐮𝐬𝐡
//  𝐊
//  :=
//  meaning that you have to push a queue containing a single element with value 𝐊
//  at its front.
// 𝐄𝐧𝐪𝐮𝐞𝐮𝐞
//  𝐊
//  :=
//  meaning that you have to enqueue value 𝐊
//  in the queue at the stack's top. If a stack is empty then perform 𝐏𝐮𝐬𝐡
//  𝐊
//  operation.
// 𝐏𝐨𝐩
//  :=
//  meaning that you have to pop a stack element.
// 𝐃𝐞𝐪𝐮𝐞𝐮𝐞
//  :=
//  meaning that you have to dequeue element from the queue at the stack's top and print that element. Note that if the queue becomes empty, then you must perform the 𝐏𝐨𝐩
//  operation. If the stack is empty then print -1
// .
// 𝐌𝐚𝐱𝐒𝐮𝐦𝐏𝐚𝐢𝐫𝐬
//  𝐊
//  :=
//  meaning that in the queue present at the stack's top, print the maximum number of consecutive pairs with sum atleast 𝐊
// . After printing, perform the 𝐏𝐨𝐩
//  operation.
// He is given to perform 𝐐
//  of the above operations mentioned above. Kirdah was unable to solve the problem in the interview. Can you help him solve the problem?

// Constraints:

// 1 ≤ 𝑄 ≤ 10^6
// 1 ≤ size of stack S, queues ≤ 10^6
// −10^9 ≤ 𝐾 ≤ 10^9
// Input
// The first line contains an integer 𝐐
// , denoting the number of operations to be perfomed. Each of the following 𝐐
//  lines contains any one of the operations given.

// Output
// Print the outputs corresponding to the operation if any.


// input
// 10
// Push 2
// Enqueue 1
// Enqueue 1
// MaxSumPairs 3
// Dequeue
// Dequeue
// Dequeue
// Push 1
// Pop
// Dequeue

// output
// 1
// -1
// -1
// -1
// -1

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
