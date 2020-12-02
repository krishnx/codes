#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct node
{
  int data;
  node *left, *right;
}*root;

void addNode(int);
void traverse(node*);
node* binTreeToDLLUtil(node*);
node* binTreeToDLL(node*);
void printDLL(node*);

int main()
{
  srand(time(NULL));
  for(int i=0; i<6; i++) 
    addNode(rand()%100 + 1);

  traverse(root);
  cout << endl;
  node *head = binTreeToDLL(root);
  printDLL(head);

  return 0;
}

void addNode(int x)
{
  node *temp = new node;
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;

  if(root == NULL) 
    root = temp;
  else {
    node *q,*r;
    q = root;
    while(q != NULL) {
      r = q;
      if(q->data > x)
        q = q->left;
      else 
        q = q->right;
    }
    if(r->data > x)
      r->left = temp;
    else 
      r->right = temp;
  }
}

void traverse(node* q)
{
  if(q != NULL) {
    traverse(q->left);
    cout << q->data << " ";
    traverse(q->right);
  }
}

node* binTreeToDLL(node* q) 
{
  if(q == NULL)
    return q;

  q = binTreeToDLLUtil(q);
  
  while(q->left != NULL) 
    q = q->left;

  return q;
}

node* binTreeToDLLUtil(node* q)
{
  if(q == NULL)
    return q;

  if(q->left != NULL) {
    node *left = binTreeToDLLUtil(q->left);
    for(; left->right != NULL; left=left->right);
    left->right = q;
    q->left = left;
    
  }
  if(q->right != NULL) {
    node *right = binTreeToDLLUtil(q->right);
    for(; right->left != NULL; right=right->left);
    right->left = q;
    q->right = right;
  }
  
  return q;
}

void printDLL(node *q)
{
  if(q != NULL) {
    while(q != NULL) {
      cout << q->data << " ";
      q = q->right;
    }
  }
}
