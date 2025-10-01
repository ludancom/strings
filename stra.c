#include <stdlib.h>
#include "str.h"
#include <assert.h>

size_t Str_getLength(const char strIn[])
{
   size_t uLength = 0;
   assert(strIn != NULL);
   while (strIn[uLength] != '\0')
      uLength++;
   return uLength;
}

char* Str_copy(char destination[], const char strIn[])
{
    int i = 0;
    assert(destination != NULL);
    assert(strIn != NULL);
    while(strIn[i] != '\0'){
        destination[i] = strIn[i];
        i++;
    }
    destination[i] = '\0';
    return (char*)destination;
}

char* Str_concat(char destination[], const char strIn[])
{
    int i = 0;
    int dest_length = Str_getLength(destination);
    assert(destination != NULL);
    assert(strIn != NULL);
    while(strIn[i] != '\0'){
        destination[dest_length+i] = strIn[i];
        i++;
    }
    destination[Str_getLength(destination)+i] = '\0';
    return (char*)destination;
}

int Str_compare(const char* str1, const char* str2){
    int i = 0;
    assert(str1 != NULL);
    assert(str2 != NULL);

    while(str1[i] != '\0')
    {
        if(str2[i] == '\0'){ /*str2 ended before str1*/
            return 1;
        }
        else if(str1[i] != str2[i]){
            return str1[i]-str2[i];
        }
        i++;
    }
    if((str2[i] != '\0')){ /*str1 ended before str2*/
        return -1;
    }
    return 0;
}

char* Str_search(const char str[], const char strInside[]){
    int k = 0;
    int i = 0;
    assert(str != NULL);
    assert(strInside != NULL);
    

    if(strInside[0]=='\0'){
        return (char*)str;
    }

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == strInside[0]){
            k=0;
            while(strInside[k]!='\0'){
                if(strInside[k] != str[i+k]){
                    break;
                }
            }
            if(strInside[k]=='\0'){
                return (char*) &str[i+k];
            }
        }
    }
    return NULL;


}