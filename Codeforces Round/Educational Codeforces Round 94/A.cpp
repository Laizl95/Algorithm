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
int main(){
    int t;
    string s;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cin>>s;
        vector<char> ans;
        ans.pb(s[0]);
        rep(i,1,n){
            int j=i,ok=0;
            for(auto &c:ans){
                if(s[j++]==c){ok=1;break;}
            }
            if(!ok) ans.pb(s[i+ans.size()]);
        }
        for(auto &c:ans) printf("%c",c);
        rep(i,ans.size(),n) printf("0");
        puts("");
    }
return 0;
}
