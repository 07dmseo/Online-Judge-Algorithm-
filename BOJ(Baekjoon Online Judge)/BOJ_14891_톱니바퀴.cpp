#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
vector<vector<int>> v, r; int t, c, m, cnt, idx; bool visited[4];
void r_rotate(int n)
{
	int temp = v[n][7];
	for (int i = 7; i > 0; i--) v[n][i] = v[n][i - 1];
	v[n][0] = temp;
}
void l_rotate(int n)
{
	int temp = v[n][0];
	for (int i = 0; i < 7; i++) v[n][i] = v[n][i + 1];
	v[n][7] = temp;
}
void rotate(int n, int d)
{
	if (n < 0 || n > 3) return; visited[n] = true;
	int d1; if (d == 1) d1 = -1; else d1 = 1;

	if (n < 3 && v[n][2] != v[n + 1][6] && !visited[n + 1]) rotate(n + 1, d1);
	if (n > 0 && v[n][6] != v[n - 1][2] && !visited[n - 1]) rotate(n - 1, d1);

	if (d == 1) r_rotate(n);
	else l_rotate(n);

}
int main()
{
	for (int i = 0; i < 4; i++) {
		string str; cin >> str; vector<int> temp;
		for (int j = 0; j < 8; j++) temp.push_back((int)(str[j] - '0'));
		v.push_back(temp);
	}
	cin >> cnt;
	for (int i = 0; i < cnt; i++) { cin >> t >> c; r.push_back({ t - 1, c }); }
	for (int i = 0; i < r.size(); i++) {
		memset(visited, false, sizeof(visited)); rotate(r[i][0], r[i][1]);
	}
	for (int i = 0; i < 4; i++) if (v[i][0]) m += pow(2, i);
	cout << m << endl;
	return 0;

}