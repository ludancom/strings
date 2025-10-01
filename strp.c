/*the pointer based implementation of c string functions*/
#include <stdlib.h>
#include "str.h"
#include <assert.h>


/*takes in a string variable strIn, returns the length of a sting*/
size_t Str_getLength(const char *strIn)
{
   const char *pcEnd;
   assert(strIn != NULL);
   pcEnd = strIn;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - strIn);
}

/*copies the given string into a string destination*/
char* Str_copy(char* destination, const char* strIn)
{
    char* original_destination = destination; /*stores the original destination to not lose it when incrementing*/
    assert(destination != NULL);
    assert(strIn != NULL);
    while(*strIn != '\0'){
        *destination = *strIn;
        strIn++;
        destination++;
    }
    *destination = '\0';
    return original_destination;
    

}
/*adds one string to the end of another*/
char* Str_concat(char* destination, const char* strIn)
{
    char* orig_dest = destination;
    char* end_of_dest = destination+Str_getLength(destination); /*end_of_dest is the pointer to the end of the destination character*/
    assert(destination != NULL);
    assert(strIn != NULL);
    while(*strIn != 0){
        *end_of_dest = *strIn;
        end_of_dest++;
        strIn++;
    }
    *end_of_dest = '\0';
    return orig_dest;
}

/*compares two strings character by character. If str1 is larger than str2, returns >0
if str2>str1, returns <0. Otherwise returns 0*/
int Str_compare(const char* str1, const char* str2){
    assert(str1 != NULL);
    assert(str2 != NULL);
    while(*str1 != '\0')
    {
        if(*str2 == '\0'){ /*str2 ended before str1*/
            return 1;
        }
        else if(*str1 != *str2){
            return *str1-*str2;
        }
        str1++;
        str2++;
    }
    if((*str2 != '\0')){ /*str1 ended before str2*/
        return -1;
    }
    return 0;
}

/*searchings for instances of a substring within another string and returns the first instance found*/
char* Str_search(const char* str, const char* strInside){
        const char* first_of_strInside = strInside;
        const char* strAtStart;
        assert(str != NULL);
        assert(strInside != NULL);

        if(Str_getLength(strInside)>Str_getLength(str)){
            return NULL;
        }
        if(*strInside == '\0'){
            return str;
        }

        while(*str != '\0')
        {
            if(*str == *first_of_strInside){
                strAtStart = str;
                strInside = first_of_strInside;
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

