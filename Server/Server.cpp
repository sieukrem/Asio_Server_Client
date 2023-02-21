#include <iostream>  
#include <boost/asio.hpp>  
  
using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

string read_(tcp::socket & socket) {
    boost::asio::streambuf buf;
    boost::asio::read_until( socket, buf, "\n" );
    string data = boost::asio::buffer_cast<const char*>(buf.data());
       return data;
}  
  
void send_(tcp::socket & socket, const string& message) {
    const string msg = message + "\n";
    boost::asio::write( socket, boost::asio::buffer(message) );
} 

int main() {
boost::asio::io_service io_service;
  
// Слушаем новое соединение 
tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234 ));
  
// Создание сокета 
tcp::socket socket_(io_service);
  
// Ожидаем  соединения  
acceptor_.accept(socket_);
  
// Читаем из сокета 
string message = read_(socket_);
cout << message << endl;
  
//операция записи  
send_(socket_, "Привет с Сервера!");
cout << "Сервер отправил приветственное сообщение клиенту!" << endl;
      return 0;
} 