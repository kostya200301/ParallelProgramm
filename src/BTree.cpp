#include <filesystem>


namespace fs = std::filesystem;


#include "BTree.h"

Btree::Btree() {
        this->path = ".";
}


Btree::Btree(string  path_, int bufferSize, bool onlySearch) {
	cout << "OPEN: " << path_ << endl;
	this->path = path_;
	this->kBuf = 0;
	this->bufS = bufferSize;



	 if (!fs::exists(path_)) { // Проверяем, существует ли уже папка
                if (fs::create_directories(path_)) { // Создаем папку и вложенные подпапки (если нужно)
//                      std::cout << "Folder created successfully." << std::endl;
                } else {
                        std::cerr << "Failed to create folder." << std::endl;
                }
        } else {
                std::cout << "Folder already exists." << std::endl;
        }

	if (!onlySearch) {
        	rocksdb::Options options;
        	options.create_if_missing = true;
        	rocksdb::Status status = rocksdb::DB::Open(options, path_, &db);
        	if (!status.ok()) {
        	        std::cerr << "Unable to open BTREE database: " << status.ToString() << std::endl;
        	}
		cout << "Connection BTREE OPEN\n";
	} else {
        	rocksdb::Options options;
        	options.create_if_missing = true;
        	rocksdb::Status status = rocksdb::DB::OpenForReadOnly(options, path_, &db);
        	if (!status.ok()) {
        	        std::cerr << "Unable to open BTREE database: " << status.ToString() << std::endl;
        	}
		cout << "Connection BTREE ONLYSEARCH OPEN\n";

	}
}


/*Btree::~Btree() {
	if (db != nullptr) {
 	   //db->Close();
 	   delete db;
	}
	std::cout << "Dest Btree done\n";

}
*/

bool Btree::AddData(const string& key, const string& value, bool com) {
	this->db->Put(rocksdb::WriteOptions(), key, value);
	return true;
}

void Btree::SetKBuf(int bufs) {
	this->bufS = bufs;
}

void Btree::PrintAll() {
	return;
}

bool Btree::Close() {
	cout << "Close: " << path << endl;
	delete db;
	// Add Close db
	return true;
}

string Btree::GetPath() {
	return this->path;
}


map<string, string> Btree::GetData(const string& start, const string& end) {

    map<string, string> answer;

    rocksdb::ReadOptions read_options;

    // Используем итератор с автоматическим удалением (C++11 и новее)
    {
        std::unique_ptr<rocksdb::Iterator> it(db->NewIterator(read_options));

        for (it->Seek(start); it->Valid() && it->key().ToString() <= end; it->Next()) {
            std::string keyStr = it->key().ToString();
            std::string valueStr = it->value().ToString();
            answer[keyStr] = valueStr;
        }
    }
	return answer;

/*

	map<string, string> answer;
	rocksdb::ReadOptions read_options;
	rocksdb::Iterator* it = db->NewIterator(read_options);
	for (it->Seek(start); it->Valid() && it->key().ToString() <= end; it->Next()) {
		std::string keyStr = it->key().ToString();
		std::string valueStr = it->value().ToString();
		answer[keyStr] = valueStr;
	}
//	std::cout << "Iterator: " << it->key().ToString() << std::endl;
	return answer;

*/



/*	map<string, string> answer;

	MDB_val mdbKey, mdbValue;
	// Находим первую запись, которая больше или равна нижней границе
	mdbKey.mv_size = start.size();
	mdbKey.mv_data = const_cast<char*>(start.c_str());
	if (mdb_cursor_get(cursor, &mdbKey, &mdbValue, MDB_SET_RANGE) != MDB_SUCCESS) {
		return map<string, string>();
	} else {
		// Перебираем записи до тех пор, пока ключ меньше или равен верхней границе
		while (std::string(static_cast<char*>(mdbKey.mv_data), mdbKey.mv_size) <= end) {
			std::string keyStr(static_cast<char*>(mdbKey.mv_data), mdbKey.mv_size);
			std::string valueStr(static_cast<char*>(mdbValue.mv_data), mdbValue.mv_size);
			answer[keyStr] = valueStr;
			if (mdb_cursor_get(cursor, &mdbKey, &mdbValue, MDB_NEXT) != MDB_SUCCESS) {
				break;
			}
		}
	}
	return answer;
*/
}


