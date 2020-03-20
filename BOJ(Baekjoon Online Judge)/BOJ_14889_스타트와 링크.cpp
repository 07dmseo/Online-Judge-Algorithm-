#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ans = 1000000, n, table[21][21]; bool visited[21]; vector<int> v;
void combination(int n, int r, int idx)
{
	if (!r) {
		vector<int> cmp; int teamA = 0, teamB = 0;
		for (int i = 1; i <= n; i++) if (!visited[i]) cmp.push_back(i);
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				if (v[i] == v[j]) continue;
				else teamB += table[v[i]][v[j]];
			}
		}
		for (int i = 0; i < cmp.size(); i++) {
			for (int j = 0; j < cmp.size(); j++) {
				if (cmp[i] == cmp[j]) continue;
				else teamA += table[cmp[i]][cmp[j]];
			}
		}

		ans = min(ans, abs(teamA - teamB)); return;
	}
	for (int i = idx; i <= n; i++) {
		if (visited[i]) continue;
		else {
			visited[i] = true; v.push_back(i);
			combination(n, r - 1, i + 1);
			visited[i] = false; v.pop_back();
		}
	}
}
int main()
{
	cin >> n;
	for (int y = 1; y <= n; y++) for (int x = 1; x <= n; x++) cin >> table[y][x];
	combination(n, n / 2, 1);
	cout << ans << "\n";
	return 0;
}