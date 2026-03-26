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
        vec->capacity = ceil(vec->capacity * VEC_MEM_EXPAND_FACTOR);
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
        for (size_t i = idx; i < vec->count - 1; i++)
        {
            vec->mem[i] = vec->mem[i+1];
        }
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