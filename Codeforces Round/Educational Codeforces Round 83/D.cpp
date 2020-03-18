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
const int N=2e5+5,inf=1e9+5,mod=998244353;
typedef long long LL;
int n,m;
LL ksm(LL x,LL t){
	LL tot=1;
	while(t){
		if(t&1) (tot*=x)%=mod;
		(x*=x)%=mod;
		t/=2;
	}
	return tot;
}
 
int main(){
    LL ans=1;
	scanf("%d %d",&n,&m);
	rep(i,1,m+1) (ans*=i)%=mod;
	rep(i,1,n) (ans*=ksm(i,mod-2))%=mod;
	rep(i,1,m-n+2) (ans*=ksm(i,mod-2))%=mod;
	printf("%lld\n",ans*(n-2)%mod*ksm(2,n-3)%mod);
	return 0;
}