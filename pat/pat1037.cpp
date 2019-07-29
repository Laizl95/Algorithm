#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
typedef long long  LL;
const int N=100005;
int a[N],b[N];
int main(){
	int nc,np;
	while(scanf("%d",&nc)!=EOF){
	   rep(i,0,nc) scanf("%d",&a[i]);
	   scanf("%d",&np);
	   rep(i,0,np) scanf("%d",&b[i]);
	   sort(a,a+nc);
	   sort(b,b+np);
	   int n=min(nc,np);
	   LL ans=0;
	   rep(i,0,n)
	    if(a[i]<0 && b[i]<0) ans+=a[i]*1LL*b[i];
	    else{
	    	int p1=i,p2=i;
		   while(p1<nc && a[p1]<=0) ++p1;
		   while(p2<np && b[p2]<=0) ++p2;
		    for(int i=nc-1,j=np-1;i>=p1&&j>=p2;--i,--j)
		     ans+=a[i]*1LL*b[j];
		   break;
		}
		     printf("%lld\n",ans);
	}
return 0;
}
