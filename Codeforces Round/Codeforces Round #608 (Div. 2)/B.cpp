#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
char s[N],s1[N];
int solve(int n){
    rep(i,0,n) s1[i]=s[i];
    vector<int> ans;
     rep(i,0,n-1){
        if(s[i]=='W') {
                ans.pb(i);
               if(s[i+1]=='W') s[i+1]='B';
               else s[i+1]='W';
        }
    }
    if(s[n-1]=='B'){
        int t=ans.size();
        cout<<t<<endl;
        rep(i,0,t) printf("%d ",ans[i]+1); puts("");
        return 1;
    }
    ans.clear();
     rep(i,0,n-1){
        if(s1[i]=='B') {
                ans.pb(i);
               if(s1[i+1]=='W') s1[i+1]='B';
               else s1[i+1]='W';
        }
    }
    if(s1[n-1]=='W'){
        int t=ans.size();
        cout<<t<<endl;
        rep(i,0,t) printf("%d ",ans[i]+1); puts("");
        return 1;
    }
    return 0;
}
int main(){
    int t,n;
    scanf("%d",&n);
    scanf("%s",s);
    if(!solve(n)) puts("-1");

return 0;
}
