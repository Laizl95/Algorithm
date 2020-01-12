#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
int a[N];
int cnt[35];
int main(){
    int n,m=-1;
    scanf("%d",&n);
    rep(i,0,n){
     scanf("%d",&a[i]);
     int x=a[i],tot=0;
     while(x>0){
        if(x&1) cnt[tot++]+=1;
        x>>=1;
        //cout<<x<<endl;
     }
    }
    cout<<cnt[1]<<" "<<cnt[0]<<endl;
    int b=1,x=1;
    rep(i,0,31){
      if(cnt[i]*2>=n){
        b=b*x;
      }
      x*=2;
    }
    int ans=0;
    rep(i,0,n){
     ans=max(a[i]^b,ans);
    }
    cout<<ans<<endl;
return 0;
}
