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
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    a[0]=0;a[1]=2;
    int p=1;
    while(a[p]<=1e9){
        ++p;
        a[p]=a[p-1]*2-a[p-2]+3;
    }
    //cout<<p<<" "<<a[p]<<endl;
    while(t--){
        scanf("%d",&n);
        int ans=0;
        while(n>=2){
            rep(i,1,p+1){
                if(a[i]>n){
                    ans+=n/a[i-1];
                    n%=a[i-1];
                }
            }
        }
        cout<<ans<<endl;
    }
return 0;
}
