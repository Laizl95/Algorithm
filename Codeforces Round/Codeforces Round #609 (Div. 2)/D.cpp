#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=3e5+5,inf=1e9+5;
typedef long long LL;
LL a[2];
int main(){
    int n,x;
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",&x);
        a[0]+=x/2;
        a[1]+=x/2;
        a[i&1]+=(x&1);
    }
    cout<<min(a[0],a[1])<<endl;
return 0;
}
