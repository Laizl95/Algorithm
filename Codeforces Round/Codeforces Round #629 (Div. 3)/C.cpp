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
int n,m,k;
char s[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
      scanf("%d %s",&n,s);
      int ok=0,x;
      vector<int> v1,v2;

      rep(i,0,n){
        int x=s[i]-'0';
        if(x==2){
            if(!ok) v1.pb(1),v2.pb(1);
            else v1.pb(0),v2.pb(2);
        }else if(x==0){
            v1.pb(0);
            v2.pb(0);
        }else if(x==1){
            if(!ok){
                ok=1;
                v1.pb(1);
                v2.pb(0);
            }else v1.pb(0),v2.pb(1);
        }
      }
      for(auto it:v1) printf("%d",it); puts("");
      for(auto it:v2) printf("%d",it); puts("");
    }
return 0;
}
