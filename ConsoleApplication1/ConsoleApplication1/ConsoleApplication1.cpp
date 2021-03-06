#include <stdio.h>
#include <algorithm>

#define MAXD 2002
using namespace std;

int D1, D2;
int Data[MAXD][MAXD];
bool vis[MAXD][MAXD];

void input() {
	scanf("%d %d", &D1, &D2);
	return;
}
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int solve() {
	for (int i = D1; i <= D2; i++) {
		for (int j = 1; j <= i; j++) {
			if (vis[i][j])
				continue;
			Data[i][j]++;
			if (i%j == 0) {

				int chk = i / j;

				for (int k = i + chk; k <= D2; k += chk) {
					vis[k][k / chk] = true;
				}
			}
			else {
				int ccnt = 1;
				int a = gcd(i, j);
				for (int k = i + i / a; k <= D2; k += i / a) {
					int l = j + ccnt * j / a; ccnt++;
					vis[k][l] = true;
				}
			}
		}
	}
	int cnt = 0;

	for (int i = D1; i <= D2; i++) {
		for (int j = 1; j <= i; j++) {
			//printf("%d ", Data[i][j]);
			cnt += Data[i][j];
		}
		//printf("\n");
	}

	return cnt;
}

int main()
{
	input();
	int res = solve();
	printf("%d", res);
	return 0;
}