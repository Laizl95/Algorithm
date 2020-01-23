#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5;
typedef long long LL;

int main(){
    int t,n,s,k;
    scanf("%d",&t);
    while(t--){
            int x;
        scanf("%d %d %d",&n,&s,&k);
        map<int,int> mp;
        mp.clear();
        rep(i,0,k){
            scanf("%d",&x);
            mp[x]=1;
        }
        int ans=n;
        int y=s;
        while(y<=n){
            if(!mp.count(y)){
                ans=min(ans,y-s);
                break;
            }
            y+=1;
        }
        y=s;
        while(y>0){
            if(!mp.count(y)){
                ans=min(ans,s-y);
                break;
            }
            y-=1;
        }
        cout<<ans<<endl;
    }
return 0;
}


