#ifndef IPC_H
#define IPC_H
#include "heap.h"

#define MAX_MESSAGES 128

typedef struct message {
    uint32_t sender_id;
    uint32_t receiver_id;
    char data[256];
} message_t;

typedef struct message_queue {
    message_t messages[MAX_MESSAGES];
    uint32_t head;
    uint32_t tail;
} message_queue_t;

extern message_queue_t ipc_queue;

void send_message(uint32_t receiver_id, const char *data);
void receive_message(message_t *msg);

#endif
