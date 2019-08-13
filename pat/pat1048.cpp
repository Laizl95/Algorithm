#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=100005;
int a[N];
int main(){
    int n,v;
    while(scanf("%d %d",&n,&v)!=EOF){
        rep(i,0,n) scanf("%d",&a[i]);
        sort(a,a+n);
        int p1=0,p2=n-1;
        while(p1<p2){
            if(a[p1]+a[p2]>v) p2-=1;
            else if(a[p1]+a[p2]<v) p1+=1;
            else{
                printf("%d %d\n",a[p1],a[p2]);
                break;
            }
        }
        if(p1>=p2) printf("No Solution\n");
    }
return 0;
}
