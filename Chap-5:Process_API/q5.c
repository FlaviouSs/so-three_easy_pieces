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
    }
    else{
        child_pid = wait(NULL);
        printf("Running parent process (pid: %d)\n", getpid());
        printf("My child pid is: %d\n", child_pid);
    }


    return 0;
}


/*

Sources: 

https://man7-org.translate.goog/linux/man-pages/man2/wait.2.html?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=tc

Wait() returns a pid. On success, returns the pid of the terminated child. On failure, -1 is returned.access
If we use wait() on the child process, it'll return -1 because the child process is not a parent process of another process.

*/
