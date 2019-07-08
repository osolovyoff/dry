#include "smtp_socket.h"

SmtpSocket::SmtpSocket(string server_name, size_t port) : _socket(_io_service)
{
	tcp::resolver resolver(_io_service);
	tcp::resolver::query query_server(server_name, boost::lexical_cast<string>(port));
	tcp::resolver::iterator endpoint_iterator = resolver.resolve(query_server);
	boost::asio::connect(_socket, endpoint_iterator);
}