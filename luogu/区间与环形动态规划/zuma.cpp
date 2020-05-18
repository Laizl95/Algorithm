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
const int N=505,inf=1e6+5,mod=19650827;
typedef long long LL;
int dp[N][N],a[N];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    rep(len,1,n+1){
        rep(i,1,n+1){
            if(len==1){dp[i][i]=1;continue;}
            int j=i+len-1;
            if(j>n) break;
            dp[i][j]=j-i+1;
            int l=i,r=j;
            while(l<=r && a[l]==a[r]){
                if(l+1<r-1) dp[i][j]=min(dp[i][j],dp[l+1][r-1]);
                else dp[i][j]=1;
                ++l;--r;
            }
            dp[i][j]=min(dp[i][j],min(dp[i][j-1]+1,dp[i+1][j]+1));
            rep(k,i,j) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
    cout<<dp[1][n]<<endl;
return 0;
}
