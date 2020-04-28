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
int a[N];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",&a[i]);
    int ok=0;
    per(i,0,n){
        per(j,0,i){
            if(a[i]<a[j]){
                rep(k,0,j) printf("%d ",a[k]);
                rep(k,i,n) printf("%d ",a[k]);
                rep(k,j,i) printf("%d ",a[k]);
                ok=1;
                break;
            }
        }
        if(ok) break;
    }
    if(!ok) puts("ERROR");
return 0;
}
