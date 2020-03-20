#include <iostream>
using namespace std;
int n, m, num[9]; bool visited[9];
void comb(int idx, int n, int r)
{
	if (r == 0) {
		for (int i = 1; i <= n; i++) if (visited[i]) cout << num[i] << " ";
		cout << endl; return; 
	}
	for (int i = idx; i <= n; i++) {
		visited[i] = true;
		comb(i + 1, n, r - 1);
		visited[i] = false;
	}
	return;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) num[i] = i;
	comb(1, n, m);
	return 0;

}