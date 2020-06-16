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
const int N=3005,inf=1e7+5;
typedef long long LL;
int n,m;
vector<pii> edge[N];
int a[N],dp[N][N];
int solve(int u){
    if(u>=n-m+1){
        dp[u][1]=a[u];
        return 1;
    }
        int cnt=0;
    for(auto &x:edge[u]){
        int t=solve(x.fi);
        cnt+=t;
        per(i,1,cnt+1){
            per(j,1,min(t,i)+1){
                dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[x.fi][j]-x.se);
            }
        }
    }
    return cnt;
}
int main(){
    scanf("%d %d",&n,&m);
    rep(i,0,n-m){
        int k,v,w;
        scanf("%d",&k);
        rep(j,0,k){
            scanf("%d %d",&v,&w);
            edge[i+1].pb(pii(v,w));
        }
    }

    rep(i,1,n+1) rep(j,1,m+1) dp[i][j]=-inf;
    rep(i,1,m+1) scanf("%d",&a[i+n-m]);
    solve(1);
    //rep(i,1,n+1){ rep(j,1,m+1) printf("%d ",dp[i][j]); cout<<endl;}
    per(i,1,m+1) {if(dp[1][i]>=0){cout<<i<<endl;return 0;}}
    cout<<"0"<<endl;
return 0;
}
