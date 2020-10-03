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
int n;
char s[N];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %s",&n,s);
        map<int,int> mp;
        LL ans=0;
        int num=0;
        mp[0]=1;
        //sum[r]-sum[l]=r-l;
        //sum[r]-r=sum[l]-l;
        rep(i,0,strlen(s)){
            int x=s[i]-'0';
            num+=x;
            ans+=mp[num-i-1];
            mp[num-i-1]+=1;
        }
        cout<<ans<<endl;
    }
return 0;
}
