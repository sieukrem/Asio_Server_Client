#include "include/program.h"
#include "include/sesion.h"

namespace serf
{

    program::program():
         acceptor  (io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1234))
        {
            async_accept();
            io_context.run();
        }

    void program::async_accept()
    {
        socket.emplace(io_context);

        acceptor.async_accept(*socket, [&] (boost::system::error_code error)
        {
            std::make_shared<serf::session>(std::move(*socket))->start();
            
            async_accept();
        });
        
    }
} // namespace serf