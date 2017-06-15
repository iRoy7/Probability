#include <stdio.h>
const int NMAX = 4;

int Src[NMAX] = { 2,4,6,8 };
int Sel[NMAX + 1];
int Picked[NMAX + 1];
int cnt;

/*
* Generate Permutation Set
* @param k Selected sequence
* @param q Target num
*/
void Permut1(int k, int q)
{
	if (k == q)
	{
		cnt++;
		for (int i = 0; i < q; i++)
			printf("%d ", Src[Sel[i]]);
		printf("\n");
		return;
	}

	// Starts i from 0 always unlike Combination starts from 's'
	for (int i = 0; i < NMAX; i++)
	{// i: Src index: 0, 1, 2, 3
		if (Picked[i] == 0)
		{
			Picked[i] = 1; // Mark Picked
			Sel[k] = i;

			Permut1(k + 1, q);

			Picked[i] = 0; // UnMark Picked
		}
	}
}

/*
* Generate Permutation Set
* @param k Selected sequence (1 <= Sel[k] <= q)
* @param q Target num
*/
void Permut2(int k, int q)
{
	if (k > q)
	{
		cnt++;
		for (int i = 1; i <= q; i++)
			printf("%d ", Src[Sel[i]]);
		printf("\n");
		return;
	}

	// Starts i from 0 always unlike Combination starts from 's'
	for (int i = 0; i < NMAX; i++)
	{// i: Src index: 0, 1, 2, 3
		if (Picked[i] == 0)
		{
			Picked[i] = 1; // Mark Picked
			Sel[k] = i;

			Permut2(k + 1, q);

			Picked[i] = 0; // UnMark Picked
		}
	}
}

/*
* Generate Repetition Permutation Set
* @param k Selected sequence (1 <= Sel[k] <= q)
* @param q Target num
*/
void RPermut(int k, int q)
{
	if (k > q)
	{
		cnt++;
		for (int i = 1; i <= q; i++)
			printf("%d ", Src[Sel[i]]);
		printf("\n");
		return;
	}

	// Starts i from 0 always unlike Combination starts from 's'
	// No need to check whether Src i is picked or NOT unlike general permutation
	for (int i = 0; i < NMAX; i++)
	{// i: Src index: 0, 1, 2, 3
		Sel[k] = i;
		RPermut(k + 1, q);
	}
}

int main()
{
	printf("Source Array: \n [ %d | %d | %d | %d ]\n", Src[0], Src[1], Src[2], Src[3]);

	printf("(1) Permutations(4P4):\n");
	cnt = 0;
	Permut1(0, 4);
	printf("-> Total permut set number is %d\n", cnt);

	printf("(2) Permutations(4P4):\n");
	for (int i = 0; i < NMAX + 1; i++)
		Picked[i] = Sel[i] = 0;
	cnt = 0;
	Permut2(1, 4);
	printf("-> Total permut set number is %d\n", cnt);

	printf("(3) Repetition Permutations(4P4):\n");
	for (int i = 0; i < NMAX + 1; i++)
		Picked[i] = Sel[i] = 0;
	cnt = 0;
	RPermut(1, 4);
	printf("-> Total repetition permut set number is %d\n", cnt);

	return 0;
}