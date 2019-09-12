#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=10005,mod=1e9+7;
class Solution{
public:
    int racecar(int target){


/*状态转移不是dp[i]=min(n+1+dp[((1<<n)-1)-i],(n-1)+2+dp[i-((1<<n-1)-1)])
          而是dp[i]=min(n+1+dp[((1<<n)-1)-i],(n-1)+1+m+1+dp[i-(2^(n-1)-1-(2^m-1))])
        /*int dp[N];
        dp[0]=0;
        rep(i,1,target+1){
            dp[i]=-1;
            int cnt=1,j;
            for(j=1;j<i;j=(1<<++cnt)-1){}
            int toal=min(cnt+dp[j-i]+(j!=i),cnt-1+dp[i-(1<<cnt-1)+1]+2);
            if(dp[i]==-1 || dp[i]>toal) dp[i]=toal;
        }*/
        int dp[N];
        dp[0]=0;
        rep(i,1,target+1){
            dp[i]=-1;
            int cnt=1,j=1;
            while(j<i) j=(1<<++cnt)-1;
            if(i==j) dp[i]=cnt;
            else{
                for(int k=0;k<=cnt-1;++k){
                    int buf=cnt+k+1+dp[i-(1<<cnt-1)+(1<<k)];
                    if(dp[i]==-1 || dp[i]>buf) dp[i]=buf;
                }
                if(dp[i]==-1 || dp[i]>cnt+1+dp[(1<<cnt)-1-i]) dp[i]=cnt+1+dp[(1<<cnt)-1-i];
            }
        }
        return dp[target];
    }
};
int main(){
 Solution a;
 int n;
 while(scanf("%d",&n)!=EOF){
    cout<<a.racecar(n)<<endl;
 }
return 0;
}
