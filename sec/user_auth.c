#include "user_auth.h"
#include <stdio.h>
#include <string.h>

// Dummy user database, because I said so.
static const char *valid_username = "admin";
static const char *valid_password = "password";

int authenticate_user(const char *username, const char *password) {
    return strcmp(username, valid_username) == 0 && strcmp(password, valid_password) == 0;
}
