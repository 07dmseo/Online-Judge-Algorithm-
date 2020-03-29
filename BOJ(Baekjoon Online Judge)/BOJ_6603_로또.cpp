/* 재귀를 이용한 조합 구하기 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int k, input; vector<int> s, ans;
void comb(int n, int r, int idx)
{
	if (!r) {
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		cout << "\n"; return;
	}
	for (int i = idx; i < n; i++) { ans.push_back(s[i]); comb(n, r - 1, i + 1); ans.pop_back(); }
}
int main()
{
	while (1) {
		cin >> k;
		if (!k) return 0;
		for (int i = 0; i < k; i++) { cin >> input; s.push_back(input); }
		sort(s.begin(), s.end());
		comb(s.size(), 6, 0);
		cout << "\n";
		s.clear();
	}
	return 0;

}

/* 라이브러리를 이용한 조합 구하기 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int k, input, pidx = 0; vector<vector<int>> s; vector<vector<vector<int>>> res;
	while (1) {
		cin >> k;
		if (!k) break; vector<int> temp;
		for (int i = 0; i < k; i++) {
			cin >> input;
			temp.push_back(input);
		}
		s.push_back(temp);
	}
	for (int i = 0; i < s.size(); i++) {
		vector<vector<int>> ans; vector<int> idx; int cnt = 0;
		for (int j = 0; j < 6; j++) idx.push_back(1);
		for (int j = 0; j < s[i].size() - 6; j++) idx.push_back(0);
		sort(idx.begin(), idx.end(), greater<int>());
		sort(s[i].begin(), s[i].end());
		do {
			vector<int> temp; cnt++;
			for (int j = 0; j < idx.size(); j++)
				if (idx[j]) temp.push_back(s[i][j]);
			ans.push_back(temp);
		} while (prev_permutation(idx.begin(), idx.end()));
		res.push_back(ans);
	}
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			for (int k = 0; k < res[i][j].size(); k++) {
				cout << res[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;

}