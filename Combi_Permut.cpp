/*
Problem Statement:
Pick two of the five ballpoint pens (5C2),
Pick two of the three pencils (3C2),
Find the number of all cases where you can list four selected (4P4).
5C2 = 10;
3C2 = 3;
5C2 * 3C2 = 30
(30) * 4P4(4!) = 720 
*/

#include <stdio.h>
const int BPMAX = 5;
const int PMAX = 3;
const int MMAX = 4;

// Ballpoint pens
int BP[BPMAX] = { 1, 2, 3, 4, 5 };
int SelBP[BPMAX + 1];
// Pencils
int P[PMAX] = { 6, 7, 8 };
int SelP[PMAX];
// Merged set
int M[MMAX];
int Sel[MMAX + 1];
int Pick[MMAX + 1];
// Counts
int combiCnt;
int totalCnt;

void Permut(int k, int q)
{
	if (k > q)
	{
		totalCnt++;

		for (int i = 1; i <= q; i++)
			printf("%d ", M[Sel[i]]);
		printf("\n");

		return;
	}

	for (int i = 0; i < MMAX; i++)
	{
		if (Pick[i] == 0)
		{
			Pick[i] = 1;
			Sel[k] = i;

			Permut(k + 1, q);

			Pick[i] = 0;
		}
	}
}

void CombiP(int s, int k, int q)
{
	if (k > q)
	{
		for (int i = 1; i <= q; i++)
		{
			//printf("%d ", P[SelP[i]]);
			M[i + 1] = P[SelP[i]];
		}

		//{M} = {1, 2, 6, 7} ... {8, 6, 5, 4}
		//for (int i = 0; i < MMAX; i++)
			//printf("%d ", M[i]);
		//printf("\n");
		/*
		* Before calling permutation of picked 4 items,
		* Need to initialize Sel[] and Pick[]
		*/
		for (int i = 0; i < MMAX; i++)
			Sel[i] = Pick[i] = 0;

		Permut(1, 4);
		return;
	}

	for (int i = s; i < PMAX; i++)
	{
		SelP[k] = i;
		CombiP(i + 1, k + 1, q);
	}
}

void CombiBP(int s, int k, int q)
{
	if (k > q)
	{
		for (int i = 1; i <= q; i++)
		{
			// printf("%d ", BP[SelBP[i]]);
			M[i - 1] = BP[SelBP[i]];
		}

		CombiP(0, 1, 2);
		return;
	}

	for (int i = s; i < BPMAX; i++)
	{
		SelBP[k] = i;
		CombiBP(i + 1, k + 1, q);
	}
}

int main()
{
	combiCnt = 0;
	totalCnt = 0;

	/* Combination (5C2) */
	CombiBP(0, 1, 2);

	printf("5C2 * 3C2 = %d\n", combiCnt);
	printf("4P4 of (5C2 * 3C2) = %d\n", totalCnt);

	return 0;
}