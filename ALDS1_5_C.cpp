// ALDS1_5_C.cpp
// Divide and Conquer - Koch Curve

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
double const PI = 3.14159265;
struct Point
{
	double x;
	double y;
};

double dist(Point p1, Point p2) {
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx * dx + dy * dy);
}

vector<Point> divide(Point p1, Point p2)
{
	vector<Point> res;

	Point p_new1;
	p_new1.x = p1.x + (p2.x - p1.x) / 3;
	p_new1.y = p1.y + (p2.y - p1.y) / 3;

	Point p_new2;
	p_new2.x = p2.x - (p2.x - p1.x) / 3;
	p_new2.y = p2.y - (p2.y - p1.y) / 3;

	Point p_new3;
	double side = dist(p_new1, p_new2);
	double theta = atan2(p_new2.y - p_new1.y, p_new2.x - p_new1.x);
	p_new3.x = p_new1.x + side * cos(PI / 3 + theta);
	p_new3.y = p_new1.y + side * sin(PI / 3 + theta);

	res.push_back(p1);
	res.push_back(p_new1);
	res.push_back(p_new3);
	res.push_back(p_new2);
	res.push_back(p2);
	return res;
}

void show(vector<Point>& ps)
{
	for (int i = 0; i < ps.size(); i++) {
		cout << ps[i].x << " " << ps[i].y << endl;
	}
}

void KochCurve(vector<Point>& ps, int n)
{
	vector<Point> res;
	if (n == 0) {
		show(ps);
		return;
	}
	else {
		res.push_back(ps[0]);
		for (int i = 0; i + 1 < ps.size(); i++) {
			vector<Point> tmp = divide(ps[i], ps[i + 1]);
			for (int j = 1; j < tmp.size(); j++) {
				res.push_back(tmp[j]);
			}
		}
		KochCurve(res, n - 1);
	}

}

int main()
{
	Point p;
	vector<Point> ps;
	ps.push_back({ 0.0, 0.0 });
	ps.push_back({ 100.0, 0.0 });
	int n;
	cin >> n;
	KochCurve(ps, n);
	return 0;
}