#ifndef RESTSERVER_H
#define RESTSERVER_H


#include <string>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "QueActions.h"
#include "Action.h"
#include "Request.h"
#include "Searcher.h"



using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;


class RestServer {

public:
	RestServer();
        RestServer(const string& serverREST);

private:
        static void handle_post(http_request request);
	static void handle_get(http_request request);
};


#endif
