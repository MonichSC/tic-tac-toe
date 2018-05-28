#ifndef TTT_HELPERS_H
#define TTT_HELPERS_H

#include <ctime>
#include <stdint.h>

// Types

typedef uint8_t uint8;
typedef int8_t int8;

typedef uint16_t uint16;
typedef int16_t int16;

typedef uint32_t uint32;
typedef int32_t int32;

typedef uint64_t uint64;
typedef int64_t int64;

typedef float float32;
typedef double float64;

typedef const char* ccstring;
typedef char* cstring;

/// Defines for the engine

//! Args or return values marked as NULLABLE can be null and will not produce NullPtrExc. 
//! Always check for null values if variable you're passing out or into function isn't NULLABLE.
#define NULLABLE 
//! Same as NULLABLE, used for arrays.
//! @sa NULLABLE
#define OFNULLABLE  
//! Specify an argument of a function that will be used to output a result of a function
#define OUTARG 
//! Args or return values marked as TODELETE means that the pointer should be deleted by user 
//! As an arg: pointer will be deleted by the class called
//! Return value: pointer should be deleted by the function reciever
#define TODELETE
//! Same as TODELETE, used for arrays.
//! @sa TODELETE
#define OFDELETE

#define DELETEVECTOR(V) for(auto it = V.begin(); it != V.end(); it++) delete (*it); V.clear()
#define DELETEMAP(V) for(auto it = V.begin(); it != V.end(); it++) delete (*it).second; V.clear()
#define FOREACH(V) for(auto it = V.begin(); it != V.end(); it++)

//! @brief Prepares terminated const char array of a given length.
//! @author Monich
cstring TODELETE prepareCString(const uint64 lenght);

//! @brief Copies given cString to a new location.
//! @author Monich
cstring TODELETE copyCString(ccstring other);

//! @brief Produces random uint64 using C rand function and bit shifting.
//! @author Monich
uint64 GenerateRandom();

#ifdef EXTENDED_CHECKS

//! @brief Asserts given statement is always true, otherwise crashes the program.
//! @param statement - statement to check against.
//! @param errString - error string printed if program crashes.
//! @author Monich
void ASSERT(bool statement, ccstring errString);

#endif // EXTENDED_CHECKS

#endif // !TTT_HELPERS_H
