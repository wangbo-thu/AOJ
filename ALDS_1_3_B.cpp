// ALDS_1_3_B.cpp
// Queue

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	int q;
	queue<string> names;
	queue<int> times;
	int time_sum = 0;
	cin >> n >> q;
	int time;
	string name;
	while (n--) {
		cin >> name >> time;
		names.push(name);
		times.push(time);
	}
	while (!times.empty()) {
		time = times.front();
		times.pop();
		name = names.front();
		names.pop();
		if (time > q) {
			times.push(time - q);
			names.push(name);
			time_sum += q;
		}
		else {
			time_sum += time;
			cout << name << " " << time_sum << endl;
		}
	}
	return 0;
}