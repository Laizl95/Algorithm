#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define mc(x,y) memcpy(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e4+5,MAXN=3,l=2,mod=10;
typedef long long LL;
struct node{
    int id,x;
    node(){}
    node(int _id,int _x):id(_id),x(_x){}
    bool operator < (const node &a) const{
        return x<a.x || (x==a.x && id<a.id);
    }
}a[N];

int main(){
    int t,s,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&s,&n);
        int id=1,x;
        rep(i,0,n){
            scanf("%d",&x);
            a[i]=node(i,x);
        }
        sort(a,a+n);
        int l=0,r=n-1,_l=-1,_r=-1,a1=0,a2=0;
        while(l<r){
            int sum=a[l].x+a[r].x;
            if(sum<s) l+=1;
            else if(sum>s) r-=1;
            else{
               if(_l==-1 || max(a[l].id,a[r].id)<_r || (max(a[l].id,a[r].id)==_r &&
                  min(a[l].id,a[r].id)<_l)) _l=min(a[l].id,a[r].id),_r=max(a[l].id,a[r].id),a1=a[l].x,a2=a[r].x;
                  r-=1;
                // printf("%d %d\n",a[l].x,a[r].x);break;
            }
        }
        if(_l==-1) puts("!OK");
        else printf("%d %d\n",a1,a2);
    }
return 0;
}
