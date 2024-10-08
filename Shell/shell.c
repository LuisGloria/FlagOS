#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "shell.h"
#include "user.h"
#include "pkg_manager.h"
#include "parser.h"

#define MAX_COMMAND_LENGTH 128
#define MAX_ARGS 10
#define MAX_PACKAGES 10

//For fuck's sake don't let furry developers
//touch this code, I beg you!

void shell_loop();
void execute_command(char *command);
void lst();
void gotodir(char *path);
void say(char *message);
void listpkg();
void changeclr(char *color);
void crtdir(char *dir_name);
void rmvdir(char *dir_name);
void shtdwn();

const char *installed_packages[MAX_PACKAGES] = {
    "package1", "package2", "package3", "package4", "package5"
};

int main() {
    shell_loop();
    return 0;
}

void shell_loop() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("osh> ");
        fgets(command, sizeof(command), stdin);  // Read the command
        command[strcspn(command, "\n")] = 0;  // Remove the newline character

        execute_command(command);
    }
}

void execute_command(char *command) {
    char *args[MAX_ARGS];
    char *token = strtok(command, " ");
    int arg_count = 0;

    while (token != NULL && arg_count < MAX_ARGS) {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    if (arg_count == 0) {
        return;
    }

    if (strcmp(args[0], "lst") == 0) {
        lst();
        return;
    }

    if (strcmp(args[0], "gotodir") == 0) {
        if (arg_count < 2) {
            printf("gotodir: missing argument\n");
        } else {
            gotodir(args[1]);
        }
        return;
    }

    if (strcmp(args[0], "say") == 0) {
        say(args[1]);
        return;
    }

    if (strcmp(args[0], "listpkg") == 0) {
        listpkg();
        return;
    }

    if (strcmp(args[0], "changeclr") == 0) {
        if (arg_count < 2) {
            printf("changeclr: missing argument\n");
        } else {
            changeclr(args[1]);
        }
        return;
    }

    if (strcmp(args[0], "crtdir") == 0) {
        if (arg_count < 2) {
            printf("crtdir: missing argument\n");
        } else {
            crtdir(args[1]);
        }
        return;
    }

    if (strcmp(args[0], "rmvdir") == 0) {
        if (arg_count < 2) {
            printf("rmvdir: missing argument\n");
        } else {
            rmvdir(args[1]);
        }
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    if (strcmp(args[0], "shtdwn") == 0) {
        shtdwn();
        return;
    }

    // Default command execution using fork/execvp
    // IDK what the hell I'm doing.
    int pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        perror("exec");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
    } else {
        wait(NULL);
    }
}

void lst() {
    DIR *dir;
    struct dirent *entry;
    struct stat entry_stat;

    if ((dir = opendir(".")) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &entry_stat) == 0 && S_ISDIR(entry_stat.st_mode)) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

void gotodir(char *path) {
    if (chdir(path) != 0) {
        perror("gotodir");
    }
}

void say(char *message) {
    if (message != NULL) {
        printf("%s\n", message);
    } else {
        printf("\n");
    }
}

void listpkg() {
    printf("Installed Packages:\n");
    for (int i = 0; i < MAX_PACKAGES; i++) {
        if (installed_packages[i] != NULL) {
            printf("- %s\n", installed_packages[i]);
        }
    }
}

void changeclr(char *color) {

    if (strlen(color) == 1) {

        int color_code = atoi(color);

        // Ensure the color code is valid (0-255 for 8-bit colors)
        // 8-bit color my ass
        if (color_code >= 0 && color_code <= 255) {
            printf("\033[38;5;%dm", color_code);
        } else {
            printf("Invalid color code. Must be between 0 and 255.\n");
        }
    } else {
        printf("Invalid color format. Provide a single 8-bit color code.\n");
    }
}

#ifdef _WIN32
void crtdir(char *dir_name) {
    if (mkdir(dir_name) != 0) {
        perror("crtdir");
    }
}
#else
void crtdir(char *dir_name) {
    if (mkdir(dir_name, 0777) != 0) {  // I don't fucking know what I'm doing.
        perror("crtdir");
    }
}
#endif

void handle_create_user(char *username, char *password, uint8_t role) {
    if (create_user(username, password, role) == 0) {
        printf("User created successfully.\n");
    } else {
        printf("Failed to create user.\n");
    }
}

void handle_authenticate_user(char *username, char *password) {
    int user_id = authenticate_user(username, password);
    if (user_id >= 0) {
        printf("Authentication successful. User ID: %d\n", user_id);
    } else {
        printf("Authentication failed.\n");
    }
}

void rmvdir(char *dir_name) {
    if (rmdir(dir_name) != 0) {
        perror("rmvdir");
    }
}

void execute_command(const char *command) {
    if (strcmp(command, "listpkg") == 0) {
        list_installed_packages();
    } else if (strncmp(command, "installpkg ", 11) == 0) {
        install_package(command + 11);
    } else if (strncmp(command, "uninstallpkg ", 13) == 0) {
        uninstall_package(command + 13);
    }
    // Other shell commands
}

void shtdwn() {
    printf("Shutting down...\n");

    // Placeholder: Different platforms will require different implementations here.
    // shutdwn is not working, I'll fix it later, fuck this shit.

    //Dear dev, if you're going to do a pull request.
    //make sure you increment the number on the bottom please.

    //input_hours_wasted_here = 25
    exit(0);
}

void execute_script(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        return;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *script = malloc(filesize + 1);
    fread(script, 1, filesize, file);
    script[filesize] = '\0';

    fclose(file);

    parse_script(script);
    free(script);
}
