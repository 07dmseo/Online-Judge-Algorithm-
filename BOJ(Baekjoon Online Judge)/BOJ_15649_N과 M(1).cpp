#include <cstdio>
#include <vector>
using namespace std;
vector<int> v; bool visited[9] = { false, };
void perm(int *arr, int n, int r)
{
	if (!r) {
		for (int i = 0; i < v.size(); i++) printf("%d ",v.at(i));
		printf("\n"); return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true; v.push_back(arr[i]);
		perm(arr, n, r - 1);
		v.pop_back(); visited[i] = false;
	}
}
int main()
{
	int n, m, arr[9]; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) arr[i] = i + 1;
	perm(arr, n, m);
	return 0;
}