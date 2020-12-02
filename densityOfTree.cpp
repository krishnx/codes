#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

struct node
{
  node *left, *right;
  int data, height;
}*root;
typedef node* nodeptr;

void addNode(int, nodeptr&);
void inOrder(nodeptr);
void preOrder(nodeptr);
void levelOrder(nodeptr);
int height(nodeptr);
int binheight(nodeptr);
int max(int, int);
nodeptr rr(nodeptr&);
nodeptr lr(nodeptr&);
nodeptr rlr(nodeptr&);
nodeptr lrr(nodeptr&);
int density(nodeptr);
int maxDepth(nodeptr);

int main()
{
  int a[] = {10,11, 3,43,456,87,12};
  int length = sizeof(a)/sizeof(a[0]);
    
  for(int i=0; i<length; i++) {
    addNode(a[i], root);
  }
  
  cout << "In Oredr: ";
  inOrder(root);
  cout << endl << "Level Order: ";
  levelOrder(root);
  cout << endl << "Pre Order: ";
  preOrder(root);  

  cout << "\nHeight: " << height(root) << endl 
       << "Density: " << density(root) << endl
       << "Max Depth: " << maxDepth(root) << endl;
  
 
  return 0;
}

void addNode(int x, nodeptr& p)
{
  if(p == NULL) {
    p = new node;
    p->data = x;
    p->height = 0;
    p->left = NULL;
    p->right = NULL;
  } else {
    if(x < p->data) {
      addNode(x, p->left);
      if (binheight(p->left) - binheight(p->right) == 2) {
	if(x < p->left->data) 
	  p = rr(p);
	else
	  p = lrr(p);
      }
    } else if(x > p->data) {
      addNode(x, p->right);
      if (binheight(p->right) - binheight(p->left) == 2) {
	if(x < p->right->data) 
	  p = rlr(p);
	else
	  p = lr(p);
      }
    } else {
      cout << "Duplicate!!\n";
    }
  }
  int m,n;
  m = binheight(p->left);
  n = binheight(p->right);
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

void preOrder(nodeptr p)
{
  if(p != NULL) {
    cout << p->data << " ";
    inOrder(p->left);
    inOrder(p->right);
  }
}

int height(nodeptr p)
{
  int lh=0, rh=0;

  if(root == NULL) 
    return 0;
  if(p == NULL)
    return 0;
  
  if(p != NULL) {
    lh = height(p->left);
    rh = height(p->right);
  }
  
  return ( (lh>=rh ? lh : rh) + 1 );
}

int max(int x, int y) 
{
  return (x>y ? x : y);
}

int binheight(nodeptr p)
{
  if(p == NULL) 
    return -1;
  else
    return p->height;
}

nodeptr rr(nodeptr& p)
{
  nodeptr q;
  q = p->left;
  p->left = q->right;
  q->right = p;
  p->height = max(binheight(p->left), binheight(p->right)) + 1;
  q->height = max(binheight(q->left), p->height) + 1;
  
  return q;
}

nodeptr lr(nodeptr& p)
{
  nodeptr q;
  q = p->right;
  p->right = q->left;
  q->left = p;
  p->height = max(binheight(p->left), binheight(p->right)) + 1;
  q->height = max(binheight(q->right), p->height) + 1;
  
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

void levelOrder(nodeptr p)
{
  queue<nodeptr> Q;
  
  while(p != NULL) {
    cout << p->data << " ";
    if(p->left != NULL)
      Q.push(p->left);
    if(p->right != NULL) 
      Q.push(p->right);
    if(!Q.empty()) {
      p = Q.front();
      Q.pop();
    } else {
      p = NULL;
    }
  }
}

int density(nodeptr p) 
{
  queue<nodeptr> currentLevel, nextLevel;
  int maxLevel=1, currLevel=1, max=1;
  currentLevel.push(p);
  while(!currentLevel.empty()) {
    nodeptr curr = currentLevel.front();
    currentLevel.pop();
    if(curr->left != NULL)
      nextLevel.push(curr->left);
    if(curr->right != NULL)
      nextLevel.push(curr->right);
    if(currentLevel.empty()) {
      queue<nodeptr> temp = currentLevel;
      currentLevel = nextLevel;
      nextLevel = temp;
      currLevel++;
      if(currentLevel.size() > max) {
	max = currentLevel.size();
	maxLevel = currLevel;
      }
    }
  }

  return maxLevel;
}

int maxDepth(nodeptr p)
{
  if(p == NULL) {
    return 0;
  } else {
    return ( 1 + max( maxDepth(p->left), maxDepth(p->right) ) );
  }
}
