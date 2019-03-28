#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(i) push_back(i)
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int N=1005;
int n,m,t;
int fa[N],in[N];
int find_fa(int x){
 return fa[x]==x?x:fa[x]=find_fa(fa[x]);
}
int main(){
    int cas=0,id[N],num[N],vis[N];
 while(scanf("%d %d %d",&n,&m,&t)!=EOF){
     if(!n && !m && !t) break;
     int a,b;
     rep(i,1,n) fa[i]=i,in[i]=0,vis[i]=0;
     rep(i,1,m){
         scanf("%d %d",&a,&b);
         int x=find_fa(a);
         int y=find_fa(b);
         if(x!=y) fa[x]=y;
         ++in[a];++in[b];
         vis[a]=vis[b]=1;
     }
     int tot=0;
     rep(i,1,n){if(vis[i] && find_fa(i)==i) id[i]=++tot;}
     //rep(i,1,n) printf("%d\n",fa[i]);cout<<tot<<endl;
     rep(i,1,tot) num[i]=0;
     rep(i,1,n) if(in[i]&1) num[id[find_fa(i)]]+=1;
     int ans=tot-1;
     rep(i,1,tot) if(num[i]>2) ans+=(num[i]-2)/2;
     printf(" %d %d\n",tot,ans);
     //if(m==0) ans=0;
     printf("Case %d: %d\n",++cas,(ans+m)*t);

 }
return 0;
}
