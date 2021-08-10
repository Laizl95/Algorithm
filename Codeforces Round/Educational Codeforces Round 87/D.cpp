#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
#define lson l,mid,i<<1
#define rson mid+1,r,i<<1|1
#define ls i<<1
#define rs i<<1|1
using namespace std;
const int N=1e6+5,inf=1e9+5,mod=998244353;
typedef long long LL;
int n,m,maxn=1e6;
int sum[N];
int lowbit(int x){
    return x&(-x);
}
void update(int i,int k){
    while(i<=maxn){
        sum[i]+=k;
        i+=lowbit(i);
    }
}
int query(int i){
    int res=0;
    while(i>0){
        res+=sum[i];
        i-=lowbit(i);
    }
    return res;
}

int main(){
    cout<<lowbit(8);
    scanf("%d %d",&n,&m);
    int x;
    rep(i,1,n+1){
        scanf("%d",&x);
        update(x,1);

    }
    rep(i,1,m+1){
        scanf("%d",&x);
        if(x<0){
           x=-x;
           int l=1,r=1e6;
           while(l<=r){
                int mid=l+r>>1;
                if(query(mid)>=x) r=mid-1;
                else l=mid+1;
           }
            update(l,-1);
        }else{
            update(x,1);
        }
    }
    int ok=0;
    rep(i,1,1e6+1)
        if(query(i)-query(i-1)>0){
            cout<<i<<endl;
            ok=1;
            break;
        }
    if(!ok) puts("0");
return 0;
}
