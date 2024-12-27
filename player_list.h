#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct player_node {
    char* value;
    struct player_node* next;
} player_node_t;


typedef struct player_list{
    player_node_t* head;
} player_list_t;


void print_name(char *name);

void player_list_init(player_list_t* lst);

void player_list_destroy(player_list_t* lst);

void player_list_append(player_list_t* lst, char* name);

bool player_list_remove(player_list_t* lst, char* name);

size_t player_list_length(const player_list_t* lst);

void print_as_target_ring(const player_list_t* lst);

void print_as_tagged_list(const player_list_t* lst);
