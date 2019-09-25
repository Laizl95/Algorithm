#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 15;
typedef long long ll;
struct node {
    int x, y;
} p[7];
int ranks[maxn], d;
bool vis[105][105];
int get_pos(int x) {
    //从数组的begin位置到end-1位置二分查找第一个
    //大于或等于num的数字，找到返回该数字的地址
    return lower_bound(ranks + 1, ranks + 1 + d, x) - ranks;
}
int main() {
    for(int i = 1; i <= 6; i++) {
        cin >> p[i].x >> p[i].y;
        ranks[++d] = p[i].x;
        ranks[++d] = p[i].y;
    }
    sort(ranks + 1, ranks + 1 + d);
    d = unique(ranks + 1, ranks + 1 + d) - (ranks + 1);
    for(int i = 1; i <= 6; i++) {
        p[i].x = get_pos(p[i].x);
        p[i].y = get_pos(p[i].y);
    }
    for(int i = p[3].x; i < p[4].x; i++) {
        for(int j = p[3].y; j < p[4].y; j++)
            vis[i][j] = 1;
    }
    for(int i = p[5].x; i < p[6].x; i++) {
        for(int j = p[5].y; j < p[6].y; j++)
            vis[i][j] = 1;
    }
    int cnt = 0;
    for(int i = p[1].x; i < p[2].x; i++) {
        for(int j = p[1].y; j < p[2].y; j++)
            if(vis[i][j] == 0) {
                cout << "YES" << endl;
                return 0;
            }
    }
    cout << "NO" << endl;
    return 0;
}
