#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    LL n;
    scanf("%lld",&n);
    int ok=0;
    for(int i=2;i*1LL*i<=n;i+=1){
        if(n%i==0){
            while(n%i==0) n/=i;
            ok=1;
            if(n==1)
                printf("%d\n",i);
            else printf("1\n");
            break;
        }
    }
    if(!ok) cout<<n<<endl;
return 0;
}
