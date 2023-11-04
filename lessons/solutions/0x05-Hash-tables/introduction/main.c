#include "def_struct.h"

int main(void)
{
    /* Create a HashTable with a capacity of CAPACITY. */
    hashtable *ht = create_table(CAPACITY);

    /* Insert items with keys and values. */
    ht_insert(ht, (char *)"1", (char *)"First address");
    ht_insert(ht, (char *)"2", (char *)"Second address");
    ht_insert(ht, (char *)"Hel", (char *)"Third address");
    ht_insert(ht, (char *)"Cau", (char *)"Fourth address");

    /* Search for items with keys. */
    print_search(ht, (char *)"1");
    print_search(ht, (char *)"2");
    print_search(ht, (char *)"3"); /* Not found. */
    print_search(ht, (char *)"Hel");
    print_search(ht, (char *)"Cau"); /* Collision! */

    /* Print the entire table. */
    print_table(ht);

    /* Delete items with keys. */
    ht_delete(ht, (char *)"1");
    ht_delete(ht, (char *)"Cau");

    /* Print the table after deletions. */
    print_table(ht);

    /* Free the memory used by the HashTable. */
    free_table(ht);

    return 0;
}


/* This is what is happening in this program*/

/**
 * 1. At the beginning, a HashTable is created with a certain capacity.
 * 2. Some items are added with keys and values, like putting books on shelves in a library.
 * 3. The librarian (program) tries to find books with specific titles (searching for items with keys).
 * 4. The librarian prints out the list of books in the library (printing the entire table).
 * 5. Some books are removed from the library (deleting items with keys).
 * 6. The librarian prints out the updated list of books.
 * 7. Finally, the librarian closes the library and cleans up.
*/