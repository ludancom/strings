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



