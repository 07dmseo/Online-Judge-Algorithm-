#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, arr[8]; vector<int> v; bool visited[8];
void perm(int n, int r)
{
	if (!r) {
		for (int i = 0; i < n; i++) 
			cout << v.at(i) << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true; v.push_back(arr[i]);
		perm(n, r - 1); 
		v.pop_back(); visited[i] = false;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) arr[i] = i + 1;
	perm(n, n);
	return 0;

}