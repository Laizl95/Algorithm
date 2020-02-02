#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=3e5+5,inf=1e9+5;
typedef long long LL;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int n,m;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        vector<int> ans;
        scanf("%d",&n);
        if(n&1){
            n-=3;
            ans.pb(7);
        }
        rep(i,0,n/2) ans.pb(1);
        rep(i,0,ans.size())
            printf("%d",ans[i]);puts("");
    }
return 0;
}
