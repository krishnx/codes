#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>

using namespace std;

class QuickSort
{
  int i,j;
  
  public:
         QuickSort();
         int splitVector(vector<int>&, int, int, int);
         void quickSortMainFunction(vector<int>&, int, int);
         void displayList(vector<int>&);     
         void swap(int&, int&);
};

QuickSort::QuickSort()
{
 
}

void QuickSort::displayList(vector<int>& vec)
{
  for(int i=0; i<vec.size(); i++) {
          cout << vec[i] << " ";        
  }  
  cout << endl;     
}

void QuickSort::swap(int& a, int& b)
{
     int temp = a;
     a = b;
     b = temp;
}

int QuickSort::splitVector(vector<int>& vec, int pivot, int start, int end)
{
 int leftBoundary = start;
 int rightBoundary = end;
 
 while(leftBoundary < rightBoundary) {
  while(pivot < vec[rightBoundary]) {
     rightBoundary--;                
  }                   
  swap(vec[leftBoundary], vec[rightBoundary]);
  while(pivot > vec[leftBoundary]) {
     leftBoundary++;            
  }
  swap(vec[leftBoundary], vec[rightBoundary]);
 } 
 return leftBoundary;   
}

void QuickSort::quickSortMainFunction(vector<int>& vec, int startIndex, int endIndex)
{
 int leftBoundary, rightBoundary;
 int pivot = vec[startIndex];
 int splitPoint;
 if(endIndex > startIndex) {
             splitPoint = splitVector(vec, pivot, startIndex, endIndex);
             vec[splitPoint] = pivot;
             quickSortMainFunction(vec, startIndex, splitPoint-1);
             quickSortMainFunction(vec, splitPoint+1, endIndex);
 } else {
   //cout << "Only one element in the vector!!" << endl;       
 }   
}

int main()
{
 QuickSort qs;

 vector<int> vec;
 srand( time(NULL) );
 for(int i=0; i<10; i++) {
          vec.push_back( rand()%100 + 1 );         
 }                      
 
 qs.displayList(vec);
 qs.quickSortMainFunction(vec, 0, 10);
 qs.displayList(vec);
 
 system("pause");
    
 return 0;    
}
