#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    int n;
    scanf("%d",&n);
    double ans=0;int k=n;
    rep(i,1,n+1){
        ans+=1.0/i;
    }
    printf("%.12lf",ans);

return 0;
}
