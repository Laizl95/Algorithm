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
const int N=1e5+5,mod=1e9+7;
typedef long long LL;
int n,m;

int main(){
  int t;LL a,b,c;
  scanf("%d",&t);
  while(t--){
    scanf("%lld %lld %lld",&a,&b,&c);
    printf("%lld\n",a+b+c-1);
  }
return 0;
}
