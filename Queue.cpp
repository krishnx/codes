#include<iostream>
#include<cstdlib>

using namespace std;

class Queue
{
 struct node {
        int data;
        node* link;       
 }*front,*rear;
 public:
        Queue();
        void addNode(int);
        void deleteNode();
        void display();      
};

Queue::Queue()
{
 front = NULL;
 rear = NULL;              
}

void Queue::deleteNode() 
{
 if(front == NULL) {
          cout << "Invalid deletion" << endl;
 } else {             
   node* temp;
   temp = front;
   front = front->link;
   cout << "deleted " << temp->data << endl;
   delete temp;     
}
}
void Queue::addNode(int x)
{
 node *temp;
 temp = new node;
 temp->data = x;
 temp->link = NULL; 
 if(front == NULL) {
   front = temp;
   rear = temp;         
 } else {
   rear->link = temp;
   rear = temp;       
 }
}

void Queue::display()
{
 node* temp;
 temp = front;
 while(front != NULL) {
      cout << front->data << " ";
      temp = front;
      front = front->link;
      delete temp;            
 }
}

int main()
{
 Queue q;
 q.addNode(10);
 q.addNode(20);
 q.addNode(30);
 q.addNode(40);
 q.addNode(50);

 q.deleteNode();
 q.deleteNode();
 q.display();
 system("pause");
  
 return 0;    
}
