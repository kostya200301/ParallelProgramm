#include <filesystem>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>


#include <unordered_map>

#include "Searcher.h"


namespace fs = std::filesystem;


class MyMergeOperator : public rocksdb::MergeOperator {
public:
    virtual ~MyMergeOperator() {}
    // Метод для выполнения полного объединения (Full Merge)
    virtual bool FullMerge(const rocksdb::Slice& key,
                           const rocksdb::Slice* existing_value,
                           const std::deque<std::string>& operand_list,
                           std::string* new_value,
                           rocksdb::Logger* logger) const override {
        // operand_list содержит последовательность операций объединения, front() первый операнд
        // Пример: конкатенация всех операндов
        for (const std::string& operand : operand_list) {
            *new_value += operand + " ";
        }
        // Если существующее значение существует, добавьте его к результату
        if (existing_value) {
            *new_value += existing_value->ToString();
        }
        return true;
    }
    // Метод для выполнения частичного объединения (Partial Merge)
    virtual bool PartialMerge(const rocksdb::Slice& key,
                              const rocksdb::Slice& left_operand,
                              const rocksdb::Slice& right_operand,
                              std::string* new_value,
                              rocksdb::Logger* logger) const override {
        // Реализуйте вашу логику частичного объединения данных (Partial Merge) здесь
        // Пример: конкатенация левого и правого операндов
        *new_value = left_operand.ToString() + " " + right_operand.ToString();
        return true;
    }
    // Возвращаем имя оператора объединения
    virtual const char* Name() const override {
        return "MyMergeOperator";
    }
};




void listFiles(const fs::path& dirPath) {
    for (const auto& entry : fs::recursive_directory_iterator(dirPath)) {
        if (fs::is_regular_file(entry)) {
            std::cout << entry.path() << std::endl;
        }
    }
}

Searcher::Searcher(){}

Searcher::Searcher(Request& r){
	this->index = r.index;
	this->treeBakets = new Btree(("./data/" + r.index  + "/testdb").c_str(), 1, true);
	this->req = r;
}


map<string, string> Searcher::GetBakets() {
	return this->treeBakets->GetData(this->req.start_time, this->req.end_time);
}

vector<string> GetUUIDtoActionsByRequest() {

}

std::vector<std::string> splitString(const std::string& input) {
    std::vector<std::string> words;
    std::string word;
    for (char c : input) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

void GetUUIDsFromFile(vector<string>& uuids, const string& path) {
	    std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		std::cerr << "Не удалось открыть файл" << std::endl;
		return;
	}
	string line;
	while (std::getline(inputFile, line)) {
		uuids.push_back(line);
	}
	inputFile.close();
}


std::vector<std::string> GetUIDsByKWordAndWord(const std::string path, const std::string word) {
	cout << "Word: " << word << " Path: " << path << endl;
	rocksdb::Options options;
    options.create_if_missing = true;
        options.merge_operator.reset(new MyMergeOperator);


	rocksdb::DB* dbase;
	rocksdb::Status status = rocksdb::DB::OpenForReadOnly(options, path, &dbase);
	if (status.ok()) {

		rocksdb::ReadOptions read_options;

		string value;
		rocksdb::Status read_status;
		cout << "WORD " << word << endl;
		read_status = dbase->Get(read_options, word, &value);
//		read_status = dbase->Get(read_options, "\"" + word + "\"", &value);
//		rocksdb::Status read_status = dbase->Get(read_options, word, &value);
		if (read_status.ok()) {
			vector<string> vecUUID = splitString(value);
			if (vecUUID.size() >= 50) {
				GetUUIDsFromFile(vecUUID, vecUUID[0]);
			}
			return vecUUID;
		} else {
			cout << "ERROR read: " << read_status.ToString() << endl;
		}
	} else {
		cout << "ERROR OPEN DB\n";
	}
	cout << "Here11\n";
	delete dbase;
	cout << "Here12\n";
	return std::vector<string>();
}


vector<string> GetDataByUUIDVec(vector<string>& UUIDs, string path) {
	 rocksdb::Options options;
	options.create_if_missing = true;
	vector<string> data;
        rocksdb::DB* dbase;
        rocksdb::Status status = rocksdb::DB::OpenForReadOnly(options, path, &dbase);
	for (auto uuid : UUIDs) {
      		if (status.ok()) {

                	rocksdb::ReadOptions read_options;

                	string value;
                	rocksdb::Status read_status = dbase->Get(read_options, uuid, &value);
                	if (read_status.ok()) {
				data.push_back(value);
	                } else {
        	                cout << "ERROR read: " << read_status.ToString() << endl;
        	        }

        	} else {
                	cout << "ERROR OPEN DB\n";
        	}
	}
	cout << "Here1\n";
	delete dbase;
	cout << "Here2\n";

	return data;

}


