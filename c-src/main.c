#include <unistd.h>
int main() {
    int stdout_fd = 1;
    char* str = "Hello, World!\n";
    unsigned int length =  3;
    write(stdout_fd, str, length);
}