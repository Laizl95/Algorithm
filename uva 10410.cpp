#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(i) push_back(i)
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int N=1015;
int n;
int b[N],pos[N];
vector<int> ans[N];
struct node{
int pos,v;
bool operator < (const node &x) const{
 return pos>x.pos;
}
}a[N];
void solve(int l,int r,int fa){
    if(l>r) return;
    priority_queue<node> q;
    rep(i,l,r) q.push(a[b[i]]);
    node now=q.top();
    int pre=0;
    while(!q.empty()){
        now=q.top();
     if(now.v==b[l] && now.v>pre && (pre==0 ||a[pre].pos==now.pos-1)){
        ans[fa].pb(b[l]);
        l+=1;
        pre=now.v;
        q.pop();
     }
     else break;
    }
    while(!q.empty() && q.top().v!=b[l]) ans[fa].pb(q.top().v),q.pop();
    int y=ans[fa].size()-1;
   // printf("%d:",fa); rep(i,0,y)  printf(" %d %d\n",ans[fa][i],pos[ans[fa][i]]);puts("");
    rep(i,0,y-1){
        int fa_c=ans[fa][i];
        int w=ans[fa][i+1];
      solve(pos[fa_c]+1,pos[w]-1,fa_c);
    }
    if(y>=0)solve(pos[ans[fa][y]]+1,r,ans[fa][y]);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        int x;
     rep(i,1,n){scanf("%d",&x);a[x].pos=i;a[x].v=x;}
     rep(i,1,n) scanf("%d",&b[i]),pos[b[i]]=i;
     rep(i,1,n) ans[i].clear();
     a[0].pos=a[b[1]].pos;
     solve(2,n,b[1]);
     rep(i,1,n){
        int y=ans[i].size()-1;
        printf("%d:",i);
        rep(j,0,y) printf(" %d",ans[i][j]);
        puts("");
     }
    }
return 0;
}
