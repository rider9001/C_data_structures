#include "../inc/vector.h"

/// ------------------------------------------
void init_vector(vector *vec)
{
    if (vec->mem != NULL)
    {
        free(vec->mem);
    }
    // create single element
    vec->mem = malloc(sizeof(int));

    vec->capacity = 1;
    vec->count = 0;
}

/// ------------------------------------------
void clear_vector(vector *vec)
{
    if (vec->mem != NULL)
    {
        free(vec->mem);
        vec->mem = NULL;
    }

    vec->capacity = 0;
    vec->count = 0;
}

/// ------------------------------------------
int vec_get(vector *vec, size_t idx)
{
    if (idx >= vec->count)
    {
        return 0;
    }
    else
    {
        return vec->mem[idx];
    }
}

/// ------------------------------------------
void push_back(vector *vec, int num)
{
    if (vec->count + 1 > vec->capacity)
    {
        // +1 is to prevent non integer values creating a new size the same as the old size
        // e.g: 1 * 1.5 = 1.5 -> 1 need to add 1 -> 2
        vec->capacity = vec->capacity * VEC_MEM_EXPAND_FACTOR + 1;
        vec->mem = realloc(vec->mem, vec->capacity * sizeof(int));
    }

    vec->mem[vec->count++] = num;
}

/// ------------------------------------------
void remove_at(vector *vec, size_t idx)
{
    // silent fail if attempting to remove outside of range
    if (idx >= vec->count) return;

    // if last index, can simply walk the count back to remove the item
    if (idx != vec->count - 1)
    {
        memcpy(vec->mem + idx, vec->mem + idx + 1, (vec->count - idx) * sizeof(int));
    }

    vec->count--;
}

/// ------------------------------------------
int pop_last(vector *vec)
{
    if (vec->count == 0) return 0;

    vec->count--;
    return vec->mem[vec->count];
}

/// ------------------------------------------
void vec_compress(vector *vec)
{
    if (vec->capacity == vec->count) return;

    int *new_mem = malloc(vec->count * sizeof(int));
    memcpy(new_mem, vec->mem, sizeof(int) * vec->count);
    free(vec->mem);
    vec->mem = new_mem;
    vec->capacity = vec->count;
}