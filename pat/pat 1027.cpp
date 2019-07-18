#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=105;
void solve(int x){
   int ans[2]={0},id=0;
   while(x){
     ans[id++]=x%13;
     x/=13;
   }
   per(i,0,2)
    if(ans[i]>=10) printf("%c",'A'+ans[i]-10);
    else printf("%d",ans[i]);
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("#");
    solve(a);solve(b);solve(c);
    puts("");
return 0;
}
