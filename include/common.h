#ifndef COMMON_H
#define COMMON_H
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct node{
    char word;
    struct node *left;
    struct node *right;
  };

  struct node* create(char Word){
    struct node* Node= (struct node*)malloc(sizeof(struct node));
    Node->word = Word;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
  }

  struct node* generate_tree(){
    struct node* Root = (struct node*)malloc(sizeof(struct node));
    Root->left = create('E');
    Root->left->left = create('I');
    Root->left->left->left = create('S');
    Root->left->left->left->left = create('H');
    Root->left->left->left->right = create('V');
    Root->left->left->right = create('U');
    Root->left->left->right->left = create('F');
    Root->left->right = create('A');
    Root->left->right->left = create('R');
    Root->left->right->left->left = create('L');
    Root->left->right->right = create('W');
    Root->left->right->right->left = create('P');
    Root->left->right->right->right = create('J');

    Root->right = create('T');
    Root->right->left = create('N');
    Root->right->left->left = create('D');
    Root->right->left->left->left = create('B');
    Root->right->left->left->right = create('X');
    Root->right->left->right = create('K');
    Root->right->left->right->left = create('C');
    Root->right->left->right->right = create('Y');
    Root->right->right = create('M');
    Root->right->right->left = create('G');
    Root->right->right->left->left = create('Z');
    Root->right->right->left->right = create('Q');
    Root->right->right->right = create('O');
    Root->right->right->right->right = create(' ');

    return Root;
  }
char *search_tree(struct node *Current, char Letter, char *Address,int * result){
  if (Current->word == Letter) {
    *result = 1;
    printf("%s ",Address );
    return Address;
  }
  else{
    char *left = ".";
    char *right = "-";
    if((Current->left != NULL)&&(*result == 0)){
      char *Destination = (char *)malloc((strlen(Address)+1)*sizeof(char));
      for (int i=0;i<strlen(Address)+1;i++){
        Destination[i]=Address[i];
      }
      strcat(Destination,left);
      Destination = search_tree(Current->left,Letter,Destination,result);
      free(Destination);
      Destination = NULL;
    }
    if ((Current->right != NULL) &&(*result == 0)){

      char *Destination = (char *)malloc((strlen(Address)+1)*sizeof(char));
      for (int i=0;i<strlen(Address)+1;i++){
        Destination[i]=Address[i];
      }
      strcat(Destination,right);
      Destination = search_tree(Current->right,Letter,Destination,result);
      free(Destination);
      Destination = NULL;
    }
    return Address;
  }
}

#endif
