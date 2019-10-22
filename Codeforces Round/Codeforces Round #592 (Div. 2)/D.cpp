#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e5+5;
typedef long long LL;
int n;
vector<int> edge[N];
int a[3][N],in[N],colour[N];
LL dp[3][3][N],inf=1e17;

LL solve(int fa,int root){

    int v=root,l;
    rep(i,0,edge[fa].size()){
         l=edge[fa][i];
        if(l==root) continue;
         v=l;
        solve(l,fa);
    }
    if(v==root){
        rep(i,0,3) rep(j,0,3)
            dp[i][j][fa]=a[j][fa]*1LL;
    }else{
        rep(i,0,3) rep(j,0,3){
            if(i==j) continue;
            dp[i][j][fa]=dp[3-i-j][i][v]+a[j][fa];
        }
    }

}
void print(LL sum,int pre,int now,int fa,int root){
        colour[fa]=now;
        int v=root;
    rep(i,0,edge[fa].size()){
         v=edge[fa][i];
        if(v==root) continue;
        else break;
    }
    if(v!=root){
      rep(i,0,3){
         if(i!=now && i!=pre && a[now][fa]+dp[i][pre][v]==dp[pre][now][fa]){
             print(dp[i][pre][v],i,pre,v,fa);
             return;
         }
      }
    }
    return;
}
int main(){

    while(scanf("%d",&n)!=EOF){
        int u,v;
        rep(i,0,3) rep(j,1,n+1) scanf("%d",&a[i][j]);
        rep(i,0,n+1) edge[i].clear(),in[i]=0;
        rep(i,0,3) rep(j,0,3) rep(k,1,n+1) dp[i][j][k]=inf;
        int ok=1;
        rep(i,0,n-1){
            scanf("%d %d",&u,&v);
            edge[u].pb(v);edge[v].pb(u);
            in[u]+=1;in[v]+=1;
            if(in[u]>2 || in[v]>2) ok=0;
        }
        int root=-1;
        rep(i,0,n+1) if(in[i]==1) root=i;
        if(!ok || root==-1){puts("-1");continue;}
        solve(root,-1);
        LL ans=inf;int pre,now;
        rep(i,0,3) rep(j,0,3) {
            if(ans>dp[i][j][root]) ans=dp[i][j][root],now=j,pre=i;
        }
        printf("%lld\n",ans);
        print(ans,pre,now,root,root);
        rep(i,1,n+1) cout<<colour[i]+1<<" ";cout<<endl;
    }
return 0;
}
