#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=1e3+5,inf=1e9+5;
typedef long long LL;
int mat[N][N],hang[N];
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<char> ans;
        vector<pair<int,int> > buf;
        int x,y,h=-1,l=-1;
        rep(i,0,n){
            scanf("%d %d",&x,&y);
            mat[y][x]=1;
            h=max(h,x);
            buf.pb(mp(y,x));
        }
        int cnt=0,p=0;
        rep(j,0,h+1){
            int pre=p;
            rep(i,p,1001){
                if(mat[i][j]==1) ++cnt,p=i;
            }

            rep(i,pre,p) ans.pb('U');
            if(cnt<n) ans.pb('R');
            else break;
        }
        if(cnt==n){
            printf("YES\n");
            rep(i,0,ans.size()) printf("%c",ans[i]);puts("");
        }
        else printf("NO\n");
        rep(i,0,buf.size())  mat[buf[i].first][buf[i].second]=0;
    }
return 0;
}
