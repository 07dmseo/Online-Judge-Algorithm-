#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
bool visited[8]; vector<int> v, s;
void perm(int n, int r)
{
	if (!r) { for (int i = 0; i < s.size(); i++) printf("%d ", s.at(i));
	printf("\n"); return; }
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true; s.push_back(v.at(i));
		perm(n, r - 1);
		s.pop_back(); visited[i] = false;
	}
}
int main()
{
	int n, m, p; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) { scanf("%d", &p); v.push_back(p); }
	sort(v.begin(), v.end());
	perm(n, m);
	return 0;

}