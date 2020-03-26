#include <string>
#include <cmath>
#include <vector>
using namespace std;
vector<int> solution(int brown, int red) {
    vector<int> answer;
    int horizontal = (int)sqrt(brown + red), vertical = (int)sqrt(brown+red);
    while(brown != 2*horizontal + 2*vertical - 4) horizontal++;
    while(red != (horizontal - 2) * (vertical - 2)){ horizontal++, vertical--; }
    answer.push_back(horizontal); answer.push_back(vertical);
    return answer;
}