#include<iostream>
#include<cstdlib>

using namespace std;

class MergeSortLL
{
      struct node 
      {
             int data;
             node *next;
      }*head;
      public:
             MergeSortLL();
             void addNode(int);
             void mergeSort(node**);
             void mergeSort1();
             node* sortedMerge(node*, node*);
             void splitLL(node*, node**, node**); 
             void display();
};

MergeSortLL::MergeSortLL()
{
                          head = NULL;
}

void MergeSortLL::mergeSort1()
{
     mergeSort(&head);     
}

void MergeSortLL::mergeSort(node **p)
{
     if( (*p == NULL) || ((*p)->next == NULL) )
     {
         return; 
     }
     node *a, *b;
     splitLL(*p, &a, &b);
     mergeSort(&a);
     mergeSort(&b);
     *p = sortedMerge(a, b);
}

MergeSortLL::node* MergeSortLL::sortedMerge(node *a, node *b)
{
     node *result = NULL;
     
     if(a == NULL)
          return b;
     if(b == NULL)
          return a;
     if(a->data <= b->data)
     {
         result = a;
         result->next = sortedMerge(a->next, b);
     }
     else
     {
         result = b;
         result->next = sortedMerge(a, b->next);
     }
     node *ans = result;
     return result;
}

void MergeSortLL::splitLL(node *p, node **frontRef, node **backRef)
{
     node *headRef = p;
     
     if( (p == NULL) || (p->next == NULL) )
     {
         return; 
     }
     
     node *slow, *fast;
     slow = p;
     fast = p->next;
     while(fast != NULL)
     {
                fast = fast->next;
                if(fast != NULL)
                {
                        fast = fast->next;
                        slow = slow->next;
                }
     }
     *frontRef = p;
     *backRef = slow->next;
     slow->next = NULL;
}

void MergeSortLL::addNode(int x)
{
     node *temp = new node;
     temp->data = x;
     temp->next = NULL;
     
     if(head == NULL)
     {
             head = temp;
     }
     else
     {
         node *q = head;
         
         while(q->next != NULL)
         {
                    q = q->next;
         }
         q->next = temp;
     }
}

void MergeSortLL::display()
{
     node *temp = head;
     
     while(temp != NULL)
     {
                cout << temp->data << " ";
                temp = temp->next;
     }
     cout << endl;
}
int main()
{
    MergeSortLL msll;
    msll.addNode(10);
    msll.addNode(100);
    msll.addNode(40);
    msll.addNode(20);
    msll.addNode(60);
    msll.addNode(30);
    msll.display();    
    msll.mergeSort1();
    msll.display();
    return 0;
}
