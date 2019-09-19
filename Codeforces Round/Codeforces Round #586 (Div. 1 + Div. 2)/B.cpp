#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e3+5;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
            int a[N];
      vector<int> v;
      rep(i,0,n){
          int ans=-1;
        rep(j,0,n){
         scanf("%d",&a[j]);
            if(ans!=-1) ans=__gcd(a[j],ans);
            else ans=a[j];
        }
        //if(i<n-2)
            v.pb(ans);
        //else v.pb(a[0]/v[0]);
      }
      int gcd=v[0];
      rep(i,0,v.size()) gcd=__gcd(gcd,v[i]);
      //v[0]/=gcd;
      rep(i,0,v.size()) printf("%d ",v[i]);
      puts("");
    }
return 0;
}
