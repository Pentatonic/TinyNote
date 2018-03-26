#include <iostream>

typedef struct node {
    int val;
    node *next;
} node;

bool insert(node **head, int k) {
    node *n = new node();
    n->val = k;
    n->next = *head;
    *head = n;
    return true;
}

int main() {
    node *head = new node();
    head->val = 0;
    insert(&head, 1);
    while (head != NULL) {
        std::cout << head->val << std::endl;
        head = head->next;
    }
    return 0;
}
