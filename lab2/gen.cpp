#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand((unsigned)time(NULL));

	FILE *fp = fopen("input.txt", "w");

	for (int i = 0; i < 500; ++i) {
		int x = rand() % 3;
		fputc('A' + x, fp);
	}

	fclose(fp);

	return 0;
}
