#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;



int main() {
	FILE *fp = fopen("2.1.txt", "w");
	freopen("2in.txt", "r", stdin);
	int t;
	cin >> t;
	int w[101];
	int n;
	for (int i = 1; i <= t; i++) {
		cin >> n;

		for (int j = 1; j <= n; j++) {
			cin >> w[j];
		}
		sort(w+1, w + n+1);
		int count = 0;
		int z=n;
		int a = 1;
		while (a <= z) { //counting should end when everything was counted
			if (w[z] >= 50) {
				z--;
				count++;
			}
			else if (w[z] >= 25) {
				z--;
				a++;
				count++;
			}
			else if (w[z] >= 17) {
				z--;
				a += 2;
				count++;
			}
			else if (w[z] >= 13) {
				z--;
				a += 3;
				count++;
			}
			else if (w[z] >= 10) {
				z--;
				a += 4;
				count++;
			}
			else if (w[z] >= 9) {
				z--;
				a += 5;
				count++;
			}
			else if (w[z] >= 8) {
				z--;
				a += 6;
				count++;
			}
			else if (w[z] >= 7) {
				z--;
				a += 7;
				count++;
			}
			else if (w[z] >= 6) {
				z--;
				a += 8;
				count++;
			}
			else if (w[z] >= 5) {
				z--;
				a += 9;
				count++;
			}
			else if (w[z] >= 4) {
				z--;
				a += 12;
				count++;
			}
			else if (w[z] >= 3) {
				z--;
				a += 16;
				count++;
			}
			else if (w[z] >= 2) {
				z--;
				a += 24;
				count++;
			}
			else if (w[z] >= 1) {
				z--;
				a += 49;
				count++;
			}
			if(z+1<a){ //when counting ends, check whether or not it exceeded the n
			    count--;
			}


		}

		printf("Case #%d: %d\n",i, count);
		fprintf(fp, "Case #%d: %d\n",i, count);		
	}


}
