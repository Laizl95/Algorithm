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
const int N=2e5+5,inf=1e7+5;
typedef long long LL;
int n;
int a[N];
vector<int> edge[N];
int solve(int u,int fa){

    for(auto &v:edge[u]){
        if(v==fa) continue;
        a[u]=max(solve(v,u)+a[u],a[u]);
    }
    return a[u];
}
int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    int u,v;
    rep(i,1,n){
        scanf("%d %d",&u,&v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    solve(1,-1);
    int ans=-2147483647;
    //cout<<ans<<endl;
    rep(i,1,n+1) ans=max(ans,a[i]);
    cout<<ans<<endl;
}
