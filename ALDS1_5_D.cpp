// ALDS1_5_D.cpp
// Divide and Conquer - The Number of Inversions
// Error: 省掉排序是不对的

#include <iostream>
#include <vector>
using namespace std;

int CntOfInversion(vector<int>& nums, int left, int right)
{
	if (left + 1 >= right) return 0;
	int cnt = 0;
	int mid = left + (right - left) / 2;
	int i = left;
	int j = mid;
	while (i < mid && j < right) {
		if (nums[i] > nums[j]) {
			cnt += mid - i;
			j++;
		}
		else {
			i++;
		}
	}
	return cnt + CntOfInversion(nums, left, mid) + CntOfInversion(nums, mid, right);

}

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int res = CntOfInversion(nums, 0, n);
	cout << res << endl;
	return 0;
}