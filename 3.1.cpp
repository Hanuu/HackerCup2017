#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct diceprob {
	int d;
	long long n[21][401];
}dice[6];

int dicetype(int b) {
	switch (b) {
	case 4: return 0;
	case 6: return 1;
	case 8: return 2;
	case 10: return 3;
	case 12: return 4;
	case 20: return 5;
	}

}
double probability(int a, int b, int c, int h) {
	int typeb = dicetype(b);
	long long sum = 0;
	if (h - c>a*b) {
		return 0;
	}
	else if (h - c < 0) {
		return 1;
	}
	else {
		for (int i = h - c; i <= b*a; i++) {
			sum += dice[typeb].n[a][i];
		}
		// 		printf("%f\n",sum/pow(b,a));
		return (sum / pow(b, a));
	}
}
double bigger(double a, double b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int a[11], b[11], c[11];
int main() {
	dice[0].d = 4;
	dice[1].d = 6;
	dice[2].d = 8;
	dice[3].d = 10;
	dice[4].d = 12;
	dice[5].d = 20;

	for (int i = 0; i <= 5; i++) {
		for (int j = 1; j <= 20; j++) {
			for (int k = j; k <= 400; k++) {
				dice[i].n[j][k] = 0;
			}
		}
	}
	for (int i = 0; i <= 5; i++) {
		for (int k = 1; k <= dice[i].d; k++) {
			dice[i].n[1][k] = 1;
		}

	}
	for (int i = 0; i <= 5; i++) {
		for (int j = 2; j <= 20; j++) {
			for (int k = j; k <= dice[i].d*j; k++) {
				if (k < dice[i].d + 1) {
					for (int a = 1; a <= k - 1; a++) {
						dice[i].n[j][k] += dice[i].n[j - 1][a];
					}

				}
				else {
					for (int a = k - dice[i].d; a <= k - 1; a++) {
						dice[i].n[j][k] += dice[i].n[j - 1][a];
					}
				}
			}
		}
	}

	//printf("%llu", dice[5].n[20][150]);

	FILE *fp = fopen("3.1.txt", "w");
	freopen("3in.txt", "r", stdin);
	int t;
	cin >> t;

	int h, s;

	for (int i = 1; i <= t; i++) {
		cin >> h;
		cin >> s;
		for (int i = 0; i <= 10; i++) {
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		for (int j = 1; j <= s; j++) {
			scanf("%dd%d", &a[j], &b[j]);
			char temp;
			scanf("%c", &temp);
			if (temp == '-') {
				scanf("%d", &c[j]);
				c[j] *= -1;
			}
			else if (temp == '+') {
				scanf("%d", &c[j]);
			}


		}
		double temp = 0;
		// 		if(i==5){
		// 		    for(int ff=1;ff<=s;ff++){
		// 		        printf("%dd%d+%d ",a[ff],b[ff],c[ff]);
		// 		    }
		// 		}

		for (int dd = 1; dd <= s; dd++) {
			temp = bigger(temp, probability(a[dd], b[dd], c[dd], h));

		}

		printf("Case #%d: %f\n", i, temp);
		fprintf(fp, "Case #%d: %f\n", i, temp);
	}
}

