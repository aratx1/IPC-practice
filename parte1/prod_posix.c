#include <stdio.h>
#include <mqueue.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    mqd_t mq = mq_open("/cola", O_CREAT | O_WRONLY, 0666, NULL);
    for (int i = 1; i <= 5; i++) {
        char msg[20];
        sprintf(msg, "Mensaje %d", i);
        mq_send(mq, msg, strlen(msg)+1, 0);
    }
    mq_close(mq);
    return 0;
}
