#ifndef USER_H
#define USER_H

#include <stdint.h>

#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    uint32_t user_id;
    char username[MAX_USERNAME_LENGTH];
    char password_hash[MAX_PASSWORD_LENGTH]; // Storing a hashed password
    uint8_t role;
} user_t;

// Function prototypes or smth
void user_init();
int create_user(const char *username, const char *password, uint8_t role);
int authenticate_user(const char *username, const char *password);
void delete_user(uint32_t user_id);

#endif