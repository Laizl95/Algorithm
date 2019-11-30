#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
struct node{
    int x,y,z;
}a[N];
vector<int> pos[N],v,ans;
int num[N],vis[N];
int solve(int p,int n){

    int p1=a[p].y,p2=a[p].z,t=2,pre=-1;

    while(t<=n-2){
        rep(i,0,pos[p1].size())
          if(pos[p1][i]!=p && pos[p1][i]!=pre) {pre=p;p=pos[p1][i];break;}
          int ok=0;
        rep(i,0,pos[p2].size())
            if(p==pos[p2][i]) ok=1;
        if(!ok) return 0;
       if(p1!=a[p].x || p2!=a[p].y){
         a[p].z=a[p].x+a[p].y+a[p].z-p1-p2;
         a[p].x=p1;
         a[p].y=p2;
         ans.pb(a[p].z);
         p1=a[p].y;p2=a[p].z;
       }else {ans.pb(a[p].z);p1=a[p].y;p2=a[p].z;}
       t+=1;
    }
    return 1;
}
int main(){
    int n;
    scanf("%d",&n);
    rep(i,0,n-2){
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
        num[a[i].x]+=1;
        num[a[i].y]+=1;
        num[a[i].z]+=1;
        pos[a[i].x].pb(i);
        pos[a[i].y].pb(i);
        pos[a[i].z].pb(i);
    }
    rep(i,0,n) if(num[i+1]==1) v.pb(i+1);
    int goal=v[1];
    int p=pos[goal][0];
    if(a[p].y==goal) swap(a[p].y,a[p].x);
    else if(a[p].z==goal) swap(a[p].z,a[p].x);
    if(num[a[p].y]==3)  swap(a[p].y,a[p].z);
    ans.pb(goal);
    ans.pb(a[p].y);
    ans.pb(a[p].z);
    if(solve(p,n)){
        rep(i,0,ans.size()) printf("%d ",ans[i]);puts("");
    }
return 0;
}
