#include <stdio.h>
#include <stdlib.h>
//#include "list.h"
#include "mylist.h"
#include <math.h>

#define ISLETTER(c) (('a'<=c && c>='z')||('A'<=c && c>='Z')) ? 1 : 0  

FILE* OpenFile(){
    FILE *fd = fopen("input.txt","r");
    if(NULL != fd)
        return fd;
    return NULL;    
}

void CloseFile(FILE *fd){
   fclose(fd);
}

/*read all the  data*/
char* ReadData2Buffer( int* num){
   char* buff;
   FILE* fd = OpenFile();
   if(NULL == fd) return -1;
   fseek(fd,0,SEEK_END);
   int len = ftell(fd);
   buff = (char*)malloc(sizeof(char)*len); 
   rewind(fd);
   fread(buff,1,len,fd);
   buff[len] = '\0';
   *num = len;
   printf("buff = %s\n len = %d\n",buff,len); //Debug use
   CloseFile(fd);
   return buff;
} 

/*Single List for word */
list InitList(){
    
    
}

/*compare two word,ignore upper or lower*/
int isLetterEqu(char src, char dst){
    int diff = abs(src-dst);
    return (diff == 0 || diff == 32) ? 1 : 0;    
}

int isWordEqu(char* src, char* dst){
    if(strlen(src) != strlen(dst)) return 0;
    while((*src != '\0') && (*dst != '\0')){
       if(!isLetterEqu(*src,*dst))
           return 0;
    }
    return 1;
}

/*separate word*/


int main(int argc, char ** argv){
      
    //xiabodan_list();	
    int len = 0;
    char word[50];
    int num = 0;
    int i = 0; 
    char* buff = ReadData2Buffer(&len);
    while(i<len){
         /*separate word*/
         if( ISLETTER(buff[i]) ){
             word[num++] = buff[i++];
             continue;
	 }else{
             num = 0;
             word[num] = '\0';
	     printf("word = %s\nnum = %d",word,num); 
	 
         
             /*compare this word with all list words*/
     
             /*store into list*/

             /*print list*/

         }
    }

    return 0;
}  
