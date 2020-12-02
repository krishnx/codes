#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

class Tree
{
  int lh, rh;
  struct node
  {
   int data;
   node *left, *right;       
  } *root;    
     public:
            Tree();
            void addNode(int );
            void traverseTree();
            int height(node *);
            void heightOfNode();
            void deleteNode(int);
            void levelOrder();
            void inOrder(node *);
            void preOrder(node *);
            void postOrder(node *);
            void findMaxInSubTreeAndDelete(node *);
};

Tree::Tree()
{
            root = NULL;
            lh = 0;
            rh = 0;
}

void Tree::addNode(int x)
{
 node *temp = new node;
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
   if(q->data > x) 
              q = q->left;
   else
              q = q->right;       
  }    
  if (r->data >= x)
     r->left = temp;
  else 
      r->right = temp;   
 }
}

void Tree::deleteNode(int x)
{
     /*
      * 1. If leaf node - delete it straight way.
      * 2. If internal node, then, remove the value of the node to be deleted, put the value of the node with highest value in the leftSubTree.
      *    and finally delete the node which had highest value.
      */
      
      node *q,*r;
      q = root;
      while(q != NULL)
      {
              if(q->data > x) {
                         q = q->left;
              } else if(q->data <x) {
                         q = q->right;
              } else {
                         r = q;      
                         break ;                         
              }
      }
      
      if( (r->left == NULL) && (r->left == NULL) )
      {
          delete r;          
      } 
      else 
      {
          findMaxInSubTreeAndDelete(r->left);           
      }    
}

void Tree::findMaxInSubTreeAndDelete(node *p)
{
     node *q = p;
     int x = q->data;
     int max = x;
     while( q != NULL ) 
     {
            if( q->data > x)
                       max = x; 
            else {
                       max = q->data;
                       q = q->right;                                  
            }            
     }
      
}

int Tree::height(node *p)
{
 if( (root == NULL) || (p == NULL) )
         return 0;
         
  if(p != NULL)
  {
   lh = height(p->left);
   rh = height(p->right);     
  }
  if(lh >= rh)
        return (lh+1);
  else
        return (rh+1);
        
           
}

void Tree::levelOrder()
{
     queue<node *> Q;
     node *p = root;
     
     while(p != NULL)
     {
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
     cout << endl;    
}

void Tree::inOrder(node *p)
{
 if(p != NULL) {    
      inOrder(p->left);
      cout << p->data << " ";
      inOrder(p->right);    
 }     
}

void Tree::preOrder(node *p)
{
 if(p != NULL) {    
  cout << p->data << " ";
  preOrder(p->left);
  preOrder(p->right);    
 }
}

void Tree::postOrder(node *p)
{
 if(p != NULL) {    
   postOrder(p->left);
   postOrder(p->right);    
   cout << p->data << " ";
  }
}

void Tree::heightOfNode()
{
 cout << "\nHeight: " << height(root);     
}

void Tree::traverseTree()
{
  cout << "\nInOrder: ";
  inOrder(root);
  cout << "\nPreOrder: ";
  preOrder(root);
  cout << "\nPostOrder: ";
  postOrder(root);
  cout << "\nLevelOrder: ";
  levelOrder();
}

int main()
{
    Tree t;
    t.addNode(1);
    t.addNode(2);
    t.addNode(11);
    t.addNode(10);
    t.addNode(3);
    t.addNode(115);
    t.addNode(101);
    t.addNode(31);
    t.addNode(1125);
    t.traverseTree(); 
    t.heightOfNode();
    //t.deleteNode(11);
   
    cout << endl;
    system("pause");
    return 0;
}
