#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;

int main(){
 double a[3][3];
 while(scanf("%lf %lf %lf",&a[0][0],&a[0][1],&a[0][2])!=EOF){
    rep(i,1,3) rep(j,0,3) scanf("%lf",&a[i][j]);
    double ans=1;
    rep(i,0,3){
        double max_a=0;int id;
        rep(j,0,3) if(a[i][j]>max_a) max_a=a[i][j],id=j;
        ans*=a[i][id];
        if(id==0) printf("W ");
        else if(id==1) printf("T ");
        else if(id==2) printf("L ");
    }
    printf("%.2lf\n",(ans*0.65-1)*2);
 }
return 0;
}
