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
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        scanf("%s",s);
        int tot=0,p;
        vector<pair<int,int> > ans;
        for(int i=0;i<n;i+=2){
            if(tot==k-1){p=i;break;}
            if(s[i]=='('){
               if(s[i+1]==')') ++tot;
               else{
                for(int j=i+1;j<n;++j)
                    if(s[j]==')'){
                        swap(s[i+1],s[j]);
                        ans.pb(make_pair(i+1,j));
                        ++tot;
                        break;
                    }
              }
            }else{
                 for(int j=i+1;j<n;++j)
                    if(s[j]=='('){
                        swap(s[i],s[j]);
                        ans.pb(make_pair(i,j));
                        ++tot;
                        break;
                    }
            }
        }
        tot=0;k=(n-p)/2;
        rep(i,p,n){
            if(tot==k) break;
            if(s[i]==')'){
                for(int j=i+1;j<n;++j)
                    if(s[j]=='('){
                        swap(s[i],s[j]);
                        ans.pb(make_pair(i,j));
                        ++tot;
                        break;
                    }
            }else ++tot;
        }
        //printf("%s\n",s);
        printf("%d\n",ans.size());
        rep(i,0,ans.size()){
            printf("%d %d\n",ans[i].first+1,ans[i].second+1);
        }
    }
return 0;
}
