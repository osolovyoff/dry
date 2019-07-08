#pragma once

#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>

using boost::asio::ip::tcp;
using namespace std;

class SmtpSocket
{
public:
	SmtpSocket(string server_name, size_t port);
	tcp::socket *get_socket() { return &_socket; }

protected:
	boost::asio::io_service _io_service;
	tcp::socket             _socket;
}; 
