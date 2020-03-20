#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a; bool visited[9]; vector<int> v;
void comb(int idx, int n, int r)
{
	if (r == 0) {
		for (int i = 0; i < n; i++) if (visited[i]) cout << v.at(i) << " ";
		cout << endl; return;
	}
	for (int i = idx; i < n; i++) {
		visited[i] = true;
		comb(i + 1, n, r - 1);
		visited[i] = false;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a; v.push_back(a);
		sort(v.begin(), v.end());
	}
	comb(0, n, m);
	return 0;
}