#include "user.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <bcrypt.h>

#define MAX_USERS 100
static user_t user_db[MAX_USERS];
static uint32_t user_count = 0;

void user_init() {
    memset(user_db, 0, sizeof(user_db));
}

int create_user(const char *username, const char *password, uint8_t role) {
    if (user_count >= MAX_USERS) {
        return -1; // User database full
    }

    // Check if username already exists
    for (uint32_t i = 0; i < user_count; i++) {
        if (strcmp(user_db[i].username, username) == 0) {
            return -2; // Username already taken
        }
    }

    user_db[user_count].user_id = user_count; // Simple user ID assignment
    strncpy(user_db[user_count].username, username, MAX_USERNAME_LENGTH);

    if (bcrypt_hashpw(password, bcrypt_gensalt(), user_db[user_count].password_hash) != 0) {
        return -3;
    }

    user_db[user_count].role = role;
    user_count++;
    return 0; // Success! I think.
}

int authenticate_user(const char *username, const char *password) {
    for (uint32_t i = 0; i < user_count; i++) {
        if (strcmp(user_db[i].username, username) == 0) {
            if (bcrypt_checkpw(password, user_db[i].password_hash) == 0) {
                return user_db[i].user_id; // Authentication successful now start working
            } else {
                return -1; // Incorrect password u dumbass
            }
        }
    }
    return -2; // User not found, damn
}

void delete_user(uint32_t user_id) {
    for (uint32_t i = 0; i < user_count; i++) {
        if (user_db[i].user_id == user_id) {
            for (uint32_t j = i; j < user_count - 1; j++) {
                user_db[j] = user_db[j + 1];
            }
            user_count--;
            return;
        }
    }
}
