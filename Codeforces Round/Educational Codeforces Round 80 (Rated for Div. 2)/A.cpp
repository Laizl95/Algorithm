#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=3e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    int t,n,d;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&d);
        if(d<=n){puts("YES");continue;}
        int g=sqrt(d)+1,ok=0;
        rep(i,2,g+1){
            if(i-1+(d+i-1)/i<=n){ok=1;break;}
        }
        if(ok) puts("YES");
        else puts("NO");
    }
return 0;
}
