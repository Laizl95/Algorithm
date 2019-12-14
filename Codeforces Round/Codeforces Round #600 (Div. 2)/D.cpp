#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int fa[N];
int find_fa(int a){
    return fa[a]==a?a:fa[a]=find_fa(fa[a]);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    rep(i,1,n+1) fa[i]=i;
    int u,v;
    rep(i,0,m){
        scanf("%d %d",&u,&v);
        int x=find_fa(u),y=find_fa(v);
        if(x<y) fa[x]=y;
        else fa[y]=x;
    }
    int ans=0,pre=-1;
    rep(i,1,n+1){
        int x=find_fa(fa[i]);
        if(x<pre){
            fa[x]=pre;
            ans+=1;
        }
        pre=max(pre,x);
    }
    printf("%d\n",ans);
return 0;
}
