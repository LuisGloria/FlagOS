#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

// Token types
typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_OPERATOR,
    TOKEN_KEYWORD,
    TOKEN_EOF,
    TOKEN_UNKNOWN
} token_type_t;

// Token structure
typedef struct {
    token_type_t type;
    char *value;
} token_t;

// Function prototypes
void parse_script(const char *script);
void execute_command(const char *command);

#endif // PARSER_H
