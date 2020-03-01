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
string s[N];
map<string,int> mp,vis;
pair<string,string> ans[N];
int num[N];
int main(){
    int t;
    scanf("%d %d",&n,&m);
    string a;
    rep(i,0,n){
        cin>>s[i];
        mp[s[i]]+=1;
    }

    int id=0;
    rep(i,0,n){

        if(vis.count(s[i])) continue;
        a=s[i];
        reverse(s[i].begin(),s[i].end());
        if(vis.count(s[i])) continue;
        //cout<<a<<" "<<s[i]<<endl;
        int t=min(mp[s[i]],mp[a]);
        if(s[i]==a) t/=2;
        if(t==0) { reverse(s[i].begin(),s[i].end()); continue;}
        vis[a]=1;vis[s[i]]=1;
        num[id]=t,ans[id++]=mp(s[i],a);
         reverse(s[i].begin(),s[i].end());
    }
    int len=0;string b;
    rep(i,0,n){
        a=s[i];
        reverse(s[i].begin(),s[i].end());
        if(a==s[i] && mp[a]%2==1){
            if(a.length()>len) len=a.length(),b=a;
        }
        reverse(s[i].begin(),s[i].end());
    }
    int x=0;
    rep(j,0,id) x+=num[j];
    printf("%d\n",m*x*2+len);
    rep(i,0,id) rep(j,0,num[i])cout<<ans[i].first;
    if(len>0) cout<<b;
    per(i,0,id) rep(j,0,num[i]) cout<<ans[i].second;cout<<endl;
return 0;
}
