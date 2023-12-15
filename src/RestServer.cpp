#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "RestServer.h"



#include "globals.h"

#include <thread>

//#include "DomainResolver.h"
using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

int work = 1;

RestServer::RestServer() {}

RestServer::RestServer(const string& serverREST) {
//                http_listener listener("http://localhost:8080/api");
                http_listener listener("http://" + serverREST);
                listener.support(methods::POST, handle_post);
	 	listener.support(methods::GET, handle_get);


                try {
                        listener.open().wait();
                        std::cout << "Listening for requests at: " << listener.uri().to_string() << std::endl;
                        //std::cin.get();
			while (work) {
                                this_thread::sleep_for(std::chrono::seconds(1));
			}
                        listener.close().wait();
                } catch (const std::exception& e) {
                        std::cout << e.what() << std::endl;
                }
}


void RestServer::handle_post(http_request request) {
                // Извлечь JSON-тело из запроса
                request.extract_json().then([request](pplx::task<json::value> task) {
                try {
                        const json::value& body = task.get();
                        // Проверить, что полученное тело является объектом JSON
                        if (body.is_object()) {
				cout << "Resive: " << body.serialize() << endl;
				request.reply(status_codes::OK, "ok");
				Action act = Action(body.serialize());
			   	queueQ->Add(act);
				cout << "GOOD add\n";
                        } else {
                                // Отправить ошибку "BadRequest", если тело запроса не является объектом JSON
                                request.reply(status_codes::BadRequest, U("Invalid JSON format in the request."));
                        }
                } catch (const http_exception& e) {
                        // Отправить ошибку "InternalError", если возникла исключительная ситуация при обработке запроса
                        request.reply(status_codes::InternalError, e.what());
                }}).wait();
}


void RestServer::handle_get(http_request request) {
                // Извлечь JSON-тело из запроса
                request.extract_json().then([request](pplx::task<json::value> task) {
                try {
                        const json::value& body = task.get();
                        // Проверить, что полученное тело является объектом JSON
                        if (body.is_object()) {
				string startTime, endTime, index;
				cout << "Received GET: " << body.serialize() << endl;

				if (body.has_field(U("startTime"))) {
					startTime = body.at(U("startTime")).as_string();
				} else {
					request.reply(status_codes::InternalError, "Поле 'startTime' отсутствует.");
					std::cout << "Поле 'startTime' отсутствует." << std::endl;
					return;
				}

				if (body.has_field(U("endTime"))) {
					endTime = body.at(U("endTime")).as_string();
				} else {
					request.reply(status_codes::InternalError, "Поле 'endTime' отсутствует.");
					std::cout << "Поле 'endTime' отсутствует." << std::endl;
					return;
				}

				if (body.has_field(U("index"))) {
					index = body.at(U("index")).as_string();
				} else {
					request.reply(status_codes::InternalError, "Поле 'index' отсутствует.");
					std::cout << "Поле 'index' отсутствует." << std::endl;
					return;
				}

				std::map<std::string, std::string> w;
				for (auto it = body.as_object().cbegin(); it != body.as_object().cend(); ++it) {
					if (it->first != U("startTime") && it->first != U("endTime") && it->first != U("index")) {
						w[it->first] = it->second.serialize();
						cout << it->first << " " << it->second.serialize() << endl;
					}
				}

				//w = {{"a","1"}, {"b","1"}};

				Request r = Request(startTime, endTime, w, index);
				Searcher s = Searcher(r);

				string result = s.GetJsonString();
//				string result = "[]";
				cout << "RES: " << result << endl;
				request.reply(status_codes::OK, result);

				//Action act = Action(body.serialize());
			   	//queueQ->Add(act);
				//cout << "GOOD add\n";
                        } else {
                                // Отправить ошибку "BadRequest", если тело запроса не является объектом JSON
                                request.reply(status_codes::BadRequest, U("Invalid JSON format in the request."));
                        }
			cout << "End priem\n";
                } catch (const http_exception& e) {
                        // Отправить ошибку "InternalError", если возникла исключительная ситуация при обработке запроса
                        request.reply(status_codes::InternalError, e.what());
                }}).wait();
	cout << "End handle_get\n";
}


