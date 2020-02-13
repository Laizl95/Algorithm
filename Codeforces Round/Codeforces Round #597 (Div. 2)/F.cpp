#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e3+5,inf=1e9+5;
typedef long long LL;
LL dp[35][2][2][2][2];
vector<int> l,r;
LL slove(int p,int low_a,int upp_a,int low_b,int upp_b){
    if(p==-1) return 1LL;
    if(dp[p][low_a][upp_a][low_b][upp_b]!=-1)
        return dp[p][low_a][upp_a][low_b][upp_b];
    int l_a=low_a?l[p]:0,r_a=upp_a?r[p]:1,l_b=low_b?l[p]:0,r_b=upp_b?r[p]:1;
    LL cnt=0;
    rep(i,l_a,r_a+1){
        rep(j,l_b,r_b+1){
            if(i==1 && j==1) continue;
            cnt+=slove(p-1,low_a && (!(i>l[p])),upp_a && (!(i<r[p])),
                 low_b && (!(j>l[p])),upp_b && (!(j<r[p])));
        }
    }
    dp[p][low_a][upp_a][low_b][upp_b]=cnt;
    return dp[p][low_a][upp_a][low_b][upp_b];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        l.clear();r.clear();
        while(a){
           l.pb(a%2);
           a>>=1;
        }
        rep(i,l.size(),31) l.pb(0);
        while(b){
           r.pb(b%2);
           b>>=1;
        }
        rep(i,r.size(),31) r.pb(0);
        //for(auto v:l)printf("%d",v);puts("");
        //for(auto v:r)printf("%d",v);puts("");
        ms(dp,-1);
        cout<<slove(30,1,1,1,1)<<endl;
    }
return 0;
}
