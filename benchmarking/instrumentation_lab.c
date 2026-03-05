#include <stdio.h>
#include "time.h"

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return *state;
}

static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
	int i;
	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
	}
}

static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return sum;
}

int main(void)
{
	clock_t begin, end, begin1, end1, begin2, end2,
			begin3, end3;
	double t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	unsigned long checksum;

	begin = clock();
	begin1 = clock();

	build_dataset();
	end1 = clock();
	t2 = (double)(end1 - begin1) / CLOCKS_PER_SEC;

	begin2 = clock();
	process_dataset();
	end2 = clock();
	t3 = (double)(end2 - begin2) / CLOCKS_PER_SEC;

	begin3 = clock();
	checksum = reduce_checksum();
	end3 = clock();
	t4 = (double)(end3 - begin3) / CLOCKS_PER_SEC;

	if (checksum == 0ul)
		printf("impossible\n");
	end = clock();
	t1 = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("TOTAL seconds: %f\n", t1);
	printf("BUILD_DATA seconds: %f\n", t2);
	printf("PROCESS seconds: %f\n", t3);
	printf("REDUCE seconds: %f\n", t4);
	return (0);
}