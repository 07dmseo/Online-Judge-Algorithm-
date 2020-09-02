#include <vector>
#include <queue>
using namespace std;
int solution(int b_len, int weight, vector<int> t_weights) {
    int ans = 0, q_weight = 0, idx = 0;
    queue<int> q;
    while(1) {
        if (idx == t_weights.size()) break;
        else if(q.size() == b_len) {
            if(q.front()) q_weight -= q.front();
            q.pop();
        }
        else if(q_weight + t_weights[idx] <= weight) {
            q.push(t_weights[idx]); q_weight += t_weights[idx], ans++, idx++; 
        }
        else { q.push(0); ans++; }
    }
    return ans + b_len;
    
}