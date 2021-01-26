
#include <string.h>
#include <stdlib.h>

#include "jam.h"
#include "hash.h"
#include "class.h"
#include "classlib.h"

void lockHashTable0(HashTable *table, Thread *self) {
    if(!tryLockVMLock(table->lock, self)) {
        disableSuspend(self);
        lockVMLock(table->lock, self);
        enableSuspend(self);
    }
    fastDisableSuspend(self);
}

void unlockHashTable0(HashTable *table, Thread *self) {
    fastEnableSuspend(self);
    unlockVMLock(table->lock, self);
}

void resizeHash(HashTable *table, int new_size) {
    HashEntry *new_table = gcMemMalloc(sizeof(HashEntry)*new_size);
    int i;

    memset(new_table, 0, sizeof(HashEntry)*new_size);

    for(i = table->hash_size-1; i >= 0; i--) {
        void *ptr = table->hash_table[i].data;
        if(ptr != NULL) {
            int hash = table->hash_table[i].hash;
            int new_index = hash & (new_size - 1);

            while(new_table[new_index].data != NULL)
                new_index = (new_index+1) & (new_size - 1);

            new_table[new_index].hash = hash;
            new_table[new_index].data = ptr;
        }
    }

    gcMemFree(table->hash_table);
    table->hash_table = new_table;
    table->hash_size = new_size;
}
