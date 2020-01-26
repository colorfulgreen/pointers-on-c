#include <stdlib.h>
#include <stdio.h>
#include "inventor.h"

Invrec *
create_subassy_record(int n_parts)
{
    Invrec *new_rec;

    /* 试图为 Invrec 部分分配内存 */
    new_rec = malloc(sizeof(Invrec));
    if( new_rec != NULL) {
        new_rec->info.subassy = malloc(sizeof(Subassyinfo));
        if(new_rec->info.subassy != NULL) {
            new_rec->info.subassy->part = malloc(n_parts * sizeof(struct SUBASSYPART));
            if(new_rec->info.subassy->part != NULL) {
                new_rec->type = SUBASSY;
                new_rec->info.subassy->n_parts = n_parts;
                return new_rec;
            }
            free(new_rec->info.subassy);
        }
        free(new_rec);
    }
    return NULL;
}

void
discard_inventory_record(Invrec *record)
{
    switch(record->type) {
        case SUBASSY:
            free(record->info.subassy->part);
            free(record->info.subassy);
            break;
        case PART:
            free(record->info.part);
            break;
    }
    free(record);
}

int main(void)
{
    Invrec *p = create_subassy_record(5);
    discard_inventory_record(p);
    return EXIT_SUCCESS;
}
