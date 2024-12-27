#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player_list.h"

void get_names(player_list_t *list) {
    printf("Enter a player's name (press enter to begin game): ");
    char *name = NULL;
    size_t len = 0;
    size_t name_length;
    
    do {
        name_length = getline(&name, &len, stdin);

        if((name_length == -1) || (name[0] == '\n')){
            break;
        }

        printf("Enter a player's name: ");
        player_list_append(list, name);
    }
    while(1);

    free(name);
}

void target(player_list_t* list, player_list_t* tagged_list){
    int n;  
    size_t len = 0;
    char *name = NULL;  
    size_t name_length;

    while(1){   
        n = player_list_length(list);
        printf("There are %d people left.\n", n);
        printf("Enter a target: ");
        name_length = getline(&name, &len, stdin);

        if(player_list_remove(list, name)){

            player_list_append(tagged_list, name);
            print_name(name);
            printf(" was tagged.\n");
   
            free(name);
            name = NULL;
        }
        else {
            print_name(name);
            printf(" is not a target.\n");
        }        
        print_as_target_ring(list);
        print_as_tagged_list(tagged_list);

        if(n == 2){
            break;
        }
    }

    free(name);
}

int main() {
    player_list_t list, tagged_list;
    player_list_init(&list);
    player_list_init(&tagged_list);
   
    get_names(&list);
    
    print_as_target_ring(&list);

    int n = player_list_length(&list);
    if (n > 1){

        print_as_tagged_list(&tagged_list);
        target(&list, &tagged_list) ;
    }

    player_list_destroy(&list);
    player_list_destroy(&tagged_list);

    return 0;
}
