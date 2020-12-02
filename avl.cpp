#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct node
{
  int data, height;
  node *left, *right;
}*root;
typedef node* nodeptr;

void insert(int, nodeptr&);
void inOrder(nodeptr);
int bh(nodeptr);
nodeptr rr(nodeptr&);
nodeptr lr(nodeptr&);
nodeptr lrr(nodeptr&);
nodeptr rlr(nodeptr&);
int max(int, int);

int main()
{
  srand(time(NULL));
  
  root = NULL;

  for(int i=0; i<5; i++) {
    insert(rand()%100 + 1, root);
  }
  inOrder(root);

  return 0;
}

void insert(int x, nodeptr& p)
{
  if(p == NULL) {
    p = new node;
    p->data = x;
    p->height - 0;
    p->left = NULL;
    p->right = NULL;
  } else {
    if(x < p->data) {
      insert(x, p->left);
      if(bh( (p->left) - bh(p->right) ) == 2) {
	if(x < p->left->data) {
	  p = rr(p);
	} else {
	  p = lrr(p);
	}
      }
    } else if(x > p->data) {
      insert(x, p->right);
      if( (bh(p->right) - bh(p->left)) == 2 ) {
	if(x < p->right->data) {
	  p = rlr(p);
	} else {
	  p = lr(p);
	}
      }
    } else {
      cout << "Duplicate\n";
    }
  }
  int m,n;
  m = bh(p->left);
  n = bh(p->right);
  p->height = max(m,n) + 1;
}

void inOrder(nodeptr p)
{
  if(p != NULL) {
    inOrder(p->left);
    cout << p->data << " ";
    inOrder(p->right);
  }
}

int bh(nodeptr p)
{
  if(p == NULL) {
    return -1;
  } else {
    return p->height;
  }
}

nodeptr rr(nodeptr& p)
{
  nodeptr q;
  q = p->left;
  p->left = q->right;
  q->right = p;
  p->height = max(bh(p->left), bh(p->right)) + 1;
  q->height = max(bh(q->left), p->height) + 1;

  return q;
}

nodeptr lr(nodeptr& p)
{
  nodeptr q;
  q = p->right;
  p->right = q->left;
  q->left = p;
  p->height = max(bh(p->left), bh(p->right)) + 1;
  q->height = max(p->height, bh(q->right)) + 1;
  
  return q;
}

nodeptr lrr(nodeptr& p)
{
  p->left = lr(p->left);
  return rr(p);
}

nodeptr rlr(nodeptr& p)
{
  p->right = rr(p->right);
  return lr(p);
}

int max(int x, int y)
{
  return ( (x > y) ? x : y );
}
