#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <rocksdb/db.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>

using namespace std;


class Btree {
private:
	string path;
	int kBuf;
	int bufS;
	rocksdb::DB* db;
public:
	Btree();
	Btree(string path, int bufferSize, bool onlySearch=false);

//	~Btree();

	bool AddData(const string& key, const string& value, bool com=false);

	bool Close();

	void SetKBuf(int bufs);

	string GetPath();

	map<string, string> GetData(const string& start, const string& end);

	void PrintAll();
};


#endif
