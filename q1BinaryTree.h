#include <stdbool.h>

struct Node
{
    char *ident;
    struct Node *left;
    struct Node *right;
};

struct Node *first;
struct Node *current;

char *getNext();
bool insertNode(char *);
bool removeNode(char *);
bool printAlphabeticalOrder();