#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct Node
{
        int data;
        struct Node* next;
};

struct Node *head = NULL;
static unsigned char size = 0;

void insert_node(int value, ...)
{
        va_list ap;
        va_start(ap, 1);
        int pos = va_arg(ap, int);
        if (pos < 0 || pos >= size) {
                pos = size;
        }
        va_end(ap);

        struct Node* curr = malloc(sizeof(struct Node));
        curr->next = NULL;

        if (!size) {
                head = curr;
        }
        else {
                if (!pos) {
                        curr->next = head;
                        head = curr;
                }
                else {
                        if (size > 1) {
                                struct Node* prev = head;
                                struct Node* now = head;
                                for (int i = 0; i < pos; ++i) {
                                        prev = now;
                                        now = now->next;
                                }
                                curr->next = now;
                                prev->next = curr;
                        }
                        else {
                                head->next = curr;
                        }
                }
        }

        curr->data = value;
        size++;
}

void delete_node(int pos)
{
        if (size == 0) {
                printf("Error in function delete_node(): no elements in the head.\n");
                return;
        }

        if (pos < 0 || pos >= size) {
                printf("Error in function delete_node(): pos is out of range.\n");
                return;
        }

        size--;
        struct Node* temp = head;

        if (!size)
                head = NULL;
        else {
                if (!pos) {
                        head = head->next;
                }
                else {
                        struct Node* prev = head;
                        for (int i = 0; i < pos; ++i) {
                                prev = temp;
                                temp = temp->next;
                        }
                        prev->next = temp->next;
                }
        }

        free(temp);
}

void print_list()
{
        if (size == 0) {
                printf("Error in function print_list(): no elements in the head.\n");
                return;
        }
        for (struct Node* now = head; now != NULL; now = now->next) {
                printf("%d ", now->data);
        }
        printf("\n");
}

int main() {
        insert_node(1, 0);
        insert_node(1, 0);
        insert_node(2, 0);
        insert_node(3, 0);
        insert_node(5);
        insert_node(8);
        insert_node(13);
        insert_node(21);
        delete_node(0);
        delete_node(4);
        print_list();
}