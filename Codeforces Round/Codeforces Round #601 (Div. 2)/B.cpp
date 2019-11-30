#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int a[N];
int main(){
  int n,m,t;
  scanf("%d",&t);
  while(t--){
      scanf("%d %d",&n,&m);
      int ans=0,x=0;
      rep(i,0,n){
        scanf("%d",&x);
        ans+=x;
      }
      if(m<n || n==2) {puts("-1");continue;}
      printf("%d\n",ans*2);
      int j=1;
      rep(i,0,n){
        printf("%d ",j);
        j+=1;
        if(j==n+1) j=1;
        printf("%d\n",j);
      }
  }
return 0;
}
