#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
char s[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s);
        vector<int> ans;
        rep(i,0,n){
            int x=s[i]-'0';
            if(x==1 || x==3 || x==5 || x==7 || x==9){
                ans.pb(x);
                if(ans.size()>=2) break;
            }
        }

        if(ans.size()<2) puts("-1");
        else{
            for(auto it: ans) printf("%d",it); cout<<endl;
        }

    }
return 0;
}
