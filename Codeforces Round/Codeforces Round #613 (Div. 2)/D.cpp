#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n;
int a[N];
vector<int> bit[N];
int solve(vector<int> v,int d){
    if(d==-1) return 0;
    vector<int> buf[2];
    rep(i,0,v.size()){
        int id=v[i];
        if(bit[id][d]==0) buf[0].pb(id);
        else buf[1].pb(id);
    }
    if(buf[0].size()==0) return solve(buf[1],d-1);
    else if(buf[1].size()==0) return solve(buf[0],d-1);
    else{
        return min(solve(buf[0],d-1),solve(buf[1],d-1))+(1<<d);
    }
}
int main(){

    int x;
    scanf("%d",&n);
    vector<int> v;
    rep(i,0,n){
     scanf("%d",&x);
     while(x>0){
        bit[i].pb(x&1);
        x>>=1;
        //cout<<x<<endl;
     }
     int t=bit[i].size();
     rep(j,t,30) bit[i].pb(0);
     v.pb(i);
    }
    int ans=solve(v,29);
    cout<<ans<<endl;
return 0;
}
