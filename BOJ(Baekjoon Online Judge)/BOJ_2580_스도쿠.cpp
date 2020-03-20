#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
int n, vsize ,map[10][10], r[3][2] = { {-2, 0}, {0, 2}, {-1, 1} };
typedef struct { int x, y; }pos; vector<pos> vq;
void sdk(int idx, int nx, int ny)
{
	if (idx >= vq.size()) {
		for (int y = 1; y <= 9; y++) {
			for (int x = 1; x <= 9; x++)
				cout << map[y][x] << " ";
			cout << endl;
		}
		exit(0);
	}
	
	int x_begin = nx + r[nx % 3][0], x_end = nx + r[nx % 3][1];
	int y_begin = ny + r[ny % 3][0], y_end = ny + r[ny % 3][1];
	stack<int> s; bool blank[10]; memset(blank, false, sizeof(blank));
	
	for (int x = 1; x <= 9; x++)
		blank[map[ny][x]] = true;
	for (int y = 1; y <= 9; y++)
		blank[map[y][nx]] = true;
	for (int y = y_begin; y <= y_end; y++)
		for (int x = x_begin; x <= x_end; x++)
			blank[map[y][x]] = true;
	for (int i = 1; i <= 9; i++)
		if (!blank[i]) s.push(i);

	while (!s.empty()) {
		map[ny][nx] = s.top(); s.pop();
		if(idx + 1 < vsize) sdk(idx + 1, vq.at(idx + 1).x, vq.at(idx + 1).y);
		else sdk(idx + 1, 0, 0);
		map[ny][nx] = 0;
	}
	
	return;
}
int main()
{
	for (int y = 1; y <= 9; y++) {
		for (int x = 1; x <= 9; x++) {
			cin >> map[y][x];
			if (!map[y][x]) vq.push_back({ x, y });
		}
	}
	vsize = vq.size();
	sdk(0, vq.front().x, vq.front().y);
	return 0;
	
}