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
const int N=1e5+5,inf=1e6+5;
typedef long long LL;
int dp[N],a[N],b[N];
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
    int n,x;
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",&a[i+1]);
    rep(i,1,n+1) {
        scanf("%d",&x);
        b[x]=i;
    }
     int len=0;
    rep(i,1,n+1){
        int p=solve(b[a[i]],1,len);
        if(p>len){++len;dp[len]=b[a[i]];}
        else dp[p]=b[a[i]];
    }
    cout<<len<<endl;
return 0;
}
