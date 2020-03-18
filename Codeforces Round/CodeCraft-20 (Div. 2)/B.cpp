#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=1e6+5,inf=1e9+5;
typedef long long LL;
#define cp complex<double>
int read(){
    int k=0;
    char f=1;
    char c=getchar();
    while(c>'9'||c<'0')
        if(c=='-')
        {
            f=-1;
            c=getchar();
        }
    while(c<='9'&&c>='0')
    {
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}

const double pi=acos(-1);
int a[N],b[N],c[2*N],p;
struct FastFourierTransform {
	int n,rev[2097253];
	cp omega[2097253],iomega[2097253];

	void init(int n) {
		this->n=n;
		for(int i=0; i<n; i++) {
			omega[i]=cp(cos(2*pi/n*i),sin(2*pi/n*i));
			iomega[i]=conj(omega[i]); //共轭复数
		}
		int k=log2(n);
		for(int i=0; i<n; i++) { //二进制位翻转
			int t=0;
			for(int j=0; j<k; j++)if(i&(1<<j))t|=(1<<(k-j-1));
			rev[i]=t;
		}
	}

	void transform(cp* a,cp* omega) {
		for(int i=0; i<n; i++)if(i<rev[i])swap(a[i],a[rev[i]]); //避免翻转两次
		for(int len=2; len<=n; len*=2) {
			int mid=len>>1;
			for(cp* p=a; p!=a+n; p+=len)
				for(int i=0; i<mid; i++) {
					cp t=omega[n/len*i]*p[mid+i];
					p[mid+i]=p[i]-t;
					p[i]+=t;
				}
		}
	}

	void dft(cp* a) {
		transform(a,omega);
	}

	void idft(cp* a) {
		transform(a,iomega);
	for(int i=0; i<n; i++)a[i]=cp(a[i].real()/(n<<2),a[i].imag()/n);
	}
} fft;

void Multiply(const int* a1,const int n1,const int* a2,const int n2,int* ans){
	int n=1;
	while(n<n1+n2)n<<=1; //化成整数
	//static cp c1[2097253],c2[2097253];
	static cp c[2097253];
	int x=max(n1,n2);
	for(int i=0; i<max(n1,n2); i++)
        c[i].real(a1[i]+a2[i],a1[i]-a2[i]);
	fft.init(n);
	fft.dft(c);
	for(int i=0; i<n; i++)c[i]*=c[i];
	fft.idft(c);
	for(int i=0; i<n1+n2-1; i++)ans[i]=round(c[i].real());
	//for(int i=0; i<n1+n2-1; i++) printf("%d ",ans[i]);
	for(int i=0; i<n1+n2-1; i++){
        if(ans[i]%p!=0) {printf("%d\n",i);return;}

	}
}
int main(){
    //int d=1,x=99999,x2=1e6;
	//while(d<x+x2)d<<=1;
	//cout<<d<<endl;
    int n,m;
    n=read();m=read();p=read();
    for (int i=0;i<n;i++) a[i]=read();
    for (int i=0;i<m;i++) b[i]=read();
    Multiply(a,n,b,m,c);
return 0;
}
