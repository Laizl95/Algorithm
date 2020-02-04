#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=3e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",&a[i]);
        int ok=1,p=-1;
        rep(i,0,n){
            if(a[i]<i){
                if(a[i]>=a[i-1]) --a[i];
                if(n-1-i>a[i]) ok=0;
            }
        }
        puts(ok?"Yes":"No");
    }
return 0;
}
