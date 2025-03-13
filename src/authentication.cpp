// authentication.cpp
#include "authentication.h"
#include <uuid/uuid.h>

std::string Authentication::generateToken() {
    uuid_t bin_uuid;
    uuid_generate_random(bin_uuid);
    char uuid[37];
    uuid_unparse(bin_uuid, uuid);
    token = uuid;
    return token;
}

bool Authentication::verifyToken(const std::string& token) {
    return token == this->token;
}
