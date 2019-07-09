#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;

int is_prime(int num){
  if(num<2) return 0;
  for(int i=2;i*i<=num;++i)
     if(num%i==0) return 0;
  return 1;
}
int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF && n>0){
            scanf("%d",&m);
        int rev_n=0,x=n;
        while(x){
            rev_n=rev_n*m+x%m;
            x/=m;
        }
        if(is_prime(n)&& is_prime(rev_n)) puts("Yes");
        else puts("No");
    }
return 0;
}
