#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>

int main()
{
	std::map<char, std::string> TABLE;
	std::map<std::string, char> I_TABLE;

	TABLE['A'] = "0";
	TABLE['B'] = "10";
	TABLE['C'] = "11";

	I_TABLE["0"]	= 'A';
	I_TABLE["10"]	= 'B';
	I_TABLE["11"]  	= 'C';

	FILE *fp = fopen("input.txt", "r");
	FILE *en = fopen("encoded.txt", "w");
	FILE *de = fopen("decoded.txt", "w");

	char ch;
	while ((ch = fgetc(fp)) != EOF) {
		fprintf(en, "%s", TABLE[ch].c_str());
	}

	fclose(fp);
	fclose(en);

	en = fopen("encoded.txt", "r");
	std::string code;

	code = "";
	while ((ch = fgetc(en)) != EOF) {
		code += ch;
		if (I_TABLE.find(code) != I_TABLE.end()) {
			fputc(I_TABLE[code], de);
			code = "";
		}
	}

	return 0;
}
