#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    stack<int> s;
    vector<int> ans(prices.size());
    
    for (int i = 0; i < prices.size(); i++) {
        while(!s.empty() && prices[s.top()] > prices[i]) {
            ans[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()) {
        ans[s.top()] = prices.size() - s.top() - 1;
        s.pop();
    }
    
    return ans;
    
}