#include <iostream>  
#include <boost/asio.hpp>  
  
using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

int main() {
    boost::asio::io_service io_service;
  
    // Создание сокета 
    tcp::socket socket(io_service);
  
    // Соединение 
    socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 1234 ));
  
    // Запрос/сообщение от клиента 
     const string msg = "Привет от Клиента!\n";
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