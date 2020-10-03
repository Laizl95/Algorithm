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
int ans[N];
char s[N];
int main(){
    int t;
    LL p,f,cnt1,cnt2,w1,w2;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld %lld %lld %lld",&p,&f,&cnt1,&cnt2,&w1,&w2);
        if(w1>w2){
            swap(w1,w2);
            swap(cnt1,cnt2);
        }
        int ans=0;
        rep(i,0,cnt1+1){
            LL left=p-i*w1;
            if(left<0) break;
            int x2=left/w2;
            int num=cnt1-i;
            int x3=min((int)(f/w1),num);
            int x4=min((f-x3*w1)/w2,cnt2-x2);
            ans=max(ans,x2+x3+x4+i);
        }
        cout<<ans<<endl;
    }
return 0;
}
