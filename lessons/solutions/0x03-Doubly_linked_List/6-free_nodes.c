/* Function to free nodes in a doubly linked list*/
void freeDll(struct Node *head) 
{
    struct Node *current = head;
    struct Node *nextNode;

    /* Traverse the list*/
    while (current != NULL) 
    {
        /* Save the reference to the next node before freeing the current node*/
        nextNode = current->next;

        /* Free the current node*/
        free(current);

        /* Move to the next node*/
        current = nextNode;
    }
}