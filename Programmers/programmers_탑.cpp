#include <string>
#include <vector>
using namespace std;
vector<int> solution(vector<int> heights) {
    vector<int> answer;
    for(int i = 0; i < heights.size(); i++){
        if(!i) { answer.push_back(0); continue; }
        for(int j = i - 1; j > -1; j--){
            if(heights.at(j) > heights.at(i)){
                answer.push_back(j + 1); break;
            }
            else if(!j && heights.at(j) <= heights.at(i)) answer.push_back(0);
        }
    }
    return answer;
}