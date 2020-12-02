#include<iostream>

using namespace std;

void permute(string&, int, int);
void swap(char&, char&);
int main()
{
  int length = 0;

  string a = "abc";
  cin >> a;
  permute(a, 0, a.size());
  
  return 0;
}

void swap(char& x, char& y)
{
	cout << "x: " << x << " y: " << y << endl; 
  char temp = x;
  x = y;
  y = temp;
}

void permute(string& str, int i, int n)
{
  int j;
  if(i == n)
    cout << str << endl;
  else {
    for(j=i; j<n; j++) {
      swap(str[i], str[j]);
      cout << "Before:   i: " << i << " j: " << j << endl; 
      permute(str, i+1, n);
      cout << "After:   i: " << i << " j: " << j << endl; 
      swap(str[i], str[j]);
    }
  }
}
