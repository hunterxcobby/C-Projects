#include "hash_tables.h"

hash_table_t *hash_table_create(unsigned long int size)
{
    unsigned long int i;
    hash_table_t *new_ht;
    /* Check if the array is empty*/
    if (size <= 0)
        return (NULL);

    /* Create a new hash table*/
    new_ht = malloc(sizeof(hash_table_t ));
    if (!new_ht)
    {
        free(new_ht);
        return (NULL);
    }

    new_ht->size = size;
    /* Allocate memory for the array of the hash node*/
    new_ht->array = malloc(size * sizeof(hash_node_t *));
    if (!new_ht->array)
    {
        free(new_ht);
        return (NULL);
    }

    for(i = 0; i < size; i++)
        new_ht->array[i] = NULL;

    free(new_ht);
    return(new_ht);
}