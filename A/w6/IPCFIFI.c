#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {

    int fd;
    char msg[] = "Hello from parent";

    mkfifo("myfifo",0666);

    fd = open("myfifo", O_WRONLY);

    write(fd, msg, strlen(msg)+1);   // write actual string

    close(fd);

    return 0;
}


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd;
    char buffer[100];

    fd = open("myfifo", O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Message received: %s\n", buffer);

    close(fd);

    return 0;
}
