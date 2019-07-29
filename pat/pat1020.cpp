#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
int a[N],b[N],n,id;
struct node{
 int l,r,x;
 node(){}
 node(int _l,int _r,int _x){l=_l;r=_r;x=_x;}
}s[N];
int build(int la,int ra,int lb,int rb){
     if(la>ra || lb>rb) return -1;
     int root=a[ra],p=-1;
     rep(i,lb,rb+1) if(b[i]==root){p=i;break;}
     int id_root=id; id+=1;
     s[id_root].x=root;//p-lb
     s[id_root].l=build(la,la+p-lb-1,lb,p-1);
     s[id_root].r=build(la+p-lb,ra-1,p+1,rb);
     return id_root;
}
void bfs(){
  queue<node> q;
  q.push(s[0]);
  vector<int> ans;
  while(!q.empty()){
    node root=q.front();
    q.pop();
    ans.pb(root.x);
    if(root.l!=-1) q.push(s[root.l]);
    if(root.r!=-1) q.push(s[root.r]);
  }
  int y=ans.size();
  rep(i,0,y) printf("%d%c",ans[i],i==y-1?'\n':' ');
}
int main(){

    while(scanf("%d",&n)!=EOF){
        rep(i,0,n) scanf("%d",&a[i]);
        rep(i,0,n) scanf("%d",&b[i]);
        id=0;
        build(0,n-1,0,n-1);
        bfs();
    }
return 0;
}
