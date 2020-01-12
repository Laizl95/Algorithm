#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
vector<LL> v;
int k;
LL n,t;
LL ans1,ans2;
void solve(LL ans,int i,int tot){
    if(tot==k){
        if(max(ans1,ans2)>max(ans,t/ans)){
            ans1=ans;
            ans2=t/ans;
            return;
        }
    }
    if(i>=v.size()) return;
    solve(ans*v[i],i+1,tot+1);
    solve(ans,i+1,tot);
}
int main(){
    scanf("%lld",&n);
    t=n;
    for(int i=2;i*1LL*i<=n;i+=1){
        if(n%i==0){
                LL tot=1;
            while(n%i==0){
                    n/=i;
                    tot*=i;
            }
            v.pb(tot);

        }
    }
    if(n>1) v.pb(n);
    sort(v.begin(),v.end());
    int y=v.size();

    ans1=t;ans2=1;
    rep(j,1,y/2+1){ k=j;solve(1LL,0,0);}

    printf("%lld %lld\n",ans1 ,ans2);
return 0;
}
