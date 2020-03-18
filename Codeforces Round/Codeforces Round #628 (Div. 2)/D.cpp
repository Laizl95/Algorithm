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
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
LL n,m,k;
int a[N],b[N];
int main(){
    //cout<<(1LL<<62)<<endl;
   scanf("%lld %lld",&n,&m);
   if(n==m){
        if(n==0){puts("0");return 0;}
        puts("1");
        cout<<n<<endl;
        return 0;
   }
   if(n>m){puts("-1"); return 0;}
        m-=n;
   if(m&1){puts("-1"); return 0;}
        m/=2;
   if((m&n)==0){
      printf("2\n");
      printf("%lld %lld\n",n+m,m);
   }else{
        puts("3");
       printf("%lld %lld %lld\n",n,m,m);
   }
return 0;
}
