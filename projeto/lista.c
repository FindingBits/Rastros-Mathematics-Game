//
// Created by João Guedes on 19/04/2020.
//

#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
node criar_lista(){
    node * head = NULL;
    head = (node *) malloc(sizeof(node));
}
node insere_cabeca(node * head, int valor){
    head->data = valor;
    head->next = NULL;
}
void *devolve_cabeca(node * head){
    node * current = head;
    printf("%d\n", current->data);
    current = current->next;
}
node proximo(node * head){
    head->next = (node *) malloc(sizeof(node));
    head->next->data = 2;
    head->next->next = NULL;
}
node remove_cabeca(node ** head){
    int retval = -1;
    node * next_node = NULL;
    next_node = (*head)->next;
    retval = (*head)->data;
    free(*head);
}
int lista_esta_vazia(node *head){
        if(head == NULL) return 1;
        else return 0;
}