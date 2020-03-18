#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=1e6+5,inf=1e9+5;
typedef long long LL;
void rd(int &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
int n,m,p;
int a[N],b[N];
int main(){
    scanf("%d %d %d",&n,&m,&p);
    rep(i,0,n) scanf("%d",&n);
    rep(i,0,m) scanf("%d",&m);
    int p1,p2;
    rep(i,0,n) if(a[i]%p!=0){p1=i;break;}
    rep(i,0,m) if(b[i]%p!=0){p2=i;break;}
    printf("%d\n",p1+p2);
return 0;
}
