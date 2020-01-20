#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e3+5,mod=1e9+7;
typedef long long LL;

int main(){
    int t;
    int a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        int x=9,cnt=0;
        while(x<=b){
            cnt+=1;
            if(x*1LL*10+9>b) break;
            x=x*10+9;
        }
        printf("%lld\n",cnt*1LL*a);
    }

return 0;
}
