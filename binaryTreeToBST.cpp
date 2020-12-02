#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
  int data;
  node *left, *right;
}*root1, *root2; 

void addNode(int x, node **headRef)
{
  node *temp = new node;
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;

  if(*headRef == NULL) {
    *headRef = temp;
  } else {
    node *q,*r;
    q = *headRef;
    while(q != NULL) {
      r = q;
      if(q->data >= x)
	q = q->left;
      else
	q = q->right;
    }
    if(r->data >= x) {
      r->left = temp;
    } else {
      r->right = temp;
    }
  }
}

void inOrderTraversal(node *head, vector<int>& vec, bool flag)
{
  if(head != NULL) {
    inOrderTraversal(head->left, vec, flag);
    if(flag) {
      cout << head->data << " ";
    } else {
      vec.push_back(head->data);
    }
    inOrderTraversal(head->right, vec, flag);
  }
}

int main()
{
  root1 = NULL;
  root2 = NULL;
  vector<int> storage;
  
  addNode(10, &root1);
  addNode(30, &root1);
  addNode(15, &root1);
  addNode(20, &root1);
  addNode(05, &root1);

  inOrderTraversal(root1, storage, false);
  sort(storage.begin(), storage.end());

  for(int i=0; i<storage.size(); i++)
    addNode(storage[i], &root2);

  inOrderTraversal(root2, storage, true);

  return 0;
}
