#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg { long mtype; char text[20]; };

int main() {
    int id = msgget(1234, 0666);
    struct msg m;
    for (int i=0;i<5;i++) {
        msgrcv(id, &m, sizeof(m.text), 0, 0);
        printf("%s\n", m.text);
    }
    msgctl(id, IPC_RMID, NULL);
    return 0;
}
