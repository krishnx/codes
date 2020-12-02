#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
  int data;
  node *left, *right, *parent;
}*root;

void addNode(int);
void preOrder(node*);

int main()
{
  root = NULL;

  srand(time(NULL));
  for(int i=0; i<5; i++) {
    addNode(rand()%100 +1);
  }
  
  preOrder(root);

  return 0;
}

void addNode(int x)
{
  node *temp  = new node;
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
  temp->parent = NULL;

  if(root == NULL) {
    root = temp;
  } else {
    node *q, *r;
    q = root;
    while(q != NULL) {
      r = q;
      if(q->data >= x) {
	q = q->left;
      } else {
	q = q->right;
      }
    }
    if(r->data >= x) {
      r->left = temp;
    } else {
      r->right = temp;
    }
    temp->parent = r;
  }
}

void preOrder(node *q)
{
  if(q != NULL) {
    if(q != root)
      cout << "Current Data: " << q->data << " Parent Data: " << q->parent->data << endl; 
    else
      cout << "Current Data: " << q->data << endl;
    preOrder(q->left);
    preOrder(q->right);
  }
}

