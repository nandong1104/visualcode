// ConsoleApplication2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#pragma warning(disable:4996)
int d1, d2,data[2004][2004],cnt2;
bool vis[2004][2004];
void input()
{
	scanf("%d %d", &d1, &d2);
	return;
}
int gcd(int a, int b)
{
	return b ? gcd(b, a%b) :  a;
}

int solve()
{
	for (int i = d1; i <= d2; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (vis[i][j])
				continue;
			data[i][j]++;
			if (i%j == 0)
			{
				int chk = i / j;
				for (int k = i + chk; k <= d2; k += chk)
				{
					vis[k][k / chk]=true;
				}
			}
			else {
				int cnt2 = 1;
				int a = gcd(i, j);
				for (int k = i + i / a; k <= d2; k += i / a)
				{
					int s = j + cnt2 * j / a;
					cnt2++;
					vis[k][s]=true;
				}
			}

		}
	}
	int cnt = 0;
	for (int i = d1; i <= d2; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cnt += data[i][j];
		}
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

