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
const int N=1e5+5,inf=1e6+5,mod=10007;
typedef long long LL;
int a[N],b[N];
int n,m;
vector<pii> v[N][2];
int main(){
    scanf("%d %d",&n,&m);
    rep(i,0,n) scanf("%d",&a[i+1]);

    rep(i,1,n+1){
        scanf("%d",&b[i]);
        v[b[i]][i&1].pb(mp(i,a[i]));
    }
     /*rep(i,1,m+1){
        rep(k,0,2){
            printf("%d\n",k);
             for(auto &it:v[i][k]) printf("%d %d\n",it.fi,it.se);

        }
    }*/
    LL ans=0;
    rep(i,1,m+1){
        rep(k,0,2){
        LL sum=0,sum2=0;

        for(auto &it:v[i][k]){
            ans=(ans+it.se*1LL*it.fi*(v[i][k].size()-1))%mod;
            ans=(ans+sum*1LL*it.se)%mod;
            sum+=it.fi;

        }
        per(j,0,v[i][k].size()){
            pii it=v[i][k][j];
            ans=(ans+sum2*1LL*it.se)%mod;
            sum2+=it.fi;
        }
        //cout<<ans<<endl;
        }
    }
    cout<<ans<<endl;
return 0;
}
