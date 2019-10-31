#include  <stdio.h>
#include  <string.h>
#include <malloc.h>
#include <stdlib.h>
 
 
const int length = 1024;
char Str[length],*Buf;
int n;
bool Polin(char *pStr){
 for(int i=0;i<strlen(pStr);++i)
    if(*(pStr+i) != (*(pStr+strlen(pStr)-1) ) ) return false;
 return true;
}
int main(void){
    Buf = NULL;
    while(1){
      system("cls");
      printf("Input string  or empty string  fo exit\n");
      gets(Str);
      if(strlen(Str)== 0) break;
      n = strlen(Str);
      if(!Buf) Buf = new char[n + 1];
      else Buf = (char*) realloc(Buf,n+1);
      
      int i,j,k=1, count = 0;
      for(i=0;i< n;i +=k)
        for(j = n ;j > i;--j){
           memset(Buf,0,n+1);
           strncpy(Buf,Str+i,j-i);
           if(Polin(Buf))  {printf(" %s",Buf);
                            k = strlen(Buf);  
                    count++;
                            break;
           }
           else k = 1;
       }
      
       printf("\n%d\n",count);
       getchar();
     }
    return 0;
}
