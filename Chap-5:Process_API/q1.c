#include <stdio.h>
#include <unistd.h>

int main(void) {

  int x = 100;

  pid_t child_pid = fork();

  if(child_pid < 0){
    printf("Error. Fork failed.");
  }
  else if(child_pid == 0){
    printf("Child process here! My PID is %d\n", getpid());
    printf("X value is: %d (PID: %d)\n", x, getpid());
  }
  else{
    printf("Dad is home! Parent process here! My PID is %d\n", getpid());
    printf("X value is: %d (PID: %d)\n", x, getpid());
    x = 21;
    printf("I've changed X value. Now it is: %d (PID: %d)\n", x, getpid());
  }
  
  return 0;
}

/*

Source: https://man7.org/linux/man-pages/man2/fork.2.html

At line 8, we've created a child process. We bassically duplicate the calling process. At the time we call fork(), the child process and the parent process have different memory spaces. However, both memory spaces have the same content.

*/
