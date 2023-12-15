#include <iostream>
#include <fstream>
#include <random>
#include <thread>
#include <mutex>
#include <csignal>

#include <chrono>
#include <filesystem>

#include "Action.h"
#include "QueActions.h"

#include "Baket.h"
#include "BTree.h"
#include "Request.h"
#include "Searcher.h"
#include "RestServer.h"

#include <rocksdb/db.h>
#include <rocksdb/merge_operator.h>
#include <rocksdb/slice.h>

#include "globals.h"
QueActions<Action>* queueQ;
std::mutex queueQMutex;
int stop = 0;


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
        // Реализуйте вашу логику объединения данных (Full Merge) здесь
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



// Генератор случайных чисел
std::mt19937_64 rng(std::random_device{}());

// Функция для генерации случайной строки заданной длины
std::string generateRandomString(size_t length) {
    std::string randomString;
    randomString.reserve(length);
    // Допустимые символы в строке
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    // Распределение случайных чисел для выбора символов
    std::uniform_int_distribution<size_t> distribution(0, characters.size() - 1);
    for (size_t i = 0; i < length; ++i) {
        randomString += characters[distribution(rng)];
    }
    return randomString;
}




void MakeQueue(QueActions<Action>& que) {
	std::ifstream inputFile("topic.txt"); // Замените "example.txt" на путь к вашему файлу

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return;
    }

    std::string line;
	int i = 0;
    while (std::getline(inputFile, line)) {
	Action act = Action(line);
	act.index = to_string(rand() % 10);
	que.Add(act);
	i++;
    }

    inputFile.close();

}


std::vector<std::string> readLinesFromFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Unable to open the file: " << filename << std::endl;
        return lines; // Возвращаем пустой вектор в случае ошибки
    }

    std::string line;
    while (std::getline(file, line)) {
//        lines.push_back(line);
	cout << "data ";
	cout  << line;
    }
    cout << endl;

    file.close();
    return lines;
}


void printRocksDB(const std::string& db_path) {
	MyMergeOperator merge_operator;

    rocksdb::DB* db;
    rocksdb::Options options;
    options.create_if_missing = true;
	options.merge_operator.reset(new MyMergeOperator);
	cout << "startOpen\n";
    rocksdb::Status status = rocksdb::DB::Open(options, db_path, &db);
	cout << "endOpen\n";
    if (!status.ok()) {
        std::cerr << "Ошибка при открытии базы данных: " << status.ToString() << std::endl;
        return;
    }

    rocksdb::ReadOptions read_options;
    rocksdb::Iterator* it = db->NewIterator(read_options);


    for (it->SeekToFirst(); it->Valid(); it->Next()) {
        std::string key = it->key().ToString();
        std::string value = it->value().ToString();
        std::cout << "Ключ: " << key << ", Значение: " << value << std::endl;
    }

    if (!it->status().ok()) {
        std::cerr << "Ошибка при обходе базы данных: " << it->status().ToString() << std::endl;
    }
	std::cout << "END\n";
    delete it;
    delete db;
}

void printRocksDB2(const std::string& db_path) {
	if ((db_path == "./data/index/136/898/13689823836589038466/Actions") || (db_path == "./data/index/136/898/13689823836589038466/Info")) {
		return;
	}
	MyMergeOperator merge_operator;

    rocksdb::DB* db;
    rocksdb::Options options;
    options.create_if_missing = true;
	options.merge_operator.reset(new MyMergeOperator);
    rocksdb::Status status = rocksdb::DB::Open(options, db_path, &db);
    if (!status.ok()) {
        std::cerr << "Ошибка при открытии базы данных: " << status.ToString() << std::endl;
        return;
    }

    rocksdb::ReadOptions read_options;
    rocksdb::Iterator* it = db->NewIterator(read_options);


    for (it->SeekToFirst(); it->Valid(); it->Next()) {
        std::string key = it->key().ToString();
        std::string value = it->value().ToString();
	if (value.size() >= 1502) {
		readLinesFromFile(value.substr(0, value.find(' ')));
//		cout << "FILE " << value.size() << " " << key << " | " << value << endl;
	}
        std::cout << "Ключ: " << key << ", Значение: " << value << std::endl;
    }

    if (!it->status().ok()) {
        std::cerr << "Ошибка при обходе базы данных: " << it->status().ToString() << std::endl;
    }
	std::cout << "END\n";
    delete it;
    delete db;
}


