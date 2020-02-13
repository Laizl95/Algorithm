#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
LL n;
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        if(n<10) printf("%d\n",n);
        else{
            if(n%9==0){
                cout<<(n/9-1)*10+9<<endl;
            }else{
                cout<<n/9*10+n%9<<endl;
            }
        }
    }
return 0;
}
