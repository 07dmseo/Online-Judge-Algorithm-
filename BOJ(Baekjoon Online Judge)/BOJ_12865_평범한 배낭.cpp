#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct { int w, v; }item; bool comp(item a, item b) { return a.w < b.w; }
int n, k, m, w, v, d[101][100001]; vector<item> v_item;
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) { cin >> w >> v; v_item.push_back({ w, v }); }
	sort(v_item.begin(), v_item.end(), comp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			item curr_item = v_item.at(i - 1);
			if (curr_item.w <= j) d[i][j] = max(d[i - 1][j], d[i - 1][j - curr_item.w] + curr_item.v);
			else d[i][j] = d[i - 1][j];
		}
	}
	for (int i = 2; i <= n; i++) m = max(d[i][k], d[i - 1][k]);
	cout << m << endl;
	return 0;

}