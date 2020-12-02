#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

void printLastTenLines(string&, int);

int main()
{
    string str = "pqr\nrst\nuvw\nxyz\n123\n456\n789\n101112\n131415";
    
    printLastTenLines(str, 10);    
    
    system("pause");
    return 0;
}

void printLastTenLines(string& str, int lines)
{
     int count = lines;
     int current = 0;
     int prev = 0;
     
     if(str == "") return ;
     else
         for(int i=str.size(); i > 0, count > 0; i--) 
         {
            if(count <= 0) { break; } 
            else {
                 if(str[i] == '\n')
                 {
                             current = i;
                             count--;
                             cout << str.substr(current, prev - current) << " ";          
                             prev = current;
                 }       
            }
         }
     cout << endl;     
}
