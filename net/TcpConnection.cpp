//
// Created by YngziJ on 2024/1/4.
//

#include "TcpConnection.h"

#include "data/global.h"


void TcpConnection::start() {
    auto current_url = current_urls;
    std::string info;

    for (auto url: current_url) {
        info += url.toString().toStdString() + "\n";
    }

    std::string message = "<html><body><h1>" +
                          info +
                          +"</h1></body></html>";


    std::string http_response =
            "HTTP/1.1 200 OK\r\nContent-Length: " + std::to_string(message.length()) + "\r\n\r\n" + message;
    //asio::write(socket_, asio::buffer(http_response));
    asio::async_write(socket_, asio::buffer(http_response),
                      std::bind(&TcpConnection::handle_write, shared_from_this(), std::placeholders::_1,
                                std::placeholders::_2));

}

void TcpConnection::handle_write(const asio::error_code &error, size_t bytes_transferred) {
    if (!error) {
        printf("handle_write\n");
    } else {
        printf("error: %s\n", error.message().c_str());
    }
}


