#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *current_pos;
static char current_char;

static void next_char() {
    current_char = *current_pos++;
}

static token_t get_next_token() {
    while (current_char != '\0') {
        if (isspace(current_char)) {
            next_char();
            continue;
        }
        if (isalpha(current_char)) {
            // Simple identifier token
            char buffer[128];
            size_t i = 0;
            while (isalnum(current_char) || current_char == '_') {
                buffer[i++] = current_char;
                next_char();
            }
            buffer[i] = '\0';
            return (token_t){TOKEN_IDENTIFIER, strdup(buffer)};
        }
        if (isdigit(current_char)) {
            // Simple number token
            char buffer[128];
            size_t i = 0;
            while (isdigit(current_char)) {
                buffer[i++] = current_char;
                next_char();
            }
            buffer[i] = '\0';
            return (token_t){TOKEN_NUMBER, strdup(buffer)};
        }
        next_char();
    }
    return (token_t){TOKEN_EOF, NULL};
}

void parse_script(const char *script) {
    current_pos = script;
    next_char();
    token_t token;
    while ((token = get_next_token()).type != TOKEN_EOF) {
        // Execute commands based on token type
        if (token.type == TOKEN_IDENTIFIER) {
            execute_command(token.value);
        }
        free(token.value);
    }
}

void execute_command(const char *command) {
    // Simple command execution based on the identifier
    if (strcmp(command, "say_hello") == 0) {
        printf("Hello, World!\n");
    } else {
        printf("Unknown command: %s\n", command);
    }
}

//once again, I don't know what I'm doing.
