#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e3+5,inf=1e9+5;
typedef long long LL;
string s[N];
char judge(char a,char b){
    if(a==b) return a;
    char p[3]={'S','E','T'};
    rep(i,0,3) if(p[i]!=a && p[i]!=b) return p[i];
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    map<string,int> mp;
    rep(i,0,n){
     cin>>s[i];
     mp[s[i]]=1;
    }
    int ans=0;
    rep(i,0,n){
        rep(j,i+1,n){
          string buf;
          rep(k,0,m) buf+=judge(s[i][k],s[j][k]);
          //cout<<buf<<endl;
          if(mp.count(buf)) ++ans;
        }
    }
    printf("%d\n",ans/3);
return 0;
}
