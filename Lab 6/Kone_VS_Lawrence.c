#include <stdio.h>
#include <stdlib.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode* head;
};

struct Graph
{
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++)
        graph->array[i].head = NULL;
    return graph;
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

void printGraph(struct Graph* graph)
{
    for (int v = 0; v < graph->V; v++)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf(" ->  %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

struct QNode
{
    int key;
    struct QNode* next;
};

struct Queue
{
    struct QNode* front, *rear;
};

struct QNode* newNode(int k)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int k)
{
    struct QNode* temp = newNode(k);
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;
    struct QNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}

int isBi1(struct Graph* adj, int src, int color[], int n)
{
    color[src] = 1;
    struct Queue* qu = createQueue();
    enQueue(qu, src);
    while (qu->front != NULL)
    {
        int u = qu->front->key;
        deQueue(qu);
        struct AdjListNode* pCrawl = adj->array[u].head;
        while (pCrawl)
        {
            if (color[pCrawl->dest] == -1)
            {
                color[pCrawl->dest] = 1 - color[u];
                enQueue(qu, pCrawl->dest);
            }
            else if (color[pCrawl->dest] == color[u])
            {
                return 0;
            }
            pCrawl = pCrawl->next;
        }
    }
    return 1;
}

int isBipartite(struct Graph* adj, int n)
{
    int color[n + 1];
    for (int i = 0; i <= n; i++)
    {
        color[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (isBi1(adj, i, color, n) == 0)
                return 0;
        }
    }
    return 1;
}

int main()
{
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    struct Graph* adj = createGraph(n + 1);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        addEdge(adj, a, b);
    }
    if (isBipartite(adj, n) == 0)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    return 0;
}
