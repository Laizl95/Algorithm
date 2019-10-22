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
int cnt=0;
void solve(int x){
    if(x==n){
            cout<<x<<endl;
        int ans=0,tot[3];
        rep(j,0,m) {
            ms(tot,0);
            rep(i,0,n) tot[mat[i][j]]+=1;
            ans+=max(max(tot[0],tot[1]),tot[2]);
        }
        cnt=max(cnt,ans);
        return;
    }
    rep(k,0,3){
        int a[15];
        rep(j,0,m) a[j]=mat[x][j],mat[x][j]=(mat[x][j]+k)%3;
        solve(x+1);
        rep(j,0,m) mat[x][j]=a[j];
    }
}
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        int ans=0;
        rep(i,0,n) rep(j,0,m){
        scanf("%d",&mat[i][j]);
           mat[i][j]%=3;
        }
        solve(0);
        printf("%d\n",cnt);
    }
return 0;
}
