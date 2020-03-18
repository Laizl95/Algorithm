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
const int N=1e6+5,inf=1e9+5;
typedef long long LL;
int n;
char s[N];
int main(){
    scanf("%d %s",&n,s);
    int tot=0;
    rep(i,0,n){
        if(s[i]==')') tot+=1;
        else tot-=1;
    }
    if(tot!=0){puts("-1"); return 0;}
    int cnt1=0,cnt2=0,ans=0,min_p;
    rep(i,0,n){
        if(s[i]==')'){
            if(cnt1>0) --cnt1;
            else{
                if(cnt2==0) min_p=i;
                ++cnt2;
            }
        }
        else{
            ++cnt1;
            if(cnt1==cnt2){
                ans+=i-min_p+1;
                //cout<<ans<<endl;
                min_p=0;
                cnt1=0;cnt2=0;
            }
        }
    }
    cout<<ans<<endl;

return 0;
}
