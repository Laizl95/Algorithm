#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
int a[N],b[N];
void build(int l,int r,int id){
    if(l>r) return;
    int num=r-l+1,l_sum=0,t=1;
    while(num-t>=0){
        num-=t;
        l_sum+=t/2;
        t<<=1;
    }
    if(num<=t/2) l_sum+=num;
    else l_sum+=t/2;
    b[id]=a[l+l_sum];
    build(l,l+l_sum-1,id*2);
    build(l+l_sum+1,r,id*2+1);
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        rep(i,0,n) scanf("%d",&a[i]);
        sort(a,a+n);
        build(0,n-1,1);
        rep(i,1,n+1)
            if(i==1) printf("%d",b[i]);
            else printf(" %d",b[i]);
        puts("");
    }
return 0;
}
