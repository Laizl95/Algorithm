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

int main(){
    int t,x,y,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&x,&y,&a,&b);
        if((y-x)%(a+b)==0) printf("%d\n",(y-x)/(a+b));
        else puts("-1");
    }
return 0;
}
