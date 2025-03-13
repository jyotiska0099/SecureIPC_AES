// aes_encryption.cpp
#include "aes_encryption.h"

std::vector<unsigned char> AES_Encryption::encrypt(const std::vector<unsigned char>& plainText, const std::vector<unsigned char>& key) {
    AES aes(AESKeyLength::AES_128);
    std::vector<unsigned char> cipherText = aes.EncryptECB(plainText, key);
    return cipherText;
}

std::vector<unsigned char> AES_Encryption::decrypt(const std::vector<unsigned char>& cipherText, const std::vector<unsigned char>& key) {
    AES aes(AESKeyLength::AES_128);
    std::vector<unsigned char> plainText = aes.DecryptECB(cipherText, key);
    return plainText;
}
