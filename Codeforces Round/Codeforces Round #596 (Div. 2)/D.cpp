#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
LL inf=1e10;
int n,p;
LL Pow(int x,int k){
     LL ans=1;
     while(k){
        if(k&1) ans=ans*x;
        k>>=1;
        x=x*x;
     }
     return ans;
}
map<LL,int> mp;
int main(){
    vector<LL> ans;int id=0;
    rep(i,2,101){
        rep(j,1,1e5+1){
            LL sum=Pow(j,i);
            if(sum<=inf) {if(!mp.count(sum)) mp[sum]=++id;}
            else break;
        }
    }
    cout<<id<<endl;
    //while(scanf("%d %d",&n,&p)!=EOF){

    //}
return 0;
}
