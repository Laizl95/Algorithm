#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
//14:43
int a[N],dp[N];
int main(){
    int n,p,k,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&p,&k);
        rep(i,1,n+1) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        dp[0]=p;
        rep(i,1,n+1){
           dp[i]=dp[i-1]-a[i];
           if(i-k>=0) dp[i]=max(dp[i],dp[i-k]-a[i]);
        }
        per(i,0,n+1)
           if(dp[i]>=0){printf("%d\n",i);break;}
    }
return 0;
}
