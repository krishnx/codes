#include<iostream>
#include<cstdlib>

using namespace std;

class Stack
{
 struct node 
 {
  int data;
  node* link;       
 }*top;      
 public:
        Stack();
        void push(int);
        void pop();
        void display();
};

Stack::Stack()
{
 top = NULL;              
}

void Stack::push(int x)
{
 node* temp;
 temp = new node;
 temp->data = x;
 temp->link = top;
 top = temp;             
}

void Stack::pop()
{
 if(top == NULL)
 {
  cout << "Stack is empty!" << endl;       
 } 
 else
 {
   node* temp = new node;
   temp = top;
   top = top->link;
   temp->link = NULL;
   cout << "Popped " << temp->data << endl;
   delete temp;   
 }    
}

void Stack::display()
{
 node *temp;
 temp = new node;
 temp = top;     
 while(temp != NULL) {
         cout << temp->data << " ";
         temp = temp->link;
 }
}

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    s.pop();
    s.pop();
    
    s.display();
    
    system("pause");    
    return 0;
}
