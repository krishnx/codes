#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct node
{
  int data;
  node *left, *right;
}*root;

typedef node* nodeptr;

void insert(int, nodeptr&);
void inOrder(nodeptr);
void deleteNode(nodeptr&, int);

int main()
{
  srand(time(NULL));
  root = NULL;
  for(int i=0; i<10; i++) 
    insert(rand()%100+1, root);
  int x = 50;
  inOrder(root);
  cout << endl;
  deleteNode(root, 50);  
  
  return 0;
}

void insert(int x, nodeptr& p)
{
  if(p == NULL) {
    p = new node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
  } else {
    if(x < p->data) {
      insert(x, p->left);
    } else if(x > p->data){
      insert(x, p->right);
    } else {
      cout << "Duplicate!\n";
    }
  }
}

void inOrder(nodeptr p)
{
  if(p != NULL) {
    inOrder(p->left);
    cout << p->data << " ";
    inOrder(p->right);
  }
}

void deleteNode(nodeptr& p, int x)
{
  bool found = false;
  
  if(root == NULL) {
    cout << "Empty tree" << endl;
  }

  nodeptr curr, parent;
  while(curr) {
    if(curr->data == x) {
      found = true;
      break;
    } else {
      parent = curr;
      if(x > curr->data) {
	curr = curr->right;
      } else {
	curr = curr->left;
      }
    }
    if(!found) {
      cout << "not Found!" << endl;
      return;
    }
    
    //3 Cases:
    //case 2
    if(
       ( (curr->left != NULL) && (curr->right == NULL) ) ||
       ( (curr->left == NULL) && (curr->right != NULL) ) 
       )
      {
	if( (curr->left != NULL) && (curr->right == NULL) ) {
	  if(parent->left == curr) {
	    parent->left = curr->right;
	    delete curr;
	  } else {
	    parent->right = curr->right;
	    delete curr;
	  }
	} else {
	  if(parent->left == curr) {
	    parent->left = curr->left;
	    delete curr;
	  } else {
	    parent->right = curr->left;
	    delete curr;
	  }
	}
	return;
      }
    
    // case 1:
    if( (curr->left == NULL) && (curr->right == NULL) ) {
      if(parent->left == curr) {
	parent->left = NULL;
	delete curr;
      } else {
	parent->left = NULL;
	delete curr;
      }
    }
    
    //case 3:
    if( (curr->left != NULL) && (curr->right != NULL) ) {
      nodeptr checker;
      checker = curr->right;
      if( (checker->left == NULL) && (checker->right == NULL) ) {
	curr = checker;
	delete checker;
	curr->right = NULL;
      } else {
	// Choose the smallest in RIGHT subtree!
	if( (curr->right)->left != NULL ) {
	  nodeptr lcurr, lcurrp;
	  lcurrp = curr->right;
	  lcurr = (curr->right)->left;
	  while(lcurr->left != NULL) {
	    lcurrp = lcurr;
	    lcurr = lcurr->left;
	  }
	  curr->data = lcurr->data;
	  delete lcurr;
	  lcurrp->left = NULL;
	} else {
	  nodeptr tmp;
	  tmp = curr->right;
	  curr->data = tmp->data; 
	  curr->right = tmp->right;
	  delete tmp;
	}
      }
    }
    return ;
  }
}

