#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=100005;
int a[N];
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        vector<pair<int,int> > ans;
        int l=0,ok=0,sum=0;
        rep(i,0,n){
            scanf("%d",&a[i]);
            sum+=a[i];
            if(sum==m) ok=1,ans.pb(make_pair(l+1,i+1));
            else if(sum>m){
                while(l<i && sum>m)
                    sum-=a[l++];
                if(sum==m) ok=1,ans.pb(make_pair(l+1,i+1));
            }
        }
        if(ok){
            rep(i,0,ans.size()) printf("%d-%d\n",ans[i].first,ans[i].second);
            continue;
        }
        sum=0;l=0;int c=-1;
        rep(i,0,n){
            sum+=a[i];
            if(sum>m){
                while(sum-a[l]>m) sum-=a[l++];
                if(c==-1 || sum-m==c) c=sum-m,ans.pb(make_pair(l+1,i+1));
                else if(sum-m<c) c=sum-m,ans.clear(),ans.pb(make_pair(l+1,i+1));
            }
        }
         rep(i,0,ans.size()) printf("%d-%d\n",ans[i].first,ans[i].second);
    }
return 0;
}
