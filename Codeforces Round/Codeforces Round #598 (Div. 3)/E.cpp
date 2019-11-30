#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5;
typedef long long LL;
const LL inf=0x3fffffffffffffff;
struct node{
    int v,id;
    bool operator <(const node &a) const{
        return v<a.v || (v==a.v && id<a.id);
    }
}a[N];
LL dp[N];
int p[N];
int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i].v),a[i].id=i;
    sort(a+1,a+n+1);
    dp[0]=0;
    //当i>=6时把它分成多个set一定小于(1-i)为一个set
    rep(i,1,n+1){
        dp[i]=inf;
        if(i-3>=0) dp[i]=min(dp[i],dp[i-3]+a[i].v-a[i-2].v);
        if(i-4>=0) dp[i]=min(dp[i],dp[i-4]+a[i].v-a[i-3].v);
        if(i-5>=0) dp[i]=min(dp[i],dp[i-5]+a[i].v-a[i-4].v);
    }
    int t=n,id=0;
    while(t!=0){
        p[a[t].id]=++id;
        if(t-3>=0 && dp[t-3]+a[t].v-a[t-2].v==dp[t]){
            rep(i,t-2,t) p[a[i].id]=id;
            t=t-3;
        }else if(t-4>=0 && dp[t-4]+a[t].v-a[t-3].v==dp[t]){
            rep(i,t-3,t) p[a[i].id]=id;
            t=t-4;
        }else if(t-5>=0 && dp[t-5]+a[t].v-a[t-4].v==dp[t]){
            rep(i,t-4,t) p[a[i].id]=id;
            t=t-5;
        }
    }
    printf("%lld %d\n",dp[n],id);
    rep(i,1,n+1) printf("%d ",p[i]);puts("");
return 0;
}
