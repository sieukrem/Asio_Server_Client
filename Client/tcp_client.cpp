#include <iostream>
#include "include/tcp_client.h"

namespace Serf {

    tcpClient::tcpClient(const std::string &address, int port) : _socket(_ioContext) {
       // std::cout << "Constructor TCPClient: " << std::endl;
        io::ip::tcp::resolver resolver {_ioContext};
        _endpoints = resolver.resolve(address, std::to_string(port));
    }

    void tcpClient::Run() {
        //std::cout << "Run: " << std::endl;       
        io::async_connect(_socket, _endpoints, 
                          [this](boost::system::error_code ec, io::ip::tcp::endpoint ep) {
                           // std::cout << "Lamda async_connect: " << std::endl;
                                if (!ec)
                                asyncRead();
                            });

        _ioContext.run();
    }

    void tcpClient::Stop() {
       // std::cout << "Stop: " << std::endl;
        boost::system::error_code ec;
        _socket.close(ec);

        if (ec) {
            // process error
        }
    }

    void tcpClient::Post(const std::string &message) {
       // std::cout << "Post: " << std::endl;
        bool queueIdle = _outgoingMessages.empty();
        _outgoingMessages.push(message);

        if (queueIdle) {
            asyncWrite();
        }
    }

    void tcpClient::asyncRead() {
       // std::cout << "asyncRead: " << std::endl;
        io::async_read_until(_socket, _streamBuf, "\n", 
                            [this](boost::system::error_code ec, size_t bytesTransferred) {
                                //std::cout << "Lamda async_read_until: " << "bytesTransferred " << bytesTransferred << std::endl;
                                onRead(ec, bytesTransferred);
                            });
    }

    void tcpClient::onRead(boost::system::error_code ec, size_t bytesTransferred) {
       // std::cout << "onRead: " << std::endl;
        if (ec) {
            Stop();
            return;
        }

        std::stringstream message;
        message << std::istream{&_streamBuf}.rdbuf();
        OnMessage(message.str());
        asyncRead();
    }

    void tcpClient::asyncWrite() {
       // std::cout << "asyncWrite: " << std::endl;
        io::async_write(_socket, io::buffer(_outgoingMessages.front()), 
                        [this](boost::system::error_code ec, size_t bytesTransferred) {
                           // std::cout << "Lamda async_write: " << std::endl;
                            onWrite(ec, bytesTransferred);
                        });
    }

    void tcpClient::onWrite(boost::system::error_code ec, size_t bytesTransferred) {
       // std::cout << "onWrite: " << std::endl;
        if (ec) {
            Stop();
            return;
        }

        _outgoingMessages.pop();

        if (!_outgoingMessages.empty()) {
            asyncWrite();
        }
    }
}