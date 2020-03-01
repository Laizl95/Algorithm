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

int n,m,tot;
char s[N];
int ans[30],vis[30];
vector<int> edge[30];
void dfs(int u){
    ans[tot++]=u;
    vis[u]=1;
    for(auto v:edge[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s),flag=1;
        rep(i,0,26) edge[i].clear();
        rep(i,1,len){
            int x=s[i]-'a',y=s[i-1]-'a';
            int ok=0;
            for(auto v:edge[y]){
                if(v==x){ok=1;break;}
            }
            if(!ok){
                if(edge[x].size()>0 || edge[y].size()>1){
                    flag=0;
                }else{
                    edge[x].pb(y);
                    edge[y].pb(x);
                }
            }
        }
        if(!flag) puts("NO");
        else{
                puts("YES");
                ms(vis,0);
                tot=0;
            rep(i,0,26){
                if(!vis[i] && edge[i].size()<2) dfs(i);
            }
            rep(i,0,26) printf("%c",ans[i]+'a');puts("");
        }
    }
return 0;
}
