#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int vis[26];
//1329 132 129
int main(){
   string s,b;
   int k;
   cin>>s>>k;
   if(k>s.length()) k=s.length();
   while(k--){
        int i=0,len=s.length();
        while(i+1<len && s[i]<=s[i+1]) ++i;
        s.erase(s.begin()+i);
   }
   int pre=0;
   rep(i,0,s.length()){
        if(s[i]=='0' && !pre) continue;
        cout<<s[i];
        pre=1;
   }
   if(!pre) cout<<"0";
   cout<<endl;
return 0;
}
