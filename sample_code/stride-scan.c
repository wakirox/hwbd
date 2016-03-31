#include <stdio.h>
#include <stdlib.h>

/* type of file items */
typedef unsigned item_type;

int main(int argc, char** argv){

	FILE* f;
	long long i, count, N, S;

	/* check command line parameters */
	if (argc < 3) exit((printf("Usage: %s file-name stride\n", argv[0]), 1));

	/* convert stride from string to integer format */
	S = atoll(argv[2]);
	if (S <= 0) exit((printf("invalid stride %s\n", argv[2]), 1));

	/* open file for reading */
	f = fopen(argv[1], "r");
	if (f == NULL) exit((printf("can't open file %s\n", argv[1]), 1));

	/* compute number N of elements in the file */
	fseeko(f, 0LL, SEEK_END);
	N = ftello(f)/sizeof(item_type);

	printf("file offset model: %lu bit\n", sizeof(off_t)*8);
	printf("item size: %lu bit\n", sizeof(item_type)*8);
	printf("make pass on file of %lld items with stride %lld...\n", N, S);

	/* make one pass over file with stride S */
	fseeko(f, 0, SEEK_SET);
	for (count = 0; count<10000; count++) {
		item_type val;
		if (!fread(&val, sizeof(item_type), 1, f)) break;
		fseeko(f, (S-1)*sizeof(item_type), SEEK_CUR);
	}
	printf("%lld read operations done.\n", count);

	fclose(f);
}
