#include <ffpoly_vector.h>

/*
 * Initializes vector field.
 * Return: 1 if success
 *		   0 if memory allocation failure
 */
int ffpoly_vector_init(vector *vec)
{
    vec->size = 0;
    vec->capacity = INIT_CAPACITY;
    vec->elems = malloc( INIT_CAPACITY*sizeof(size_t) );
	if (!vec->elems) { return 0; }
	else { return 1; }
}

/*
 * Frees underlying array structure
 * Note if the vector struct was intialized onto the heap, that must be freed
 * too.
 */
void ffpoly_vector_free(vector *vec)
{
    free(vec->elems);
    vec->capacity = 0;
    vec->size = 0;
}

/*
 * Growth Policy handling:
 * If the current size is equal to the capacity, grow capacity by a factor of
 * 2.
 * If the current size is 4 times less than or equal to the capacity, shrink
 * capacity by a factor of 2.
 * Return: 1 if success.
 *		   0 if memory allocation error. 
 */
static int ffpoly_growth_policy(vector *vec)
{
	int x = 0;
    if (vec->capacity == vec->size)
    {
        x = vector_grow(vec, 2*(vec->capacity));
    }
    if (vec->size > 0 && vec->size*4 <= vec->capacity)
    {
        x = vector_grow(vec, (vec->capacity)/2);
    }
	return x;
}

/* Return: 1 if success.
 *		   0 if memory allocation error. 
 */
static int ffpoly_vector_grow(vector *vec, size_t new_size)
{
    size_t *elems = realloc(vec->elems, new_size * sizeof(size_t));
    if (elems)
    {
        vec->capacity = new_size;
        vec->elems = elems;
		return 1;
    }
	else { return 0; }
}

/*
 * Appends an element to the end of the array.
 * Return: 1 if success.
 *		   0 if memory allocation error.
 */
int ffpoly_vector_add(vector *vec, uint_fast32_t new_elem)
{
    if (growth_policy(vec))
	{
		vec->elems[vec->size++] = new_elem;
		return 1;
	}
	else { return 0; }
}

/*
 * Sets element within the vector at given index ind to the value of new_elem.
 * Return: 1 if success.
 *		   -1 if indexing out of bounds.
 */
int ffpoly_vector_set(vector *vec, size_t ind, uint_fast32_t new_elem)
{
	if (ind >= vec->size) { return -1; }
    vec->elems[ind] = new_elem;
	return 1;
}

/*
 * Copies the ind'th element in vec into x.
 * Return: 1 if success.
 *		   -1 if indexing out of bounds.
 */
int ffpoly_vector_get(vector *vec, size_t ind, uint_fast32_t *x)
{
	if (ind >= vec->size) { return -1; }
	*x = vec->elems[ind]
    return 1;
}

/*
 * Removes the last element of vec, and copies into x.
 * Return: 1 if success.
 *		   -1 if indexing out of bounds.
 */
int ffpoly_vector_pop(vector *vec, unint_fast32_t *x)
{
    return vector_delete(vec, vec->size-1, x);
}

/*
 * Removes and copies into x the element at given index within vector.
 * Return: 1 if success.
 *		   0 if out of memory.
 *		   -1 if indexing out of bounds.
 */
int ffpoly_vector_delete(vector *vec, size_t ind, uint_fast32_t *x)
{
	if (ind >= vec->size) { return -1; }

    *x = vec->elems[ind];

    for (size_t i = ind; i < vec->size; i++)
    {
        vec->elems[i] = vec->elems[i+1];
    }
    vec->size--;
    return growth_policy(vec);
}
