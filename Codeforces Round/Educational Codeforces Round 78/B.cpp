#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        if(a==b) {puts("0");continue;}
        if(a>b) swap(a,b);
        int c=1;
        while(1){
            if(1LL*(c+1)*c/2>=b-a) break;
            c+=1;
        }
            LL d=a+1LL*(c+1)*c/2;int ans;
            if((d-b)%2==0) ans=c;
            else if((c+1+d-b)%2==0) ans=c+1;
            else ans=c+2;
             printf("%d\n",ans);
    }
return 0;
}
