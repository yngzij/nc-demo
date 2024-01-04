//
// Created by YngziJ on 2024/1/4.
//

#include "TcpServer.h"
#include "TcpConnection.h"


void TcpServer::accept() {
    auto new_connection = TcpConnection::create(io_context_);
    acceptor_.async_accept(new_connection->socket(),
                           std::bind(&TcpServer::handle_accept, this, new_connection, std::placeholders::_1));
}

void TcpServer::handle_accept(TcpConnection::TcpConnectionPtr new_connection, const std::error_code &error) {
    if (!error) {
        new_connection->start();
    }

    accept();
}
