#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int vis[N],p[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,x;
        scanf("%d %d",&n,&m);
        rep(i,1,n+1) scanf("%d",&x),p[x]=i,vis[i]=0;
       // rep(i,1,n+1) printf("%d ",p[i]); puts("");
        int now=1,num=0;LL ans=0;
        rep(i,1,m+1){
            scanf("%d",&x);
            if(vis[p[x]]) ans+=1,num+=1;
            else{
                ans+=(p[x]-num-1)*2+1;
                rep(i,now,p[x]+1) vis[i]=1;
                now=p[x]+1;
                num+=1;
            }
        }
        printf("%lld\n",ans);
    }
return 0;
}
