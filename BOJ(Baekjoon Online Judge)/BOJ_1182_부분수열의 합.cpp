#include <cstdio>
#include <vector>
using namespace std;
int n, s, b, cnt; vector<int> a, v;
void comb(int idx, int n, int r)
{
	if (!r) {
		int sum = 0; for (int i = 0; i < v.size(); i++) sum += v.at(i);
		if (s == sum) cnt += 1;
		return;
	}
	for (int i = idx; i < a.size(); i++) {
		v.push_back(a.at(i)); comb(i + 1, n, r - 1); v.pop_back();
	}
}
int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b); a.push_back(b);
	}
	for (int i = 1; i <= n; i++)
		comb(0, n, i);
	printf("%d\n", cnt);
	return 0;

}