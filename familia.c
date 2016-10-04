#include <stdio.h>
#include <sys/types.h>
#include <csignal>
#include <unistd.h>
#include <cstdlib>

int main(int argc, char const *argv[]) {
  pid_t process_id_1;
  pid_t process_id_2;
  pid_t process_id_3;
  pid_t process_id_4;
  pid_t process_id_5;
  int counter_father = 0;
  int counter_son1 = 0;
  int counter_son2 = 0;
  int counter_son3 = 0;
  int counter_gson = 0;
  int counter_gson2 = 0;

  while(counter_father < 18) {
    printf("> father have %d\n", counter_father);
    sleep(1);
    counter_father++;
  }

  process_id_1 = fork();
  printf("> 1st son born\n");

  if(process_id_1 == 0) {
    // 1st son
    while(true) {
      printf("> 1st son have %d\n", counter_son1);
      sleep(1);
      counter_son1++;
      if(counter_son1 == 5) {
        printf("> 1st son is dead \n");
        kill(getpid(), SIGKILL);
      }
    }
  }
  else {
    // father
    while(true) {
      printf("> father have %d\n", counter_father);
      sleep(1);
      counter_father++;
      if(counter_father == 20) {

        process_id_2 = fork();
        printf("> 2st son born\n");

        if(process_id_2 == 0) {
          // 2dn son
          while(true) {
            printf("> 2nd son have %d \n", counter_son2);
            sleep(1);
            counter_son2++;
            if(counter_son2 == 15) {

              process_id_3 = fork();
              printf("> 1st grandson born\n");

              if(process_id_3 == 0) {
                // grandson
                while(true) {
                  printf(">> 1st grandson have %d \n", counter_gson);
                  sleep(1);
                  counter_gson++;
                  if(counter_gson == 5) {
                    printf("> 1st grandson is dead \n");
                    kill(getpid(), SIGKILL);
                    return 0;
                  }
                }
              }
              // else {
              //   // 2nd son
              //   while(true) {
              //     sleep(1);
              //     counter_son2++;
              //     if(counter_son2 == 15) {
              //       printf("> 2nd son is dead \n");
              //       kill(getpid(), SIGKILL);
              //     }
              //   }
              // }
            }
            if(counter_son2 == 15) {
              printf("> 2nd son is dead \n");
              kill(getpid(), SIGKILL);
            }
          }
        }
        else{
          // father
          while(true) {
            printf("> father have %d\n", counter_father);
            sleep(1);
            counter_father++;
            if(counter_father == 21) {

              process_id_4 = fork();
              printf("> 3st son born\n");

              if(process_id_4 == 0) {
                // 3rd son
                while(true) {
                  printf("> 3rd son have %d \n", counter_son3);
                  sleep(1);
                  counter_son3++;
                  if(counter_son3 == 2) {

                    process_id_5 = fork();
                    printf("> 2st grandson born\n");

                    if(process_id_5 == 0) {
                      // 2dn grandson
                      while(true) {
                        printf("> 2dn grandson have %d \n", counter_gson2);
                        counter_gson2++;
                        sleep(1);
                        counter_gson2;
                        if(counter_gson2 == 10) {
                          printf("> 3rd son is dead \n");
                          kill(getpid(), SIGKILL);
                        }
                      }
                    }
                    else {
                      // 3rd son
                      while(true) {
                        printf("> 3rd son have %d \n", counter_son3);
                        sleep(1);
                        counter_son3++;
                        if(counter_son3 == 5) {
                          printf("> 3rd son is dead \n");
                          kill(getpid(), SIGKILL);
                        }
                      }
                    }
                  }
                }
              }
              // else {
              //   // father
              //   sleep(1);
              //   counter_father++;
              //   if (counter_father == 33) {
              //     printf("> father dead \n");
              //     kill(getpid(), SIGKILL);
              //   }
              // }
            }
            if (counter_father == 33) {
              printf("> father dead \n");
              kill(getpid(), SIGKILL);
            }
          }
        }

      }
    }
  }
}
