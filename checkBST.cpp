#include<iostream>
#include<stack>

using namespace std;

struct node {
  int data;
  node *left, *right;
}*root;

void addNode(int);
void inOrderTraversal(node*);
bool checkBST();
void inOrderIterative(int a[]);

int main()
{
  int a[5] = {1,2,34,3,7};

  for(int i=0; i<5; i++) {
    addNode(a[i]);
  }

  inOrderTraversal(root);
  cout << endl;
  cout << "KRishna:: " << checkBST() << endl;

  return 0;
}

bool checkBST()
{
  int a[5];
  inOrderIterative(a);
  for(int i=0; i<5; i++) {
    for(int j=i+1; j<5; j++) {
      if(a[i] > a[j])
	return false;
    }
  }

  return true;
}

void addNode(int x)
{
  node *temp = new node;
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
  
  node *r, *q;
  if(root == NULL) {
    root = temp;
  } else {
    q = root;
    while(q != NULL) {
      r = q;
      if(x > q->data)
	q = q->right;
      else 
	q = q->left;
    }
    if(r->data > x)
      r->left = temp;
    else 
      r->right = temp;
  }
}

void inOrderTraversal(node *p)
{
  if(p != NULL) {
    inOrderTraversal(p->left);
    cout << p->data << " ";
    inOrderTraversal(p->right);
  }
}

void inOrderIterative(int a[])
{
  node *current = root;
  stack<node *> s;
  int i=0;

  while(!s.empty() || current) {
    if(current) {
      s.push(current);
      current = current->left;
    } else {
      current = s.top();
      s.pop();
      a[i] = current->data; i++;
      current = current->right;
    }
  }
}
