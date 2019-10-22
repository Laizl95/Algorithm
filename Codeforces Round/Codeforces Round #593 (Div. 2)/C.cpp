#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;

int n;
vector<int> ans[N];
int main(){

    while(scanf("%d",&n)!=EOF){
        int tot=0,ok=1;
        rep(k,0,n){
            if(ok){
                rep(i,0,n) ans[i+1].pb(++tot);
                ok=0;
            }else{
                per(i,0,n) ans[i+1].pb(++tot);
                ok=1;
            }
        }
      rep(i,1,n+1){
       rep(j,0,ans[i].size()) printf("%d ",ans[i][j]);
       puts("");
      }
    }
return 0;
}


