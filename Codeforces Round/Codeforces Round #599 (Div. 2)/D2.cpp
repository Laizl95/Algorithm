#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
//14:08
set<int> s;
int n,m,head[N],tot,vis[N];
struct node{
    int v,next;
    node(){}
    node(int _v,int _next){v=_v;next=_next;}
}edge[N];
void add_edge(int u,int v){
    edge[tot]=node(v,head[u]);
    head[u]=tot;
    tot+=1;
}
int solve(){
    queue<int> q;int id=0;
    while(!s.empty()){
        set<int>::iterator it;
        for(it=s.begin();it!=s.end();++it){
            q.push(*it);break;
        }
        ++id;
        s.erase(q.front());
        vis[q.front()]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                vis[v]=1;
            }
            vector<int> buf;
            for(it=s.begin();it!=s.end();++it)
                if(!vis[*it]) {
                        buf.pb(*it);
                        q.push(*it);
                }
            for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                vis[v]=0;
            }
            rep(i,0,buf.size()) s.erase(buf[i]);
        }
    }
    return id;
}
int main(){
    tot=0;
    scanf("%d %d",&n,&m);
    rep(i,0,n+1) head[i+1]=-1;
    int u,v;
    rep(i,0,m){
        scanf("%d %d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    rep(i,0,n) s.insert(i+1);
    printf("%d\n",solve()-1);

return 0;
}
