// authentication.h
#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>

class Authentication {
public:
    /**
     * Generates a unique authentication token.
     * @return The generated token.
     */
    std::string generateToken();

    /**
     * Verifies if the given token is valid.
     * @param token The token to verify.
     * @return True if the token is valid, false otherwise.
     */
    bool verifyToken(const std::string& token);
private:
    std::string token;
};

#endif // AUTHENTICATION_H
