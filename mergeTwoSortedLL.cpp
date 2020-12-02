#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
  int data;
  node *next;
}*head1, *head2;

void addNode(node**,int);
void mergeSort(node**);
void display(node*);
void splitLL(node*, node **, node **);
node* sortedMerge(node*, node*);
void mergeSortedLL(node*, node*, node*);

int main()
{
  head1 = NULL;
  head2 = NULL;
  
  for(int i=0; i<5; i++) {
    addNode(&head1, rand()%100 +1);
    addNode(&head2, rand()%100 +1);
  }
  cout << "\nBefore Sorting:\n";
  display(head1);
  display(head2);

  mergeSort(&head1);
  mergeSort(&head2);

  cout << "\nAfter Sorting:\n";
  display(head1);
  display(head2);
  
  cout << "\nMerging Sorted Lists:\n"  ;
  node *head3 = NULL;
  head3 = sortedMerge(head1, head2);
  display(head3);
  
  return 0;
}

void addNode(node **q, int x)
{
  node *head = *q;
  node *temp = new node;
  temp->data = x;
  temp->next = NULL;

  if(*q == NULL) 
    *q = temp;
  else {
    while(head->next != NULL) {
      head = head->next;
    }
    head->next = temp;
  }  
}

void mergeSort(node **headRef)
{
  if( (*headRef == NULL) || ((*headRef)->next == NULL) ) 
    return ;

  node *a, *b;
  splitLL(*headRef, &a, &b);

  mergeSort(&a);
  mergeSort(&b);

  *headRef = sortedMerge(a, b);
}

void splitLL(node *headRef, node **frontRef, node **backRef)
{
  node *p = headRef;

  node *fast, *slow;
  slow = p;
  fast = p->next;
  
  while(fast != NULL) {
    fast = fast->next;
    if(fast != NULL) {
      fast = fast->next;
      slow = slow->next;
    }
  }

  *frontRef = headRef;
  *backRef = slow->next;
  slow->next = NULL;
}

node* sortedMerge(node *a, node *b)
{
  node *result = NULL;
  
  if(a == NULL)
    return b;
  if(b == NULL)
    return a;
  if(a->data <= b->data) {
    result = a; 
    result->next = sortedMerge(a->next, b);
  } else {
    result = b; 
    result->next = sortedMerge(a, b->next);
  }
  return result;
}

void display(node *q)
{
  while(q != NULL) {
    cout << q->data << " ";
    q = q->next;
  }
  cout << endl;
}
