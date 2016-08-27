#include <stdio.h>
#define SZN 101
#define INT_MAX 2147483647

int M[SZN];
int C[SZN];
int trr[SZN];
int N, P;
int minCost;

int main()
{
	freopen("appMemoryMgr.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &P);

		for (int i = 0; i < N; i++)
		{
			M[i] = 0; scanf("%d", &M[i]);
		}
		for (int i = 0; i < N; i++)
		{
			C[i] = 0; scanf("%d", &C[i]);
		}

		/* Power Set */
		minCost = INT_MAX;
		for (int i = 0; i < (1 << N); i++)
		{
			int seizedMem = 0;
			int trrCnt = 0;
			int cost = 0;

			for (int j = 0; j < N; j++)
			{
				if (i & (1 << j))
				{
					seizedMem += M[j];
					trr[trrCnt++] = C[j];
				}
			}

			if (seizedMem >= P)
			{
				for (int k = 0; k < trrCnt; k++)
					cost += trr[k];

				if (minCost > cost) minCost = cost;
			}
		}

		printf("%d\n", minCost);
	}

	return 0;
}
