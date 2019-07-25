#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
int n,k,head[N*2],vis[N*2],tot,num[N*2];
//数组记录其顶点所有边的权值和，遍历顶点后的值/2就是联通分量权值
map<string,int> mp;
map<int,string> mp2;
vector<pair<string,int> > ans;
struct E{
    int v,w,next;
    E(){}
    E(int _v,int _w,int _next){v=_v;w=_w;next=_next;}
}edge[2*N];
void add_edge(int u,int v,int w){
  edge[tot]=E(v,w,head[u]);
  head[u]=tot++;
}
int dfs(int u,int &max_id,int &tot){
        vis[u]=1;//printf("%d ",u);
     int sum=num[u];
   for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(vis[v]) continue;
            tot+=1;
            if(num[v]>num[max_id]) max_id=v;
            sum+=dfs(v,max_id,tot);
   }
   return sum;
}
int main(){
    while(scanf("%d %d",&n,&k)!=EOF){
        string u,v;int w;
        int id=0;
        rep(i,0,n){
            cin>>u>>v>>w;
            if(mp.count(u)==0) head[id]=-1,num[id]=0,mp2[id]=u,mp[u]=id++;
            if(mp.count(v)==0) head[id]=-1,num[id]=0,mp2[id]=v,mp[v]=id++;
            int u_id=mp[u],v_id=mp[v];
            num[u_id]+=w;num[v_id]+=w;
            add_edge(u_id,v_id,w);
            add_edge(v_id,u_id,w);
        }
        rep(i,0,id) vis[i]=0;tot=0;
        ans.clear();
        rep(i,0,id)
            if(!vis[i]){
                int id=i,tot=1;
                if(dfs(i,id,tot)/2>k && tot>2) ans.pb(make_pair(mp2[id],tot));
                //puts("");
            }
       printf("%d\n",ans.size());
       sort(ans.begin(),ans.end());
       rep(i,0,ans.size()) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
return 0;
}
