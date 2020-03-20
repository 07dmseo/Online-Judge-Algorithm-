#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct { int x, y; }pos; queue<pos> bfs_q; 
priority_queue<int, vector<int>, greater<int>> min_heap;
char map[26][26]; bool visited[26][26] = { false, }; 
int n, estate, cnt, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void bfs()
{
	int curr_x, curr_y;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (visited[y][x] || map[y][x] != '1') continue;
			bfs_q.push({ x,y });
			while (!bfs_q.empty()) {
				pos curr_pos = bfs_q.front();
				bfs_q.pop();
				if (visited[curr_pos.y][curr_pos.x]) continue;
				cnt += 1, visited[curr_pos.y][curr_pos.x] = true;
				for (int i = 0; i < 4; i++) {
					curr_x = curr_pos.x + dx[i], curr_y = curr_pos.y + dy[i];
					if (visited[curr_y][curr_x] || map[curr_y][curr_x] != '1') continue;
					else if (curr_x < 1 || curr_x > n || curr_y < 1 || curr_y > n) continue;
					bfs_q.push({ curr_x,curr_y });
				}
			}
			estate += 1, min_heap.push(cnt), cnt = 0;
		}
	}
	cout << estate << endl; while (!min_heap.empty()) { cout << min_heap.top() << endl; min_heap.pop(); }
}

int main()
{
	cin >> n;
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			cin >> map[y][x];
	bfs();
	return 0;

}