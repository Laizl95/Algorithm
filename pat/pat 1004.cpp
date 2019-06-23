#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=105;
vector<int> node[N];
int num[N];
int dfs(int fa,int h){

    int t=node[fa].size()-1;
    if(t==-1){
        num[h]+=1;
        return h;
    }
    int max_h=0;
    rep(i,0,t){
        int child=node[fa][i];
       // cout<<child<<endl;
        //if(vis[child]) continue;
        //vis[child]=1;
        max_h=max(max_h,dfs(child,h+1));
       // vis[child]=0;
    }
    return max_h;
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        rep(i,1,n) node[i].clear();
        int fa,k,child;
        rep(i,1,m){
         scanf("%d %d",&fa,&k);
          rep(j,1,k){
           scanf("%d",&child);
           node[fa].pb(child);
          }
        }
        int h=dfs(1,1);//cout<<h<<endl;
        rep(i,1,h)printf("%d%c",num[i],i==h?'\n':' ');
    }
return 0;
}
