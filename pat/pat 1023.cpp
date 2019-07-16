#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=10005;

int main(){
   set<int> s;set<int>::iterator iter;

   s.insert(2);
   s.insert(1);
   for(iter = s.begin() ; iter != s.end() ; ++iter){
         cout<<*iter<<" ";
    }

return 0;
}
