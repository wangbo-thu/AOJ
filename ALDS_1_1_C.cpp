#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	bool res = true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = false;
			break;
		}
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		if (isPrime(nums[i]))
			cnt++;
	}
	cout << cnt << endl;
	
	return 0;
}