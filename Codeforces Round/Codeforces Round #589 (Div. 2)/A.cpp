#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=3*1e5+5;
typedef long long LL;
vector<int>  edge[N];
int sets[N],vis[N],X[N],Y[N];
int judge(int num[],int m){
    if(!num[1] || !num[2] || !num[3]) return 0;
    LL sum=num[1]*1LL*num[2]+num[1]*1LL*num[3]+num[3]*1LL*num[2];
    if(sum!=m) return 0;
    rep(i,0,m) if(sets[X[i]]==sets[Y[i]]) return 0;
    return 1;
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        rep(i,1,n+1) vis[i]=0,sets[i]=0,edge[i].clear();
        rep(i,0,m){
            scanf("%d %d",&X[i],&Y[i]);
            edge[X[i]].pb(Y[i]);
            edge[Y[i]].pb(X[i]);
        }
        rep(i,0,edge[1].size()) vis[edge[1][i]]=1;
        rep(i,1,n+1) if(!vis[i]) sets[i]=1;
        int u;
        rep(i,1,n+1) if(vis[i]==1){u=i;break;}
        ms(vis,0);
        rep(i,0,edge[u].size()) vis[edge[u][i]]=1;
        rep(i,1,n+1) if(!vis[i]) sets[i]=2;
        rep(i,1,n+1) if(!sets[i]) sets[i]=3;
        int set_num[4]={0};
        rep(i,1,n+1) set_num[sets[i]]+=1;
         //rep(i,1,n+1) printf("%d ",sets[i]);puts("");
        if(judge(set_num,m)){
            rep(i,1,n+1) printf("%d ",sets[i]);puts("");
        }
        else puts("-1");continue;
    }
return 0;
}
