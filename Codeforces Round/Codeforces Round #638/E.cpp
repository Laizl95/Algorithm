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
const int N=2e5+5,inf=1e6+5;
typedef long long LL;
int a[505],b[505];
int dp[505][505];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    LL sum1=0;
    rep(i,1,n+1){
        scanf("%d %d",&a[i],&b[i]);
        sum1+=a[i];
        sum1+=b[i];
    }
    dp[0][0]=1;
    rep(i,1,n+1){
        rep(x,0,k){
            if(!dp[i-1][x]) continue;
            rep(j,0,a[i]+1){
                if(j>=k) break;
                //cout<<j<<" "<<(a[i]-j)%k+b[i]<<endl;
                if((a[i]-j)%k+b[i]>=k) dp[i][(x+j)%k]=1;
            }
            dp[i][(x+a[i])%k]=1;
        }
    }
    LL ans=0;
    rep(i,0,k) if(dp[n][i]){ans=(sum1-i)/k;break;}
    cout<<ans<<endl;
return 0;
}
