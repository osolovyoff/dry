#include "smtp_client.h"
#include <iostream>
#include <sstream>

std::string SmtpClient::encode_base64(const std::string & message)
{
	cout << "encode_base64 working..." << endl;
	return std::string(base64_message(message.c_str()), base64_message(message.c_str() + message.length()));
}

void SmtpClient::send_message(const string& server_name, size_t port, const string& username, const string& password, const string& message_sender,
	const string& message_receiver, const string& subject_message, const string& message)
{
	cout << "send message working..." << endl;
	static const string newline = "\r\n";

	SmtpSocket socket(server_name, port);
	SmtpOpenSSL ssl_connect(socket.get_socket()->native());
	
	cout << ssl_connect.read_command();
	ssl_connect.write_command(string("EHLO ") + server_name + newline);
	cout << ssl_connect.read_command();
	ssl_connect.write_command(string("AUTH LOGIN") + newline);
	cout << ssl_connect.read_command();
	ssl_connect.write_command(encode_base64(username) + newline);
	cout << ssl_connect.read_command();
	ssl_connect.write_command(encode_base64(password) + newline);
	cout << ssl_connect.read_command();
	ssl_connect.write_command(string("MAIL FROM: <") + message_sender + " >" + newline);
	cout << ssl_connect.read_command();
	ssl_connect.write_command(string("RCPT To:<") + message_receiver + ">" + newline);
	cout << ssl_connect.read_command();
	ssl_connect.write_command(string("DATA") + newline);
	cout << ssl_connect.read_command();
	ssl_connect.write_command(string("From: <") + message_sender + ">" + newline);
	ssl_connect.write_command(string("To: <") + message_receiver + ">" + newline);
	ssl_connect.write_command(string("SUBJECT: ") + subject_message + newline);
	ssl_connect.write_command(newline + message + newline + "." + newline);
	cout << ssl_connect.read_command() << endl;
	ssl_connect.write_command(string("QUIT") + newline);
	cout << ssl_connect.read_command();
}

