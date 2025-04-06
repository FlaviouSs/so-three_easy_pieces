#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    pid_t child_pid = fork();

    if(child_pid < 0){
        printf("Error. Fork failed!\n");
    }
    else if(child_pid == 0){
        printf("Running child process...\n");
        int x = close(STDOUT_FILENO);

        if(x == -1)
            printf("Error! Could not close file descriptor!\n");
        else
            printf("Trying to print some output after closing the descriptor!\n");
    }
    else{
        wait(NULL);
        printf("Running parent process\n");
    }

    return 0;
}