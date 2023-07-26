#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define print(arr, n) for (int i = 0 ; i < n ; i ++) {printf("%d ", arr[i]) ;}
#define fr(a,b) for (int i = a ; i < b ; i ++)

void swap(int *a, int *b)
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int min(int a, int b)
{
    if (a > b)
    {
        return b ;
    }
    return a ;
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
	newNode -> dest = dest ;
	newNode -> next = NULL ;
	return newNode ;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)) ;
	graph -> V = V ;
	graph -> array = (struct AdjList*)malloc(V * sizeof(struct AdjList)) ;
	int i ;
	for (i = 0 ; i < V ; i ++)
		graph -> array[i].head = NULL ;
	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
	struct AdjListNode* check = NULL ;
	struct AdjListNode* newNode = newAdjListNode(dest) ;

	if (graph -> array[src].head == NULL)
    {
		newNode -> next = graph -> array[src].head ;
		graph -> array[src].head = newNode ;
	}
	else
    {

		check = graph -> array[src].head ;
		while (check -> next != NULL)
        {
			check = check -> next ;
		}
		check -> next = newNode ;
	}
}

void printGraph(struct Graph* graph)
{
    for (int v = 0; v < graph -> V; v ++)
    {
        struct AdjListNode* pCrawl = graph -> array[v].head ;
        printf("\n Adjacency list of vertex %d\n head ", v) ;
        while (pCrawl)
        {
            printf(" ->  %d", pCrawl -> dest) ;
            pCrawl = pCrawl -> next ;
        }
        printf("\n") ;
    }
}

struct QNode
{
	int key ;
	struct QNode* next ;
};

struct Queue
{
	struct QNode *front, *rear ;
};

struct QNode* newNode(int k)
{
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)) ;
	temp -> key = k ;
	temp -> next = NULL ;
	return temp ;
}

struct Queue* createQueue()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)) ;
	q -> front = q -> rear = NULL ;
	return q ;
}

void enQueue(struct Queue* q, int k)
{
	struct QNode* temp = newNode(k) ;
	if (q -> rear == NULL)
    {
		q -> front = q -> rear = temp ;
		return ;
	}
	q -> rear -> next = temp ;
	q -> rear = temp ;
}

void deQueue(struct Queue* q)
{
	if (q -> front == NULL)
		return ;
	struct QNode* temp = q -> front ;
	q -> front = q -> front -> next ;
	if (q -> front == NULL)
		q -> rear = NULL ;
	free(temp) ;
}

int main()
{
    int n, m, a, b ;
    scanf("%d%d", &n, &m) ;
    int inDegree[n + 1] ;
    fr(0, n + 1)
    {
        inDegree[i] = 0 ;
    }
    struct Graph* adj = createGraph(n + 1);
    struct Queue* qu = createQueue();
    fr(0, m)
    {
        scanf("%d%d", &a, &b) ;
        addEdge(adj, a, b) ;
        inDegree[b] ++ ;
    }
    for (int i = 0 ; i < n + 1 ; i ++)
    {
        struct AdjListNode* pCrawl = adj -> array[i].head;
        if (inDegree[i] == 0)
        {
            enQueue(qu, i) ;
        }
    }
    int cnt = 0 ;
    while (qu -> front != NULL)
    {
        int first = qu -> front -> key ;
        deQueue(qu) ;
        cnt ++ ;
        struct AdjListNode* pCrawl = adj -> array[first].head;
        while (pCrawl)
        {
            inDegree[pCrawl -> dest] -- ;
            if (inDegree[pCrawl -> dest] == 0)
            {
                enQueue(qu, pCrawl -> dest) ;
            }
            pCrawl = pCrawl -> next ;
        }
    }
    if (cnt == n + 1)
    {
        printf("Yes") ;
    }
    else
    {
        printf("No") ;
    }
    return 0;
}