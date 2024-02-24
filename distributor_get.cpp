#include <iostream>
#include <thread>
#include <vector>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>
#include <cpprest/http_listener.h>

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace web::http::experimental::listener;

int work = 1;

vector<pair<string, int>> servers;
vector<string> results;

void initialize() {
    for (int i = 0; i < 1; ++i) {
        servers.push_back({"localhost", 5002 + i});
        results.push_back("");
    }
}

void get_serv_json(string u, int port, vector<string>& results, int a, string req_string) {
    http_client client(U("http://" + u + ":" + to_string(port) + "/api"));

    http_request request(methods::GET);
    request.headers().set_content_type(U("application/json"));
    request.set_body(req_string, "application/json");

    client.request(request).then([](http_response response) {
        if (response.status_code() == status_codes::OK) {
            return response.extract_string();
        } else {
            return pplx::task_from_result(U("Error: ") + response.to_string());
        }
    }).then([&results, &a, &u, &port](pplx::task<string> previousTask) {
        try {
            string response = previousTask.get();
            results[a] = response;
            cout << "Response from the server http://" << u << ':' << port << "/api: " << response << '\n';
        } catch (const std::exception& e) {
            results[a] = "{}";
            cout << "Error: " << e.what() << '\n';
        }
    }).wait();
}

void handle_get(http_request request) {
    request.extract_json().then([request](pplx::task<json::value> task) {
            try {
                const json::value& body = task.get();
                if (body.is_object()) {
                    string req_string = body.serialize();
                    cout << "Received GET-request\n";

                    vector<thread> thread_vec;

                    for (int a = 0; a < servers.size(); a++) {
                        thread t(get_serv_json, servers[a].first, servers[a].second, ref(results), a, req_string);
                        thread_vec.push_back(move(t));
                    }

                    for (int i = 0; i < thread_vec.size(); i++){
                        thread_vec[i].join();
                    }

                    string s = "[";
                    for (int i = 0; i < results.size(); i++) {
                        if (results[i].size() != 2) {
                            s += results[i].substr(1, results[i].size() - 2) + ", ";
                        }
                    }

                    s = s.substr(0, s.size() - 2);
                    s += "]";

                    cout << "s = " << s << "\n\n";
                    request.reply(status_codes::OK, U(s), U("application/json"));
                } else {
                    request.reply(status_codes::BadRequest, U("Invalid JSON format in the request."));
                }
            } catch (const http_exception& e) {
                request.reply(status_codes::InternalError, e.what());
    }}).wait();
}

int main() {
    initialize();

    http_listener listener("http://localhost:8081/api");
    listener.support(methods::GET, handle_get);
    try {
        listener.open().wait();
        cout << "Listening for GET-requests at: " << listener.uri().to_string() << '\n';
        while (work) {
            this_thread::sleep_for(chrono::seconds(1));
        }
        listener.close().wait();
    } catch (const exception& e) {
        cout << e.what() << '\n';
    }

    return 0;
}