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
const int N=2e3+5,inf=1e9+5,mod=1e9+7;
typedef long long LL;
int c[N][N];
LL sum[N][N];
int main(){
    int t,k,n,m;
    scanf("%d %d",&t,&k);
    rep(i,0,2001) c[i][0]=1;
    rep(i,1,2001){
        rep(j,1,i+1)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
    }

    rep(i,1,2001){
        rep(j,1,i+1){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            sum[i][j]+=(c[i][j]==0);
        }
        sum[i][i+1]=sum[i][i];
    }
    //rep(i,1,4) {rep(j,1,i+1) printf("%d ",sum[i][j]);puts("");}
    while(t--){
        scanf("%d %d",&n,&m);
        if(m>n) m=n;
        printf("%lld\n",sum[n][m]);
    }
return 0;
}
