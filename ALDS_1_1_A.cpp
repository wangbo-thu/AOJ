// ALDS1_1_A.cpp
// Insertion Sort
#include <cstdio>
#include <vector>

void trace(vector<int> &nums, int n)
{
	for (int i = 0; i < n; i++) {
		if (i > 0) printf(" ");
		printf("%d", nums[i]);
	}
	printf("\n");
}

void myswap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void insertSort(vector<int> &nums, int n)
{
	for (int i = 1; i < n; i++) {
		int key = nums[i];
		int j = i - 1;
		while (j >= 0 && nums[j] > key) {
			nums[j+1] = nums[j];
			j--;
		}
		nums[j+1] = key;
		trace(nums, n);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &nums[i]);
	trace(nums, n);
	insertSort(nums, n);
	return 0;
}