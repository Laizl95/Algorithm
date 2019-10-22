#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define mc(x,y) memcpy(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e4+5,MAXN=3,l=2,mod=10;
typedef long long LL;

int main(){
    int n,m,s;
    scanf("%d %d %d",&n,&m,&s);
    int l=2,r=n,ans=0;
    while(l<=r){
        int mid=l+r>>1;
        ans+=(mid-l+1)*m+s;
        l=mid+1;
    }
    cout<<ans<<endl;
}
