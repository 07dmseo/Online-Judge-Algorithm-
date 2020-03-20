#include <string>
#include <vector>
using namespace std;
int ans, t_size, v_size;
int solution(vector<vector<int>> triangle) {
    t_size = triangle.size();
    for(int i = 1; i < t_size; i++){
        v_size = triangle.at(i).size();
        for(int j = 0; j < v_size; j++){
            if(!j) triangle[i][j] += triangle[i - 1][j];
            else if (j == v_size) triangle[i][j] += triangle[i - 1][j - 1];
            else triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
        }
    }
    for(int i = 0; i < t_size; i++) ans = max(ans, triangle[t_size - 1][i]);
    return ans;
}