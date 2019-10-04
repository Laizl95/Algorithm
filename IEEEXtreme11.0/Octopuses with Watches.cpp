#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=15,mod=1e9+7;
typedef long long LL;
int mat[N][N];
int n,m;
int solve(int x,int y,int sum){
    int t=sum-mat[x][y];
    if(t<0) return 0;
    int a[N][N];
    rep(i,0,n) rep(j,0,m) a[i][j]=mat[i][j];
    int ans=0;
    rep(i,0,t+1){
        rep(r,0,m) a[x][r]+=i;
        rep(c,0,n) a[c][y]+=t-i;
        int tot=0;
        rep(i,0,n) rep(j,0,m)
            if(a[i][j]==3 || a[i][j]==6 || a[i][j]==9 || a[i][j]==12)
                tot+=1;
                cout<<tot<<endl;
        ans=max(ans,tot);
    }
    return ans;
}
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        int ans=0;
        rep(i,0,n) rep(j,0,m){
            scanf("%d",&mat[i][j]);
            if(mat[i][j]==3 || mat[i][j]==6 || mat[i][j]==9 || mat[i][j]==12)
                ans+=1;
        }
        rep(i,0,n) rep(j,0,m) rep(k,1,5)
            ans=solve(i,j,3*k);
        printf("%d\n",ans);
    }
return 0;
}
