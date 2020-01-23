#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5;
typedef long long LL;
int a[N];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,1,4*n+1) scanf("%d",&a[i]);
        sort(a+1,a+1+4*n);
        int s=-1,ok=1;
        for(int i=1;i<=2*n;i+=2){
            if(s==-1) s=a[i]*a[4*n-i+1];
            else if(a[i]*a[4*n-i+1]!=s) ok=0;
            if(a[i]!=a[i+1] || a[4*n-i+1]!=a[4*n-i]) ok=0;
        }
        puts(ok?"YES":"NO");
    }
return 0;
}
