#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=10005;
int a[N];
struct node{
 int l,r,sum;
}b[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        rep(i,0,n) scanf("%d",&a[i]);
        int head=0,now=0;
        while(head<n)
          if(a[head]<0){
                int sum=0,l=head,r=head;
           while(head<n && a[head]<0){
              sum+=a[head];
              r=head;
              head+=1;
           }
           b[now].l=l;b[now].r=r;b[now++].sum=sum;
           }
          else if(a[head]>0){
            int sum=0,l=head,r=head;
           while(head<n && a[head]>0){
              sum+=a[head];
              r=head;
              head+=1;
           }
           b[now].l=l;b[now].r=r;b[now++].sum=sum;
          }else{
           b[now].l=head;b[now].r=head;b[now++].sum=0;head+=1;
          }
      // rep(i,0,now) printf("%d ",b[i].sum); puts("");
       int l=b[0].l,r=b[0].r,sum=0,
       max_sum=-1,max_l=b[0].l,max_r=b[now-1].r;
       rep(i,0,now){
          sum+=b[i].sum;
          if(l==-1) l=b[i].l;
          r=b[i].r;
          if(sum<0) sum=0,l=r=-1;
          else if(max_sum<sum) max_sum=sum,max_l=l,max_r=r;

       }
        if(max_sum>=0) printf("%d %d %d",max_sum,a[max_l],a[max_r]);
        else printf("%d %d %d",0,a[0],a[n-1]);
    }
return 0;
}
