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
int n,m,k;
vector<int> edge[N];
int in[N],a[N],b[N],ans[N];
int main(){
    scanf("%d",&n);
    int u,v;
    rep(i,0,n-1){
        scanf("%d %d",&a[i],&b[i]);
        //edge[u].pb(v);
        //edge[v].pb(u);
        in[a[i]]+=1;
        in[b[i]]+=1;
    }
    int tot=1;
    rep(i,0,n-1){
        u=a[i];v=b[i];
        if(in[u]==1 || in[v]==1) ans[i]=tot++;
    }
    rep(i,0,n-1) if(ans[i]==0) ans[i]=tot++;
    rep(i,0,n-1) printf("%d ",ans[i]-1);puts("");

return 0;
}
