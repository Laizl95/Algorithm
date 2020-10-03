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
const int N=1e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;
LL num[N];
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    int n,m,d;
    scanf("%d %d %d",&n,&d,&m);
    vector<int> v1,v2;
    int x;
    rep(i,0,n){
        scanf("%d",&x);
        if(x<=m) v1.pb(x);
        else v2.pb(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),cmp);
    LL ans=0,sum=0;
    rep(i,0,v1.size()) num[i+1]=num[i]+v1[i],sum+=v1[i];
    ans=sum;
    int t=v1.size(),start=0;
    for(auto x:v2){
        if(t+1<=n){
            t+=1+d;
            sum+=x;
            ans=sum;
        }else{
            int r=start+t+1-n;
            if(r>v1.size()) break;
            //cout<<"r="<<r<<" start="<<start<<endl;
           if(num[r]-num[start]<x){
             sum+=x-(num[r]-num[start]);
             ans=sum;
             start=r;
             t=n+d;
           }else break;
        }
        //cout<<start<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
return 0;
}
