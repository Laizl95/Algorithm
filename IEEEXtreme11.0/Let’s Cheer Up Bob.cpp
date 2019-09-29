#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=5,inf=1e8;
typedef long long LL;
struct node{
    int r,c;
}mat[10];
vector<node> ans,ans2,v1,v;
int b[3][3],vis[10],cnt;

int is_small(vector<node> a,vector<node> buf){
    int len_a=a.size(),len_buf=buf.size();
   if(len_a==0 || len_a>len_buf) return 1;
   if(len_a<len_buf) return 0;
   if(len_a==len_buf){
        rep(i,0,len_a){
            if(buf[i].r<a[i].r) return 1;
            else if(a[i].r==buf[i].r){
                if(a[i].c<buf[i].c) return 0;
                else if(a[i].c>buf[i].c)  return 1;
            }
            else return 0;
        }
    }
   return 0;
}

int judge(int t){
    rep(i,0,3) if(b[i][1]==t &&b[i][0]==t && b[i][2]==t) return 1;
    rep(i,0,3) if(b[1][i]==t && b[0][i]==t && b[2][i]==t) return 1;
    if((b[0][0]==t && b[1][1]==t && b[2][2]==t) ||
       (b[0][2]==t && b[1][1]==t && b[2][0]==t)) return 1;
    return 0;
}

void dfs(int p){
   if(judge(0)) return;
   if(judge(1)){
        //puts("");rep(i,0,v.size()) printf("(%d %d) ",v[i].r+1,v[i].c+1);puts("");
     if(is_small(ans,v)){
        ans.clear();
        rep(i,0,v.size()) ans.pb(v[i]);
     }
     return;
   }
   rep(i,0,9){
        if(vis[i] || b[mat[i].r][mat[i].c]!=-1 ) continue;
            vis[i]=1;
        b[mat[i].r][mat[i].c]=p;
        if(!p) v.pb(mat[i]);
        dfs(p^1);
        b[mat[i].r][mat[i].c]=-1;
        vis[i]=0;
        if(!p) v.pop_back();
        if(p) return;
   }
   return;
}
int main(){

    rep(i,0,9) scanf("%d %d",&mat[i].r,&mat[i].c);
    rep(i,0,9) mat[i].r-=1,mat[i].c-=1;
    ms(b,-1);ms(vis,0);ans.clear();v.clear();cnt=-1;
    dfs(1);
    rep(i,0,ans.size()) printf("%d %d\n",ans[i].r+1,ans[i].c+1);
return 0;
}
