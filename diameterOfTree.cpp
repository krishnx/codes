#include<iostream>

using namespace std;

struct node
{
  int data;
  node *left, *right;
}*root;

node* addNode(int);
void traverse(node *);
int diameter(node *);
int height(node *);
int diameterOpt(node *, int *);
int max(int, int);

int main()
{
  root = addNode(10);
  root->left = addNode(12);
  root->right = addNode(0);
  root->left->left = addNode(210);
  root->left->right = addNode(110);
  root->right->right = addNode(11230);

  int h = height(root);

  traverse(root);
  cout << "\nheight: " << h << endl;

  cout << "Diameter: " << diameter(root) << endl;
  cout << "DiameterOpt: " << diameterOpt(root, &h) << endl;

  return 0;
}

node* addNode(int x)
{
  node *temp = new node;
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

void traverse(node *q) 
{
  if(q != NULL) {
      traverse(q->left);
      cout << q->data << " ";
      traverse(q->right);
  }
}

int height(node *q)
{
  if(q == NULL)
    return 0;
  
  int l = height(q->left);
  int r = height(q->right);

  return 1 + max(l, r);
}

int diameter(node *q)
{
  if(q == NULL) 
    return 0;

  int lh = height(q->left);
  int rh = height(q->right);

  int ld = diameter(q->left);
  int rd = diameter(q->right);

  return max(1+lh+rh, max(ld, rd));
}

int diameterOpt(node *q, int *height) 
{
  int lh=0;
  int rh=0;
  int ld=0;
  int rd=0;

  if(q == NULL) {
    *height = 0;
    return 0;
  }
  
  ld = diameterOpt(q->left, &lh);
  rd = diameterOpt(q->right, &rh);

  *height = max(lh, rh) + 1;

  return max(lh+rh+1, max(ld,rd));
}

int max(int x, int y)
{
  return x>y ? x :y;
}
