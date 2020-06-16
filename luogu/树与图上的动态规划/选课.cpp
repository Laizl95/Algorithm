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
const int N=305,inf=1e6+5;
typedef long long LL;
int n,m;
vector<int> edge[N];
int ans[N][N],in[N],a[N],dp[N][N];
int solve(int u){
    int cnt=1;
    dp[u][1]=a[u];
    for(auto &v:edge[u]){
        int t=solve(v);
        cnt+=t;
        per(i,1,cnt+1){
            rep(j,1,min(t,i)+1){
                 if(i-j>=0)
                    dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[v][j]);
            }
        }
        /*for(int j=m;j>=1;j--)
            for(int i=j-1;i>=1;i--)
                dp[u][j] = max(dp[u][j], dp[u][j - i] + dp[v][i]);*/
    }
    return cnt;
}
int main(){
    scanf("%d %d",&n,&m);
    int u,w;
    rep(i,0,n){
        scanf("%d %d",&u,&w);
        if(u) edge[u].pb(i+1),in[i+1]=1;
        a[i+1]=w;
    }
    vector<int> v;
    v.pb(-1);
    rep(i,1,n+1){
        if(!in[i]) {v.pb(i);solve(i);}
    }
    //rep(i,1,v.size()) {rep(j,1,m+1) printf("%d ",dp[v[i]][j]);puts("");}
    rep(i,1,v.size()){
        rep(j,1,m+1){
            ans[i][j]=ans[i-1][j];
            rep(k,1,m+1)
                if(j>=k)ans[i][j]=max(ans[i][j],ans[i-1][j-k]+dp[v[i]][k]);
        }
    }
    cout<<ans[v.size()-1][m]<<endl;
return 0;
}
