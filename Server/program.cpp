#include "include/program.h"
#include "include/sesion.h"

namespace prog
{

    program::program(boost::asio::io_context& io_context, std::uint16_t port)
        : io_context(io_context)
        , acceptor  (io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
        {}

    void program::async_accept()
    {
        socket.emplace(io_context);

        acceptor.async_accept(*socket, [&] (boost::system::error_code error)
        {
            std::make_shared<ses::session>(std::move(*socket))->start();
            async_accept();
        });
    }
} // namespace prog