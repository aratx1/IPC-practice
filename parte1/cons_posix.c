#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char buffer[50];
    mqd_t mq = mq_open("/cola", O_RDONLY);
    for (int i = 0; i < 5; i++) {
        mq_receive(mq, buffer, 50, NULL);
        printf("%s\n", buffer);
    }
    mq_close(mq);
    mq_unlink("/cola");
    return 0;
}
