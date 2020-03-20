#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
queue<int> bfs_q; vector<int> graph[1001]; 
int n, m, u, v, e; bool visited[1001] = { false, };
void bfs()
{
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		bfs_q.push(i); visited[i] = true;
		while (!bfs_q.empty()) {
			int curr = bfs_q.front(); bfs_q.pop();
			for (int i = 0; i < graph[curr].size(); i++) {
				if (visited[graph[curr][i]]) continue;
				bfs_q.push(graph[curr][i]); visited[graph[curr][i]] = true;
			}
		}
		e += 1;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs();
	cout << e << endl;
	return 0;
}