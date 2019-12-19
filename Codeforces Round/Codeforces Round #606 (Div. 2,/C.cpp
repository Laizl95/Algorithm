#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
char s[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       scanf("%s",s);
       int len=strlen(s);
       vector<int> ans;
       rep(i,2,len){
           if(s[i]=='e' && s[i-1]=='n' && s[i-2]=='o'){

            if(i-3>=0 && s[i-3]=='w' && i-4>=0 && s[i-4]=='t')
                ans[ans.size()-1]+=1;
            else ans.pb(i-1);
           }
           if(s[i]=='o' && s[i-1]=='w' && s[i-2]=='t'){
                ans.pb(i-1);
           }
       }
       cout<<ans.size()<<endl;
       rep(i,0,ans.size()) printf("%d ",ans[i]+1); puts("");
    }
return 0;
}
