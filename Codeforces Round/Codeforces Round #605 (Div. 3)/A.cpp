#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int d[3]={0,1,-1};
int main(){
    int t,a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&a,&b,&c);
        int ans=abs(a-b)+abs(a-c)+abs(b-c);
        rep(i,0,3) rep(j,0,3) rep(k,0,3){
            ans=min(ans,abs(a+d[i]-b-d[j])+abs(a+d[i]-c-d[k])+abs(b+d[j]-c-d[k]));
        }
        printf("%d\n",ans);
    }
return 0;
}
