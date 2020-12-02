#include<iostream>

using namespace std;

struct node
{
  int data; 
  node *next;
}*head;

void addNode(int);
void display();
void reverseLL(node**);

int main()
{
  int a[] = {1,23,3,45,5,6,7};
  int length = sizeof(a)/sizeof(a[0]);
  for(int i=0; i<length; i++) 
    addNode(a[i]);

  display();
  reverseLL(&head);
  display();

  return 0;
}

void addNode(int x)
{
  node *temp = new node;
  temp->data = x;
  temp->next = NULL;

  if(head == NULL) { 
    head = temp;
  } else {
    node *q;
    q = head;
    while(q->next != NULL) {
      q = q->next;
    }
    q->next = temp;
  }
}

void display()
{
  node *q = head;
  while(q != NULL) {
    cout << q->data << " ";
    q = q->next;
  }
  cout << endl;
}

void reverseLL(node **head_ref)
{
  node *first, *rest;
  
  if(*head_ref == NULL) 
    return ; 
  
  first = *head_ref;
  rest  = first->next;

  if(rest == NULL) 
    return ;

  reverseLL(&rest);
  first->next->next = first;
  first->next = NULL;
  *head_ref = rest;
}
