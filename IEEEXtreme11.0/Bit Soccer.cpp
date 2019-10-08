#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e5+5;
typedef long long LL;
vector<int> bit[N];
int sq[N];
int judge(LL x,int n){
     LL m=x;
     rep(i,0,n) sq[i]=0;
     vector<int> v;
     while(x){
        v.pb(x&1);
        x>>=1;
     }
     int t1=v.size();
     rep(j,0,n) if(bit[j].size()>t1) sq[j]=1;
    rep(i,0,t1){
       if(v[i]==0){
         rep(j,0,n) if(sq[j]==1 ||(bit[j].size()>i && bit[j][i]==1)) sq[j]=1;
       }
    }
     int l[45];
     ms(l,-1);
     rep(i,0,n) if(sq[i]==0){
          rep(j,0,bit[i].size()){
              if(l[j]==-1) l[j]=0;
              l[j]|=bit[i][j];
           }
         }
        rep(i,0,t1)
            if(v[i]!=l[i]) return 0;

        //rep(i,p,45) if(l[i]!=-1) return 0;
    return 1;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
            LL x;
        rep(i,0,n){
          scanf("%lld",&x);
           while(x){
            bit[i].pb(x&1);
            x>>=1;
           }
        }
        int q;
        scanf("%d",&q);
        while(q--){
            scanf("%lld",&x);
            puts(judge(x,n)?"YES":"NO");
        }
    }
return 0;
}
