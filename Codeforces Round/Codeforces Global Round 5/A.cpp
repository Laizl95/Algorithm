#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
//14:35

int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
        int ok=1,a;
    rep(i,0,n){
        scanf("%d",&a);
        if(a%2==0) printf("%d\n",a/2);
        else{
            if(ok) {if(a<0)printf("%d\n",a/2);else printf("%d\n",(a+1)/2);ok=0;}
            else {if(a<0)printf("%d\n",(a-1)/2);else printf("%d\n",a/2);ok=1;}
        }
    }
  }
return 0;
}
