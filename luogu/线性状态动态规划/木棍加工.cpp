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
const int N=5e3+5,inf=1e6+5,mod=998244353;
typedef long long LL;
int dp[N];
pii a[N];
bool cmp(const pii &a,const pii &b){
    return a.fi>b.fi || (a.fi==b.fi && a.se>=b.se);
}
int solve(const int &x,const int &_l,const int &_r){
    int l=_l,r=_r;
    while(l<=r){
        int mid=l+r>>1;
        if(dp[mid]>=x) r=mid-1;
        else l=mid+1;
    }
    return l;
}
int main(){
    int n;
    scanf("%d",&n);
    rep(i,0,n)
        scanf("%d %d",&a[i].fi,&a[i].se);
    sort(a,a+n,cmp);
    int len=0;
    rep(i,0,n){
        int p=solve(a[i].se,1,len);
        if(p>len){++len;dp[len]=a[i].se;}
        else dp[p]=a[i].se;
    }
    cout<<len<<endl;
return 0;
}