using namespace std::chrono;


void TestSearch() {
	map<string, string> w = {{"data.body.Event.System.Task", "10"}, {"data.action", "execute"}};
//      map<string, string> w = {{"data.action", "execute"}};
        Request r = Request("1694532139241", "1994732139241", w, "index");
        Searcher s = Searcher(r);
        s.PrintAll("lol");

}



void TestRocksDbSpeed() {
	rocksdb::DB* db;
	        rocksdb::Options options;
        options.create_if_missing = true;
           options.merge_operator.reset(new MyMergeOperator); // Установка вашего функтора объединения
        rocksdb::Status status = rocksdb::DB::Open(options, "./test1", &db);
        if (!status.ok()) {
                cout << "Unable to open database\n";
                throw "Unable to open database";
        }
	auto s1 = chrono::steady_clock::now();
	for (int i = 0; i < 1000000; i++) {
		if (i % 1000 == 0) {
			auto s2 = chrono::steady_clock::now();
			std::cout << i << ") " << chrono::duration_cast<chrono::milliseconds>(s2 - s1).count() << "ms" << std::endl;
			s1 = chrono::steady_clock::now();
		}
		db->Merge(rocksdb::WriteOptions(), "lol", generateRandomString(6) + "gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc6666666666666666666666666666666666666666666gny6rfki8ynf56khfyfhhhbbccvkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkgctyicykccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc66666666666666666666666666666666666666666666666666666666666ggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggtfthvhvhtcthhvbjfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhwgny6rfki8ynf56khfyfhhhbbcfdhfdhuuudbwejwendwnedhw");
	}
	delete db;

}



void listDirectories(const std::string& path) {
    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_directory(entry)) {
		listDirectories(entry.path().string()); // Рекурсивный вызов для вложенных директорий
        } else {
//		cout << "\n\n\n\n\n\n\n\n";
		std::cout << path << std::endl;
		printRocksDB2(path);
		break;
	}
    }
}





class Worker {
public:
    Worker(int numThreads, map<string, Baket*>* IndexLastBaketMAP) : numThreads_(numThreads), IndexLastBaketMAP_(IndexLastBaketMAP), stopFlag_(false) {}

    void Start() {
        for (int i = 0; i < numThreads_; ++i) {
            threads_.emplace_back([this]() {
                WorkerThread();
            });
        }
    }

    void EnqueueTask(const Action& action) {
        std::unique_lock<std::mutex> lock(queueMutex_);
        tasks_.push(action);
        lock.unlock();
        conditionVariable_.notify_one();
    }

