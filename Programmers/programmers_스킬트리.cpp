#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> trees) {
    int ans = 0;
    vector<bool> checked(26);
    vector<string> compare;
    
    for (int i = 0; i < skill.size(); i++)
        checked[(int)(skill[i] - 'A')] = true;
    
    for (int i = 0; i < trees.size(); i++) {
        string temp;
        for (int j = 0; j < trees[i].size(); j++) {
            if(checked[(int)(trees[i][j] - 'A')])
                temp += trees[i][j];
        }
        compare.push_back(temp);
    }
    
    for (int i = 0; i < compare.size(); i++) {
        int correct = 0;
        for (int j = 0; j < compare[i].size(); j++) {
            if(skill[j] != compare[i][j]) break;
            else correct++;
        }
        if(correct == compare[i].size()) ans++;
    }
    return ans;
    
}