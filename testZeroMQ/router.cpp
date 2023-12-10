#include <zmq_addon.hpp>
#include <iostream>
#include <vector>
#include <zmq.hpp>
#include <thread>
using namespace std;


int main() {


    zmq::context_t context(1);
    zmq::socket_t worker(context, ZMQ_ROUTER);
    worker.connect("tcp://localhost:5555");

    std::cout << "Работник готов к работе." << std::endl;

    while (true) {
        zmq::message_t identity;
        if (!worker.recv(identity, zmq::recv_flags::none)) {
            std::cerr << "Ошибка при приеме identity. Код ошибки: " << zmq_errno() << std::endl;
            return 1;
        }

        std::cout << "Получен identity" << std::endl;

        std::vector<zmq::message_t> recv_msgs;
        const auto ret = zmq::recv_multipart(worker, std::back_inserter(recv_msgs));

        if (!ret) {
            std::cerr << "Ошибка при приеме сообщений. Код ошибки: " << zmq_errno() << std::endl;
            return 1;
        }

        std::cout << "Получено " << *ret << " сообщений" << std::endl;

        for (const auto& msg : recv_msgs) {
            std::string taskString(reinterpret_cast<const char*>(msg.data()), msg.size());
            std::cout << "Содержимое сообщения: " << taskString << std::endl;
        }
	std::this_thread::sleep_for(10ms);
    }

    return 0;
}








int main2() {
    zmq::context_t context(1);
    zmq::socket_t worker(context, ZMQ_ROUTER);
    worker.connect("tcp://localhost:5555");

    std::cout << "Сервер-работник готов к работе." << std::endl;

    while (true) {
        zmq::message_t identity;
	cout << "start\n";
        if (!worker.recv(identity, zmq::recv_flags::none)) {
		cout << "in if\n";
            std::cerr << "Ошибка при приеме identity." << std::endl;
            return 1;
        }

	std::cout << "Работник получил identity." << std::endl;

        std::vector<zmq::message_t> recv_msgs;
        const auto ret = zmq::recv_multipart(worker, std::back_inserter(recv_msgs));
        if (!ret) {
            std::cerr << "Ошибка при приеме сообщений." << std::endl;
            return 1;
        }

        std::cout << "Получено " << *ret << " сообщений" << std::endl;

        for (const auto& msg : recv_msgs) {
            std::string taskString(reinterpret_cast<const char*>(msg.data()), msg.size());
            std::cout << "Содержимое сообщения: " << taskString << std::endl;

            // Выполнение задачи (просто добавление "Выполнено!" к тексту задачи)
            taskString += " Выполнено!";

            // Отправка identity
            if (!worker.send(identity, zmq::send_flags::sndmore)) {
                std::cerr << "Ошибка при отправке identity." << std::endl;
                return 1;
            }

            // Пустая заглушка
            zmq::message_t empty;
            if (!worker.send(empty, zmq::send_flags::sndmore)) {
                std::cerr << "Ошибка при отправке пустой заглушки." << std::endl;
                return 1;
            }

	    const zmq::const_buffer taskBuffer(taskString.data(), taskString.size());
            if (!worker.send(taskBuffer, zmq::send_flags::none)) {
                std::cerr << "Ошибка при отправке результата." << std::endl;
                return 1;
            }
        }
    }

    return 0;
}
