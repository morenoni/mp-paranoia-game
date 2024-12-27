#include "player_list.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void print_name(char *name);

void player_list_init(player_list_t* lst){
    lst->head = NULL;
}

void player_list_destroy(player_list_t* lst){
    struct player_node *current = lst->head;
    struct player_node *next;

    while (current != NULL){
        next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
    lst->head = NULL;
}

void player_list_append(player_list_t* lst, char* name){
    struct player_node *new_node = malloc(sizeof(struct player_node));

    if (new_node == NULL){
        free(new_node);
        return;
    }
  
    new_node->value = strdup(name);
    if (new_node->value == NULL) {
        free(new_node); 
        return;
    }
    new_node->next = NULL;
  
    if (lst->head == NULL){
        lst->head = new_node;
        return;
    }
  
    struct player_node *current = lst->head;
    while (current->next != NULL){
      current = current->next;
    }

    current->next = new_node;
}

bool player_list_remove(player_list_t* lst, char* name){
    if (name == NULL){
        return false;
    }
    
    struct player_node *current = lst->head;
    struct player_node *aux;
    struct player_node *next;
    
    while (current != NULL){
        if(strcmp(current->value, name) == 0){

            if(current == lst->head){
                lst->head = current->next;
                free(current->value);
                free(current);
            }
            else {
            
                next = current->next;

                free(current->value);
                free(current);
    
                aux->next = next;
            }
            return true;
        }
        aux = current;
        current = current->next;
    }

    return false;
}

size_t player_list_length(const player_list_t* lst){
    player_node_t *current = lst->head;
    int count = 0;

    while(current != NULL){
       count++;
       current = current->next;
    }
   
    return count;
}

void print_as_target_ring(const player_list_t* lst){
    int len = player_list_length(lst);
    if(len == 0){
        printf("There are no targets left.\n");
        return;
    }
    else if(len == 1){
        print_name(lst->head->value);
        printf(" is the final person remaining.\n");
        printf("Target Ring:\n");
        printf("    There are no targets left.\n");
        return;
    }

    printf("Target ring: \n");
    
    struct player_node *head = lst->head;
    struct player_node *next;
    struct player_node *current = lst->head;
    
    while (current != NULL){   
        next = current->next;
        if(next == NULL){
            next = head;
        }

        printf("\t");
        print_name(current->value);
        printf(" is stalking ");
        print_name(next->value);
        printf("\n");

        current = current->next;
    }
}

void print_name(char *name){
    int i = 0;
    while (name[i] != '\n'){
        printf("%c", name[i]);
        i++;
    }
}

void print_as_tagged_list(const player_list_t* lst){
    if(player_list_length(lst) == 0){
        printf("No people have been tagged yet.\n\n\n");
        return;
    }
    printf("Tagged Lists: \n");
    
    struct player_node *current = lst->head;
    
    while (current != NULL){   
        printf("\t");
        print_name(current->value);
        printf("\n");

        current = current->next;
    }
    printf("\n\n");
}