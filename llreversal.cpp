#include<iostream>
#include<cstdlib>

using namespace std;

class LinkedList
{
 struct node {
    int data;    
    node* link;    
 }*head;     
 public:
        LinkedList();
        void addNode(int);

        void reverseList();
        void displayList();     
};

LinkedList::LinkedList()
{
  head = NULL;                                                        
}

void LinkedList::addNode(int x)
{
 node *temp,*q;
 temp=new node;
 temp->data=x;
 temp->link=NULL;
 
 if(head==NULL)
 head=temp;
 else         
 {
              q=head;
              while(q->link!=NULL)
              q=q->link;
              
              q->link=temp;
              }
              
              
}

void LinkedList::reverseList()
{
  node *r,*q;
  node *p;
  p=head;
  q=p->link;
  p->link=NULL;
  
  while(q!= NULL) {
        r = q->link;
        q->link = p;
        p = q;
        q = r;      
  }
  head = p;     
}

void LinkedList::displayList()
{
 node* temp = head;
 
 while(temp!= NULL) {
       cout << temp->data << " ";
       temp=temp->link;                 
 }    

}

int main()
{
 LinkedList ll;
 ll.addNode(10);   
 ll.addNode(20);
 ll.addNode(30);
 ll.addNode(40);
 ll.addNode(50);
 ll.displayList();
 ll.reverseList();
 ll.displayList();
  
 system("pause");     
 return 0;   
}
