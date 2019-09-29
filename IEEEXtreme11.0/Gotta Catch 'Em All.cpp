#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=205,inf=1e8;
typedef long long LL;
int mat[N][N],sum[N][N];
int n,m;
int judge(int x){
    rep(i,0,n) rep(j,0,m) sum[i][j]=-inf;
        sum[0][0]=x;
    rep(i,0,n) rep(j,0,m){
        if(i==0 && j==0) continue;
        if(i-1>=0 && sum[i-1][j]+mat[i][j]>sum[i][j])
            sum[i][j]=sum[i-1][j]+mat[i][j];

        if(j-1>=0 && sum[i][j-1]+mat[i][j]>sum[i][j])
            sum[i][j]=sum[i][j-1]+mat[i][j];
        if(sum[i][j]<=0) sum[i][j]=-inf;
    }
    return sum[n-1][m-1]>0;
}
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){

        rep(i,0,n) rep(j,0,m) scanf("%d",&mat[i][j]);
        int l=1,r=inf;
        while(l<=r){
            int mid=l+r>>1;
            if(judge(mid)) r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
return 0;
}
/*6 2
0 0
-3 0
1 0
100 -1
-1000 -10
-100000 0*/
