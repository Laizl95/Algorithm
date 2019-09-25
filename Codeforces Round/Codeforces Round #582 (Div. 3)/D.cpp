#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
int cnt[N],a[N],num[N];
vector<int> v[N];
bool cmp(int &a,int &b){
    return a>b;
}
int main(){
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF){
        // ms(num,0);ms(cnt,0);rep(i,0,N) v[i].clear();
        int maxx=-1;
         rep(i,0,n){
             scanf("%d",&a[i]);
             maxx=max(maxx,a[i]);
             cnt[a[i]]+=1;
             int x=a[i],y=1;
             while(x) {num[x/2]+=y,cnt[x/2]+=1;v[x/2].pb(y);x/=2,y+=1;}
        }
        int ans=-1;
        rep(i,0,maxx+1)
           if(cnt[i]>=k){
               sort(v[i].begin(),v[i].end(),cmp);
                int y=cnt[i]-k,x=num[i],y1=v[i].size();
                y=min(y,y1);
                rep(j,0,y) x-=v[i][j];
                if(ans==-1 || x<ans) ans=x;
           }
        printf("%d\n",ans);
    }
return 0;
}
