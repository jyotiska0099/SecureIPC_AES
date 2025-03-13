#include "ipc_shared_memory.h"
#include "aes_encryption.h"
#include "authentication.h"
#include <iostream>
#include <vector>

int main() {
    // Create shared memory
    IPC_SharedMemory shm;
    key_t shmKey = 12345; // Renamed variable
    int shmid = shm.createSharedMemory(shmKey, 1024);
    void* shmaddr = shm.attachSharedMemory(shmid);

    // Generate authentication token
    Authentication auth;
    std::string token = auth.generateToken();
    std::cout << "Token: " << token << std::endl;

    // Encrypt message using AES
    AES_Encryption aes;
    std::vector<unsigned char> encryptionKey = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    std::vector<unsigned char> message = {0x48, 0x65, 0x6c, 0x6c, 0x6f}; // "Hello"
    std::vector<unsigned char> encryptedMessage = aes.encrypt(message, encryptionKey);

    // Send encrypted message via shared memory
    std::copy(encryptedMessage.begin(), encryptedMessage.end(), static_cast<unsigned char*>(shmaddr));

    // Verify authentication token
    if (auth.verifyToken(token)) {
        std::cout << "Authentication successful." << std::endl;
    } else {
        std::cout << "Authentication failed." << std::endl;
    }

    // Detach and remove shared memory
    shm.detachSharedMemory(shmaddr);
    shm.removeSharedMemory(shmid);

    return 0;
}
