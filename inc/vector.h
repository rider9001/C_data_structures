/// ------------------------------------------
/// @file vector.h
///
/// @brief header file for vector structure
/// ------------------------------------------
#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/// @brief Factor to expand memory by when capacity is reached
#define VEC_MEM_EXPAND_FACTOR 1.5

/// @brief Vector structure for storing int
typedef struct
{
    int *mem;
    size_t count;
    size_t capacity;
} vector;


/// ------------------------------------------
/// @brief Initializes a vector struct to a single element.
/// All vectors need to be instantiated and passed byref
/// to this function to initialize.
/// Can also be used to reset a vector
///
/// @param vec vector to initialise/reset
void init_vector(vector *vec);

/// ------------------------------------------
/// @brief Function to free vector memory and set vector size to 0
///
/// @param vec pointer to vector to clear
void clear_vector(vector *vec);

/// ------------------------------------------
/// @brief Safe get function for vector
/// If idx is out of bounds then 0 is returned
///
/// @param vec vector to get from
/// @param idx index to get at
///
/// @return value at index or 0 if OOB
int vec_get(vector *vec, size_t idx);

/// ------------------------------------------
/// @brief Pushes num onto the back of the array, expanding capacity if necessary
///
/// @param vec vector to push to
/// @param num input to push
void push_back(vector *vec, int num);

/// ------------------------------------------
/// @brief Removes the value at the given index
/// Checks if the index is within the bounds of the vector
/// Silently fails if idx is out of bounds
/// Shifts all subsequent data backwards into new space
///
/// @param vec vector to remove from
/// @param idx index to remove at
void remove_at(vector *vec, size_t idx);

/// ------------------------------------------
/// @brief Removes and returns value of last element
/// Returns 0 if there is no element to pop
///
/// @param vec vector to pop from
///
/// @return value of popped element
int pop_last(vector *vec);

/// ------------------------------------------
/// @brief compresses vector memory to only nessecary space
///
/// @param vec vector to compress
void vec_compress(vector *vec);