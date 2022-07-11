
#include "remove_a_word.h"

bool remove_def_from_file(int d, wstring word_dir) {
	ifstream fin;
	fin.open(word_dir, ios::binary | ios::in);
	if (!fin.is_open()) {
		return false;
	}
	fin.seekg(d);
	int n;
	fin.read((char*)&n, sizeof(int));
	int* len = new int[n];
	int size_delete = n;
	for (int i = 0; i < n; ++i) { 
		fin.read((char*)&len[i], sizeof(int));
		fin.seekg(len[i]);
		size_delete = size_delete + sizeof(int) + len[i];
	}	
	fin.close();
	
	ofstream fout;
	fout.open(word_dir, ios::binary | ios::app | ios::out);
	if (!fout.is_open()) {
		return false;
	}
	fout.seekp(d);
	for (int i = 0; i < size_delete; ++i) {
		char del = ' ';

	}
	fout.close();
}

bool remove_a_word(wstring word, AVL& tree, string def_dir) {
	int d = tree.search(word)->d;
	wstring word_dir =	wstring(def_dir.begin(), def_dir.end()) + (wchar_t)towupper(word[0]) + L".bin";

	return tree.remove(word);
}