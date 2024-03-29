#include <stdio.h>
#include "loader.h"
#include "tokenizer.c"
#include "parser.c"
#include "tokens.h"

int main(int argc , char ** argv ){

  Length_tracker * len_tracker = (Length_tracker *)
    malloc(sizeof(Length_tracker));

  Node * buffer = loader(argv[1] , len_tracker);
  
  Node *parsedbuffer = parsing(buffer);

  Token * tok_array = flatten_token_list(parsedbuffer , len_tracker);

  for ( int i = 0 ; i < len_tracker->token_list_len ;  i++){
   printf("%s\n",tok_array[i].name);
  }
  
  return 0;
  
}
