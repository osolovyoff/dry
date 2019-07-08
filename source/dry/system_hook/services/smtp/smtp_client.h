
#include "smtp_openssl.h"
#include <iostream>
#include <sstream>
#include <string>

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include "smtp_socket.h"

using namespace std;
using base64_message = boost::archive::iterators::base64_from_binary<boost::archive::iterators::transform_width<const char*, 6, 8>>;

class SmtpClient
{
public:
	static void send_message( const string& server_name
                            , size_t port
                            , const string& username
                            , const string& password
                            , const string& message_sender
                            , const string& message_receiver
                            , const string& subject_message
                            , const string& message);
private:
	static string encode_base64(const string & message);
};
