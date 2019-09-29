#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
#define ll long long
const int maxn=1e6+5;
const int mod=1e9+7;
int p[maxn],bit[maxn],tol;
struct node1{
    int l,r;
}c[maxn];
bool cmp(node1 a,node1 b){
    if(a.r!=b.r)return a.r<b.r;
    return a.l<b.l;
}
int sum(int i){ //1 - i的和
    int s=0;
    while(i>0)
    {
        s=(s+bit[i])%mod;
        i-=i&-i;
    }
    return s%mod;
}
void add(int i,int x){ //在i位置加上k
    while(i<=tol)
    {
        bit[i]=(bit[i]+x)%mod;
        i+=i&-i;
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    tol=1;
    for(int i=0;i<m;i++)  {
        scanf("%d %d",&c[i].l,&c[i].r);
        p[tol++]=c[i].l;
        p[tol++]=c[i].r;
    }
    sort(p+1,p+tol+1);
    sort(c,c+m,cmp);
    int s=0;
    rep(i,0,m){
        int l=lower_bound(p+1,p+tol+1,c[i].l)-p;
        int r=lower_bound(p+1,p+tol+1,c[i].r)-p;
        int ans=0;
        if(c[i].l==0)ans++;
        ans+=sum(r-1)-sum(l-1);
        ans=(ans+mod)%mod;
        add(r,ans);
        if(c[i].r==n)s=sum(r)-sum(r-1);
    }
    printf("%d\n",(s+mod)%mod);
    return 0;
}
