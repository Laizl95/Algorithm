#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define lson l,mid,i<<1
#define rson mid+1,r,i<<1|1
#define ls i<<1
#define rs i<<1|1
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int dp[N],a[N],id;

int main(){
        int t;
        scanf("%d",&t);
        while(t--){
            int h,n,x;
            scanf("%d %d",&h,&n);
            rep(i,1,n+1){
                scanf("%d",&a[i]);
            }
            a[n+1]=0;a[0]=h;
          rep(i,1,n+2) dp[i]=inf;dp[0]=0;
           rep(i,1,n+2){
                dp[i]=min(dp[i],dp[i-1]+(a[i-1]-a[i]>0));
                if(a[i]==0) dp[i]=min(dp[i],dp[i-1]);
                if(i+1<n+2 && a[i-1]!=a[i] && a[i]-1==a[i+1]) dp[i+1]=min(dp[i+1],dp[i-1]);
               // cout<<a[i]<<" "<<dp[i]<<endl;
           }
           cout<<dp[n+1]<<endl;
        }
return 0;
}
