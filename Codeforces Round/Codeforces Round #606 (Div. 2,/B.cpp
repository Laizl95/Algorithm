#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       LL ans=0;
       rep(i,1,10){
           LL a=i*1LL;
         while(a<=n){
            ans+=1;
            a=a*10+i;
         }
       }
       cout<<ans<<endl;
    }
return 0;
}
