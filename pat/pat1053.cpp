#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=105;
struct node{
    int w;
    vector<int> v;
    node(){v.clear();}

}s[N];
bool cmp(int x1,int x2){
    return s[x1].w>s[x2].w;
}
int pre[N];
vector<int> ans;
void solve(int u,int sum){
    sum-=s[u].w;
    vector<int> v=s[u].v;
    int k=v.size();
    rep(i,0,k){
        pre[v[i]]=u;
        solve(v[i],sum);
    }
    if(k==0 && sum==0) ans.pb(u);
    return;
}
int dfs(int u){
    if(u==-1) return 0;
    dfs(pre[u]);
    if(pre[u]==-1) printf("%d",s[u].w);
    else printf(" %d",s[u].w);
}
int main(){
    int n,m,l;
    while(scanf("%d %d %d",&n,&m,&l)!=EOF){
            ans.clear();
        rep(i,0,n) s[i]=node(),scanf("%d",&s[i].w),pre[i]=-1;
        int fa,k,child;
        rep(i,0,m){
            scanf("%d %d",&fa,&k);
            rep(i,0,k){
                scanf("%d",&child);
                s[fa].v.pb(child);
            }
            sort(s[fa].v.begin(),s[fa].v.end(),cmp);
        }
        solve(0,l);
        k=ans.size();
        rep(i,0,k){
            dfs(ans[i]);puts("");
        }
    }
return 0;
}
