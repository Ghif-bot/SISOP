#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void func1() {
    int i;
    for (i = 0; i < 50; i++) {
        printf("%d\n", i);
    }
}

void func2() {
    int i;
    for (i = 51; i < 101; i++) {
        printf("%d\n", i);
    }
}

int main() {
    pid_t child_id;
    int status;
    child_id = fork();
    if (child_id < 0) {
        exit(EXIT_FAILURE);
    }

    if (child_id == 0) {
        func1();
    } else {
        while ((wait(&status)) > 0)
            ;
        func2();
    }
}