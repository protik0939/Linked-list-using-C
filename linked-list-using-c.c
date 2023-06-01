#include <stdio.h>
#include <stdlib.h>

void create();
void Insert_begining();
void Insert_middle();
void Insert_end();
void Delete_begining();
void Delete_middle();
void Delete_end();
void Search();
void display();

struct node
{
    int info;
    struct node *next;
};

struct node *start = NULL;

// This is main function
int main()
{
    int choice;

    while (1)
    {

        printf("Enter 1 to create\n");
        printf("Enter 2 to Insert in the begining\n");
        printf("Enter 3 to Insert at middle\n");
        printf("Enter 4 to Insert at end\n");
        printf("Enter 5 to Delete the begining\n");
        printf("Enter 6 to Delete from middle\n");
        printf("Enter 7 to Delete from end\n");
        printf("Enter 8 to Search\n");
        printf("Enter 9 to display\n");
        printf("Enter 10 to exit\n");


        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            create();
            break;
        }

        case 2:
        {
            Insert_begining();
            break;
        }

        case 3:
        {
            Insert_middle();
            break;
        }

        case 4:
        {
            Insert_end();
            break;
        }

        case 5:
        {
            Delete_begining();
            break;
        }

        case 6:
        {
            Delete_middle();
            break;
        }

        case 7:
        {
            Delete_end();
            break;
        }

        case 8:
        {
            Search();
            break;
        }

        case 9:
        {
            display();
            break;
        }

        case 10:
        {
            exit(0);
            break;
        }

        }
    }

    return 0;
}

// This is create function
void create()
{

    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Out of memory space\n");
        exit(0);
    }

    printf("Enter the data value for the node:\n");
    scanf("%d", &temp->info);

    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
    }

    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void Insert_begining()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Out of memory space\n");
        exit(0);
    }

    printf("Enter the data value for the node:\n");
    scanf("%d", &temp->info);

    temp->next = start;
    start = temp;
}


void Insert_middle()
{
    struct node *temp, *ptr;
    int pos, i = 1, n;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Out of memory space\n");
        exit(0);
    }

    printf("Enter the data value for the node:\n");
    scanf("%d", &temp->info);
    temp->next = NULL;

    printf("Enter the position for the new node to be inserted:\n");
    scanf("%d", &pos);

    ptr = start;
    while (ptr != NULL && i < pos - 1)
    {
        ptr = ptr->next;
        i++;
    }

    if (pos == 1)
    {
        temp->next = start;
        start = temp;
    }

    else if (ptr == NULL)
    {
        printf("Invalid position\n");
        free(temp);
    }

    else
    {
        temp->next = ptr->next;
        ptr->next = temp;
    }
}


void Insert_end()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Out of memory space\n");
        exit(0);
    }

    printf("Enter the data value for the node:\n");
    scanf("%d", &temp->info);

    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}


void Delete_begining()
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = start;
    start = start->next;
    free(temp);
    printf("Node at the beginning deleted successfully\n");
}

void Delete_middle()
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int pos;
    printf("Enter the position of the node to be deleted: ");
    scanf("%d", &pos);

    struct node *temp = start;
    struct node *prev = NULL;

    for (int i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    if (prev == NULL)
    {
        start = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
    printf("Node at position %d deleted successfully\n", pos);
}

void Delete_end()
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = start;
    struct node *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
    {
        start = NULL;
    }
    else
    {
        prev->next = NULL;
    }

    free(temp);
    printf("Last node deleted successfully\n");
}


void Search()
{
    int value, index = 0;
    struct node *ptr = start;

    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter the value to search for: ");
    scanf("%d", &value);

    while (ptr != NULL)
    {
        if (ptr->info == value)
        {
            printf("%d found at index %d\n", value, index);
            return;
        }

        ptr = ptr->next;
        index++;
    }

    printf("%d not found in the list\n", value);
}


// This is diaplay function
void display()
{

    struct node *ptr;

    if (start == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        ptr = start;
        printf("The list elements are: ");

        while (ptr != NULL)
        {
            printf("%d ", ptr->info);
            ptr = ptr->next;
        }

        printf("\n");
    }
}
