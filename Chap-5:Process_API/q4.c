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
        printf("Running child process (pid: %d)\n", getpid());
        char *args[] = {"ls", "-la", ".", NULL};
        execvp("/bin/ls", args);
        perror("Execvp failed!\n");
    }
    else{
        sleep(1);
        printf("\n\n Running parent process (pid: %d)\n", getpid());
    }


    return 0;
}


/*

Sources: 

https://man7.org/linux/man-pages/man3/exec.3.html
https://man7.org/linux/man-pages/man2/execve.2.html

*/
