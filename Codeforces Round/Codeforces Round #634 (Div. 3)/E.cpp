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
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
int a[N],sum[N][205];
vector<int> pos[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,1,201) pos[i].clear();
        rep(i,1,n+1){
            scanf("%d",&a[i]);
            rep(j,1,201) sum[i][j]=sum[i-1][j];
            sum[i][a[i]]+=1;
            pos[a[i]].pb(i);

        }
        //cout<<sum[10][132]<<" "<<sum[0][132]<<endl;
        int mx=0;
        rep(j,1,201){
            int m=pos[j].size();
            mx=max(mx,sum[n][j]);
            rep(i,1,m/2+1){
                int l=pos[j][i-1],r=pos[j][m-i],x=0;
                rep(k,1,201) x=max(x,sum[r-1][k]-sum[l][k]);
                mx=max(mx,x+i*2);
            }
        }
        cout<<mx<<endl;

    }
return 0;
}
