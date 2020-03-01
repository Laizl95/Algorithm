#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int n,m;
char s[N];
int in[N],ind[N],ans[N];
vector<int> v1,v2,edge[N];
void topo(){
    priority_queue<int> q;
    priority_queue<int,vector<int>,greater<int> > s;
    rep(i,0,n) in[i]=ind[i];
    rep(i,0,n){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.top();
        q.pop();
        v1.pb(u);
        for(auto v:edge[u]){
            in[v]--;
            if(in[v]==0){
                q.push(v);
            }
        }
    }
     rep(i,0,n) in[i]=ind[i];
     rep(i,0,n){
        if(in[i]==0){
            s.push(i);
        }
    }
    while(!s.empty()){
        int u=s.top();
        s.pop();
        v2.pb(u);
        for(auto v:edge[u]){
            in[v]--;
            if(in[v]==0){
                s.push(v);
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n+1) ind[i]=0;
        scanf("%s",s);
        int len=strlen(s);
        rep(i,0,len+1) edge[i].clear();
        rep(i,0,len){
            if(s[i]=='<')
                edge[i].pb(i+1),ind[i+1]+=1;
            else
                edge[i+1].pb(i),ind[i]+=1;
        }

        topo();
        int tot=1;
        //rep(i,0,n) printf("%d ",v1[i]);puts("");
        //rep(i,0,n) printf("%d ",v2[i]);puts("");
        rep(i,0,n) ans[v1[i]]=tot++;
        rep(i,0,n) printf("%d ",ans[i]);puts("");
        tot=1;
        rep(i,0,n) ans[v2[i]]=tot++;
        rep(i,0,n) printf("%d ",ans[i]);puts("");
        v1.clear();
        v2.clear();
    }
    return 0;
}
