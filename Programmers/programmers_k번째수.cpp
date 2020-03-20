#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, curr;
    for(int i = 0; i < commands.size(); i++){
        for (int j = commands.at(i)[0]; j <= commands.at(i)[1]; j++)
            curr.push_back(array.at(j-1));
        sort(curr.begin(), curr.end());
        answer.push_back(curr.at(commands.at(i)[2]-1));
        while(!curr.empty()) curr.pop_back();
    }
    return answer;
}