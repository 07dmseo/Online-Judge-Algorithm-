#include <string>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
int solution(int n, vector<vector<int>> comp) {
	stack<int> s; bool visited[200], pushed; int answer = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		else { s.push(i); visited[i] = true; }
		while (!s.empty()) {
			int curr = s.top(); pushed = false;
			for (int j = 0; j < n; j++) {
				if (visited[j] || curr == j) continue;
				else if (comp[curr][j]) { 
					s.push(j); visited[j] = true; pushed = true; break;
				}
			}
			if (pushed) continue;
			else s.pop();
		}
		answer += 1;
	}
	return answer;

}