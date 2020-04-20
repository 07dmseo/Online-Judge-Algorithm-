#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, x, y, d, g, ans, dx[] = { 1,0,-1,0 }, dy[] = { 0,-1,0,1 }; bool res[101][101];
typedef struct { int x, y, d, g; } curve; vector<curve> v;
int rectangle()
{
	for (int y = 0; y < 100; y++) 
		for (int x = 0; x < 100; x++) 
			if (res[y][x] && res[y + 1][x] && res[y][x + 1] && res[y + 1][x + 1]) ans++;
	return ans;

}

void dragoncurve()
{
	for (int i = 0; i < v.size(); i++) {
		bool temp[101][101]; memset(temp, 0, sizeof(temp));
		int nx = v[i].x, ny = v[i].y;
		vector<int> list; list.push_back(v[i].d);

		for (int j = 0; j < v[i].g; j++) {
			int list_size = list.size() - 1;
			for (int k = list_size; k >= 0; k--) list.push_back((list[k] + 1) % 4);
		}

		temp[ny][nx] = true;
		for (int j = 0; j < list.size(); j++) {
			nx += dx[list[j]], ny += dy[list[j]];
			temp[ny][nx] = true;
		}

		for (int y = 0; y < 101; y++)
			for (int x = 0; x < 101; x++)
				if (temp[y][x]) res[y][x] = true;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		v.push_back({ x,y,d,g });
	}
	dragoncurve();
	cout << rectangle() << endl;
	return 0;

}