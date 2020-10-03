#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<map>
#include<bitset>
#include<list>
//#include<unordered_map>
#ifdef LOCAL
#include<ctime>
#include<windows.h>
#include<random>
#include"file.h"
#define __int128 LL
#endif

#define y1 zyy_orz
#define hash sto_zyy

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL>pLL;
typedef pair<int, int>pii;
const double eps = 1e-10;
const double Pi = 3.1415926535897932;
const int dir[4][2] = { -1,0,0,-1,1,0,0,1 };
//const int dir[8][2] = { -1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1 };
//const int dir[8][2] = { -2,-1,-2,1,2,-1,2,1,-1,2,-1,-2,1,2,1,-2 };


const int maxn = 2e5 + 5;
struct node {
	int b, w;
	bool operator<(const node& oth)const {
		return w < oth.w;
	}
};


int n, m, K;
vector<node>G[maxn];
vector<int>deg[maxn];
bitset<maxn>vis[55];

bool flag[55];

bool mutex[55][55];

int now[15];

int ans = 0;

inline int id(int a, int b) {
	return a * (a - 1) / 2 + b;
}

void dfs(int a) {
	if (a == K + 1) {
		ans++;
		return;
	}
	for (int aa = 1; aa <= a; aa++) {
		int aid = id(a, aa);
		if (flag[aid])continue;
		bool ok = true;
		for (int b = 1; b < a && ok; b++) {
			int bid = id(b, now[b]);
			if (mutex[aid][bid]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			now[a] = aa;
			dfs(a + 1);
		}
	}

}

int main() {
#ifdef LOCAL
	fileopen();
#endif
 cout<<(~(3))<<endl;
    cout<<(~(-3))<<endl;
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= m; i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		G[a].push_back(node{ b,w });
	}

	for (int i = 1; i <= n; i++) {
		deg[G[i].size()].push_back(i);
		sort(G[i].begin(), G[i].end());
	}

	for (int i = 1; i <= K; i++) {
		for (int ii = 1; ii <= i; ii++) {
			int p = id(i, ii);
			for (int a : deg[i]) {
				if (vis[p][G[a][ii - 1].b] == true) {
					flag[p] = true;
					break;
				}
				vis[p][G[a][ii-1].b] = true;
			}
		}
	}

	for (int i = 1; i <= K; i++) {
		for (int ii = 1; ii <= i; ii++) {
			int a = id(i, ii);
			for (int j = i + 1; j <= K; j++) {
				for (int jj = 1; jj <= j; jj++) {
					int b = id(j, jj);
					if ((vis[a] & vis[b]).any())
						mutex[a][b] = mutex[b][a] = true;
				}
			}
		}
	}


	dfs(1);
	printf("%d\n", ans);

#ifdef LOCAL
	fileclose();
#endif
	return 0;
}
