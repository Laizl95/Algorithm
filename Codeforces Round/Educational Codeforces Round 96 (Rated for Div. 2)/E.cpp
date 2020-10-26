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
const int N=2e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;
char s[N],rev_s[N];
int sum[N];
int n;
int lowbit(int x){//求最小幂2^k 例：a[1]+a[2]+..a[6]=sum[6]+sum[4] 6-lowbit(6)=4
    return x&(-x);
}

void update(int i,int k){  //在i位置加上k
    while(i<=n){
        sum[i]+=k;
        i+=lowbit(i);
    }
}

int query(int i){    //求a[1 - i]的和
    int res=0;
    while(i>0){
        res+=sum[i];
        i-=lowbit(i);
    }
    return res;
}
int main(){
    scanf("%d %s",&n,s+1);
    stack<int> q[35];
    rep(i,1,n+1) {
        q[s[i]-'a'].push(i);
        rev_s[i]=s[n-i+1];
    }
    LL ans=0;
    per(i,1,n+1){
        int p=q[rev_s[i]-'a'].top();
        q[rev_s[i]-'a'].pop();
        ans+=i-p+query(p);
        update(p,1);
    }
    cout<<ans<<endl;
return 0;
}
