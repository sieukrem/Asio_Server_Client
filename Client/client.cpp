#include "include/tcp_client.h"
#include "include/jsonparser.h"
#include <iostream>
#include <thread>

using namespace Serf;

int main(int argc, char* argv[]) {
    tcpClient client {"localhost", 1234};

    jsonparser pars; 
    std::string key = "formula";
    std::string result = "grdeherhe";
    std::string jsontext = "";
    //std::string id = "";

    client.OnMessage = [](const std::string& message) {
         //std::string id = pars.GetParsText(jsontext, message);
         //std::string result = pars.TranslateJsonText(key, jsontext);
        std::cout  << message;
    };

    std::thread t{[&client] () { client.Run(); }};

    while(true) {
        std::string message;
        getline(std::cin, message);

        if (message == "\\q") break;

        client.Post(pars.TranslateTextJson(key, message) + "\n");
    }

    client.Stop();
    t.join();
    return 0;
}












/*

int main() {

    pars::Parser parser;
    std::string inText;

    std::cin >> inText;

    boost::asio::io_service io_service;
  
    // Создание сокета 
    tcp::socket socket(io_service);
  
    // Соединение 
    socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 1234 ));
  
    // Запрос/сообщение от клиента 
    const string msg = parser.TranslateTextJson(inText) + "\n"; 

    boost::system::error_code error;
    boost::asio::write( socket, boost::asio::buffer(msg), error );
     if( !error ) {
        cout << "Клиент отправил приветственное сообщение!" << endl;
     }  
     else {
        cout << "отправить не удалось: " << error.message() << endl;
     }  
  
    // Получение ответа от сервера  
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
     if( error && error != boost::asio::error::eof ) {
        cout << "получить не удалось: " << error.message() << endl;
     }  
     else {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        cout << data << endl;
     }  
     
     return 0;
} 
*/