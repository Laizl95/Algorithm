#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
LL a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        LL ans1=0,num=0,ans3=-(1e15+5);
        int ok=0;
        rep(i,0,n){
            scanf("%lld",&a[i]);
            ans1+=a[i];
        }
        int cnt=0,l=0;
        rep(i,0,n){
            num+=a[i];
            if(ans3<num || (ans3==num && cnt>i-l+1)){
                ans3=num;
                cnt=i-l+1;
            }
            if(num<=0){
                num=0;
                l=i+1;
            }
        }

        if(ans1==ans3 && cnt==n)puts("YES");
        else puts("NO");

    }
return 0;
}
