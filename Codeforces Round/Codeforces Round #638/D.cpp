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
int n;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       int x=1;
       vector<int> v;
       while(n>=x){
            n-=x;
            v.pb(x);
            x*=2;
       }
       if(n) v.pb(n);
       sort(v.begin(),v.end());
       printf("%d\n",v.size()-1);
       rep(i,1,v.size())
            printf("%d ",v[i]-v[i-1]);
        puts("");

    }
return 0;
}
