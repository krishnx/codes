#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

int findLCS(string, string);

int main()
{
  string s1("krishna");
  string s2("kishan");

  int ans = 0;
  ans = findLCS(s1, s2);
  cout << ans << endl;
  
  return 0;
}

void printLCS(vector<vector<int> > par,int r,int c, string s1){
  if(r&&c){
    if(par[r][c] == 1)
      printLCS(par,r-1,c-1,s1);
    else if(par[r][c] == 2)
      printLCS(par,r-1,c,s1);
    else
      printLCS(par,r,c-1,s1);
    cout<<s1[r-1];
  }
}


int findLCS(string a, string b)
{
  if(b.length() > a.length())
    swap(a,b);

  int m,n;
  m = a.length();
  n = b.length();
  
  vector<vector<int> > lcs(2, vector<int>(n+1,0));
  vector<vector<int> > par(max(n,m)+1);
  for(int i=1; i<=m; i++) 
    {
      par[i].push_back(0);
      for(int j=1; j<=n; j++) 
	{
	  if(a[i-1] == b[j-1]) {
	    lcs[1][j] = lcs[0][j-1] + 1;
	    par[i].push_back(1);
	  }
	  else{
	    //lcs[1][j] = max( lcs[0][j], lcs[1][j-1] );
	    if(lcs[0][j] < lcs[1][j-1]){
	      lcs[1][j] = lcs[1][j-1];
	      par[i].push_back(2);
	    }
	    else{
	      lcs[1][j] = lcs[0][j];
	      par[i].push_back(3);
	    }
	  }
	}
      for(int k=0; k<n; k++)
	lcs[0][k] = lcs[1][k];
    }
  for(int i=1;i<=m;++i){
    for(int j=1;j<=n;++j){
      cout<<par[i][j]<<" ";
    }
    cout<<endl;
  }    
  cout<<endl;
  printLCS(par,m,n,a);
  return (lcs[1][n]);
}
