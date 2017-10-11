#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int> > code;


/**
 * This function reads character from a given file
 * and store it in the buffer.
 */
void read(char buffer[], int &len, char file_name[])
{
	int i, j, k;
	len = 0;
	char ch;

	// open the file in read mode
	FILE *fp = fopen(file_name, "r");

	// read character and store it in 
	// the buffer. 
	while ((ch = getc(fp)) != EOF) {
		buffer[len++] = ch;
	}

	fclose(fp);
}

void encode(char buffer[], int len, char file_name[])
{
	vector<pair<char, int> > code;
	int i, j, k;
	char ch;

	ch = buffer[0];
	k = 1;
	for (i = 1; i < len; ++i) {
		if (buffer[i] != ch) {
			code.push_back(make_pair(ch, k));
			ch = buffer[i];
			k = 0;
		}
		k++;
	}
	code.push_back(make_pair(ch, k));

	FILE *fp = fopen(file_name, "w");

	for (i = 0; i < code.size(); ++i) {
		fprintf(fp, "%c%d", code[i].first, code[i].second);
	}

	fclose(fp);
}

void decode(char en_name[], char de_name[])
{
	int i, j, k, len;
	char ch, buffer[1001];

	FILE *fp = fopen(en_name, "r");

	len = 0;
	while (fscanf(fp, "%c%d", &ch, &k) != EOF) {
		while (k--) {
			buffer[len++] = ch;
		}
	}

	fclose(fp);

	fp = fopen(de_name, "w");

	for (i = 0; i < len; ++i) {
		fputc(buffer[i], fp);
	}
	
	fclose(fp);
}

int main()
{
	char buffer[1001];
	int len;

	char input_file[] = "input.txt";
	read(buffer, len, input_file);

	char encoded_file[] = "encoded.txt";
	encode(buffer, len, encoded_file);

	char decoded_file[] = "decoded.txt";
	decode(encoded_file, decoded_file);

	return 0;
}
