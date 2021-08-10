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
const int N=2e5+5,inf=1e9+5,mod=998244353;
typedef long long LL;
int n,m,k;
char s[N];
int vis[N],a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);
        int len=strlen(s+1),num=0,ans=inf;
        rep(i,1,4) vis[i]=0;
        rep(i,1,len+1){
            if(!vis[s[i]-'0']) ++num;
            vis[s[i]-'0']=i;
            if(num==3){
                rep(i,1,4) a[i]=vis[i];
                sort(a+1,a+1+3);
                ans=min(ans,a[3]-a[1]+1);
            }
        }
        if(ans==inf) puts("0");
        else cout<<ans<<endl;
    }
return 0;
}
