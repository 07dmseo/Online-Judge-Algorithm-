#include <vector>
#include <stack>
using namespace std;
vector<int> solution(vector<int> p, vector<int> s) {
    vector<int> ans;
    while(p.size()) {
        stack<int> st;
        for (int i = 0; i < p.size(); i++) {
            p[i] += s[i];
            if(!i && p[i] >= 100) st.push(0);
            else if(i && !st.size()) continue;
            else if(st.size() && p[i] >= 100 && st.top() == i - 1) st.push(i);
        }
        
        if(!st.empty()) {
            ans.push_back(st.size());
            p.erase(p.begin(), p.begin() + st.size());
            s.erase(s.begin(), s.begin() + st.size());
        }
    }
    return ans;
    
}