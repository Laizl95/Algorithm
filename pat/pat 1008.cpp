#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0,a,pre=0;
        rep(i,0,n){
            scanf("%d",&a);
            if(a>=pre) ans+=(a-pre)*6+5;
            else ans+=(pre-a)*4+5;
            pre=a;
        }
        printf("%d\n",ans);
    }
return 0;
}
