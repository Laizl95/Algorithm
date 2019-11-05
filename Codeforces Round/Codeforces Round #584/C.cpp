#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5;
typedef long long LL;
char s[N];
int ans[N];
int main(){
    //freopen("D:\\input.txt","r",stdin);
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        vector<pair<int,int> > a,b;
        int ok=0,flag=1;
        per(i,1,n+1){
            int v=s[i]-'0';
           if(a.size()==0 || a.back().first>=v) a.pb(make_pair(v,i));
           else if(!ok){
                ok=1;int pos;
                rep(i,0,a.size()) if(a[i].first<v){pos=i;break;}
                rep(i,0,pos){
                    b.pb(a[i]);
                }
                b.pb(make_pair(v,i));
                vector<pair<int,int> > buf;
                rep(i,pos,a.size()) buf.pb(a[i]);
                a.clear();
                rep(i,0,buf.size()) a.pb(buf[i]);
           }else if(a.front().first<=v && b.back().first>=v) b.pb(make_pair(v,i));
            else{flag=0;}
        }
        if(!flag) puts("-");
        else{
            rep(i,0,a.size()) ans[a[i].second]=1;
            rep(i,0,b.size()) ans[b[i].second]=2;
            rep(i,1,n+1) printf("%d",ans[i]);puts("");
        }
    }
return 0;
}
