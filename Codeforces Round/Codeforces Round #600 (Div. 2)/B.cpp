#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e6+5,inf=1e9+5;
typedef long long LL;
int cnt[N],vis[N];//该天出现的次数 现在是否在
int ans[N];
int main(){
    int n,a,tot=0;//该天未出去的人
    scanf("%d",&n);
    vector<int> v;
    int ok=1,id=0;
    rep(i,0,n){
        scanf("%d",&a);
        if(a<0){
                a=-a;
            if(!vis[a]) ok=0;
            else {
                vis[a]=0;tot-=1;
                if(tot==0){
                    id+=1;
                    rep(i,0,v.size()) cnt[v[i]]=0;
                    v.clear();
                }
            }
        }
        else{
            if(cnt[a]>0){
                if(tot>0) ok=0;
                else{
                    id+=1;
                    tot=1;
                    rep(i,0,v.size()) cnt[v[i]]=0;
                    v.clear();
                    cnt[a]=1;
                    vis[a]=1;
                    ans[id]+=1;
                }
            }else{
                 v.pb(a);
                 tot+=1;
                 ans[id]+=1;
                 cnt[a]+=1;
                 vis[a]=1;
            }
        }
        //cout<<"tot:"<<tot<<endl;
    }
    if(tot!=0) ok=0;
    if(!ok) printf("%d\n",-1);
    else{
        if(ans[id]==0) id-=1;
        printf("%d\n",id+1);
        rep(i,0,id+1) printf("%d ",ans[i]*2);
        puts("");
    }
return 0;
}
