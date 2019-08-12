#include <bits/stdc++.h>
using namespace std;
int num[12],dp[12][12];
int dfs(int pos,int now,int limit)
{
    if(pos==-1)
        return now;
    int &ans=dp[pos][now];
    if(!limit&&ans!=-1)
        return ans;
    ans=0;
    int up=limit?num[pos]:9;
    for(int i=0; i<=up; i++)
    {
        ans+=dfs(pos-1,i==1?now+1:now,limit&&i==up);
    }
    return ans;
}
int solve(int x)
{
    int cnt=0;
    while(x)
    {
        num[cnt++]=x%10;
        x/=10;
    }
    return dfs(cnt-1,0,1);
}
int main()
{
    int n;
    cout<<(1<<30)<<endl;
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(n));
    return 0;
}
