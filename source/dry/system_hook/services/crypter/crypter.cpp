#include "Crypto.h"

#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void Crypto::generate(int bits)
{
    _rsa =  RSA_generate_key(bits, RSA_F4, nullptr, nullptr);
}

void Crypto::create_keyfile(KeyType key_type, const char * filename)
{
    FILE  *file = nullptr;
    if (key_type == KeyType::Private)
    {
        fopen_s(&file, file_key_name, "w");
        PEM_write_RSAPublicKey(file, keypair);
        fclose(file);

        fopen_s(&file, file_key_name, "rb");
        PEM_read_RSAPublicKey(file, &_rsa, nullptr, nullptr);
        fclose(file);
    }
    else if (key_type == KeyType::Public)
    {
        fopen_s(&file, file_key_name, "w");

        const EVP_CIPHER *cipher = EVP_get_cipherbyname("des-ede3-cbc");
        PEM_write_RSAPrivateKey(file, keypair, cipher, nullptr, 0, nullptr, nullptr);
        fclose(file);

        fopen_s(&file, file_key_name, "rb");
        PEM_read_RSAPrivateKey(file, &_rsa, nullptr, nullptr);
        fclose(file);
    }
    else
    {
        assert("wrong key_type");
    }
    EVP_cleanup();
}

int Crypto::public_encrypt_message(int message_len, unsigned char* message, unsigned char* encrypted_message, int padding) 
{    
    const int result = RSA_public_encrypt(message_len, message, encrypted_message, _key, padding);
    return result;
}

int Crypto::private_decrypt_message(int message_len, size_char* encrypted_message, size_char* decrypted_message, int padding) 
{
    const int result = RSA_private_decrypt(message_len, encrypted_message, decrypted_message, _key, padding);
    return result;
}

void Crypto::create_encrypted_file(size_char* encrypted_message) 
{
	FILE* encrypted_file;
	fopen_s(&encrypted_file,"encrypted_file.ini", "w");
    fwrite(encrypted_message, sizeof(*encrypted_message), RSA_size(_rsa), encrypted_file);
    fclose(encrypted_file);
	std::cout << "Encrypted file has been created." << std::endl;
}

void Crypto::create_descrypted_file(size_char* decrypted_message, int decrypt_message_len)
{
	FILE *decrypted_file;
	fopen_s(&decrypted_file, "decrypted_file.ini", "w");
	fwrite(decrypted_message, sizeof(*decrypted_message), decrypt_message_len - 1, decrypted_file);
	fclose(decrypted_file);
	std::cout << "Decrypted file has been created." << std::endl;
}