// ipc_shared_memory.h
#ifndef IPC_SHARED_MEMORY_H
#define IPC_SHARED_MEMORY_H

#include <sys/ipc.h>
#include <sys/shm.h>

class IPC_SharedMemory {
public:
    /**
     * Creates a new shared memory segment.
     * @param key The key for the shared memory segment.
     * @param size The size of the shared memory segment.
     * @return The ID of the shared memory segment.
     */
    int createSharedMemory(key_t key, size_t size);

    /**
     * Attaches to an existing shared memory segment.
     * @param shmid The ID of the shared memory segment.
     * @return A pointer to the attached shared memory.
     */
    void* attachSharedMemory(int shmid);

    /**
     * Detaches from a shared memory segment.
     * @param shmaddr The address of the shared memory segment.
     */
    void detachSharedMemory(void* shmaddr);

    /**
     * Removes a shared memory segment.
     * @param shmid The ID of the shared memory segment.
     */
    void removeSharedMemory(int shmid);
};

#endif // IPC_SHARED_MEMORY_H
