#include<iostream>
#include<cstdlib>

using namespace std;

class Tree
{
 struct node
 {
   int data;
   node* left;
   node* right;        
 }*root;      
 public:
        Tree();
        void addNode(int);
        void preOrderTraversal(node*);     
        void inOrderTraversal(node*);
        void postOrderTraversal(node*);
        void traverseTree();
};

Tree::Tree()
{
 root = NULL;            
}

void Tree::addNode(int x)
{
 node* temp = new node;
 temp->data = x;
 temp->left = NULL;
 temp->right = NULL;
 
 if(root == NULL)
 {
  root = temp;        
 }
 else 
 {
  node *q,*r;
  q = root;
  
  while(q != NULL)
  {
   r = q;       
   if( x > q->data )
   {
       q = q->right;
   }
   else 
   {
        q = q->left;
   }
  }
  if(r->data > x) {
    r->left = temp;         
  } else {
    r->right = temp;     
  }      
 }      
}

void Tree::traverseTree()
{
 if(root != NULL) {
  cout << "inOrderTraversal: ";
  inOrderTraversal(root);
  cout << endl << "preOrderTraversal: ";
  preOrderTraversal(root);
  cout << endl << "postOrderTraversal: ";
  postOrderTraversal(root);
 } else {
   cout << "Tree has no data!!" << endl;;       
 }
}

void Tree::preOrderTraversal(node *r)
{
 node *q = new node;
 q = r;
 if(q != NULL) {
      cout << q->data << " ";
      preOrderTraversal(q->left);
      preOrderTraversal(q->right);       
 } else {
   //cout << "Empty Tree!!" << endl;       
 }
}

void Tree::inOrderTraversal(node *r)
{
 node *q = new node;
 q = r;
 if(q != NULL) {
      preOrderTraversal(q->left);
      cout << q->data << " ";      
      preOrderTraversal(q->right);       
 } else {
   //cout << "Empty Tree!!" << endl;       
 }
}

void Tree::postOrderTraversal(node *r)
{
 node *q = new node;
 q = r;
 if(q != NULL) {
      preOrderTraversal(q->left);
      preOrderTraversal(q->right);       
      cout << q->data << " ";
 } else {
   //cout << "Empty Tree!!" << endl;       
 }
}

int main()
{
    Tree t;
    t.addNode(30);
    t.addNode(10);
    t.addNode(40);
    t.addNode(20);
    t.addNode(50);
    t.traverseTree();

    system("pause");
    return 0;    
}
