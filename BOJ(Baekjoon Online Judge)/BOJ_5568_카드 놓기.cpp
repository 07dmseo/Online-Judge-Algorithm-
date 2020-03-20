#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, k, a; vector<int> v, t; set<string> tbl; bool visited[10];
void permutation(int n, int r)
{
	if (!r) {
		string temp; for (int i = 0; i < t.size(); i++) temp += to_string(t[i]);
		if (tbl.find(temp) == tbl.end()) tbl.insert(temp); return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			else {
				visited[i] = true; t.push_back(v[i]);
				permutation(n, r - 1);
				visited[i] = false; t.pop_back();
			}
		}
	}
}
int main()
{
	cin >> n >> k; for (int i = 0; i < n; i++) { cin >> a; v.push_back(a); }
	permutation(n, k);
	cout << tbl.size() << "\n";
	return 0;

}