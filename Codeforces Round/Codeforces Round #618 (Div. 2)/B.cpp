#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int n,m;
int a[N];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,0,2*n) scanf("%d",&a[i]);
        sort(a,a+2*n);
        int id=n;
        printf("%d\n",a[n]-a[n-1]);
    }
return 0;
}
