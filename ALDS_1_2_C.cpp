// ALDS_1_2_C.cpp
// Stable Sort

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);
	vector<char> labels(N);
	for (int i = 0; i < N; i++) {
		cin >> labels[i] >> nums[i];
	}
	
	return 0;
}
