#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void answer(vector< vector<int> >& arr, int y, int x, int size) {
       if (size == 1) {
              cout << arr[y][x];
              return;
       }
       else {
              bool defrent = false;
              int cur = arr[y][x];
              for (int i = y; i < y + size; ++i) {
                     bool brk = false;
                     for (int j = x; j < x + size; ++j) {
                           if (arr[i][j] != cur)
                           {
                                  brk = true;
                                  defrent = true;
                                  break;
                           }
                     }
                     if (brk)
                           break;
              }
              if (defrent) {
                     cout << "(";
                     answer(arr, y, x, size / 2);
                     answer(arr, y, x + size / 2, size / 2);
                     answer(arr, y + size / 2, x, size / 2);
                     answer(arr, y + size / 2, x + size / 2, size / 2);
                     cout << ")";
              }
              else { 
                     cout << arr[y][x];
              }
       }
}
int main() {
       int size;
       cin >> size;
       vector< vector<int> > arr(size, vector<int>(size));
       for (int i = 0; i < size; ++i) {
              for (int j = 0; j < size; ++j) {
                     scanf("%1d", &arr[i][j]);
              }
       }
       answer(arr, 0, 0, size);
       return 0;
}