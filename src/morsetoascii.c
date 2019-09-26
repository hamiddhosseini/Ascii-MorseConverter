#include "common.h"
#include <string.h>

char find(struct node* Root,char morse[],int Size)
{
  for (int i=0; i< Size;i++){
    if (morse[i]=='.'){
      Root = Root->left;
    }
    if (morse[i] == '-'){
      Root = Root->right;
    }
  }
    return Root->word;
}

int main(int argc, char * argv[]){
  struct node* Root = (struct node*)malloc(sizeof(struct node));
  Root = generate_tree();

  char Letter;
  int Size;
  if (argc != 1){
    for (int index=1;index<argc;index++){
      Size = strlen(argv[index]);
      Letter = find(Root,argv[index],Size);
      printf("%c",Letter);
    }
    printf("\n");
  }
  else{
    printf("Input type not compatible!\n");
  }
}
