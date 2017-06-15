/*
* Generate combinations
*/

#include <stdio.h>
const int NMAX = 4;

int Src[NMAX] = { 1, 2, 3, 4 };
int Sel[NMAX+1];
int cnt;

/*
* Generate Combination Set
* @ param s Start number (0 <= Src[s] < NMAX)
* @ param k Selected sequence (0 <= Sel[k] < q)
* @ param q Target number
*/
void Combi_Set_L(int s, int k, int q)
{
	if (k == q)
	{
		cnt++;
		for (int i = 0; i < q; i++)
			printf("%d ", Src[Sel[i]]);
		printf("\n");
		return;
	}

	// i is started from 's' unlike permutation has started from '0'
	for (int i = s; i < NMAX; i++)
	{
		Sel[k] = i;
		Combi_Set_L(i + 1, k + 1, q);
	}
}

/*
* Generate Combination Set
* @ param s Start number (0 <= Src[s] < NMAX)
* @ param k Selected sequence (1 <= Sel[k] <= q)
* @ param q Target number
*/
void Combi_Set_L2(int s, int k, int q)
{
	if (k > q)
	{
		cnt++;
		for (int i = 1; i <= q; i++)
			printf("%d ", Src[Sel[i]]);
		printf("\n");
		return;
	}

	// i is started from 's' unlike permutation has started from '0'
	for (int i = s; i < NMAX; i++)
	{// i: Src index: 0, 1, 2 3
		Sel[k] = i;
		Combi_Set_L2(i + 1, k + 1, q);
	}
}

/*
* Generate Repetition Combination Set
* @ param s Start number (0 <= Src[s] < NMAX)
* @ param k Selected sequence (1 <= Sel[k] <= q)
* @ param q Target number
*/
void RCombi_Set_L(int s, int k, int q)
{
	if (k > q)
	{
		cnt++;
		for (int i = 1; i <= q; i++)
			printf("%d ", Src[Sel[i]]);
		printf("\n");
		return;
	}

	// Keep i unlike general combination increase i. (i+1)
	for (int i = s; i < N; i++)
	{// i: Src index: 0, 1, 2 3
		Sel[k] = i;
		RCombi_Set_L(i, k + 1, q);
	}
}

int trr[3] = { 0, };
void print_trr(int q)
{
	printf("{ %d %d %d }\n", trr[0], trr[1], trr[2]);
}

/*
* Generate Repetition Combination Set
* @ param n Start number (NMAX > Src[s] >= 0)
* @ param r Selected number (Target > Sel[k] >= 0)
* @ param q Target number
*/
void Combi_Set_AL(int n, int r, int q)
{
	if (r == 0)
	{
		cnt++;
		print_trr(q);
		return;
	}
	else if (r > n) return;
	else
	{
		trr[r - 1] = Src[n - 1];
		Combi_Set_AL(n - 1, r - 1, q);
		Combi_Set_AL(n - 1, r, q);
	}
}

int main()
{
	printf("Source Array: \n [ %d | %d | %d | %d ] \n", Src[0], Src[1], Src[2], Src[3]);
	
	printf("(1) L order Combinations (4C3):\n");
	cnt = 0;
	Combi_Set_L(0, 0, 3);
	printf("-> total combi set number is %d \n", cnt);
	
	for (int i = 0; i < NMAX; i++) Sel[i] = 0;

	printf("(2) L order R Combinations (4C3):\n");
	cnt = 0;
	RCombi_Set_L(0, 0, 3);
	printf("-> total combi set number is %d \n", cnt);

	printf("(3) AL order Combinations (4C3):\n");
	cnt = 0;
	Combi_Set_AL(4, 3, 3);
	printf("-> total combi set number is %d \n", cnt);

	return 0;
}