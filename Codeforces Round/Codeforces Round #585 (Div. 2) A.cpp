#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;

int main(){
 int a1,a2,k1,k2,n;
 while(scanf("%d %d %d %d %d",&a1,&a2,&k1,&k2,&n)!=EOF){
     int sum=n-(k1-1)*a1-(k2-1)*a2,minx,maxx;
     minx=max(0,sum);
     if(k1>k2) swap(k1,k2),swap(a1,a2);
     int t=min(n/k1,a1);
     n-=t*k1;
     printf("%d %d\n",minx,t+n/k2);
 }
return 0;
}
