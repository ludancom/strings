#include <stdlib.h>
#include "str.h"
#include <assert.h>

/*returns the length of a sting*/
size_t Str_getLength(const char strIn[])
{
   size_t uLength = 0;
   assert(strIn != NULL);
   while (strIn[uLength] != '\0')
      uLength++;
   return uLength;
}

/*copies the given string into a string destination*/
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


/*adds one string to the end of another*/
char* Str_concat(char destination[], const char strIn[])
{
    int i = 0;
    size_t dest_length = Str_getLength(destination);
    assert(destination != NULL);
    assert(strIn != NULL);
    while(strIn[i] != '\0'){
        destination[dest_length+i] = strIn[i];
        i++;
    }
    destination[dest_length+i] = '\0';
    return (char*)destination;
}

/*compares two strings character by character. If str1 is larger than str2, returns >0
if str2>str1, returns <0. Otherwise returns 0*/
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
            return (int)(str1[i]-str2[i]);
        }
        i++;
    }
    if((str2[i] != '\0')){ /*str1 ended before str2*/
        return -1;
    }
    return 0;
}

/*searchings for instances of a substring within another string and returns the first instance found*/
char* Str_search(const char str[], const char strInside[]){
    size_t k = 0;
    size_t i = 0;
    assert(str != NULL);
    assert(strInside != NULL);
    

    if(strInside[0]=='\0'){
        return (char*)str;
    }

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == strInside[0] && str[i+k] != '\0'){
            k=0;
            while(strInside[k]!='\0'){
                if(strInside[k] != str[i+k]){
                    break;
                }
                k++;
            }
            if(strInside[k]=='\0'){
                return (char*) &str[i];
            }
        }
    }
    return NULL;


}