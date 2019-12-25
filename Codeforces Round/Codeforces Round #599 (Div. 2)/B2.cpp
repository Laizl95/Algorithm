#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
char s1[N],s2[N];
int tot[26];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
       scanf("%d %s %s",&n,s1,s2);
       ms(tot,0);
       rep(i,0,n)
            if(s1[i]!=s2[i])
                tot[s1[i]-'a']+=1,tot[s2[i]-'a']+=1;
        int ok=1;
       rep(i,0,26)
        if(tot[i]&1){
            ok=0;
            break;
        }
        if(!ok){puts("No");continue;}
        puts("Yes");
        vector<pair<int,int> > ans;
    while(true){
        vector<pair<int,int> > v;
        char goal='0';
       rep(i,0,n)
           if(s1[i]!=s2[i]){
            if(goal=='0'){
                goal=s1[i];
                v.pb(make_pair(1,i));
                continue;
            }else if(goal==s1[i])  v.pb(make_pair(1,i));
             else if(goal==s2[i])  v.pb(make_pair(2,i));
           }
       if(goal=='0') break;
       int y=v.size();
       for(int i=0;i<y;i+=2){
        if(v[i].first==v[i+1].first){
           ans.pb(make_pair(v[i].second,v[i+1].second));
           swap(s1[v[i].second],s2[v[i+1].second]);
        }
        else{
             swap(s1[v[i+1].second],s2[v[i+1].second]);
             swap(s1[v[i].second],s2[v[i+1].second]);
             ans.pb(make_pair(v[i+1].second,v[i+1].second));
             ans.pb(make_pair(v[i].second,v[i+1].second));
        }
       }
    }
    printf("%d\n",ans.size());
    rep(i,0,ans.size()){
        printf("%d %d\n",ans[i].first+1,ans[i].second+1);
    }
    }
return 0;
}
