#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
int n,p;
int main(){

    while(scanf("%d %d",&n,&p)!=EOF){
            int k=1,ok=1;
        while(1){
            LL sum=n*1LL-p*1LL*k;

            int tot=k;
            if(sum<=0){ok=0;break;}
            while(sum){
                if(sum%2) tot-=1;
                sum/=2;
             }
             if(tot>=0){
                cout<<k<<endl;
                break;
             }
             k+=1;
        }
        if(!ok) puts("-1");
    }
return 0;
}
