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
int n,m;
int a[N],vis[N];
string s;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        cin>>s;
        sort(s.begin(),s.end());
        if(s[m-1]!=s[0]){
            printf("%c\n",s[m-1]);
            continue;
        }
        int num=0;
        int vis[26];
        ms(vis,0);
        rep(i,m,n){
            if(!vis[s[i]-'a']) vis[s[i]-'a']=1,++num;
            if(num>1) break;
        }
        if(num>1)
            cout<<s.substr(m-1,s.length()-(m-1))<<endl;
        else{
                string ans;
            int x=n/m,y=n%m,r=s.length()-1;
            rep(i,1,x) ans+=s[r],--r;
            if(y) ans+=s[r];
            ans+=s[0];
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
        }

    }
return 0;
}
