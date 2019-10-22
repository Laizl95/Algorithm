#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
int n;
char s[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
      scanf("%d",&n);
      scanf("%s",s);
      int l=n,r=-1;
      rep(i,0,n){
        if(s[i]=='1') l=min(l,i),r=max(r,i);
      }

       int ans=n;
       if(l!=n) ans=max(ans,max(2*(r+1),2*(n-1-l+1)));
        cout<<ans<<endl;
    }
return 0;
}
