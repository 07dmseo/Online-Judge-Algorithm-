#include <stack>
#include <string.h>
using namespace std;
queue<int> bfs_q; stack<int> dfs_s; vector<int> graph[1001];
int n, m, v, a, b; bool visited[1001] = { false, };

void dfs(int start)
{
	memset(visited, false, sizeof(visited));
	dfs_s.push(start); visited[start] = true;
	cout << start << " ";
	while (!dfs_s.empty()) {
		int curr_pos = dfs_s.top(); bool pushed = false;
		for (int i = 0; i < graph[curr_pos].size(); i++) { 
			if (visited[graph[curr_pos][i]]) continue;
			dfs_s.push(graph[curr_pos][i]); visited[graph[curr_pos][i]] = true; 
			cout << graph[curr_pos][i] << " "; pushed = true; break;
		}
		if (!pushed) {
			dfs_s.pop(); continue;
		}
	}
	cout << endl;
}

void bfs(int start)
{
	memset(visited, false, sizeof(visited));
	bfs_q.push(start);
	while (!bfs_q.empty()) {
		int curr_pos = bfs_q.front(); bfs_q.pop();
		if (visited[curr_pos]) continue;
		visited[curr_pos] = true; cout << curr_pos << " ";
		for (int i = 0; i < graph[curr_pos].size(); i++)
			bfs_q.push(graph[curr_pos][i]);
	}
	cout << endl;
}

int main()
{
	cin >> n >> m >> v;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());
	dfs(v); bfs(v);
	return 0;

}