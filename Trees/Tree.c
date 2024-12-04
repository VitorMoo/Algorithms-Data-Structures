#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode 
{
    int value;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode *createNode(int value){
    treeNode *result = malloc(sizeof(treeNode));

    if(result != NULL){
        result -> left = NULL;
        result -> right = NULL;
        result -> value = value;
    }
    return result;
}

  void printTreeRec(treeNode *root, int level){
    if (root == NULL){
        return;
    }
    printTreeRec(root->right, level + 1);
    for(int i = 0; i < level; i++){
        printf("    ");
    }
    printf("%d\n", root->value);
    printTreeRec(root->left, level + 1);
}

  void printTree(treeNode* root){
    printTreeRec(root,0);
  }

    bool insertNumber(treeNode **rootPtr, int value){
        treeNode *root = *rootPtr;

        if(root == NULL){
            (*rootPtr) = createNode(value);
            return true;
        }

        if(value == root->value){
          return false;
        }

        if(value < root->value){
            return insertNumber(&(root->left), value);
        }else{
            return insertNumber(&(root->right),value);
        }
    }

    bool findNumber( treeNode * root, int value){
      if (root == NULL) return false;
      if(root->value == value ){
        return true;
      }
      if(value < root->value){
        return findNumber(root->left,value);
      }else{
        return findNumber(root->right,value);
      }
    }

    void inOrderTraversal(treeNode *root){
      if(root == NULL){
        return;
    }else{
        inOrderTraversal(root->left);
        printf("%d ", root->value);
        inOrderTraversal(root->right);
    }
    }

    void preOrderTraversal(treeNode *root){
      if(root == NULL){
        return;
    }else{
        printf("%d ", root->value);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    }

    void postOrderTraversal(treeNode *root){
      if(root == NULL){
        return;
    }else{
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->value);
    }
    }

    void freeTree(treeNode* root){
    if(root == NULL){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

  int main(){

    treeNode *root = NULL;
    insertNumber(&root, 10);
    insertNumber(&root, 5);
    insertNumber(&root, 15);
    insertNumber(&root, 2);
    insertNumber(&root, 7);
    insertNumber(&root, 20);
    insertNumber(&root, 16);
    insertNumber(&root, 14);
    insertNumber(&root, 1);

    printf("Is this number in the tree? \n");
    printf("%d (%d)\n", 14, findNumber(root, 14));
    printf("%d (%d)\n", 6, findNumber(root, 6));

    printf("\nTree Structure:\n");
    printTree(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    freeTree(root);

  return 0;
  }
