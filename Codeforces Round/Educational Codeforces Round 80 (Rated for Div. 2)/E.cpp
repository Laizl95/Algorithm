#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=3e5+5,inf=1e9+5;
typedef long long LL;
int sum[2*N],a[N],mx_l[N],mx_r[N],pos[N];
int n,m;
int lowbit(int x){
    return x&(-x);
}
void update(int i,int k){
    while(i<=n+m){
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
    scanf("%d %d",&n,&m);
    rep(i,1,n+1) mx_l[i]=i,mx_r[i]=i,pos[i]=n-i+1;
    rep(i,1,n+1) update(i,1);
    rep(i,0,m){
        scanf("%d",&a[i]);
        mx_l[a[i]]=1;

    }
    rep(i,0,m){
        mx_r[a[i]]=max(mx_r[a[i]],n-query(pos[a[i]]-1));
        update(pos[a[i]],-1);
        pos[a[i]]=n+i+1;
        update(pos[a[i]],1);
    }
    rep(i,1,n+1){
        mx_r[i]=max(mx_r[i],n-query(pos[i]-1));
        printf("%d %d\n",mx_l[i],mx_r[i]);
    }

return 0;
}
