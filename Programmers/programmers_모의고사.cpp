#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> answers) {
    vector<int> ans; vector<vector<int>> h; int m = 0, res[4] = {0, };
    h.push_back({0});
    h.push_back({1,2,3,4,5});
    h.push_back({2,1,2,3,2,4,2,5});
    h.push_back({3,3,1,1,2,2,4,4,5,5});
    for (int i = 1; i <= 3; i++){
        for (int k = 0, j = 0; j < answers.size(); k++, j++){
            if(answers[j] == h[i][k]) res[i]++;
            if(k == h[i].size() - 1) k = -1;
        }
        m = max(m, res[i]);
    }
    for (int i = 1; i <= 3; i++) if(m == res[i]) ans.push_back(i);
    return ans;
    
}