#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=15;
typedef long long ll;
struct node{
 int exp;
 double a;
 bool operator < (const node &a) const{
    return exp>a.exp;
 }
}poly1[N],poly2[N],ans[N*N];
int vis[2005];
int main(){
    int n1,n2;
    while(scanf("%d",&n1)!=EOF){
        rep(i,0,n1) scanf("%d %lf",&poly1[i].exp,&poly1[i].a);
        scanf("%d",&n2);
        rep(i,0,n2) scanf("%d %lf",&poly2[i].exp,&poly2[i].a);
        int id=1;ms(vis,0);
        rep(i,0,n1){
            rep(j,0,n2){
              int exp=poly1[i].exp+poly2[j].exp;
              double a=poly1[i].a*poly2[j].a;
              if(a==0) continue;
              if(vis[exp]) ans[vis[exp]].a+=a;//这里可能也等于0
              else vis[exp]=id,ans[id].a=a,ans[id++].exp=exp;
            }
        }
        sort(ans+1,ans+id);
        int tot=0;
	    rep(i,1,id) if(ans[i].a!=0) ++tot;
	    printf("%d",tot);

	    rep(i,1,id)
		if(ans[i].a!=0){
	      printf(" %d %.1lf",ans[i].exp,ans[i].a);
		}
        puts("");
    }
return 0;
}
