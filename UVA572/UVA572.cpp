#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <bitset>
#include <cassert>
using namespace std;

const int maxn = 105;

char pic[maxn][maxn];
int m, n, idx[maxn][maxn];

void dfs(int i, int j, int cnt)
{
	if (i < 0 || i >= m || j < 0 || j >= n)
		return;
	if (idx[i][j] > 0 || pic[i][j] != '@')
		return;
	idx[i][j] = cnt;
	for (int dr = -1; dr <= 1; dr++)
		for (int dc = -1; dc <= 1; dc++)
			if (!(dr == 0 && dc == 0))
				dfs(i + dr, j + dc, cnt);
}

int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	while (scanf("%d%d", &m, &n) == 2 && m && n)
	{
		for (int i = 0; i < m; i++)
			scanf("%s", pic[i]);
		memset(idx, 0, sizeof(idx));
		int cnt = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (idx[i][j] == 0 && pic[i][j] == '@')
				{
					dfs(i, j, ++cnt);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}