#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int vis[N],sum[4];
void solve(int sum1,int sum2,int tot,vector<int> v,int c){
    int total=sum1;
    sum1-=sum2+1;
    int ans=(sum1+1)/2;
    cout<<ans<<endl;
    int cnt=0;
    rep(i,0,v.size()){
        if(cnt>=ans) break;
        if(!vis[v[i]]){cnt+=1;printf("%d ",v[i]+1);}
    }puts("");
}
int main(){
    std::ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    int t,n;string s;
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       vector<int> v1,v2,buf;
       map<string,int> mp;
       ms(sum,0);
       int tot=0;
      rep(i,0,n) vis[i]=0;
      rep(i,0,n){
        cin>>s;
        int len=s.length()-1;
        if(s[0]=='0' && s[len]=='0') sum[0]+=1;
        else if(s[0]=='0' && s[len]=='1') sum[1]+=1;
        else if(s[0]=='1' && s[len]=='0') sum[2]+=1;
        else if(s[0]=='1' && s[len]=='1') sum[3]+=1;
        if(s[0]=='0' && s[len]=='1'){
            v1.pb(i);
            mp[s]=i;
            reverse(s.begin(),s.end());
            if(mp.count(s)!=0){
                //sum[1]-=1,sum[2]-=1;
                int id=mp[s];
                vis[id]=1;vis[i]=1;
                buf.pb(id);buf.pb(i);
                tot+=1;
            }
        }
        else if(s[0]=='1' && s[len]=='0'){
            v2.pb(i);
            mp[s]=i;
            reverse(s.begin(),s.end());
            if(mp.count(s)!=0) {
                 int id=mp[s];
                vis[id]=1;vis[i]=1;
                buf.pb(id);buf.pb(i);
                tot+=1;
            }
        }
      }
      //cout<<sum[1]<<" "<<sum[2]<<endl;
      if(sum[1]>sum[2]) solve(sum[1],sum[2],tot,v1,3);
      else if(sum[1]<sum[2]) solve(sum[2],sum[1],tot,v2,0);
      else{
        if(sum[1]==0 && sum[0]!=0 && sum[3]!=0) puts("-1");
        else puts("0\n");
      }
      rep(j,0,buf.size()) vis[buf[j]]=0;
    }
return 0;
}
