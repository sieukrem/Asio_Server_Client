#pragma once

#include <iostream>
#include <optional>
#include <boost/asio.hpp>

namespace ses
{
    class session : public std::enable_shared_from_this<session>
    {

    public:
        // конструктор
        session(boost::asio::ip::tcp::socket&& socket);

        void start();

    private:
        boost::asio::ip::tcp::socket socket;
        boost::asio::streambuf streambuf;
    };

} // namespace ses
