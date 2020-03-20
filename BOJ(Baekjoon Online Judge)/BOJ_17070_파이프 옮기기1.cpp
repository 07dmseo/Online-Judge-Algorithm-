#include <iostream>
using namespace std;
int n, ans, v[17][17];
void dfs(int x, int y, int d)
{
	int right = v[y][x + 1], down = v[y + 1][x], dia = right + down + v[y + 1][x + 1];
	if (x == n && y == n) { ans++; return; }
	else if (x > n || y > n) return;
	else if (d == 1) { if (!right) dfs(x + 1, y, 1); if (!dia) dfs(x + 1, y + 1, 3); }
	else if (d == 2) { if (!down) dfs(x, y + 1, 2); if (!dia) dfs(x + 1, y + 1, 3); }
	else if (d == 3) { 
		if (!right) dfs(x + 1, y, 1); if (!down) dfs(x, y + 1, 2); if (!dia) dfs(x + 1, y + 1, 3);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> v[i][j];
	dfs(2, 1, 1);
	cout << ans << endl;
	return 0;

}