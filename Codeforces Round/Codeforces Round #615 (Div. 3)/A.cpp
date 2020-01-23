#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    int t,n,m;
    int a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&a,&b,&c,&n);
        int k=max(max(a,b),c);
        n-=k-a;
        n-=k-b;
        n-=k-c;
        if(n<0 || n%3!=0) puts("NO");
        else puts("YES");
    }
return 0;
}
