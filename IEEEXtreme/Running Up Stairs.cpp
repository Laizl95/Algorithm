#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define mc(x,y) memcpy(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int maxn=1e5+5;
typedef long long LL;
#define M 36
#define N 1001
#define DLEN 4
/* 注意输出的时候格式控制长度应该同DLEN一致 */
/* N用于控制位数、DLEN为压位长度、M对应DLEN个9 */

class BigNum
{
private:
    int len;
    int a[N];
public:
    BigNum(){len=1;memset(a,0,sizeof(a));} //构造函数
    BigNum(const int&);      //将int转化成大数
    BigNum(const char*);     //将char*转化为大数
    BigNum(const BigNum &);  //大数拷贝构造函数

    friend istream& operator >> (istream&,BigNum&); //重载输入运算符
    friend ostream& operator << (ostream&,BigNum&); //重载输出运算符

    BigNum operator + (const BigNum &)const; //加法，两个大数相加
    BigNum operator - (const BigNum &)const; //减法，两个大数相减
    BigNum operator * (const BigNum &)const; //乘法，两个大数相乘
    BigNum operator / (const int &)const;    //除法，大数除以int
    BigNum operator ^ (const int &)const;    //求幂，大数的n次方
    BigNum &operator= (const BigNum &);      //赋值，大数之间赋值
    int operator % (const int &)const;    //取模，大数对int取模
    int operator > (const BigNum &)const; //比较，两个大数比较
};
BigNum::BigNum(const int &b)
{
    int c,d=b;
    len=0;
    memset(a,0,sizeof(a));
    while(d>M)
    {
        c=d-(d/(M+1))*(M+1);
        d=d/(M+1);
        a[len++]=c;
    }
    a[len++]=d;
}
BigNum::BigNum(const char *s)
{
    memset(a,0,sizeof(a));
    int Index=0;
    int L=strlen(s);
    len=L%DLEN?L/DLEN+1:L/DLEN;
    for(int i=L-1;i>=0;i-=DLEN)
    {
        int t=0;
        int k=i-DLEN+1;
        if(k<0) k=0;
        for(int j=k;j<=i;j++) t=t*10+s[j]-'0';
        a[Index++]=t;
    }
}
BigNum::BigNum(const BigNum &T)
{
    len=T.len;
    memset(a,0,sizeof(a));
    for(int i=0;i<len;i++) a[i]=T.a[i];
}
BigNum & BigNum::operator = (const BigNum &n)
{
    len=n.len;
    memset(a,0,sizeof(a));
    for(int i=0;i<len;i++) a[i]=n.a[i];
    return *this;
}
istream& operator >> (istream &cin,BigNum &b)
{
    char ch[N*DLEN];
    cin>>ch;
    //Trim(ch);
    int cnt=0;
    int L=strlen(ch);
    for(int i=L-1;i>=0;)
    {
        int sum=0,t=1;
        for(int j=0;j<DLEN && i>=0;j++,i--,t*=10) sum+=(ch[i]-'0')*t;
        b.a[cnt]=sum;
        cnt++;
    }
    b.len=cnt++;
    return cin;
}
ostream& operator << (ostream& cout,BigNum& b)
{
    cout<<b.a[b.len-1];
    for(int i=b.len-2;i>=0;i--) printf("%04d",b.a[i]);
    return cout;
}
BigNum BigNum::operator + (const BigNum &T)const
{
    BigNum t(*this);
    int big=T.len>len?T.len:len;
    for(int i=0;i<big;i++)
    {
        t.a[i]+=T.a[i];
        if(t.a[i]>M)
        {
            t.a[i+1]++;
            t.a[i]-=M+1;
        }
    }
    t.len=t.a[big]?big+1:big;
    return t;
}
BigNum BigNum::operator - (const BigNum &T)const
{
    bool flag=*this>T==1?0:1;
    BigNum t1=*this>T==1?*this:T;
    BigNum t2=T>*this==1?*this:T;
    int big=t1.len;
    for(int i=0;i<big;i++)
    {
        if(t1.a[i]<t2.a[i])
        {
            int j=i+1;
            while(t1.a[j]==0) j++;
            t1.a[j--]--;
            while(j>i) t1.a[j--]+=M;
            t1.a[i]+=M+1-t2.a[i];
        }
        else t1.a[i]-=t2.a[i];
    }
    t1.len=big;
    while(t1.a[len-1]==0 && t1.len>1) t1.len--,big--;
    if(flag) t1.a[big-1]=0-t1.a[big-1];
    return t1;
}
BigNum BigNum::operator * (const BigNum &T)const
{
    BigNum ret;
    int i,j;
    int tmp1,tmp2;
    for(i=0;i<len;i++)
    {
        int up=0;
        for(j=0;j<T.len;j++)
        {
            tmp1=a[i]*T.a[j]+ret.a[i+j]+up;
            if(tmp1>M)
            {
                tmp2=tmp1-tmp1/(M+1)*(M+1);
                up=tmp1/(M+1);
                ret.a[i+j]=tmp2;
            }
            else
            {
                up=0;
                ret.a[i+j]=tmp1;
            }
        }
        if(up) ret.a[i+j]=up;
    }
    ret.len=i+j;
    while(!ret.a[ret.len-1] && ret.len>1) ret.len--;
    return ret;
}
BigNum BigNum::operator / (const int &b)const
{
    BigNum ret;
    int down=0;
    for(int i=len-1;i>=0;i--)
    {
        ret.a[i]=(a[i]+down*(M+1))/b;
        down=a[i]+down*(M+1)-ret.a[i]*b;
    }
    ret.len=len;
    while(ret.a[ret.len-1]==0 && ret.len>1) ret.len--;
    return ret;
}
int BigNum::operator % (const int &b)const
{
    int d=0;
    for(int i=len-1;i>=0;i--) d=((d*(M+1))%b+a[i])%b;
    return d;
}
BigNum BigNum::operator ^ (const int &n)const
{
    int i;
    BigNum t,ret(1);
    if(n<0) exit(-1);
    if(n==0) return 1;
    if(n==1) return *this;
    int m=n;
    while(m>1)
    {
        t=*this;
        for(i=1;(i<<1)<=m;i<<=1) t=t*t;
        m-=i;
        ret=ret*t;
        if(m==1) ret=ret*(*this);
    }
    return ret;
}
int BigNum::operator > (const BigNum &T)const
{
    if(len>T.len) return 1;
    if(len==T.len)
    {
        int ln=len-1;
        while(a[ln]==T.a[ln] && ln>=0) ln--;
        if(ln>=0 && a[ln]>T.a[ln]) return 1;
        else if(ln<0) return 0;
        return -1;
    }
    return -1;
}
void Trim(char *s) //去掉前导0
{
    int i,len=strlen(s);
    for(i=0;i<len;i++) if(s[i]!='0') break;
    i==len?strcpy(s,"0"):strcpy(s,s+i);
}
BigNum dp[maxn];
int main(){
    int t;
    dp[1]=1;dp[2]=2;
   rep(i,3,22005) dp[i]=dp[i-1]+dp[i-2];
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        cout<<dp[x]<<endl;
    }
return 0;
}
