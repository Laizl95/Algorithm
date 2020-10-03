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
const int N=3e3+5,inf=1e6+5,mod=19650827;
typedef long long LL;
int n;
int a[N],num[N][N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,1,n+1){
            rep(j,1,n+1) num[i][j]=0;
        }
        rep(i,1,n+1){
            scanf("%d",&a[i]);
            rep(j,1,n+1) num[j][i]+=num[j][i-1];
            num[a[i]][i]+=1;
        }
        LL ans=0;
        rep(i,1,n+1){
           rep(j,i+1,n+1){
                ans+=num[a[j]][i-1]*(num[a[i]][n]-num[a[i]][j]);
           }
        }
        cout<<ans<<endl;
    }
return 0;
}
