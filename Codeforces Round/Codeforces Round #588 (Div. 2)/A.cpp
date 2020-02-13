#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=1e6+5,inf=1e9+5;
typedef long long LL;

int n,m;
int a[N];
int main(){
    int sum=0;
    rep(i,0,4) scanf("%d",&a[i]),sum+=a[i];
    int ok=0;
    rep(i,0,4){
        if(a[i]==sum-a[i]) ok=1;
        rep(j,0,4){
            if(i==j) continue;
            if(a[i]+a[j]==sum-a[i]-a[j]) ok=1;
        }
    }
    puts(ok?"YES":"NO");
return 0;
}
