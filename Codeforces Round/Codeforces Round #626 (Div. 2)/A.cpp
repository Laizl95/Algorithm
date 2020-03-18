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
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n;
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
      scanf("%d",&n);
      int x;vector<int> v1,v2;
      rep(i,0,n){
        scanf("%d",&x);
        if(x&1) v1.pb(i+1);
        else v2.pb(i+1);
      }
      if(v2.size()>0){
          cout<<v2.size()<<endl;
        for(auto it:v2)
            printf("%d ",it);puts("");
      }else{
        int y=v1.size();
        if(y>=2){
                puts("2");
            rep(i,0,2) printf("%d ",v1[i]);puts("");
        }else puts("-1");
      }
    }
return 0;
}
