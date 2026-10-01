#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// 1. Insert at beginning
void insertBeginning()
{
    int value;
    struct Node *newNode;

    printf("Enter element: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;

    printf("Element inserted successfully.\n");
}

// 2. Insert at end
void insertEnd()
{
    int value;
    struct Node *newNode;
    struct Node *temp;

    printf("Enter element: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Element inserted successfully.\n");
}

// 3. Delete at beginning
void deleteBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

// 4. Delete at end
void deleteEnd()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    if (temp->next == NULL)
    {
        printf("Deleted element: %d\n", temp->data);
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Deleted element: %d\n", temp->data);

    temp->prev->next = NULL;

    free(temp);
}

// 5. Forward Traversal
void forwardTraversal()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Forward Traversal: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// 6. Backward Traversal
void backwardTraversal()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Backward Traversal: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n");
        printf("1. Insert element at beginning\n");
        printf("2. Insert element at end\n");
        printf("3. Deletion at beginning\n");
        printf("4. Deletion at end\n");
        printf("5. Forward traversing\n");
        printf("6. Backward traversing\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                forwardTraversal();
                break;

            case 6:
                backwardTraversal();
                break;

            case 7:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter 1 to 7.\n");
        }
    }

    return 0;
}
