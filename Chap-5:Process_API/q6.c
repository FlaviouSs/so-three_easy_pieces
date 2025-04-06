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
        child_pid = waitpid(child_pid, NULL, 0);
        printf("Running parent process (pid: %d)\n", getpid());
        printf("My child pid is: %d\n", child_pid);
    }


    return 0;
}


/*

Sources: 

https://man7-org.translate.goog/linux/man-pages/man2/wait.2.html?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=tc

It would be usefull if the parent process have multiple child processes.

*/
