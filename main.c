#include <stdio.h>

#include "inc/vector.h"

int main()
{
    const size_t fill = 10;

    vector vec;
    init_vector(&vec);

    for (size_t i = 0; i < fill; i++)
    {
        push_back(&vec, i);
    }

    printf("Count: %lu\n", vec.count);
    printf("Capacity: %lu\n", vec.capacity);

    for (size_t i = 0; i < vec.count; i++)
    {
        printf("%i\n", vec.mem[i]);
    }

    const size_t remove_idx = 4;
    printf("Remove test: %lu\n", remove_idx);
    remove_at(&vec, remove_idx);

    printf("Count: %lu\n", vec.count);
    printf("Capacity: %lu\n", vec.capacity);
    for (size_t i = 0; i < vec.count; i++)
    {
        printf("%i\n", vec.mem[i]);
    }

    printf("Pop test:\n");
    pop_last(&vec);

    printf("Count: %lu\n", vec.count);
    printf("Capacity: %lu\n", vec.capacity);
    for (size_t i = 0; i < vec.count; i++)
    {
        printf("%i\n", vec.mem[i]);
    }

    printf("Get test:\n");
    pop_last(&vec);

    printf("Count: %lu\n", vec.count);
    printf("Capacity: %lu\n", vec.capacity);
    for (size_t i = 0; i < vec.count + 5; i++)
    {
        printf("%i\n", vec_get(&vec, i));
    }

    printf("Compress test:\n");
    vec_compress(&vec);

    printf("Count: %lu\n", vec.count);
    printf("Capacity: %lu\n", vec.capacity);
    for (size_t i = 0; i < vec.count; i++)
    {
        printf("%i\n", vec_get(&vec, i));
    }

    return 0;
}