#include <stdio.h>
const int NMAX = 5;

int Src[NMAX] = { 1, 2, 3, 4 };
int Sel[NMAX];
int N = 4;
int cnt;

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

	for (int i = s; i < N; i++)
	{
		Sel[k] = i;
		Combi_Set_L(i + 1, k + 1, q);
	}
}

void RCombi_Set_L(int s, int k, int q)
{
	if (k == q)
	{
		cnt++;
		for (int i = 0; i < q; i++)
			printf("%d ", Src[Sel[i]]);
		printf("\n");
		return;
	}

	for (int i = s; i < N; i++)
	{
		Sel[k] = i;
		RCombi_Set_L(i, k + 1, q);
	}
}

int trr[3] = { 0, };
void print_trr(int q)
{
	printf("{ %d %d %d }\n", trr[0], trr[1], trr[2]);
}

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