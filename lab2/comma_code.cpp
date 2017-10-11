#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>

int main()
{
	FILE *fp = fopen("input.txt", "r");
	FILE *en = fopen("encoded.txt", "w");

	std::map<char, std::string> TABLE;
	TABLE['A'] = "0";
	TABLE['B'] = "01";
	TABLE['C'] = "011";

	std::map <std::string, char> I_TABLE;
	I_TABLE["0"] 	= 'A';
	I_TABLE["01"] 	= 'B';
	I_TABLE["011"] 	= 'C';

	char ch;
	while ((ch = fgetc(fp)) != EOF) {
		fprintf(en, "%s", TABLE[ch].c_str());
	}

	fclose(fp);
	fclose(en);

	en = fopen("encoded.txt", "r");
	FILE *de = fopen("decoded.txt", "w");

	std::string code;
	ch = fgetc(en);
	code = ch;
	while ((ch = fgetc(en)) != EOF) {
		if (ch == '0') {
			fputc(I_TABLE[code], de);
			code = ch;
		} else {
			code += ch;
		}
	}
	fputc(I_TABLE[code], de);

	fclose(en);
	fclose(de);

	return 0;
}
