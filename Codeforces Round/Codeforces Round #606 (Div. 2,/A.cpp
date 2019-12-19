#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int a[N];
bool cmp(int &a,int &b){
    return a>b;
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        map<int,int> mp;
        mp.clear();
        scanf("%d",&n);
        rep(i,0,n){
            scanf("%d",&a[i]);
            mp[a[i]]+=1;
        }
        sort(a,a+n,cmp);
        vector<int> v;
        rep(i,0,n){
            if(i==0 || a[i]!=a[i-1]) v.pb(a[i]);
        }
        int ans=0;
        rep(i,0,v.size()){
            int x=v[i];
            //cout<<"x="<<x<<endl;
            while((x&1)==0 && mp[x]!=0){
                ans+=1;
                mp[x/2]+=mp[x];
                mp[x]=0;
                x/=2;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}
