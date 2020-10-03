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
int a[N],b[N],vis[N];
set<int> v;
int get(int x){
    int bit=0;
    while(x){
        if(x&1) v.insert(1<<bit);
        x>>=1;
        bit++;
    }
    return bit;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    rep(i,0,n) scanf("%d",&a[i]);
    rep(i,0,m) scanf("%d",&b[i]);
    int ans=0,id=-1;
    rep(j,1,n+1){
        int mx=-2,id=-1;
        rep(i,0,n){
            if(vis[i]) continue;
            int num=a[i]&b[0];
            for(auto &x:v){
                if((x^num)<num) num^=x;
                //if(x^num==0 && x==num) num^=x;
            }
            rep(j,0,m){
                int temp=a[i]&b[j];
                for(auto &x:v) {
                    if((x^temp)<temp) temp^=x;
                    //if(x^temp==0 && x==temp) temp^=x;
                }
                num=min(num,temp);
            }
            if(mx<num){
                mx=num;
                id=i;
            }
        }
        //cout<<mx<<endl;
        vis[id]=1;
        get(mx);
        //for(auto &x:v) printf("%d ",x);cout<<endl;
        ans|=mx;
    }
    cout<<ans<<endl;
return 0;
}
