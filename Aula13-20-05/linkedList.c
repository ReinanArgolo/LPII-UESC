#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int num;
    struct item* prox;
} item;

typedef struct itemPos {
    int pos;
    item* endrc;
} pos;

item* newItem(int);
void addFirst(int, item**);
void addLast(int, item**);
void addAtPosition(int, item**, int);
void printList(item*);
int contarElementos(item*);
pos* searchElement(int num, item* head); 
void remover(int n, item** head);

int main(void) {
    item* head = NULL;



    printf("= = = = MENU = = = =\n");
    printf("Opções: \n1. Adicionar no começo.\n2. Adicionar ao final.\n3. Aicionar em uma posição específica.\n4. Remover elemento.\n6. Remover elemento\n");
    
    addFirst(10, &head);
    addFirst(20, &head);
    addLast(15, &head);
    addAtPosition(7, &head, 2);

    int count = contarElementos(head);
    printf("Número de elementos na lista: %d\n", count);

    pos* position = searchElement(10, head);
    printf("%d\n", *position);
    printList(head);
    remover(10, &head);
    printList(head);

    pos* pos = searchElement(15, head);
  
    count = contarElementos(head);
    printf("Número de elementos na lista: %d\n", count);
    
    return 0;
}

item* newItem(int n) {
    item* newNode = (item*)malloc(sizeof(item));
    if (newNode == NULL) {
        printf("Erro na alocação de memória\n");
        exit(1);
    }
    newNode->num = n;
    newNode->prox = NULL;
    return newNode;
}

void addFirst(int num, item** head) {
    item* value = newItem(num);
    value->prox = *head;
    *head = value;
}

void addLast(int num, item** head) {
    item* value = newItem(num);
    if (*head == NULL) {
        *head = value;
        return;
    }
    
    item* temp = *head;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    
    temp->prox = value;
}

void addAtPosition(int num, item** head, int position) {
    if (position == 0) {
        addFirst(num, head);
        return;
    }
    
    item* value = newItem(num);
    item* temp = *head;
    int i = 0;
    
    while (i < position - 1 && temp->prox != NULL) {
        temp = temp->prox;
        i++;
    }
    
    value->prox = temp->prox;
    temp->prox = value;
}

void printList(item* head) {
    item* temp = head;
    printf("Lista: ");
    while (temp != NULL) {
        printf("-> %d ", temp->num); 
        temp = temp->prox;
    }
    printf("\n");
}

int contarElementos(item* head) {
    int count = 0;
    item* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->prox;
    }
    return count;
}

pos* searchElement(int num, item* head) {
    pos* position = malloc(sizeof(pos));
    int pos_num = 0;
    item* temp = head;
    while(temp != NULL) {
        if(temp->num == num) {
            position->endrc = temp;
            position->pos = pos_num;
            return position;
        }
        pos_num++;
        temp = temp->prox; 
    }

    return NULL;
}

void remover(int n, item** head) {
    pos* position = searchElement(n, *head);
    if(position == NULL) {
        printf("Elemento não encontrado na lista");
        exit(1);
    }
    item* temp = *head;
    item* last = NULL;

    while(position->endrc != temp) {
        last = temp;
        temp = temp->prox;
    }

    last->prox = temp->prox;
    free(temp);

}





