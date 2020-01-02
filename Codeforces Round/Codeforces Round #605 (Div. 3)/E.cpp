#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
//反向建图 dfs会返回祖先节点但该点没有更新
int ans[N],d[N],n;
vector<int> edge[N],odd,even;
struct node{
    int d,v;
    node(){}
    node(int _d,int _v){d=_d;v=_v;}
};
void bfs(const vector<int> &v1,const vector<int> &v2){
     queue<node> q;
     rep(i,1,n+1) d[i]=inf;
     rep(i,0,v1.size()){
        q.push(node(0,v1[i]));
        d[v1[i]]=0;
     }
     while(!q.empty()){
        node now=q.front();
        q.pop();
        rep(i,0,edge[now.v].size()){
            int v=edge[now.v][i];
            if(d[v]!=inf) continue;
            d[v]=now.d+1;
            q.push(node(now.d+1,v));
        }
     }
     rep(i,0,v2.size()){
        if(d[v2[i]]!=inf) ans[v2[i]]=d[v2[i]];
     }
}
int main(){
    int x;
    scanf("%d",&n);
    rep(i,1,n+1){
        scanf("%d",&x);
        ans[i]=inf;
        if(x&1) odd.pb(i);
        else even.pb(i);
        if(x+i<=n) edge[x+i].pb(i);
        if(i-x>0) edge[i-x].pb(i);
    }
    bfs(even,odd);
    bfs(odd,even);
    rep(i,1,n+1) printf("%d ",ans[i]==inf?-1:ans[i]);
    puts("");
return 0;
}
