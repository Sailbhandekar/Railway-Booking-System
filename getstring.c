#include"train.h"

char *getstring(void){
        char *name=NULL;
        int i=0;
        __fpurge(stdin);
      do{
              name=realloc(name,i+1);
              name[i]=getchar();
      }while(name[i++]!='\n');
      name[i-1]='\0';

      return name;

}
