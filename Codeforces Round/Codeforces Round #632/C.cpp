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
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
int a[N],ans[N];
int main(){
    int t;
    scanf("%d",&n);
    LL sum=0;
    map<LL,int> mp;
    mp[0]=0;

    rep(i,1,n+1){
        scanf("%d",&a[i]);
        if(a[i]==0){
            ans[i]=0;
        }else ans[i]=-1;
    }
    per(i,1,n+1){
        if(ans[i]!=0) ans[i]=ans[i+1]+1;
    }
    rep(i,1,n+1){
        sum+=a[i];
        if(mp.count(sum)){
            int l=mp[sum];
            ans[l+1]=i-l-1;
        }
        mp[sum]=i;
       /* if(a[i]==0){
            mp.clear();
            mp[0]=i;
        }*/
    }
    LL num=0;
    per(i,1,n) ans[i]=min(ans[i],ans[i+1]+1);
    rep(i,1,n+1){
        //cout<<ans[i]<<endl;
        //num+=(1+ans[i])*1LL*ans[i]/2;
        num+=ans[i];
    }
    cout<<num<<endl;
return 0;
}
