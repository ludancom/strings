#include <stdlib.h>
#include "str.h"
#include <assert.h>

size_t Str_getLength(const char *strIn)
{
   const char *pcEnd;
   assert(strIn != NULL);
   pcEnd = strIn;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - strIn);
}

char* Str_copy(char* destination, const char* strIn)
{
    assert(destination != NULL);
    assert(strIn != NULL);
    char* original_destination = destination; //stores the original destination to not lose it when incrementing
    while(*strIn != '\0'){
        *destination = *strIn;
        strIn++;
        destination++;
    }
    return original_destination;
}

char* Str_concat(char* destination, const char* strIn)
{
    assert(destination != NULL);
    assert(strIn != NULL);
    char* orig_dest = destination;
    char* end_of_dest = destination+Str_getLength(destination); //end_of_dest is the pointer to the end of the destination character
    while(*strIn != 0){
        *end_of_dest = *strIn;
        end_of_dest++;
        strIn++;
    }
    return orig_dest;
}

//if str1 exhausts all characters, 
int Str_compare(const char* str1, const char* str2){
    assert(str1 != NULL);
    assert(str2 != NULL);
    while(*str1 != '\0')
    {
        if(*str2 == '\0'){ //str2 ended before str1
            return 1;
        }
        else if(*str1 != *str2){
            return *str1-*str2;
        }
        str1++;
        str2++;
    }
    if((*str2 != '\0')){ //str1 ended before str2
        return -1;
    }
    return 0;
}

    char* Str_search(const char* str, const char* strInside){
        assert(str != NULL);
        assert(strInside != NULL);
        if(str_getLength(*strInside)>Str_getLength(*str)){
            return NULL;
        }
        char* first_of_strInside = strInside;
        while(*str != '\0')
        {
            if(*str == *first_of_strInside){
                char* strAtStart = *str;
                while(*strInside != '\0'){
                    if(*strAtStart != *strInside){
                        break;
                    }
                    strInside++;
                    strAtStart++;
                }
                if(*strInside != '\0'){
                    strInside = first_of_strInside;
                }
                else{
                    return(char*) str;
                }
            }
            str++;
        }
        return NULL;

    }

