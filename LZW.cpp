#include <bits/stdc++.h>

using namespace std;

string bin(int x)
{
	string ret = "";
	for (int i = 0; i < 12; ++i) {
		ret += ((char)(x%2 + '0'));
		x /= 2;
	}
	reverse(ret.begin(), ret.end());
	
	return ret;
}

void read(char buffer[], int &len, char file[])
{
	char ch;
	FILE *fp = fopen(file, "r");
	len = 0;

	while ((ch = getc(fp)) != EOF) {
		buffer[len++] = ch;
	}

	fclose(fp);
}

void encode(char buffer[], int len, char file[], map<string, int> &code)
{
	int i, next_free;
	string pre;

	FILE *fp = fopen(file, "w");

	next_free = 0;
	for (i = 'A'; i <= 'Z'; ++i) {
		string s = "";
		s += ((char)i);
		code[s] = next_free++;
	}

	pre = buffer[0];
	for (i = 1; i < len; ++i) {
		if (code.find(pre+buffer[i]) == code.end()) {
			fprintf(fp, "%s", bin(code[pre]).c_str());
			code[pre+buffer[i]] = next_free++;
			pre = buffer[i];
		} else {
			pre += buffer[i];
		}
	}
	fprintf(fp, "%s", bin(code[pre]).c_str());

	fclose(fp);
}

void decode(char e_file[], char d_file[])
{
	FILE *fp1 = fopen(e_file, "r");
	FILE *fp2 = fopen(d_file, "w");

	map <int, string> TABLE;

	char ch;
	string s, STRING, ENTRY;
	int CODE, i, next_free = 0;

	for (i = 'A'; i <= 'Z'; ++i) {
		TABLE[next_free++] = ((char)i);
	}

	CODE = 0;
	for (i = 0; i < 12; ++i) {
		ch = getc(fp1);
		CODE = (CODE * 2 + ch - '0');
	}

	STRING = TABLE[CODE];
	fprintf(fp2, "%s", STRING.c_str());
	CODE = 0; i = 0;

	while ((ch = getc(fp1)) != EOF) {
		CODE = (CODE * 2 + ch - '0');
		i++;
		if (i == 12) {
			if (TABLE.find(CODE) == TABLE.end()) {
				ENTRY = STRING + STRING[0];	
			} else {
				ENTRY = TABLE[CODE];
			}
			fprintf(fp2, "%s", ENTRY.c_str());
			TABLE[next_free++] = STRING + ENTRY[0];
			STRING = ENTRY;
			i = 0;
			CODE = 0;
		}
	}

	fclose(fp1);
	fclose(fp2);
}

int main()
{
	char buffer[1001];
	int len;

	char input_file[] = "input.txt";
	read(buffer, len, input_file);

	char encoded_file[] = "encoded.txt";
	map <string, int> code;
	encode(buffer, len, encoded_file, code);

	char decoded_file[] = "decoded.txt";
	decode(encoded_file, decoded_file);

	return 0;
}
