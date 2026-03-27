#include <stdio.h>
#include <stddef.h>
#include <sys/time.h>

#include "inc/vector.h"

unsigned long getMicrotime()
{
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (unsigned long)1e6 + currentTime.tv_usec;
}

int main()
{
    const size_t fill = 10;

    vector *vec = malloc(sizeof(vector));
    init_vector(vec);

    for (size_t i = 0; i < fill; i++)
    {
        push_back(vec, i);
    }

    printf("Count: %lu\n", vec->count);
    printf("Capacity: %lu\n", vec->capacity);

    for (size_t i = 0; i < vec->count; i++)
    {
        printf("%i, ", vec->mem[i]);
    }
    printf("\n");

    const size_t remove_idx = 4;
    printf("Remove at test index: %lu\n", remove_idx);
    remove_at(vec, remove_idx);

    printf("Count: %lu\n", vec->count);
    printf("Capacity: %lu\n", vec->capacity);
    for (size_t i = 0; i < vec->count; i++)
    {
        printf("%i, ", vec->mem[i]);
    }
    printf("\n");

    printf("Pop test:\n");
    pop_last(vec);

    printf("Count: %lu\n", vec->count);
    printf("Capacity: %lu\n", vec->capacity);
    for (size_t i = 0; i < vec->count; i++)
    {
        printf("%i, ", vec->mem[i]);
    }
    printf("\n");

    printf("Get test:\n");
    pop_last(vec);

    printf("Count: %lu\n", vec->count);
    printf("Capacity: %lu\n", vec->capacity);
    for (size_t i = 0; i < vec->count + 5; i++)
    {
        printf("%i, ", vec_get(vec, i));
    }
    printf("\n");

    printf("Compress test:\n");
    vec_compress(vec);

    printf("Count: %lu\n", vec->count);
    printf("Capacity: %lu\n", vec->capacity);
    for (size_t i = 0; i < vec->count; i++)
    {
        printf("%i, ", vec_get(vec, i));
    }
    printf("\n");

    const size_t fill_count = 1e8;
    init_vector(vec);
    printf("Push %lu elements test:\n", fill_count);
    size_t start = getMicrotime();
    for(size_t i = 0; i < fill_count; i++)
    {
        push_back(vec, i);
    }
    size_t end = getMicrotime();

    printf("Took %lu micros\n", end-start);

    const size_t divider = 1000000;
    printf("Remove at %lu elements test:\n", fill_count / divider);
    start = getMicrotime();
    for(size_t i = 0; i < fill_count / divider; i++)
    {
        remove_at(vec, 1);
    }
    end = getMicrotime();
    printf("Took %lu micros\n", end-start);

    printf("Clear test:\n");
    clear_vector(vec);
    printf("Count: %lu\n", vec->count);
    printf("Capacity: %lu\n", vec->capacity);

    printf("Push after clear test:\n");
    for (size_t i = 0; i < fill; i++)
    {
        push_back(vec, i);
    }

    printf("Count: %lu\n", vec->count);
    printf("Capacity: %lu\n", vec->capacity);
    for (size_t i = 0; i < vec->count; i++)
    {
        printf("%i, ", vec_get(vec, i));
    }
    printf("\n");

    clear_vector(vec);

    return 0;
}