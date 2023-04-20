#include <stdio.h>
#include <stdlib.h>

struct node_t {
    int data;
    struct node_t* left;
    struct node_t* right;
};

int add(struct node_t** tree, int data, int count) {
    if ((*tree) == NULL) {
        if(count < 5){
            struct node_t* new_node = malloc(sizeof(struct node_t));
            new_node->data = data;
            new_node->left = new_node->right = NULL;

            return count;
        }
        return count;
    }
    if((*tree)->data == data)
        count++;

    if (data < (*tree)->data) {
        add((*tree)->left, data, count);
    }
    else if (data > (*tree)->data) {
        add((*tree)->right, data, count);
    }

    return count;
}

int cnt_elements(struct node_t* tree)
{
    if (tree == NULL) return 0;
    return cnt_elements(tree->left)+cnt_elements(tree->right)+1;
}

int search(struct node_t* tree,int data)
{
    if (tree == NULL)
        return 0;

    if (data == tree->data)
        return 1;
    if (data < tree->data)
        return search(tree->left, data);
    else
        return search(tree->right, data);
}

void print_tree(struct node_t* tree) {
    if (tree == NULL) return;

    printf("%d\n", tree->data);

    print_tree(tree->left);
    print_tree(tree->right);

}

int main() {
    struct  node_t* tree;
    int count;
    count = add(tree, 13, 0);
    count = add(tree, 13, 0);
    count = add(tree, 13, 0);
    count = add(tree, 13, 0);
    count = add(tree, 13, 0);
    count = add(tree, 13, 0);
    count = add(tree, 13, 0);

    printf("%d ", search(tree,13));
    printf("%d ", search(tree, 41));
    printf("%d ", search(tree, 44));

    printf("%d ", cnt_elements(tree));

    print_tree(tree);

    return 0;
}

