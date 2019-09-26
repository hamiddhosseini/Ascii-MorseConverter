#include "common.h"
int main (int argc, char *argv[]){
    struct node* Root = (struct node*)malloc(sizeof(struct node));
    char *Address= (char *)malloc(sizeof(char)*6);
    Root = generate_tree();
    int Size;
    int result=0;

    if (argc != 1){
      for(int i =1; i<argc;i++){
        Size = strlen(argv[i]);
        for (int j=0;j<Size;j++){
          result = 0;
          search_tree(Root,argv[i][j],Address,&result);
        }
      }
      printf("\n");
    }
    else{
      printf("Input type not compatible");
    }
}
