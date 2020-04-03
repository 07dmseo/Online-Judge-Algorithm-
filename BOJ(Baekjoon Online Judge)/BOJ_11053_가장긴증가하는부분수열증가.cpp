#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, e; vector<int> v;
int main()
{
	cin >> n; 
	vector<int> dp(n);
	for (int i = 0; i < n; i++) { cin >> e; v.push_back(e); }
	for (int i = 0; i < n; i++) {
		dp[i] = 1; int mvalue = 0;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) mvalue = max(mvalue, dp[j]);
		}
		dp[i] += mvalue;
	}
	for (int i = 0; i < n; i++) m = max(m, dp[i]);
	cout << m << "\n";
	return 0;

}