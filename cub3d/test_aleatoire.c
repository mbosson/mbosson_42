#include<stdio.h>
#include<time.h>
 
int main(int argc, char *argv[])
{
  int   nb;
 
  nb = 0;
  srand(time(0) * getpid());
  nb = rand() % 100000000;
  printf("%p\n", nb);
  return (0);
}
