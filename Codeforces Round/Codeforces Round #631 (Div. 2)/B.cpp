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
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
int a[N],vis[N];
vector<int> p[N];
int judge(int x,int id){
    rep(i,1,n+1) vis[i]=0;
    if(id==0){
        int num=0;
        rep(i,0,x+1){
            vis[a[i]]+=1;
            num=max(a[i],num);
        }
        rep(i,1,num+1) if(vis[i]!=1) return 0;
        return 1;
    }
    int num=0;
    rep(i,x,n){
        vis[a[i]]+=1;
        num=max(a[i],num);
    }
    rep(i,1,num+1) if(vis[i]!=1) return 0;
    return 1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int g=-1,ok=1;
        rep(i,0,n){
            scanf("%d",&a[i]);
            g=max(g,a[i]);
            p[a[i]].pb(i);
            if(p[a[i]].size()>2) ok=0;
        }
        if(!ok){
            puts("0");
        }else{
            int l=-1,r=-1,mx=0;
            rep(i,1,g+1){
                if(p[i].size()==0){ok=0;break;}
                if(p[i].size()==2){
                    int x1=min(p[i][0],p[i][1]),x2=max(p[i][0],p[i][1]);
                    if(l==-1 && r==-1) l=x1,r=x2;
                    if((x1<l && x2<l) || (x1>r && x2>r)){
                        ok=0;break;
                    }
                    l=max(l,x1);
                    r=min(r,x2);
                }else{
                    mx=1;
                    break;
                }
            }
            if(!ok) puts("0");
            else{
            if(!mx){
                if(!judge(l,0) || !judge(r,1)){
                    puts("0");
                }else{
                    if(r-l==1){
                        puts("1");
                        printf("%d %d\n",l+1,n-l-1);
                    }else puts("0");
                }
            }else{
                 int cnt=0;
                    vector<pii> v;
                if(l==-1){
                    puts("0");
                }else{
                if(judge(r-1,0)&&judge(r,1)){
                        ++cnt;
                        v.pb(pii(r,n-r));
                }
                if(l+1!=r && judge(l+1,1) && judge(l,0)){
                        ++cnt;
                        v.pb(pii(l+1,n-l-1));
                }
                printf("%d\n",cnt);
                for(auto it:v){
                    printf("%d %d\n",it.fi,it.se);
                }}
            }
        }
        }
        rep(i,0,n) p[a[i]].clear();
    }
return 0;
}
