// aes_encryption.h
#ifndef AES_ENCRYPTION_H
#define AES_ENCRYPTION_H

#include <vector>
#include "AES.h"

class AES_Encryption {
public:
    /**
     * Encrypts the given plaintext using AES-128 ECB mode.
     * @param plainText The plaintext to encrypt.
     * @param key The encryption key (16 bytes for AES-128).
     * @return The encrypted ciphertext.
     */
    std::vector<unsigned char> encrypt(const std::vector<unsigned char>& plainText, const std::vector<unsigned char>& key);

    /**
     * Decrypts the given ciphertext using AES-128 ECB mode.
     * @param cipherText The ciphertext to decrypt.
     * @param key The decryption key (16 bytes for AES-128).
     * @return The decrypted plaintext.
     */
    std::vector<unsigned char> decrypt(const std::vector<unsigned char>& cipherText, const std::vector<unsigned char>& key);
};

#endif // AES_ENCRYPTION_H
