#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define pdi pair<double,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;
double a[N];
//sumL n-x-sumR
int main(){
    int n;
    scanf("%d",&n);
    int num=0;
    double ans=0;
    rep(i,0,2*n){
        scanf("%lf",&a[i]);
        ans+=a[i]-(int)a[i];
        if(a[i]-(int)a[i]<1e-7) ++num;
    }
    double res=1e9;
    for(int i=max(num-n,0);i<=min(num,n);++i){
        res=min(res,fabs(ans-(n-i)));
    }
    printf("%.3f",res);
    return 0;
}