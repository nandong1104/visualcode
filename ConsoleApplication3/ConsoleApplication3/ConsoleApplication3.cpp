#include "stdafx.h"
#include <math.h>
#pragma warning(disable:4996)
int chk[30];
int chkr[30];  //오른쪽 대각선
int chkl[30]; //왼쪽 대각선
int vis[30];
int n,cnt;
void f(int x, int y)
{
	if (x > n)
	{
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (chk[i] == 0 && chkr[x+n-i-1] == 0 && chkl[x+i] == 0)
		{
			chk[i] = 1;
			chkr[x+n-i-1] = 1;
			chkl[x + i] = 1;
			f(x + 1, i);
			chk[i] = 0;
			chkr[x +n-i-1] = 0;
			chkl[x + i] = 0;
		}
		else {
			continue;
		}
	}
}

int main()
{
	scanf("%d", &n);
	f(1, 1);
	printf("%d", cnt);




}