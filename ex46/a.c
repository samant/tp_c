
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

struct node {
  char *key;
  char *value;
  struct node *next;
};

typedef struct node entry;

struct hash_struct {
  int size;
  struct node **table;
};

typedef struct hash_struct hash;

hash *hashtable_create( int size ) {
  hash *hashtable = NULL;
  int i;

  if( size < 1 ) {
    return NULL;
  }

  if( ( hashtable = malloc( sizeof( hash ) ) ) == NULL ) {
    return NULL;
  }

  if( ( hashtable->table = malloc( sizeof( entry * ) * size ) ) == NULL ) {
    return NULL;
  }

  for( i = 0; i < size; i++ ) {
    hashtable->table[i] = NULL;
  }

  hashtable->size = size;

  return hashtable;
}

int hashtable_hash( hash *hashtable, char *key ) {
  unsigned long int hash_val;
  int i = 0;

  while( hash_val < ULONG_MAX && i < strlen( key ) ) {
    hash_val = hash_val << 8;
    hash_val += key[ i ];
    i++;
  }

  return hash_val % hashtable->size;
}

entry *hashtable_newpair( char *key, char *value ) {
  entry *new_pair;

  if( ( new_pair = malloc( sizeof( entry ) ) ) == NULL ) {
    return NULL;
  }

  if( (new_pair->key = strdup(key)) == NULL ) {
    return NULL;
  }

  if( (new_pair->value = strdup(value)) == NULL ) {
    return NULL;
  }

  new_pair->next = NULL;

  return new_pair;
}

void hashtable_set( hash *hashtable, char *key, char *value ) {
  int bin = 0;
  entry *new_pair = NULL;
  entry *next = NULL;
  entry *last = NULL;

  bin = hashtable_hash( hashtable, key );

  next = hashtable->table[ bin ];

  while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
    last = next;
    next = next->next;
  }

  if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {
    free( next->value );
    next->value = strdup(value);
  } else {
    new_pair = hashtable_newpair( key, value );
    if( next == hashtable->table[ bin ] ) {
      new_pair->next = next;
      hashtable->table[ bin ] = new_pair;
    } else{
      if ( next == NULL ) {
        last->next = new_pair;
      } else  {
        new_pair->next = next;
        last->next = new_pair;
      }
    }
  }
}

char *hashtable_get( hash *hashtable, char *key ) {
  int bin = 0;
  entry *pair;

  bin = hashtable_hash( hashtable, key );

  pair = hashtable->table[ bin ];
  while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
    pair = pair->next;
  }

  if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
    return NULL;
  } else {
    return pair->value;
  }
}

char *strdup (const char *s) {
  char *d = malloc (strlen (s) + 1);
  if (d == NULL) return NULL;
  strcpy (d,s);
  return d;
}

int main( int argc, char **argv ) {

  hash *hashtable = hashtable_create( 65536 );

  hashtable_set( hashtable, "key1", "unamur" );
  hashtable_set( hashtable, "key2", "bac1hd" );
  hashtable_set( hashtable, "key3", "programmation" );
  hashtable_set( hashtable, "key4", "c" );

  printf( "%s\n", hashtable_get( hashtable, "key1" ) );
  printf( "%s\n", hashtable_get( hashtable, "key2" ) );
  printf( "%s\n", hashtable_get( hashtable, "key3" ) );
  printf( "%s\n", hashtable_get( hashtable, "key4" ) );

  return 0;
}