    void Stop() {
        stopFlag_ = true;
        conditionVariable_.notify_all();
        for (std::thread& thread : threads_) {
            if (thread.joinable()) {
                thread.join();
            }
        }
	for (auto p : *IndexLastBaketMAP_) {
		delete p.second;
	}
    }

private:
    void WorkerThread() {
        while (true) {
            std::unique_lock<std::mutex> lock(queueMutex_);

//		    std::cout << "queue size: " << tasks_.size() << std::endl; // queue size: 0

            conditionVariable_.wait(lock, [this]() {
                return !tasks_.empty() || stopFlag_;
            });

            if (stopFlag_ && tasks_.empty()) {
//            if (stopFlag_) {
                return; // Завершаем поток, если задачи больше нет и установлен флаг stopFlag_
            }

            Action task = tasks_.front();
            tasks_.pop();
            lock.unlock();
//		cout << (*IndexLastBaketMAP_)[task.index]->end_time << " " << task.GetTime() << endl;
		std::unique_lock<std::mutex> lock2(mapMutex_);

	    if ((*IndexLastBaketMAP_)[task.index]->end_time < task.GetTime()) {
			cout << "Create new BAKet " << (*IndexLastBaketMAP_)[task.index]->end_time << " " << task.GetTime() << endl;
			string NewPath = "./data/" + task.index + "/testdb";
			Btree b = Btree(NewPath.c_str(), 0);
			auto currentTime = std::chrono::system_clock::now();
                	uint64_t currentTimeInSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch()).count();
			delete (*IndexLastBaketMAP_)[task.index];
                	(*IndexLastBaketMAP_)[task.index] = new Baket(currentTimeInSeconds, 5, task.index);
                	b.AddData(to_string((*IndexLastBaketMAP_)[task.index]->start_time), (*IndexLastBaketMAP_)[task.index]->hash, 1);
			b.Close();
	    }
		lock2.unlock();
             (*IndexLastBaketMAP_)[task.index]->Add(task, 1);

        }
    }

    map<string, Baket*>* IndexLastBaketMAP_; // Теперь хранится указатель на Baket
    std::vector<std::thread> threads_;
    int numThreads_;
    std::queue<Action> tasks_;
    std::mutex queueMutex_;
    std::mutex mapMutex_;
    std::condition_variable conditionVariable_;
    std::atomic<bool> stopFlag_; // Флаг для остановки потоков
};


std::string generateRandomJson() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    int a = dis(gen);

    std::ostringstream jsonStream;
    jsonStream << "{\"index\":\"index" << a << "\",\"data\":{";

    int nParams = rand() % 10 + 1;
    // Генерируем несколько случайных полей и значений
    for (int i = 0; i < nParams; ++i) {
        std::uniform_int_distribution<> valueDis(1, 100);
        int value = valueDis(gen);

        jsonStream << "\"field" << i << "\":" << "\"" << value << "\"";

        if (i < nParams - 1) {
            jsonStream << ",";
        }
    }

    jsonStream << "}}";
    cout << jsonStream.str() << endl;

    return jsonStream.str();
}


void start_rest() {
	cout << "start rest\n";
	RestServer serv = RestServer("localhost:8088/api");
/*
	int k = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Action act = Action(generateRandomJson());
//			cout << act.index << " " << i << "\n";
			std::unique_lock<std::mutex> lock(queueQMutex);
			queueQ->Add(act);
			lock.unlock();
		}
			std::this_thread::sleep_for(1ms);
	}
*/

//	MakeQueue(*queueQ);

}


Worker* worker;

void interruptHandler(int signal) {
    worker->Stop();

    std::cout << "Принудительная остановка программы. Выполнение действий перед завершением..." << std::endl;
    std::this_thread::sleep_for(5s);
    // Здесь можно выполнить необходимые действия перед завершением программы
    // Например, сохранить состояние, закрыть файлы, освободить ресурсы и т. д.
    exit(signal); // Завершение программы с указанным кодом возврата
}


