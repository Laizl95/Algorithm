#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
char x[N];
LL dp[N*4][2];
void pushup(int sign) {
    dp[sign][1] = min(dp[sign << 1][1], dp[sign << 1 | 1][1]);
    dp[sign][0] = min(dp[sign << 1][0], dp[sign << 1 | 1][0]);
}
void build(int sign, int l, int r) {
    if(l == r) {
        dp[sign][0] = dp[sign][1] = INF;
        if(l == 0) {
            dp[sign][0] = 0;
        }
        return ;
    }
    int mid = (l + r) >> 1;
    build(sign << 1, l, mid);
    build(sign << 1 | 1, mid + 1, r);
    pushup(sign);
}
ll query(int sign, int l, int r, int a, int b, int flag) {
    if(l == a && r == b) {
        return dp[sign][flag];
    }
    int mid = (l + r) >> 1;
    if(b <= mid)
        return query(sign << 1, l, mid, a, b, flag);
    else if(a > mid)
        return query(sign << 1 | 1, mid + 1, r, a, b, flag);
    else {
        return min(query(sign << 1, l, mid, a, mid, flag), query(sign << 1 | 1, mid + 1, r, mid + 1, b, flag));
    }
}
void update(int sign, int l, int r, int pos, ll x, int flag) {
    if(l == r) {
        dp[sign][flag] = min(dp[sign][flag], x);
        return ;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid)
        update(sign << 1, l, mid, pos, x, flag);
    else
        update(sign << 1 | 1, mid + 1, r, pos, x, flag);
    pushup(sign);
}
int main() {
    int n, k;
    memset(dp, 0x3f, sizeof(dp));
    cin >> n >> k;
    cin >> x + 1;
    build(1, 0, n);
    for(int i = 1; i <= n; i++) {
        ll zero = query(1, 0, n, i - 1, i - 1, 0) + i;
        zero = min(zero, query(1, 0, n, max(0, i - k), i - 1, 1));
        /*
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + i);
            for(int j = max(0, i - k); j < i; j++)
            dp[i][0] = min(dp[i][0], dp[j][1]);

        */
        update(1, 0, n, i,  zero, 0);
        if(x[i] == '1') {
            ll one = INF;
            one = query(1, 0, n, max(0, i - k - 1), i - 1, 1);
            one = min(one, query(1, 0, n, max(0, i - k - 1), i - 1, 0));
            one += i;
            update(1, 0, n, i, one, 1);
            /*
                for(int j = max(0, i - k - 1); j < i; j++) {
                dp[i][1] = min(dp[j][0] + i, dp[i][1]);
                dp[i][1] = min(dp[j][1] + i, dp[i][1]);
                }
            */
        }
    }
    cout << min(query(1, 0, n, n, n, 0), query(1, 0, n, n, n, 1)) << endl;
    return 0;
}
