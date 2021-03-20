#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *f = fopen("./data/01.dat", "r");
	if (f == NULL) {
		printf("Error opening file.\n");
		return -1;
	}
	uint8_t buf[5];
	size_t numbers_len = 0;
	size_t numbers_cap = 32;
	int *numbers = malloc(sizeof(*numbers) * numbers_cap);

	while (fgets(buf, sizeof(buf), f)) {
		int n = strtol(buf, NULL, 10);
		if (n == 0)
			continue;
		if (numbers_len == numbers_cap) {
			int *new_numbers = realloc(numbers, sizeof(*numbers) * numbers_cap * 2);
			if (new_numbers == NULL) {
				printf("Error reallocating memory for numbers.\n");
				return -1;
			}
			numbers = new_numbers;
			numbers_cap *= 2;
		}

		for (int i = 0; i < numbers_len; ++i) {
			if (numbers[i] + n == 2020) {
				printf("%d and %d is 2020. %d * %d is %d\n", numbers[i], n, numbers[i], n,
				       numbers[i] * n);
				exit(0);
			}
		}

		numbers[numbers_len++] = n;
	}

	fclose(f);

	return 0;
}