// Ishu and Rohu are back with their exciting card game using a deck of 𝑁
//  cards. Each card has a non-negative value assigned to it.

// The game is played as follows: Ishu and Rohu take turns drawing cards from the deck. In each turn, Rohu draws the card with the smallest value, while Ishu draws the card with the largest value. After each draw, a new card is placed in the deck with a value equal to the absolute difference between the cards drawn by Ishu and Rohu. This process continues until there are fewer than 2 cards left in the deck.

// After each turn, Ishu and Rohu want to know the score, which is the sum of all the card values obtained up to that point.

// You need to write a program to help Ishu and Rohu determine the score after each turn.

// Input
// The first line of input contains a single integer, 𝑁
//  (1 ≤ 𝑁 ≤ 10^5)
//  denoting the number of cards.

// The second line of input contains 𝑁
//  space-separated non-negative integers, representing the initial values assigned to the 𝑁
//  cards. The values ranges from 1 to 109
// .

// Output
// Print 𝑛−1
//  lines, each containing a single integer. The 𝑖
// -th line represents the score after the 𝑖
// -th turn.


// input
// 6
// 8 9 2 10 5 4

// output
// 34
// 26
// 16
// 10
// 0

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define pass (void)0
#define print(arr, n) for (long long i = 0 ; i < n ; i ++) {printf("%lld ", arr[i]) ;}

void swap(long long *a, long long *b)
{
    long long temp = *a ;
    *a = *b ;
    *b = temp ;
}

long long max(long long a, long long b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

long long min(long long a, long long b)
{
    if (a > b)
    {
        return b ;
    }
    return a ;
}

struct Node
{
  long long key;
  struct Node *left;
  struct Node *right;
  long long height;
  long long count ;
};

long long height(struct Node *N)
{
  if (N == NULL)
    return 0;
  return N->height;
}

struct Node *newNode(long long key)
{
  struct Node *node = (struct Node *)
    malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  node->count = 1 ;
  return (node);
}

struct Node *rightRotate(struct Node *y)
{
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

struct Node *leftRotate(struct Node *x)
{
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

long long getBalance(struct Node *N)
{
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

struct Node *insertNode(struct Node *node, long long key)
{
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    node->count += 1 ;
  node->height = 1 + max(height(node->left),height(node->right));

  long long balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node)
{
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

struct Node* deleteNode(struct Node* root, long long key)
{
	if (root == NULL)
		return root;
	if ( key < root->key )
		root->left = deleteNode(root->left, key);
	else if( key > root->key )
		root->right = deleteNode(root->right, key);
	else
	{
    if (root -> count == 1)
    {
      if( (root->left == NULL) || (root->right == NULL) )
      {
        struct Node *temp = root->left ? root->left : root->right;
        if (temp == NULL)
        {
          temp = root;
          root = NULL;
        }
        else
        *root = *temp; 
        free(temp);
      }
      else
      {
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
      }
    }
    else
    {
      root -> count -= 1 ;
    }
	}
	if (root == NULL)
	return root;
	root->height = 1 + max(height(root->left), height(root->right));
	long long balance = getBalance(root);
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void print2DUtil(struct Node* root, long long space)
{
    if (root == NULL)
        return;
    space += 10;
    print2DUtil(root->right, space);
    printf("\n");
    for (long long i = 10; i < space; i++)
        printf(" ");
    printf("%lld\n", root->key);
    print2DUtil(root->left, space);
}

signed main()
{
    long long n, x ;
    scanf("%lld", &n) ;
    struct Node *root = NULL;
    long long su = 0 ;
    for (long long i = 0 ; i < n ; i ++)
    {
        scanf("%lld", &x) ;
        root = insertNode(root, x) ;
        su += x ;
    }
    
    for (long long i = 0 ; i < n - 1 ; i ++)
    {
        struct Node* temp = root ;
        while (temp -> left)
        {
            temp = temp -> left ;
        }
        long long m = temp -> key ;
        temp = root ;
        while (temp -> right)
        {
            temp = temp -> right ;
        }
        long long M = temp -> key ;
        root = deleteNode(root, m) ;
        root = deleteNode(root, M) ;
        root = insertNode(root, M - m) ;
        su -= 2 * m ;
        printf("%lld\n", su) ;
        // print2DUtil(root, 0) ;
    }
    return 0;
}
