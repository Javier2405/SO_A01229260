#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{

  if(argc >= 2){
    printf(1,"Ya me dormi\n");
    sleep(atoi(argv[1])*100);
    printf(1,"Ya desperte\n");

  };
  exit();
}