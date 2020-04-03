#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m = -1000, e; vector<int> v;
int main()
{
	cin >> n;
	vector<int> dp(n);
	for (int i = 0; i < n; i++) { cin >> e; v.push_back(e); }
	for (int i = 0; i < n; i++) {
		if (!i) { dp[i] = v[i]; continue; }
		if (v[i] + dp[i - 1] < v[i]) dp[i] = v[i];
		else dp[i] = v[i] + dp[i - 1];
	}
	for (int i = 0; i < n; i++) m = max(m, dp[i]);
	cout << m << "\n";
	return 0;

}