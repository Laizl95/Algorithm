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
const int N=2e5+5,inf=1e6+5;
typedef long long LL;
int a[N],dp[N];
int solve(const int &x,const int &_l,const int &_r){
    int l=_l,r=_r;
    while(l<=r){
        int mid=l+r>>1;
        if(dp[mid]<x) r=mid-1;
        else l=mid+1;
    }
    return l;
}
int solve2(const int &x,const int &_l,const int &_r){
    int l=_l,r=_r;
    while(l<=r){
        int mid=l+r>>1;
        if(dp[mid]>=x) r=mid-1;
        else l=mid+1;
    }
    return l;
}
int main(){
    //freopen("D://input.txt", "r", stdin);
    int n=0;
    while(scanf("%d",&a[++n])!=EOF){
    }
    --n;
    int len=0;
    rep(i,1,n+1){
        int p=solve(a[i],1,len);
        if(p>len){++len;dp[len]=a[i];}
        else dp[p]=a[i];
    }
    //rep(i,1,len+1) printf("%d ",dp[i]);puts("");
    printf("%d\n",len);
    len=0;
    rep(i,1,n+1){
        int p=solve2(a[i],1,len);
        if(p>len){++len;dp[len]=a[i];}
        else dp[p]=a[i];
    } //rep(i,1,len+1) printf("%d ",dp[i]);puts("");
    printf("%d\n",len);
return 0;
}
