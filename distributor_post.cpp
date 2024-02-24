#include <iostream>
#include <mutex>
#include <set>
#include <vector>
#include "cpp-httplib/httplib.h"
#include "json/single_include/nlohmann/json.hpp"

using namespace std;

mutex mtx;

int k = 4;
int req_num = 0;
set<pair<int, int>> servers_workloads;
vector<pair<string, int>> servers;
vector<int> workload_distribution;

int pow(int n, int m) {
    int res = 1;
    while (m != 0) {
        res *= n;

        m -= 1;
    }

    return res;
}

void initialize() {
    for (int i = 0; i < 2; ++i) {
        servers_workloads.insert({0, i});
        servers.push_back({"localhost", 8088 + i});
        workload_distribution.push_back(pow(k, i));
    }


}

int main() {
    initialize();

    httplib::Server server;
    cout << "Listening for POST-requests at : http://192.168.1.3:8080/api\n";

    server.Post("/api", [](const httplib::Request req, httplib::Response res) {
        cout << "Received POST-request:\n";

        mtx.lock();
        req_num += 1;
        int index;

        for (int i = workload_distribution.size() - 1; i >= 0; --i) {
            if (req_num % workload_distribution[i] == 0) {
                index = i;
                break;
            }
        }

        set<pair<int, int>>::iterator it = servers_workloads.begin();

        for (int i = 0; i < index; ++i) {
            it++;
        }
        int server_number = it->second;
        servers_workloads.erase(it);

        res.status = httplib::OK_200;
        httplib::Client client(servers[server_number].first, servers[server_number].second);
        auto response = client.Post("/api", req.body, "application/json");

        if (response && response->status == 200) {
            cout << "Received response from server: http://" << servers[server_number].first << ':';
            cout << servers[server_number].second << "/api: " << response->body << '\n';

            nlohmann::json response_json = nlohmann::json::parse(response->body);

            int new_workload = response_json["load"];

            servers_workloads.insert({new_workload, server_number});
        } else {
            res.set_content("Error forwarding the request", "text/plain");
        }
        cout << '\n';
        mtx.unlock();
    });

    server.listen("192.168.1.3", 8080);
}