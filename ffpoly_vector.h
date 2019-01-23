#include <stddef.h>
#include <stdint.h>

#ifndef ffpoly_vector_h
#define ffpoly_vector_h

//Becausce C# and Java had a reason to
#define INIT_CAPACITY 8

typedef struct ffpoly_vector
{
    uint_fast32_t *elems;
    size_t capacity;
    size_t size;
} ffpoly_vector;

//Constructor / Destructor
int ffpoly_vector_init(vector *);
void ffpoly_vector_free(vector *);

//Modifiers
int ffpoly_vector_add(vector *, uint_fast32_t);
int ffpoly_vector_set(vector *, size_t, uint_fast32_t);
int ffpoly_vector_get(vector *, size_t, uint_fast32_t *);
int ffpoly_vector_pop(vector *, uint_fast32_t *);
int ffpoly_vector_delete(vector *, size_t, uint_fast32_t *);

//Growth policy
static int ffpoly_vector_grow(vector *, size_t);
static int ffpoly_growth_policy(vector *);

#endif
