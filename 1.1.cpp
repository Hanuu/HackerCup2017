#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

struct point {
	int p;
	int x;
	int y;
};
double distance(point a, point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double angle(point p1, point p2, point p3) {
	return acos((distance(p1, p2)*distance(p1, p2) + distance(p1, p3)*distance(p1, p3) - distance(p2, p3)*distance(p2, p3)) / (2 * distance(p1, p2)* distance(p1, p3)));
}
bool wb(point a,point p1,point p2) {

	if ((a.x - 50)*(a.x - 50) + (a.y - 50)*(a.y - 50) > 2500) {
		return 0;
	}
	else {
		if (a.x >= 50) {
			if (50 * angle(p1, p2, a)/3.14159265359 <= a.p) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			if (-50 * angle(p1, p2, a)/ 3.14159265359 + 100 <= a.p) {
				return 1;
			}
			else {
				return 0;
			}

		}
	}
}


int main() {
	FILE *fp = fopen("1.1.txt", "w");
	freopen("1in.txt", "r", stdin);
	int t;
	cin >> t;

	point n[1001];
	point p1, p2;
	p1.x = 50;
	p1.y = 50;
	p2.x = 50;
	p2.y = 100;

	for (int i = 1; i <= t; i++) {
		cin >> n[i].p;
		cin >> n[i].x;
		cin >> n[i].y;
		if (wb(n[i], p1, p2)==0) {
			
			printf("Case #%d: white\n",i);
			fprintf(fp, "Case #%d: white\n",i);
		}
		else {
			printf("Case #%d: black\n",i);
			fprintf(fp, "Case #%d: black\n",i);
		}
	}


}
