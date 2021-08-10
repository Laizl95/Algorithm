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
const int N=1e5+5,inf=1e9+5,mod=998244353;
typedef long long LL;
int r,n;
struct node{
    int t,x,y;
}a[N];
int dp[N],ans[N];
int solve(int i,int num){
    int l=0,r=i-1;
    while(l<=r){
        int mid=l+r>>1;
        if(a[mid].t<num) l=mid+1;
        else r=mid-1;
    }
    return l;
}
int dis(int i,int j){
    return abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
}
int main(){
    scanf("%d %d",&r,&n);
    a[0].t=0;a[0].x=1;a[0].y=1;
    rep(i,1,n+1) dp[i]=-inf;
    rep(i,1,n+1) scanf("%d %d %d",&a[i].t,&a[i].x,&a[i].y);
    ans[0]=0;
    rep(i,1,n+1){
        int p=max(0,i-2*r);
        int ok=0;
        rep(j,p,i)
            if(dis(i,j)+a[j].t<=a[i].t)
                ok=1,dp[i]=max(dp[i],dp[j]);
        if(ok) dp[i]+=1;
        if(i-2*r>=0) dp[i]=max(ans[p]+1,dp[i]);
        ans[i]=max(ans[i-1],dp[i]);
    }
    cout<<ans[n]<<endl;
return 0;
}
