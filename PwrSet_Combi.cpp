#include <stdio.h>
const int NMAX = 11;

int main()
{
	static int Src[] = { -5, -4, -3, -2, -1, 1, 2, 3, 4, 5 };
	int N = sizeof(Src) / sizeof(int);
	int Trr[NMAX] = { 0, };
	int cnt = 0;

	/* Power set */
	for (int i = 1; i < (1 << N); i++)
	{
		int zeroSum = 0;
		int tn = 0;
		int existCnt = 0;

		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{// Selections
				zeroSum += Src[j];
				Trr[tn++] = Src[j];

				/* Check Combinations */
				existCnt++;
			}
		}

		if (zeroSum == 0 && existCnt == 3 && tn > 0)
		//if (subSum == 0)
		{
			cnt++;
			for (int k = 0; k < tn; k++)
				printf("%d ", Trr[k]);
			printf("\n");
		}
	}

	printf("Zero-sum Combi set composed of 3 items = (%d)\n", cnt);

	return 0;
}