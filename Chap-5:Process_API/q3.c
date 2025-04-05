#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    pid_t child_pid = fork();


    if(child_pid < 0){
        printf("Error. Fork failed!\n");
    }
    else if(child_pid == 0){
        printf("Hello   (pid: %d)\n", getpid());
    }
    else{
        sleep(1);
        printf("goodbye     (pid: %d)\n", getpid());
    }

    return 0;
}

/*

Source: https://man7.org/linux/man-pages/man3/sleep.3.html

The output order is defined by the process scheduler at the time.
If we want to ensure that the child process execute before the parent process, withou using the wait() function,
we should use the sleep function in the parent process. It'll "force" the scheduler to execute the child process output
before the parent process output.

*/