int main() {
	signal(SIGINT, interruptHandler);

	queueQ = new QueActions<Action>();
//	exit(0);

//	cout << "2\n";
//	std::this_thread::sleep_for(2000s);
//	exit(2);




//	printRocksDB("./data/index/164/952/16495210996784604711/BI/90/90/9090438969232797043/");
//	printRocksDB("./data/index/136/898/13689823836589038466/Actions");
//	printRocksDB("./data/i7/178/834/17883474622666318159/Actions");

//	exit(1);

//	listDirectories("./data");
//	exit(1);

//	cout << "start\n";
//	for (int i = 0; i < 10; i++) {
//		auto start1 = chrono::steady_clock::now();
//		TestRocksDbSpeed();
//		auto start2 = chrono::steady_clock::now();
//		std::cout << i << ") " << chrono::duration_cast<chrono::milliseconds>(start2 - start1).count() << "ms" << std::endl;
//	}
//	exit(1);

//	uint64_t ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//	std::cout << ms << std::endl;
//	exit(0);


//	map<string, string> w = {{"data.body.Event.System.Task", "10"}, {"data.action", "execute"}};
//	map<string, string> w = {{"data.action", "execute"}};


//	map<string, string> w = {{"data.scope_id", "c1f2bfb4-7ac4-46d5-9107-a1fa035a78f2"}};
//	map<string, string> w = {{"data.tag", "wineventlog"}, {"data.corrections.expected_datetime_formats.", "DATETIME_ISO8601"}};


//	map<string, string> w = {{"data..score", "100"}, {"data..last_name", "Ivanov"}};
//	{"index":"index2","data":{"field0":"5","field1":"44","field2":"22"}}

//	map<string, string> w = {{"field0", "100"}};
//	Request r = Request("1695748426", "2695748426", w, "index1");
//	Searcher s = Searcher(r);
//	cout << "JS: " << s.GetJsonString() << endl;
//	cout << "end\n";
//	exit(1);

//	std::thread thr2(start_rest);

//	std::this_thread::sleep_for(1800s);

//	exit(0);

	map<string, Baket*> IndexLastBaketMAP;



//	Btree backets = Btree("./testdb", 0);
	//Ключ: data.body.Event.System.Task, Значение: 6613064059438764800
	//Ключ: data.category.low, Значение: data/index/702/231/7022314576534891456
	//Ключ: data.object.name, Значение: data/index/702/231/7022314576534891456
	//Ключ: data.status, Значение: 1822355192588271656
//	printRocksDB("data/index/182/564/18256464624817333207/BI/66/13/6613064059438764800");
//	printRocksDB("./data/index/182/564/18256464624817333207/BI/75/05/7505263013960753053");
//	printRocksDB("./data/index/182/564/18256464624817333207/Info");
//	printRocksDB("./testdb");

	std::thread thr(start_rest);


//	std::this_thread::sleep_for(180s);
//	thr.join();

//	Baket b(currentTimeInSeconds, 2500000);
//	backets.AddData(to_string(b.start_time), b.hash, 1);
	cout << "Stop\n";


//	std::this_thread::sleep_for(20000s);

	int numThreads = 2; // Указать количество потоков
	worker = new Worker(numThreads, &IndexLastBaketMAP); // Передаем Baket в Worker
	worker->Start();


//	exit(0);
	for (int i = 0; i < 1; i++) {
		int u = 0;
		auto start = chrono::steady_clock::now();
//		while (queue.GetSize() != 0) {
		while (true) {
			std::unique_lock<std::mutex> lock(queueQMutex);
//			cout << "Size: " << queueQ->GetSize()  << endl;


			if (queueQ->GetSize() == 0) {
//				std::this_thread::sleep_for(20ms);
//				if (queueQ->GetSize() == 0) {
//					break;
//				}

				continue;
				//break;
			}
			//continue;
//			cout << "Here\n";
//			if (u % 10000 == 0) {
//				auto end = chrono::steady_clock::now();
//				std::cout << u << ") " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << std::endl;
//				start = chrono::steady_clock::now();
//			}
			Action a = queueQ->Get();
			lock.unlock();
			if (!IndexLastBaketMAP[a.index]) {
				string NewPath = "./data/" + a.index +  "/testdb";
				Btree b = Btree(NewPath.c_str(), 0); // MB change a.index to hash(a.index)
				auto currentTime = std::chrono::system_clock::now();
				uint64_t currentTimeInSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch()).count();

				IndexLastBaketMAP[a.index] = new Baket(currentTimeInSeconds, 5, a.index);
				b.AddData(to_string(IndexLastBaketMAP[a.index]->start_time), IndexLastBaketMAP[a.index]->hash, 1);
				b.Close();
			}
			worker->EnqueueTask(a);
//			cout << "GOOD ADD " << u << endl;
//			b.Add(a, 1);
			u++;

		}

//		MakeQueue(*queueQ);
//		auto end = chrono::steady_clock::now();
//		std::cout << "last) " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << std::endl;


	}
		cout<< "END\n";
	    worker->Stop();
		cout<< "END2\n";


}
