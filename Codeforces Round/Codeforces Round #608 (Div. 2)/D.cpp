#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=5e3+5,inf=1e9+5;
typedef long long LL;
int a[N],b[N],c[N],d[N];
int dp[N][N];//到达第i个城市当前有j个士兵时的最大值
vector<int> edge[N];
bool cmp(const int &u,const int &v){
    return c[u]>c[v];
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    rep(i,1,n+1) scanf("%d %d %d",&a[i],&b[i],&c[i]);
    int u,v;
    rep(i,1,n+1) d[i]=i;
    rep(i,0,m){
        scanf("%d %d",&u,&v);
        d[v]=max(d[v],u);
    }
    rep(i,1,n+1){
        edge[d[i]].pb(i);
    }
    rep(i,1,n+1) sort(edge[i].begin(),edge[i].end(),cmp);
    ms(dp,-1);
    dp[0][k]=0;
    rep(i,1,n+1){
        rep(j,a[i],5001){
            if(dp[i-1][j]==-1) continue;
            dp[i][j+b[i]]=dp[i-1][j];
        }
        for(auto v:edge[i]){
            rep(j,1,5001){
                if(dp[i][j]==-1) continue;
                dp[i][j-1]=max(dp[i][j-1],dp[i][j]+c[v]);
            }
        }
    }
    int mx=-1;
    rep(i,0,5001) mx=max(mx,dp[n][i]);
    printf("%d\n",mx);

return 0;
}
