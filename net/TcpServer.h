//
// Created by YngziJ on 2024/1/4.
//

#ifndef UNTITLED11_TCPSERVER_H
#define UNTITLED11_TCPSERVER_H


#include <asio.hpp>


class TcpConnection;


class TcpServer {


public:
    TcpServer(asio::io_context &io_context, short port)
            : acceptor_(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)) {
        printf("listen on %d\n", port);
    }

    void accept();

    void handle_accept(std::shared_ptr<TcpConnection> new_connection, const std::error_code &error);
private:
    asio::io_context io_context_;
    asio::ip::tcp::acceptor acceptor_;
};


#endif //UNTITLED11_TCPSERVER_H
