#include "q1BinaryTree.h"

bool insertNode(char *word)
{
    // if head = null,  tree is empty
    if (head == NULL)
    {
        struct Node node = {
            .ident = word,
            .count = 1,
            .left = NULL,
            .right = NULL,
        };

        return true;
    }

    bool inserted = false;
    struct Node current = head;
    while (!inserted) // recursivity could also be used
    {
        int cmp = strcmp(word, current->ident);

        if (cmp < 0)
        {
            if (current.left == NULL)
            {
                struct Node node = {
                    .ident = word,
                    .count = 1,
                    .left = NULL,
                    .right = NULL,
                };
                current.left = node;
                return true;
            }
            else
            {
                current = current.left;
            }
        }
        else if (cmp == 0)
        {
            current.count++;
        }
        else
        {
            if (current.right == NULL)
            {
                struct Node node = {
                    .ident = word,
                    .count = 1,
                    .left = NULL,
                    .right = NULL,
                };
                current.right = node;
                return true;
            }
            else
            {
                current = current.right;
            }
        }
    }
    return false;
}

void inorder(struct Node *tree)
{
   if (tree == NULL)
      return;
   inorder(tree->ltree);
   printf("%s\n", tree->data);
   inorder(tree->rtree);
}

bool printAlphabeticalOrder()
{
    if (head == NULL)
        return false;
    else
        inorder(head);
    return true;
}