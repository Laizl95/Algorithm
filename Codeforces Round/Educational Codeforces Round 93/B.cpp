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
        scanf("%s",s);
        int len=strlen(s);
        puts(s);
        vector<int> v;
        int cnt=0;
        rep(i,0,len){
            if(s[i]=='1') ++cnt;
            else{
                if(cnt) v.pb(cnt);
                cnt=0;
            }
        }
        if(cnt) v.pb(cnt);
        sort(v.begin(),v.end());
        //for(auto &x:v) printf("%d ",x);cout<<endl;
        int ans=0;
        for(int i=v.size()-1;i>=0;i-=2)
            ans+=v[i];
        cout<<ans<<endl;
    }
return 0;
}
