#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct { int x, t; } pos; queue<pos> bfs_q;
int n, k, curr_x, d[] = { -1, 1, 2 }, t = 100000;  bool visited[100001] = { false, };

int bfs(int start)
{
	bfs_q.push({ start, 0 }); visited[start] = true;
	while (!bfs_q.empty()) {
		pos curr_pos = bfs_q.front(); bfs_q.pop();
		if (curr_pos.x == k) { t = min(t, curr_pos.t); visited[k] = false; continue; }
		for (int i = 0; i < 3; i++) {
			if (i != 2) curr_x = curr_pos.x + d[i];
			else curr_x = curr_pos.x * d[i];
			if (curr_x < 0 || curr_x > 100000 || visited[curr_x]) continue;
			bfs_q.push({ curr_x, curr_pos.t + 1 }); visited[curr_x] = true;
		}
	}
	return t;
}

int main()
{
	cin >> n >> k;
	cout << bfs(n) << endl;
	return 0;
}