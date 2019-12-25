#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    int t,r,b,k;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d %d",&r,&b,&k);
       if(r>b) swap(r,b);
       if((b-__gcd(r,b)-1)/r+1<k) puts("OBEY");
       else puts("REBEL");
    }
return 0;
}
