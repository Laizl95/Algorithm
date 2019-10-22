#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int ans=a+a*2+c/2+c/2*2;
        int hope=a*2+c/2;
        int tot1=a,tot2=c/2;
        while(hope>b){
            if(hope<=b) break;
            ans-=3;
            if(tot1!=0){tot1-=1,hope-=2;}
            else if(tot2!=0) {tot2-=1,hope-=1;}
            else {ans=0;break;}
            if(hope<=b) break;
        }
        cout<<ans<<endl;

    }
return 0;
}
