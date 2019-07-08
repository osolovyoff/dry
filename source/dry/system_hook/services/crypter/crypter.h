#pragma once
#include <string>
#include "openssl/rsa.h" 
#include "openssl/pem.h" 
#include <iostream>

#define PUBLIC_KEY   1
#define PRIVATE_KEY  0
const int ms_padding = RSA_PKCS1_OAEP_PADDING;
const int ms_key_length = 8192;
const int ms_max_word_length = ms_key_length / 8;
using size_char = unsigned char;

class Crypto
{
    constexpr char* 

public:
    enum class KeyType: uint8_t
    {
        Public = PUBLIC_KEY,
        Private = PRIVATE_KEY,
    };

	Crypto() = default;
	~Crypto() = default;

    void generate(int bits);
    void create_keyfile(KeyType, const char* filename);

	RSA * create_RSA(RSA *key_pair, int key_type, char *file_key_name);
	int public_encrypt_message(int message_len, size_char* message, size_char *encrypted_message, int padding);
	int private_decrypt_message(int message_len, size_char* encrypted_message, size_char *descrypted_message, int padding);

	void create_encrypted_file(size_char* encrypted_message, RSA * key_pair);
	void create_descrypted_file(size_char* decrypted_message, int decrypt_message_len);

private:
    RSA* _rsa;
};