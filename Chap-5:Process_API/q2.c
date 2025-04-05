#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
  

  int file_descricptor = open("q2.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
  pid_t  child_pid = fork();

  char *buffer = malloc(100);

  if(child_pid < 0){
    printf("Error. Fork failed.");
  }
  else if(child_pid == 0){
    printf("Child process here! My PID is %d\n", getpid());
    buffer = "Child Process Text!";
    write(file_descricptor, buffer, strlen(buffer));
  }
  else{
    printf("Dad is home! Parent process here! My PID is %d\n", getpid());
    buffer = "Parent Process Text!";
    write(file_descricptor, buffer, strlen(buffer));
  }

  return 0;
}

/*

Sources: 

https://man7.org/linux/man-pages/man2/open.2.html
https://man7.org/linux/man-pages/man2/write.2.html

*/