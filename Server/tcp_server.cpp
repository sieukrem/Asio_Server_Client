#include "include/tcp_server.h"


#include <iostream>

namespace Serf
{
    using boost::asio::ip::tcp;
    tcpServer::tcpServer(IPV ipv, int port) : _ipVersion(ipv), _port(port),
                                              _acceptor(_ioContext, tcp::endpoint(_ipVersion == IPV::V4 ? tcp::v4() : tcp::v6(), _port))
    {
        //std::cout << "Constructor TCPServer: " << std::endl;
    }

    int tcpServer::Run()
    {
        //std::cout << "Run: " << std::endl;
        try
        {
            startAccept();
            _ioContext.run();
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return -1;
        }
        return 0;
    }
    // Работаем стекстом 
    void tcpServer::Broadcast(const std::string &message)
    {
        
        std::string key = "formula";
        //std::cout << "Broadcast: " << std::endl;
        pars.StringSorting(message);        
        std::string stringformula = pars.TranslateJsonText(key, pars.GetJson());
        auto sumformula = math.Parse(stringformula.begin(), stringformula.end());
        std::string change = std::to_string(sumformula->Evaluate());
        std::string finish = pars.GetId() + ": Сумма: " + change + "\n";
        
        for (auto &connection : _connections)
        {
            if (pars.GetId() == connection->GetUsername())
                connection->Post(finish);
        }
    }

    void tcpServer::startAccept()
    {
        //std::cout << "startAccept: " << std::endl;
        _socket.emplace(_ioContext);

        // асинхронно ждем соединения клиента
        _acceptor.async_accept(*_socket, [this](const boost::system::error_code &error)
                               {
                                            //std::cout << "Lamda async_accept: " << std::endl;
                                            // создаем нового клиента 
                                            auto connection = tcpConnection::Create(std::move(*_socket));
            

        if (OnJoin) {
            OnJoin(connection);
        }
        // Добавляем нашего пользователя
        _connections.insert(connection);
        if (!error) {
            auto massHandler = [this](const std::string& message) { 
                                    //std::cout << "Lamda 1: " << std::endl;
                                    if (OnClientMessage) OnClientMessage(message);                                    
                                };

            auto errorhandler = [&, weak =std::weak_ptr(connection)] {
                                        //std::cout << "Lamda 2: " << std::endl;
                                        if (auto shared = weak.lock(); shared && _connections.erase(shared)) {
                                            if (OnLeave) OnLeave(shared);
                                        }
                                };                   
            connection->Start(massHandler, errorhandler);
        }

        startAccept(); });
    }


}