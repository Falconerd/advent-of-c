#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *f = fopen("./data/02.dat", "r");
	if (f == NULL) {
		printf("Error opening file.\n");
		return -1;
	}
	uint8_t buf[128];
	uint32_t valid_count = 0;

	while (fgets(buf, sizeof(buf), f)) {
		uint8_t *tok = strtok(buf, "-");
		int32_t min = strtol(tok, NULL, 10);
		tok = strtok(NULL, " ");
		int32_t max = strtol(tok, NULL, 10);
		tok = strtok(NULL, ":");
		uint8_t c = tok[0];
		tok = strtok(NULL, "\n");

		uint8_t count = 0;
		count += tok[min] == c;
		count += tok[max] == c;
		if (count == 1)
			valid_count++;
	}

	printf("Found %u valid values.\n", valid_count);

	fclose(f);

	return 0;
}
