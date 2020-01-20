#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
typedef long long LL;
struct node{
    int id,x;
    node(){}
    node(int _id,int _x){id=_id;x=_x;}
}a[N];
int cmp(node &a,node &b){
    return a.x>b.x || (a.x==b.x && a.id<b.id);
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        rep(i,0,n) scanf("%d",&a[i].x),a[i].id=i+1;
        sort(a,a+n,cmp);
        int ans=0;
        rep(i,0,n) ans+=i*a[i].x+1;
        printf("%d\n",ans);
        rep(i,0,n) printf("%d ",a[i].id); puts("");
    }
return 0;
}
