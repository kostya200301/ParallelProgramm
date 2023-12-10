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
				//cout << body.serialize() << endl;
				//Action act = Action(body.serialize());
			   	queueQ->push(body.serialize());
				cout << "GOOD add " + body.serialize() << "\n";
                        } else {
                                // Отправить ошибку "BadRequest", если тело запроса не является объектом JSON
                                request.reply(status_codes::BadRequest, U("Invalid JSON format in the request."));
                        }
                } catch (const http_exception& e) {
                        // Отправить ошибку "InternalError", если возникла исключительная ситуация при обработке запроса
                        request.reply(status_codes::InternalError, e.what());
                }}).wait();
}


