#include <iostream>
#include <vector>
#include <zmq.hpp>
#include <zmq_addon.hpp>
#include <thread>
#include <openssl/ssl.h>
#include "RestServer.h"

#include "globals.h"

using namespace std;

ThreadSafeQueue<string>* queueQ;

void StartRest() {
    RestServer("localhost:8080/api");
}


int main2() {
    zmq::context_t context(1);
    zmq::socket_t dealer(context, ZMQ_DEALER);
    dealer.bind("tcp://*:5555");

    std::cout << "Дилер готов к работе." << std::endl;

    std::string task = "Привет, это сообщение!";
    zmq::message_t zmqMessage(task.data(), task.size());

    // Отправляем сообщение
    if (!dealer.send(zmqMessage, zmq::send_flags::none)) {
        std::cerr << "Ошибка при отправке сообщения. Код ошибки: " << zmq_errno() << std::endl;
        return 1;
    }

    std::cout << "Сообщение успешно отправлено." << std::endl;

    return 0;
}



int main() {


    queueQ = new ThreadSafeQueue<string>();

    std::thread thr(StartRest);

    zmq::context_t context(2);
    zmq::socket_t dealer(context, ZMQ_DEALER);
    dealer.bind("tcp://*:5555");

    std::cout << "Распределяющий сервер готов к работе." << std::endl;

    // Отправка задач работникам
   // for (int taskNumber = 1; taskNumber <= 100; ++taskNumber) {
    while (true){
	if (queueQ->empty()) {
		continue;
	}
	string data;
	queueQ->pop(data);
        std::string task = "Задача " + data;
//        std::string task = "Задача ";
        zmq::message_t zmqMessage(task.data(), task.size());

	    // Отправляем сообщение
	if (!dealer.send(zmqMessage, zmq::send_flags::none)) {
		std::cerr << "Ошибка при отправке сообщения. Код ошибки: " << zmq_errno() << std::endl;
		return 1;
	}

	std::cout << "Сообщение успешно отправлено." << std::endl;
    }

    std::cout << "End sending\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Получение результатов
    std::vector<zmq::message_t> recv_msgs;
    const auto ret = zmq::recv_multipart(dealer, std::back_inserter(recv_msgs));
    std::cout << "End reciv\n";

    if (!ret) {
        std::cerr << "Ошибка при приеме сообщений." << std::endl;
        return 1;
    }


    std::cout << "Получено " << *ret << " сообщений" << std::endl;

    for (const auto& msg : recv_msgs) {
        std::string resultString(reinterpret_cast<const char*>(msg.data()), msg.size());
        std::cout << "Содержимое сообщения: " << resultString << std::endl;
    }

    return 0;
}
