#include "helpers.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

//! @version 1.0.0
cstring TODELETE prepareCString(uint64 lenght)
{
    cstring res = new char[lenght + 1];
    res[lenght] = '\0';
    return res;
}

//! @version 1.0.0
cstring TODELETE copyCString(ccstring other)
{
#ifdef EXTENDED_CHECKS
    ASSERT(other, "copyCString: no other string");
#endif

	cstring res = prepareCString(strlen(other));
	strcpy(res, other);
	return res;
}

//! @version 1.0.0
uint64 GenerateRandom()
{
    uint64 res = 0;

    res = 0;
    for (int i = 3; i >= 0; i--)
    {
        res <<= 8;
        res += 0xFF & rand();
    }

    return res;
}

#ifdef EXTENDED_CHECKS

//! @version 1.0.0
void ASSERT(bool statement, ccstring errString)
{
    if(!statement)
    {
        printf("ASSERT: CRITICAL ERROR ENCOUNTERED: %s\n EXITING MODULE IMMEDIATELY!", errString);
        exit(1);
    }
}

#endif // EXTENDED_CHECKS
