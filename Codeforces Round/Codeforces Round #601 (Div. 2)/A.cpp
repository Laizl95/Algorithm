#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=105,inf=1e9+5;
typedef long long LL;

int n,m,k;
int main(){

    int t;int a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        int x=abs(a-b),ans=0;
        ans+=x/5;
        x%=5;
        if(x==2 || x==1) ans+=1;
        if(x==3 || x==4) ans+=2;
        printf("%d\n",ans);
    }
return 0;
}
