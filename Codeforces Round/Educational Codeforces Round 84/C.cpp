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

int main(){
    scanf("%d %d %d",&n,&m,&k);
    int x,y;
    rep(i,0,2*k) scanf("%d %d",&x,&y);
    printf("%d\n",n-1+m-1+(n-1)*m+m);
    rep(i,0,n-1) printf("U");
    rep(i,0,m-1) printf("L");
    rep(i,0,m){
        if(i&1)rep(j,0,n-1) printf("U");
        else rep(j,0,n-1) printf("D");
        printf("R");
    }
return 0;
}
