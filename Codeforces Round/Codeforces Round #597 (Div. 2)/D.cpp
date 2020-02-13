#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e3+5,inf=1e9+5;
typedef long long LL;

int n,m;
pii a[N];
int c[N],k[N],fa[N],vis[N];
vector<int> v[N];
struct node{
    int u,v;
    LL d;
    node(){}
    node(int _u,int _v,LL _d){
        u=_u;v=_v;d=_d;
    }
}edge[N*N];
int find_fa(int a){
    return fa[a]==a?a:fa[a]=find_fa(fa[a]);
}
LL get_cost(const pii &a,const pii &b,int i,int j){
    return (k[i]+k[j])*1LL*
    (abs(a.first-b.first)+abs(a.second-b.second));
}
bool cmp(const node &a,const node &b){
    return a.d<b.d;
}
int main(){
    scanf("%d",&n);
    int x,y;
    rep(i,0,n){
        scanf("%d %d",&x,&y);
        a[i+1]=mp(x,y);
    }
    int cnt=0;
    rep(i,0,n+1) fa[i]=i;
    rep(i,1,n+1) scanf("%d",&c[i]);
    rep(i,1,n+1) scanf("%d",&k[i]);
    rep(i,1,n+1){
        int min_v=c[i];
        edge[cnt++]=node(0,i,c[i]*1LL);
        rep(j,i+1,n+1){
            LL cost=get_cost(a[i],a[j],i,j);
            edge[cnt++]=node(i,j,cost);
        }
    }
    LL ans=0;
    vector<int> buf1;
    vector<pii> buf2;
    rep(i,0,n+1) fa[i]=i;
    sort(edge,edge+cnt,cmp);
    rep(i,0,cnt){
        int u=edge[i].u,v=edge[i].v;
        int fa_u=find_fa(u),fa_v=find_fa(v);
        if(fa_u!=fa_v){
            if(u==0) buf1.pb(v);
            else buf2.pb(mp(u,v));
            fa[fa_v]=fa_u;
            ans+=edge[i].d;
        }
    }
    printf("%lld\n%d\n",ans,buf1.size());
    for(auto it: buf1) printf("%d ",it); puts("");
    printf("%d\n",buf2.size());
    for(auto it:buf2) printf("%d %d\n",it.first,it.second);
return 0;
}
