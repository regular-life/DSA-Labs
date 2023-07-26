#include <conio.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define pass (void)0
#define print(arr, n) for (int i = 0  ; i < n  ; i ++) {printf("%d ", arr[i])  ;}
#define fr(a,b) for (int i = a  ; i < b  ; i ++)

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

struct AdjListNode
{
    int dest ;
    struct AdjListNode* next ;
} ;

struct AdjList
{
    struct AdjListNode* head ;
} ;

struct Graph
{
    int V ;
    struct AdjList* array ;
} ;

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode)) ;
    newNode->dest = dest ;
    newNode->next = NULL ;
    return newNode ;
}

struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)) ;
    graph->V = V ;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList)) ;
    int i ;
    for (i = 0 ; i < V ; i++)
    {
        graph->array[i].head = NULL ;
    }
    return graph ;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}


void dfs(struct Graph* graph, int* order, int* bridge_detect, int* mark, int v, int l, int* flag)
{
    mark[v] = 1 ;
    order[v] = order[l] + 1 ;
    bridge_detect[v] = order[v] ;
    
    struct AdjListNode* pCrawl = graph->array[v].head ;
    while (pCrawl)
    {
        int u = pCrawl->dest ;

        if (u == l)
        {
            pCrawl = pCrawl->next ;
            continue ;
        }

        if (order[v] < order[u])
        {
            pCrawl = pCrawl->next ;
            continue ;
        }

        if (mark[u])
        {
            bridge_detect[v] = (order[u] < bridge_detect[v]) ? order[u] : bridge_detect[v] ;
        }
        else
        {
            dfs(graph, order, bridge_detect, mark, u, v, flag) ;
        }

        bridge_detect[v] = (bridge_detect[u] < bridge_detect[v]) ? bridge_detect[u] : bridge_detect[v] ;
        pCrawl = pCrawl->next ;
    }

    if (bridge_detect[v] == order[v] && l != 0)
    {
        *flag = 0 ;
    }
}

void convert(struct Graph* graph)
{
    int V = graph->V ;
    int order[V] ;
    int bridge_detect[V] ;
    int mark[V] ;

    fr(0, V)
    {
        order[i] = 0 ;
        bridge_detect[i] = 0 ;
        mark[i] = 0 ;
    }

    int flag = 1 ;

    dfs(graph, order, bridge_detect, mark, 1, 0, &flag) ;

    if (flag == 0)
    {
        printf("NO") ;
    }
    else
    {
        printf("YES") ;
    }
}

int main()
{
    int v, e, a, b ;
    scanf("%d%d", &v, &e) ;
    if (v == 1) 
    {
        printf("YES");
        return 0;
    }
    struct Graph* adj = createGraph(v) ;
    while (e --)
    {
        scanf("%d%d", &a, &b) ;
        addEdge(adj, a - 1, b - 1) ;
    }

    convert(adj) ;

    return 0 ;
}