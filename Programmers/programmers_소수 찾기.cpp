#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> cmp; int answer = 0;
bool isPrimeNumberOrNew(int test) {
	if (!test || test == 1) return false;
	for (int j = 2; j <= sqrt(test); j++)
		if (!(test % j)) return false;
	for (int j = 0; j < cmp.size(); j++)
		if (test == cmp[j]) return false;
	return true;
}
int solution(string num) {
	for (int i = 1; i <= num.size(); i++) {
		sort(num.begin(), num.end());
		do {
			string temp = ""; int test = 0;
			for (int j = 0; j < i; j++) temp.push_back(num[j]); test = atoi(temp.c_str());
			if (!isPrimeNumberOrNew(test)) continue;
			else cmp.push_back(test);
		} while (next_permutation(num.begin(), num.end()));
	}
	return cmp.size();

}