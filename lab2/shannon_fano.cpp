#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <map>

using namespace std;

#define fi first
#define sc second
#define mkp make_pair

map<char, int> mp;
pair<int, char> A[100];
map<char, string> TABLE;
map<string, char> I_TABLE;

void make(int i, int j, string code)
{
	if (i > j) return;

	if (i == j) {
		TABLE[A[i].sc] = code;
		return;
	}

	int start, mid, end, ans, req;
	start = i;
	end = j;
	ans = i;

	req = (A[end].fi - A[start-1].fi) / 2;
	while (start <= end) {
		mid = (start + end) >> 1;
		
		int sum = A[mid].fi - A[i-1].fi;
		if (sum <= req) {
			ans = mid;
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	make(i, ans, code + "0");
	make(ans+1, j, code + "1");
}

int main()
{
	char BUFFER[1001];
	int i, j, k, len, N;
	char ch;

	FILE *fp = fopen("input.txt", "r");
	len = 0;
	while ((ch = fgetc(fp)) != EOF) {
		BUFFER[len++] = ch;
		mp[ch]++;
	}
	fclose(fp);

	i = 0;
	for (auto it: mp) {
		A[++i] = mkp(it.sc, it.fi);
	}
	N = i;

	for (i = 1; i <= N; ++i) {
		A[i].fi += A[i-1].fi;
	}

	make(1, N, "");

	for (auto it: TABLE) {
		I_TABLE[it.sc] = it.fi;
	}

	fp = fopen("encoded.txt", "w");
	for (i = 0; i < len; ++i) {
		fprintf(fp, "%s", TABLE[BUFFER[i]].c_str());
	}
	fclose(fp);

	string code = "";
	fp = fopen("encoded.txt", "r");
	FILE *de = fopen("decoded.txt", "w");

	while ((ch = fgetc(fp)) != EOF) {
		code += ch;
		if (I_TABLE.find(code) != I_TABLE.end()) {
			fputc(I_TABLE[code], de);
			code = "";
		}
	}

	fclose(fp);
	fclose(de);

	return 0;
}
