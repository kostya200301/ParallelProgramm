#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <string>
#include <chrono>
#include <map>
#include <vector>
//#include <nlohmann/json.hpp>
#include <random>
#include "UUID.h"
#include "NER.h"

using namespace std;
using namespace std::chrono;

std::string generateRandomString(size_t length);



class Action {
private:
	string time;
	uint64_t timeInt;

public:
	map<string, vector<string>> data;
	string str;
	string uuid;
	nlohmann::json json;
	string index;
public:
	Action() {
		auto tm = std::chrono::duration_cast<std::chrono::milliseconds>(system_clock::now().time_since_epoch()).count();
		this->time = to_string(tm);
		this->timeInt = tm;
		this->uuid = UUID::GetUUID();
		this->index = "default";
	}

//	~Action() {
//		cout << "DESTRUCKTOR: " << time << endl;
//	}

	Action(std::string json_) {
		this->str = json_;
		NER nerser = NER(json_);
		this->json = nerser.GetJSON();
		this->uuid = UUID::GetUUID();
		auto currentTime = std::chrono::system_clock::now();
                uint64_t currentTimeInSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch()).count();
                this->time = to_string(currentTimeInSeconds);
                this->timeInt = currentTimeInSeconds;

		if (json.find("index") != json.end()) {
			this->index = json["index"];
		} else {
			cout << "Error. Not 'index' in JSON action\n";;
			//throw "Error. Not 'index' in JSON action";
		}
		if (json.find("data") != json.end()) {
			this->json = json["data"];
		} else {
			cout << "Error. Not 'data' in JSON action\n";;
			//throw "Error. Not 'data' in JSON action";
		}


	}


	void GetRand() {
		vector<string> names = {"message", "info", "about", "human", "yesterday", "name", "date"};
		for (auto n : names) {
			vector<string> v1;
			for (int i = 0; i < 5; i++) {
				v1.push_back(generateRandomString(3));
			}
			data[n] = v1;
			for (auto p : v1) { this->str += p + " ";}
		}
	}

	uint64_t GetTime() {
		return this->timeInt;
	}

	string GetTimeS() {
		return this->time;
	}
};


#endif
