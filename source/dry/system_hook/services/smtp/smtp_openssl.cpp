#include "smtp_openssl.h"
#include <iostream>

//https://wiki.openssl.org/index.php/SSL/TLS_Client
SmtpOpenSSL::SmtpOpenSSL(int socket, const SSL_METHOD *ssl_method) : _ctx(nullptr, SSL_CTX_free), _ssl(nullptr, SSL_free)
{
	_ctx = decltype(_ctx) (SSL_CTX_new(ssl_method), SSL_CTX_free);	
	_ssl = decltype(_ssl) (SSL_new(_ctx.get()), SSL_free);
	const int result_set_fd = SSL_set_fd(_ssl.get(), socket);
	const int result_connect = SSL_connect(_ssl.get());
	
}

void SmtpOpenSSL::write_command(const string& command)
{
	const int result = SSL_write(_ssl.get(), command.c_str(), command.length());
}

string SmtpOpenSSL::read_command()
{
	char buffer_message[READ_BUFFER_SIZE];

	string result_command;
	while (true)
	{
		const int result_read = SSL_read(_ssl.get(), buffer_message, READ_BUFFER_SIZE);
		result_command += string(buffer_message, buffer_message + result_read);
		return result_command;
	}
}

SmtpOpenSSL::~SmtpOpenSSL()
{
	SSL_shutdown(_ssl.get());
}