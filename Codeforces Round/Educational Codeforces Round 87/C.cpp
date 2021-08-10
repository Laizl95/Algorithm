#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
#define pi acos(-1)
using namespace std;
const int N=2e5+5,inf=1e9+5,mod=998244353;
const double eps=1e-6;
typedef long long LL;
int n,m,k;

double solve(int n){
   return tan(pi*(n-2)/(n*2));
}
int main(){
    int t;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        double s=solve(2*n);
        printf("%.10f\n",s);
    }
return 0;
}
