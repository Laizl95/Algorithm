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
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
LL dp[N];//价格为i时有多少种支付方式
LL a[5],d[5];
int main(){
    //1 2 2 3 4 5 6 7 8 11
    int n,s;
    rep(i,0,4) scanf("%lld",&a[i]);
    dp[0]=1;
    rep(i,0,1e5+1) rep(j,0,4)
        if(i>=a[j]) dp[i]+=dp[i-a[j]];
        rep(i,1,11) printf("%d ",dp[i]);puts("");
    scanf("%d",&n);
    rep(i,0,n){

        rep(i,0,4) scanf("%lld",&d[i]);
        scanf("%d",&s);
        int k=1<<4;LL ans=0;
        rep(i,1,k){
            int m=s,num=0;
            rep(j,0,4){
                if(((1<<j)&i)!=0) m-=(d[j]+1)*a[j],++num;
            }
            if(m>=0){
                ans+=(num%2*2-1)*dp[m];
            }
        }
        printf("%lld\n",dp[s]-ans);
    }
return 0;
}
