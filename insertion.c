#include "inverted_Search.h"
extern char *fname;
/*Function definition for insert_at_last*/
int insert_at_last(Wlist **head, data_t *data)
{
    /*Memory allocation*/
    Wlist *new = malloc(sizeof(Wlist));

    if (new == NULL)
    {
        return FAILURE;
    }

    /*Creation Node*/
    strcpy(new->word, data);
    new->link = NULL;
    new->Tlink = NULL;
    new->file_count = 1;

    update_link_table(&new);
    
    /*empty list*/
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    /*List non empty*/
    Wlist *temp = *head;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new;

    return SUCCESS;
}
/*Function defintion for update_link_table*/
int update_link_table(Wlist *head[])
{
    Ltable *newTable = malloc(sizeof(Ltable));
    if (newTable == NULL)
        return 0;
    strcpy(newTable->file_name, fname);
    newTable->word_count = 1;
    newTable->table_link = NULL;
    (*head)->Tlink = newTable;
}