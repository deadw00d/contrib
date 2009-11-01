/**************************************************************************
 *
 * Copyright 2008 Tungsten Graphics, Inc., Cedar Park, Texas.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL TUNGSTEN GRAPHICS AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/

/**
 * General purpose hash table.
 *  
 * @author José Fonseca <jrfonseca@tungstengraphics.com>
 */

#ifndef U_HASH_TABLE_H_
#define U_HASH_TABLE_H_


#include "pipe/p_error.h"


#ifdef __cplusplus
extern "C" {
#endif

   
/**
 * Generic purpose hash table.
 */
struct hash_table;


/**
 * Create an hash table.
 * 
 * @param hash hash function
 * @param compare should return 0 for two equal keys.
 */
struct hash_table *
hash_table_create(unsigned (*hash)(void *key),
                  int (*compare)(void *key1, void *key2));


enum pipe_error
hash_table_set(struct hash_table *ht,
               void *key,
               void *value);

void *
hash_table_get(struct hash_table *ht, 
               void *key);


void
hash_table_remove(struct hash_table *ht, 
                  void *key);

#define hash_table_clear u_hash_table_clear

void
hash_table_clear(struct hash_table *ht);


enum pipe_error
hash_table_foreach(struct hash_table *ht,
                   enum pipe_error (*callback)(void *key, void *value, void *data),
                   void *data);

void
hash_table_destroy(struct hash_table *ht);


#ifdef __cplusplus
}
#endif

#endif /* U_HASH_TABLE_H_ */