string Searcher::GetJsonString() {
	map<string, map<string, vector<string>>> MapKeyWordUUID; // Map {KEYword: pair<Baket.id(path), vector<UUID> >}
	for (auto el : GetBakets()) {
		cout << "Est\n";
		for (auto pairKeyVal : this->req.keyWords) {
			string keyWord = pairKeyVal.first;
			Baket b = Baket(el.second, this->index);
			string id = b.GetBIbyKEYword(keyWord);
			cout << "PATH: " << b.path + "/BI/" + id.substr(0, 2) + "/" + id.substr(2, 2) + "/" + id << endl;
			auto vec = GetUIDsByKWordAndWord(b.path + "/BI/" + id.substr(0, 2) + "/" + id.substr(2, 2) + "/" + id, pairKeyVal.second);
			MapKeyWordUUID[keyWord][b.path].insert(MapKeyWordUUID[keyWord][b.path].end(), vec.begin(), vec.end());
		}
	}


	std::unordered_map<string, int> mIntersection;
	map<string, vector<string>> pathUUID;
	int lvl = 0;
	int lastLVL = MapKeyWordUUID.size();
	for (auto keyMap : MapKeyWordUUID) {
		for (auto pathVec : keyMap.second) {
			for (auto el : pathVec.second) {
				if (mIntersection[el] == lvl) {
					mIntersection[el]++;
					if (lvl == lastLVL - 1) {
						pathUUID[pathVec.first].push_back(el);
					}
				}
			}
		}
		lvl++;
	}
	string result = "[";
	for (auto p : pathUUID) {
		for (auto el : GetDataByUUIDVec(p.second, p.first + "/Actions")) {
			cout << el << endl;
			result += el + ",";
		}
	}

	if (result != "[") {
		result.erase(result.size() - 1);
	}

	result += "]";
	cout << "Try Close BTree\n";
	this->treeBakets->Close();
	this->treeBakets = nullptr;
	cout << "Close BTree\n";

	return result;
}


void Searcher::PrintAll(const std::string& dir) {

	map<string, map<string, vector<string>>> MapKeyWordUUID; // Map {KEYword: pair<Baket.id(path), vector<UUID> >}
	for (auto el : GetBakets()) {
		cout << "Est\n";
		for (auto pairKeyVal : this->req.keyWords) {
			cout << "wan\n";
			string keyWord = pairKeyVal.first;
			cout << "twon " << el.second << endl;
			Baket b = Baket(el.second, this->index);
			cout << "trin\n";
			string id = b.GetBIbyKEYword(keyWord);
//			std::cout << "Get sUCSess\n";
			cout << "PATH: " << b.path + "/BI/" + id.substr(0, 2) + "/" + id.substr(2, 2) + "/" + id << endl;
			auto vec = GetUIDsByKWordAndWord(b.path + "/BI/" + id.substr(0, 2) + "/" + id.substr(2, 2) + "/" + id, pairKeyVal.second);
			MapKeyWordUUID[keyWord][b.path].insert(MapKeyWordUUID[keyWord][b.path].end(), vec.begin(), vec.end());

//			cout << el.first << " " << el.second << endl;
		}
	}


/*
	vector<vector<string>> VECvecUUID;
	for (auto pairKeyVal : this->req.keyWords) {
		cout << "PAIR " << pairKeyVal.first << " " << pairKeyVal.second << endl;
		vector<string> v;
		for (auto el : GetBakets()) {
			string keyWord = pairKeyVal.first;
			Baket b = Baket(el.second);
			string id = b.GetBIbyKEYword(keyWord);
//			std::cout << "Get sUCSess\n";
			auto vec = GetUIDsByKWordAndWord(b.path + "/BI/" + id.substr(0, 2) + "/" + id.substr(2, 2) + "/" + id, pairKeyVal.second);
			//VECvecUUID.push_back(vec);
			v.insert(v.end(), vec.begin(), vec.end());
//			cout << el.first << " " << el.second << endl;
		}
		VECvecUUID.push_back(v);
	}
*/

//	cout << "Peresecheniya:\n";

//	for (auto p1 : VECvecUUID) {
//		for (auto p2 : p1) {
//			cout << p2 << " ";
//		}
//		cout << endl;
//	}


	std::unordered_map<string, int> mIntersection;
	map<string, vector<string>> pathUUID;
	int lvl = 0;
	int lastLVL = MapKeyWordUUID.size();
	for (auto keyMap : MapKeyWordUUID) {
		for (auto pathVec : keyMap.second) {
			for (auto el : pathVec.second) {
				if (mIntersection[el] == lvl) {
					mIntersection[el]++;
					if (lvl == lastLVL - 1) {
						pathUUID[pathVec.first].push_back(el);
					}
				}
			}
		}
		lvl++;
	}

//	for (auto pp : mIntersection) {
//		cout << pp.first << " " << pp.second << "\n";
//	}
//	cout << "LEVL: " << lvl << endl;

//	vector<string> uuids;
//	for (auto els : mIntersection) {
//		if (els.second == lvl) {
//			cout << "IN " << els.first << " ";
//			uuids.push_back(els.first);
//		}
//	}
//	cout << endl;
//	GetDataByUUIDVec(uuids, "./data/index/181/262/1812626249461584692/Actions");
//	GetDataByUUIDVec(uuids, "./data/index/859/130/8591306228638903464/Actions");

	for (auto p : pathUUID) {
		for (auto el : GetDataByUUIDVec(p.second, p.first + "/Actions")) {
			cout << el << endl;
		}
	}


//    fs::path folderPath = dir; // Замените на путь к вашей папке
//    if (fs::is_directory(folderPath)) {
//        listFiles(folderPath);
//    } else {
//        std::cerr << "Invalid folder path." << std::endl;
//    }


}
