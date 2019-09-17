#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=200005;
char s1[N],s2[N];
int v1[N],v2[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s %s",s1,s2);
        int tot1=0,tot2=0;
        rep(i,0,n)
        if(s1[i]=='a' && s2[i]=='b'){
            v1[++tot1]=i+1;
        }
        else if(s1[i]=='b' && s2[i]=='a'){
            v2[++tot2]=i+1;
        }
        if((tot1+tot2)&1) printf("-1\n");
        else{
            printf("%d\n",(tot1+tot2)/2+tot1%2);
            for(int i=1;i<tot1;i+=2)
                printf("%d %d\n",v1[i],v1[i+1]);
            for(int i=1;i<tot2;i+=2)
                printf("%d %d\n",v2[i],v2[i+1]);
            if(tot1&1){
               printf("%d %d\n",v1[tot1],v1[tot1]);
               printf("%d %d\n",v1[tot1],v2[tot2]);
            }
        }
    }
return 0;
}
