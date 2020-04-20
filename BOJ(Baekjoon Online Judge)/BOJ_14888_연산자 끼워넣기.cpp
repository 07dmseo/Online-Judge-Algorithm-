/* 재귀를 활용한 dfs 방법 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, s = 1000000000, l = -1000000000, operation[4]; vector<int> num;
int do_operation(int res, int next, int arithmetic)
{
	switch (arithmetic) {
	case 0: return res + next;
	case 1: return res - next;
	case 2: return res * next;
	case 3: return res / next;
	}
}

void dfs(int res, int r)
{
	if (r == n - 1) { s = min(s, res); l = max(l, res); return; }
	for (int i = 0; i < 4; i++) {
		if (!operation[i]) continue;
		else {
			operation[i]--;
			dfs(do_operation(res, num[r + 1], i), r + 1);
			operation[i]++;
		}
	}
}

int main()
{
	cin >> n; for (int i = 0; i < n; i++) { cin >> a; num.push_back(a); }
	for (int i = 0; i < 4; i++) cin >> operation[i]; dfs(num[0], 0);
	cout << l << "\n" << s << endl;
	return 0;
}

/* 라이브러리를 활용한 순열 방법 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, a, s = 1000000000, l = -1000000000; vector<int> num, opt;
int do_operation(int res, int next, int arithmetic)
{
	switch (arithmetic) {
	case 0: return res + next;
	case 1: return res - next;
	case 2: return res * next;
	case 3: return res / next;
	}
}

int main()
{
	cin >> n; for (int i = 0; i < n; i++) { cin >> a; num.push_back(a); }
	for (int i = 0; i < 4; i++) {
		cin >> a; while (a) { opt.push_back(i); a--; }
	}
	sort(opt.begin(), opt.end());
	do {
		int ans = num[0];
		for (int i = 0; i < opt.size(); i++) ans = do_operation(ans, num[i + 1], opt[i]);
		l = max(l, ans); s = min(s, ans);

	} while (next_permutation(opt.begin(), opt.end()));
	cout << l << "\n" << s << endl;
	return 0;

}