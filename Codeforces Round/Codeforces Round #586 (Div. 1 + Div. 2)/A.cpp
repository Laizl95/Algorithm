#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e5+5;
//46
char s[N];
int tot[26];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",s);
        ms(tot,0);
        vector<int> ans;
        rep(i,0,n) tot[s[i]-'a']+=1;
        rep(i,0,tot['n'-'a']) ans.pb(1);
        rep(i,0,tot['z'-'a']) ans.pb(0);
        rep(i,0,ans.size())
            if(i==0) printf("%d",ans[i]);
            else printf(" %d",ans[i]);
            puts("");
    }
return 0;
}
