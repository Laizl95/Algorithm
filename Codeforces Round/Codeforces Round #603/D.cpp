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
int vis[26],fa[N];
int find_fa(int x){
    return fa[x]==x?x:fa[x]=find_fa(fa[x]);
}
int main(){
    int t;
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%s",s);
        int len=strlen(s);
        int g=s[0]-'a';
        if(!vis[g]) vis[g]=i+1,fa[vis[g]]=i+1;
        int fa_y=find_fa(vis[g]);
        rep(j,0,len){
            int g=s[j]-'a';
            if(!vis[g]) vis[g]=i+1,fa[vis[g]]=i+1;
            int fa_x=find_fa(vis[g]);
            if(fa_x!=fa_y) fa[fa_x]=fa_y;
        }
    }
    set<int> s;
    rep(i,0,26){
        if(!vis[i]) continue;
        int x=find_fa(vis[i]);
        s.insert(x);
    }
    printf("%d\n",s.size());

return 0;
}
