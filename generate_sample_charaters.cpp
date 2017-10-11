#include <bits/stdc++.h>

using namespace std;

void set_up()
{
	srand((unsigned)time(NULL));
}

int main()
{
	// set seed for random function
	set_up();

	// name and mode of sample input file
	char file_name[] = "input.txt";
	char mode[] = "w";

	// open file
	FILE *fp = fopen(file_name, mode);

	// write random chaaracters in file
	for (int i = 0; i < 1000; ++i) {
		char ch = (rand() % 10) + 'A';
		fputc(ch, fp);
	}

	// close opened file
	fclose(fp);

	return 0;
}
