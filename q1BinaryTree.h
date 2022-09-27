#include <stdbool.h>

struct Node
{
    char *ident;
    int count;
    struct Node *left;
    struct Node *right;
};

struct Node head;

bool insertNode(char *);
// bool removeNode(char *); removing is not needed in this case and adds too much complexity so I won't implement it
bool printAlphabeticalOrder();