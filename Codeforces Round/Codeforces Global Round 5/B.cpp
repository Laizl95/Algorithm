#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
//14:35
int a[N],b[N];
int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
        int x;
    rep(i,0,n) scanf("%d",&x),a[x]=i;
    int ans=0,min_x=n;
    rep(i,0,n)scanf("%d",&b[i]);
     per(i,0,n){
        if(a[b[i]]>min_x) ans+=1;
        if(a[b[i]]<min_x) min_x=a[b[i]];
     }
        cout<<ans<<endl;
  }
return 0;
}
