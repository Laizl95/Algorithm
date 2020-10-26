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
    int n;
    scanf("%d",&n);
    LL now=2;
    LL temp=1;
    cout<<2<<endl;
    rep(i,2,n+1){
       // temp+x=i*(i+1)*(i+1);
        LL x=i*1LL*(i+1)*(i+1)-(i-1);
        cout<<x<<endl;
    }
return 0;
}
