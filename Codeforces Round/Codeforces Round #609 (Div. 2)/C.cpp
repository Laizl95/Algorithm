#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
char s[N];
int n,k,a[N];
vector<int> v[N];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    scanf("%s",s);
    rep(i,0,n) a[i]=s[i]-'0';
    vector<int> ans;
    rep(i,0,k) ans.pb(a[i]);

    int p=0,l=k,cnt=0,id=0;
    while(l<n){
        cnt+=1;
        v[id].pb(a[l]);
        if(cnt==k) {cnt=0;id+=1;}
        l+=1;
    }
    rep(i,0,id+1){
       int y=v[i].size(),ok=1;
       rep(j,0,y){
         if(v[i][j]>ans[j]){
            ok=0;
            break;
         }
         if(ans[j]>v[i][j]) {ok=-1;break;}
       }
       if(ok==0){
            int bit=1;
            per(j,0,ans.size()){
                ans[j]=ans[j]+bit;
                bit=ans[j]/10;
                ans[j]%=10;
                if(bit==0) break;
            }
            break;
       }else if(ok==-1) break;
    }
    cout<<n<<endl;int tot=0;
    while(true){
        rep(i,0,ans.size()){
            printf("%d",ans[i]);
             tot+=1;
             if(tot==n) break;
        }
        if(tot==n) break;
    }puts("");
return 0;
}
