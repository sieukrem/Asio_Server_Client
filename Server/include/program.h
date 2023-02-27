#pragma once

#include <iostream>
#include <optional>
#include <boost/asio.hpp>

namespace serf
{
    class program
    {

    public:
        program();

        void async_accept();

    private:
        boost::asio::io_context io_context;
        boost::asio::ip::tcp::acceptor acceptor;
        std::optional<boost::asio::ip::tcp::socket> socket;

    };    

} // namespace serf
