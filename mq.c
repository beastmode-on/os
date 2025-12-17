#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg { long type; char text[50]; };

int main() {
    key_t key = ftok(".", 65);
    int id = msgget(key, 0666 | IPC_CREAT);

    if (fork() == 0) {   // Sender
        struct msg m = { 1, "Hello Message Queue" };
        msgsnd(id, &m, sizeof(m.text), 0);
    }
    else {             // Receiver
        struct msg m;
        msgrcv(id, &m, sizeof(m.text), 1, 0);
        printf("Received: %s\n", m.text);
        msgctl(id, IPC_RMID, NULL);
    }
    return 0;
}
