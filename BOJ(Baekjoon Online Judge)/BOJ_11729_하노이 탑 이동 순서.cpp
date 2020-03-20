#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n; typedef struct { int a, b; }pos;
queue<pos>hanoi_q;
void hanoi(int n, int src, int des, int aux)
{
	if (n == 1) {
		hanoi_q.push({ src, des });
		return;
	}
	hanoi(n - 1, src, aux, des);
	hanoi_q.push({ src, des });
	hanoi(n - 1, aux, des, src);
}
int main()
{
	scanf("%d", &n);
	hanoi(n, 1, 3, 2);
	printf("%d\n",hanoi_q.size());
	while (!hanoi_q.empty()) {
		pos curr_pos = hanoi_q.front(); hanoi_q.pop();
		printf("%d %d\n",curr_pos.a , curr_pos.b);
	}
	return 0;

}