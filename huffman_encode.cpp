#include <bits/stdc++.h>

using namespace std;

struct node {
	char data;
	node *left;
	node *right;
};	

// traverse tree to assign code to characters
void get_code(node *root, string cur_code, map<char, string> &code)
{
	// if the node is null then return
	if (root == NULL) return;

	// if the data part is null then it is an internal
	// node otherwise it is a leaf node
	if (root->data == '\0') {
		get_code(root->left, cur_code + "0", code);
		get_code(root->right, cur_code + "1", code);
	} else {
		// in case of leaf node assing the generated code 
		// to the character
		code[root->data] = cur_code;
	}
}

map<char, string> encode(multiset <pair<int, node*> > &pq, char buffer[], int len)
{
	int data;
	node *root, *node1, *node2;

	// generating tree
	while (pq.size() > 1) {
		data = 0;

		node1 = (*pq.begin()).second; 
		data += (*pq.begin()).first;
		pq.erase(pq.begin());
		
		node2 = (*pq.begin()).second; 
		data += (*pq.begin()).first;
		pq.erase(pq.begin());

		node *tmp = new node;
		tmp->data = '\0';
		tmp->left = node1;
		tmp->right = node2;
		pq.insert(make_pair(data, tmp));
	}
	root = (*pq.begin()).second;
	
	map <char, string> code;

	get_code(root, "", code);
	
	FILE *fp = fopen("encoded.txt", "w");

	for (int i = 0; i < len; ++i) {
		fprintf(fp, "%s", code[buffer[i]].c_str());
	}

	fclose(fp);

	return code;
}

void decode(map<char, string> &code)
{
	map <string, char> icode;

	// create an inverse of code
	for (auto it: code) {
		icode[it.second] = it.first;
	}

	char buffer[1001], ch;
	int len;
	string s;

	FILE *fp = fopen("encoded.txt", "r");

	s = "";
	len = 0;
	while ((ch = getc(fp)) != EOF) {
		s += ch;
		if (icode.find(s) != icode.end()) {
			buffer[len++] = icode[s];
			s = "";
		}
	}

	fclose(fp);

	fp = fopen("decoded.txt", "w");

	for (int i = 0; i < len; ++i) {
		fputc(buffer[i], fp);
	}

	fclose(fp);
}

int main()
{
	char file_name[] = "input.txt";
	char mode[] = "r";
	char buffer[1001];
	char ch;
	
	node *root, *node1, *node2;
	int len, data;
	map <char, int> mp;

	// get reference to file
	FILE *fp = fopen(file_name, mode);

	// read all the characters from the file
	len = 0;
	while ((ch = getc(fp)) != EOF) {
		// store frequency in a map and the
		// characters in a character buffer
		mp[ch]++;
		buffer[len++] = ch;
	}

	// priority queue to store node info
	multiset <pair<int, node*> > pq;

	// insert all leaf nodes into priority 
	// queue with current frequency
	for (auto it: mp) {
		node *tmp = new node;
		tmp->data = it.first;
		tmp->left = NULL;
		tmp->right = NULL;
		pq.insert(make_pair(it.second, tmp));
	}

	fclose(fp);

	map <char, string> code = encode(pq, buffer, len);
	decode(code);

	return 0;
}
