//
// Created by YngziJ on 2024/1/4.
//

#ifndef UNTITLED11_TCPCONNECTION_H
#define UNTITLED11_TCPCONNECTION_H


#include <memory>
#include <asio.hpp>


class TcpConnection : public std::enable_shared_from_this<TcpConnection> {
public:
    typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

    static TcpConnectionPtr create(asio::io_context &io_context) {
        return TcpConnectionPtr(new TcpConnection(io_context));
        //return std::make_shared<TcpConnection>(io_context);
    }

    asio::ip::tcp::socket &socket() {
        return socket_;
    }

    void start();
private:
    TcpConnection(asio::io_context &io_context)
            : socket_(io_context), io_context_(io_context) {
    }

    asio::ip::tcp::socket socket_;
    asio::io_context &io_context_;

    void handle_write(const asio::error_code &error, size_t bytes_transferred);
};


#endif //UNTITLED11_TCPCONNECTION_H
