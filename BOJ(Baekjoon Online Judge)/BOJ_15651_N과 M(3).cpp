#include <cstdio>
#include <vector>
using namespace std;
int n, m; vector<int> v;
void perm(int n, int r)
{
	if (!r) {
		for (int i = 0; i < v.size(); i++) printf("%d ", v.at(i));
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		v.push_back(i); perm(n, r - 1); v.pop_back();
	}
	return;

}
int main()
{
	scanf("%d%d", &n, &m);
	perm(n, m);
	return 0;

}