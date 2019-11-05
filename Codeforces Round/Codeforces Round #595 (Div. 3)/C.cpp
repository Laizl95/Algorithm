#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5;
typedef long long LL;

int main(){
    //freopen("D:\\input.txt","r",stdin);
    int t;LL a;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&a);
        LL n=a;
        vector<int> bit;
        while(a){
            bit.pb(a%3);
            a/=3;
        }
        int pos=-1;
        //rep(i,0,bit.size()) printf("%d",bit[i]);puts("");
        per(i,0,bit.size()){
           if(bit[i]==2){pos=i;break;}
        }
        if(pos==-1){cout<<n<<endl;}
        else{
            int p=-1;
            rep(i,pos+1,bit.size()) if(bit[i]==0) {p=i;bit[i]=1;break;}
            if(p==-1) p=bit.size(),bit.pb(1);
            rep(i,0,p) bit[i]=0;

            LL m=1,ans=0;
            rep(i,0,bit.size()){
                if(bit[i]==2) bit[i]=0;
                ans+=m*bit[i];
                m*=3;
            }
        cout<<ans<<endl;
        }
    }
return 0;
}
