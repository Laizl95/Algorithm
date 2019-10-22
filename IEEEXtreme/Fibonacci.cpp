#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define mc(x,y) memcpy(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=3*1e5+5,MAXN=3,l=2,mod=10;
typedef long long LL;
int n,m;
int a[N];
struct matrix{
    int v[MAXN][MAXN];
    void O(){ms(v, 0);}
    void E(){ms(v, 0);rep(i,1,l+1) v[i][i]=1;}
     inline matrix operator +(const matrix &p){
        matrix ret;
        rep(i,1,l+1) rep(j,1,l+1){
            ret.v[i][j]=v[i][j]+p.v[i][j];
            if(ret.v[i][j]>=mod)
             ret.v[i][j]-=mod;
        }
        return ret;
    }
    inline matrix operator *(const matrix &b){
        matrix c;
        c.O();
        rep(k,1,l+1)rep(i,1,l+1)rep(j,1,l+1){
        c.v[i][j]=(c.v[i][j]+v[i][k]*b.v[k][j]%mod)%mod;
        }
        return c;
    }
   inline matrix operator ^(int p){
        matrix x, y;
        x.E();
        mc(y.v,v);
        while(p){
            if(p&1) x=x*y;
            p>>=1;
            y=y*y;
        }
        return x;
    }
};
int main(){
    int t;
    matrix a,b;

    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d",&k);
        a.v[1][1]=1;a.v[1][2]=1;a.v[2][1]=1;a.v[2][2]=0;
        b.v[1][1]=3;b.v[1][2]=2;b.v[2][1]=2;b.v[2][2]=1;
        if(k<=3){cout<<k<<endl;continue;}
        a=a^(k-3);
        a=b*a;
        cout<<a.v[1][1]<<endl;
    }
return 0;
}
