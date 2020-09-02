#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct { int p, idx; }element;
int solution(vector<int> priorities, int location) {
    int ans = 1;
    queue<element> q;
    vector<int> p_list;
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        p_list.push_back(priorities[i]);
    }
    sort(p_list.begin(), p_list.end(), greater<int>());
    while(!q.empty()) {
        element current = q.front();
        if(p_list[ans - 1] > current.p) { q.pop(); q.push(current); }
        else {
            if(current.idx == location) return ans;
            q.pop(); ans++;
        }
    }
    return ans;
}