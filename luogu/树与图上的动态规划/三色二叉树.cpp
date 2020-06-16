#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e5+5,inf=1e6+5;
typedef long long LL;
char s[N];
int cnt=0,p=0;
int dp[N][2],dp2[N][2];
struct node{
    int l,r;
    node(){}
    node(int _l,int _r){l=_l;r=_r;}
}a[N];
int build(){
    //if(p>=len) return -1;
    int now=p,id=++cnt;
    a[id].l=-1;
    a[id].r=-1;
    if(s[now]=='0') {return id;}
    ++p;
    a[id].l=build();
    if(s[now]=='2'){
        ++p;
        a[id].r=build();
    }
    return id;
}
void solve(int u){
    if(a[u].l==-1 && a[u].r==-1){
        dp[u][1]=1;
        dp[u][0]=0;
        return ;
    }
    int l=a[u].l,r=a[u].r;
    if(l!=-1) solve(a[u].l);
    if(r!=-1) solve(a[u].r);
    if(l!=-1 && r!=-1){
        dp[u][1]=max(dp[l][0]+dp[r][0]+1,dp[u][1]);
        dp[u][0]=max(dp[u][0],
                     max(dp[l][1]+dp[r][0],dp[l][0]+dp[r][1]));
    }
    else if(l!=-1){
        dp[u][1]=max(dp[l][0]+1,dp[u][1]);
        dp[u][0]=max(dp[u][0],dp[l][1]);
    }else if(r!=-1){
        dp[u][1]=max(dp[r][0]+1,dp[u][1]);
        dp[u][0]=max(dp[u][0],dp[r][1]);
    }

}
void solve2(int u){
    if(a[u].l==-1 && a[u].r==-1){
        dp2[u][1]=1;
        dp2[u][0]=0;
        return ;
    }
    dp2[u][1]=inf;dp2[u][0]=inf;
    int l=a[u].l,r=a[u].r;
    if(l!=-1) solve2(a[u].l);
    if(r!=-1) solve2(a[u].r);
    if(l!=-1 && r!=-1){
        dp2[u][1]=min(dp2[l][0]+dp2[r][0]+1,dp2[u][1]);
        dp2[u][0]=min(dp2[u][0],
                     min(dp2[l][1]+dp2[r][0],dp2[l][0]+dp2[r][1]));
    }
    else if(l!=-1){
        dp2[u][1]=min(dp2[l][0]+1,dp2[u][1]);
        dp2[u][0]=min(dp2[u][0],dp2[l][1]);
        dp2[u][0]=min(dp2[u][0],dp2[l][0]);
    }else if(r!=-1){
        dp2[u][1]=min(dp2[r][0]+1,dp2[u][1]);
        dp2[u][0]=min(dp2[u][0],dp2[r][1]);
        dp2[u][0]=min(dp2[u][0],dp2[r][0]);
    }

}
void dfs(int u){
    if(u==-1) return ;
    dfs(a[u].l);
    printf("%d ",u);
    dfs(a[u].r);
}
int main(){
    scanf("%s",s);
    build();
   // dfs(1);
    solve(1);
    cout<<max(dp[1][1],dp[1][0])<<" ";
    solve2(1);
    cout<<min(dp2[1][1],dp2[1][0])<<endl;
return 0;
}
