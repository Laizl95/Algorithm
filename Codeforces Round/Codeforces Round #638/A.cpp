#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5,inf=1e6+5;
typedef long long LL;
int n,m;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==2){cout<<"2"<<endl;continue;}
        LL ans1=0,ans2=0;
        rep(i,1,n/2){
           ans1+=(1<<i);
        }
        ans1+=(1<<n);
        rep(i,n/2,n){
            ans2+=(1<<i);
        }
        cout<<abs(ans1-ans2)<<endl;

    }
return 0;
}
