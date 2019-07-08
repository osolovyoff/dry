#pragma once
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include <openssl/err.h>
#include <memory>
#include <string>

using namespace std;

class SmtpOpenSSL
{
	enum {READ_BUFFER_SIZE = 256 };

public:
	SmtpOpenSSL(int socket, const SSL_METHOD *ssl_method = SSLv23_method());
	~SmtpOpenSSL();

	void   write_command(const string& command);
	string read_command();

protected:
	unique_ptr<SSL_CTX, decltype (SSL_CTX_free)*> _ctx;
	unique_ptr<SSL, decltype (SSL_free)*> _ssl;
};
