#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e6+5,inf=1e9+5,M=1e5+5;
typedef long long LL;
int n,m;
vector<int> v[M];
int b[M],c[M],sum[N];
int lowbit(int x){
    return x&(-x);
}

void updata(int i,int k){
    while(i<=1e6+1){
        sum[i]+=k;
        i+=lowbit(i);
    }
}

int getsum(int i){
    int res=0;
    while(i>0){
        res+=sum[i];
        i-=lowbit(i);
    }
    return res;
}

int main(){
    //cout<<lowbit(0)<<endl;
    scanf("%d",&n);
    LL ans=0;int x,sum=0;
    rep(i,0,n){
        scanf("%d",&m);
        int minx=1e6+5,maxx=-1;
        rep(j,0,m){
            scanf("%d",&x);
            x+=1;
            v[i].pb(x);

            minx=min(minx,v[i][j]);
            maxx=max(maxx,v[i][j]);
        }
        b[i]=minx;
        int ok=0,k=-1;
        per(j,0,m){
             k=max(v[i][j],k);
             if(v[i][j]<k) {ok=1;break;}
        }
        c[i]=ok;
        if(!ok)  updata(maxx,1);
        sum+=ok;
    }
    rep(i,0,n){
        if(c[i]) ans+=n;
        else{
           ans+=getsum(1e6+1)-getsum(b[i]);
           ans+=sum;
        }
    }
    printf("%lld\n",ans);
return 0;
}
