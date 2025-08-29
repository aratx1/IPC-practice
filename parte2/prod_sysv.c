#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg { long mtype; char text[20]; };

int main() {
    int id = msgget(1234, IPC_CREAT | 0666);
    struct msg m;
    m.mtype = 1;
    for (int i=1;i<=5;i++) {
        sprintf(m.text, "Mensaje %d", i);
        msgsnd(id, &m, sizeof(m.text), 0);
    }
    return 0;
}
