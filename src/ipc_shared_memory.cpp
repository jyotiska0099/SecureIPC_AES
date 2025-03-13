#include "ipc_shared_memory.h"
#include <cstddef> // Include for nullptr

int IPC_SharedMemory::createSharedMemory(key_t key, size_t size) {
    return shmget(key, size, 0666 | IPC_CREAT);
}

void* IPC_SharedMemory::attachSharedMemory(int shmid) {
    return shmat(shmid, nullptr, 0); // Use nullptr instead of NULL
}

void IPC_SharedMemory::detachSharedMemory(void* shmaddr) {
    shmdt(shmaddr);
}

void IPC_SharedMemory::removeSharedMemory(int shmid) {
    shmctl(shmid, IPC_RMID, nullptr); // Use nullptr instead of NULL
}
