#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

template<typename A, typename B>
pair<B,A> flip_pair(const pair<A,B> &p)
{
    return pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
map<B,A> flip_map(const map<A,B> &src)
{
    map<B,A> dst;
    transform(src.begin(), src.end(), inserter(dst, dst.begin()), 
                   flip_pair<A,B>);
    return dst;
}

int main(void)
{
  std::map<char, int> src;
  
  src['a'] = 10;
  src['b'] = 20;
  src['c'] = 160;
  src['d'] = 110;
  src['e'] = 0;
  
  std::map<int, char> dst = flip_map(src);

  map<int, char>::iterator it;
  for(it=dst.begin(); it!=dst.end(); it++) {
    cout << it->first << " : " << it->second << endl;
  }
}
