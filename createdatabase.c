#include "inverted_Search.h"

char*fname;
/**
 *  Builds the database by processing each file in the file list.
 *
 * Iterates through the linked list of files starting from f_head and
 * calls read_datafile() for each file to populate/update the word list.
 *
 * Parameter.
 *  f_head  Pointer to the head of the file linked list.
 *  head    Array of pointers to Wlist structures used as the database.
 *
 * return void
 */

void create_database(Flist *f_head, Wlist *head[])
{
    while (f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->link;
    }
}
/*Function definition  for read_datafile
  Functions reads file content. calculate index for each word in a file  
  acccording to index data inserted in array.
  
  Parameter : 
              1. File link list
              2. head -> Array of pointers to Wlist structures used as the database.
              3. File name
  return   structure
  */
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{

    // Opening file in Read mode
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf(COLOR_RED "Failed to open file" COLOR_RESET "\n");
        return NULL;
    }
    char word[WORD_SIZE];
    fname = filename;
    while ((fscanf(fptr, "%s", word) != EOF))
    {
        int flag = 1;
        int index = tolower(word[0]) % 97;
        if (!(index >= 0 && index <= 25))
            index = 26;
        if (head[index] != NULL)
        {
            Wlist *temp = head[index];
            while (temp)
            {
                if ((strcmp(temp->word, word)) == 0)
                {

                    update_word_count(&temp, filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
            if (flag == 1)
            {
                insert_at_last(&head[index], word);
            }
        }
        else
        {
             insert_at_last(&head[index], word);
        }
    }

    fclose(fptr);
}
/*
  Function to update word count.
  Formal argument ->  1. head pointer 2. name of file
  1.table is empty
     i) Memory allocation for table and storing address of  created table in
        the Word list
     ii) Initilized member
              file name.
              link of next table.
              word count.
     iii)
*/
int update_word_count(Wlist **head, char *file_name)
{
    Ltable *temp = (*head)->Tlink;

    Ltable *prev = NULL;
    while (temp != NULL)
    {
        if (strcmp(temp->file_name, file_name) == 0)
        {
            temp->word_count++;
            return 1;
        }
        prev = temp;
        temp = temp->table_link;
    }

    // Not found → add new node
    Ltable *new = malloc(sizeof(Ltable));
    if (new == NULL)
        return 0;

    strcpy(new->file_name, file_name);
    new->word_count = 1;
    new->table_link = NULL;
    ++((*head)->file_count);
    if (prev)
        prev->table_link = new;
    else
        (*head)->Tlink = new;

    return 1;
}
