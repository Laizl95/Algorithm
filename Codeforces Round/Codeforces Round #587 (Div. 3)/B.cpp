#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
struct mats {
    mats(){}
    mats(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height)
    {}
    int x;          //矩形左上角x坐标
    int y;          //矩形左上角y坐标
    int width;      //矩形宽度
    int height;     //矩形高度
}mat[3];
bool isOverlap(const mats &rc1, const mats &rc2){
    if (rc1.x + rc1.width  >= rc2.x &&
        rc2.x + rc2.width  >= rc1.x &&
        rc1.y + rc1.height >= rc2.y &&
        rc2.y + rc2.height >= rc1.y
       )
        return true;
        return false;
}

int x[6],y[6];
int main(){
    int n;
    while(scanf("%d %d %d %d",&x[0],&y[0],&x[1],&y[1])!=EOF){

        rep(i,2,6) scanf("%d %d",&x[i],&y[i]);
        for(int i=0;i<6;i+=2) mat[i]=mats(x[i],y[i+1],x[i+1]-x[i],y[i+1]-y[i]);
        if(isOverlap(mat[0],mat[1]) || (isOverlap(mat[0],mat[2])) ) puts("YES");
        else puts("NO");

    }
return 0;
}
