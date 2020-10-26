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
const int N=2e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;

int main(){
    int t,n;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ok=0;
        rep(i,0,501){
            rep(j,0,201){
                if(n-3*i-j*5>=0 && (n-3*i-j*5)%7==0){
                    ok=1;
                    printf("%d %d %d\n",i,j,(n-3*i-j*5)/7);
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok) puts("-1");
    }
return 0;
}
