#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node_t {
	int value;
	int height;
	struct node_t* left;
	struct node_t* right;
};

int max(int a, int b) {
	return a > b ? a : b;
}

int get_node_height(struct node_t* node) {
	if (node == NULL) {
		return 0;
	}

	return node->height;
}

int is_bst_balanced(struct node_t* node) {
	if (node == NULL) {
		return 1;
	}

	int current_difference = abs(get_node_height(node->left) - get_node_height(node->right));

	if (current_difference > 1) {
		return 0;
	}

	return is_bst_balanced(node->left) && is_bst_balanced(node->right);
}

void calculate_node_height(struct node_t* node) {
	if (node == NULL) {
		return;
	}

	node->height = 1 + max(get_node_height(node->left), get_node_height(node->right));
}

struct node_t* init_node(int value) {
	struct node_t* new_node = malloc(sizeof(struct node_t));
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	calculate_node_height(new_node);

	return new_node;
}

struct node_t* insert(struct node_t* root, int value) {
	if (root == NULL) {
		return init_node(value);
	}

	if (value > root->value) {
		root->right = insert(root->right, value);
	}

	if (value < root->value) {
		root->left = insert(root->left, value);
	}

	calculate_node_height(root);
	return root;
}

struct node_t* find(struct node_t* root, int value) {
	if (root == NULL) {
		return NULL;
	}

	if (root->value > value) {
		return find(root->left, value);
	}

	if (root->value < value) {
		return find(root->right, value);
	}

	return root;
}

void populate_array_inorder_traversal(struct node_t* node, int* arr, int* pos) {
	if (node == NULL) {
		return;
	}

	populate_array_inorder_traversal(node->left, arr, pos);
	arr[*pos] = node->value;
	(*pos)++;
	populate_array_inorder_traversal(node->right, arr, pos);
}

void inorder_traversal(struct node_t* node) {
	if (node == NULL) {
		return;
	}

	inorder_traversal(node->left);
	printf("%d with height %d\n", node->value, node->height);
	inorder_traversal(node->right);
}

void delete(struct node_t* node, int value) {
	delete_internal(node, NULL, value);
}

void delete_internal(struct node_t* node, struct node_t* parent, int value) {
	if (node == NULL) {
		return;
	}

	if (node->value == value) {
		// case: no children
		if (node->left == NULL && node->right == NULL) {
			if (parent->right == node) {
				parent->right = NULL;
			} else {
				parent->left = NULL;
			}
			free(node);
			return;
		}

		// case: two children
		if (node->right != NULL && node->left != NULL) {


			return;
		}

		// case: one child
		if (node->left != NULL || node->right != NULL) {
			struct node_t* child = node->left != NULL ? node->left : node->right;
			if (parent->right == node) {
				parent->right = child;
			} else {
				parent->left = child;
			}
			free(node);
			return;
		}
	}

	if(node->value > value) {
		delete_internal(node->left, node, value);
	}

	if(node->value < value) {
		delete_internal(node->right, node, value);
	}
}

/*struct node_t* rotate_left(struct node_t* left){
    struct node_t *y = left->right;
	struct node_t *newo = y->left;

	y->left = left;
	left->right = newo;

	left->height = max(height(a->left), height(a->right))+1;
	y->height = max(height(b->left), height(b->right))+1;

	return y;
}; //tuk baq se oburkah

struct node_t* insert_to_balance(struct node_t* node_t, int value){
    if (is_bst_balanced != true){
        if (value < node->value)
		node->left = insert(node->left, value);

        else if (value > node->value)
		node->right = insert(node->right, value);

        else
            return node;
        int balance = is_bst_balanced(node_t);
        //sega sa 4te case-a

        if (balance > 1 && value > node->right->value){
            return rotate_left(node);}


    }
};//ne uspqh da go izmislq i si pomagah ot https://www.geeksforgeeks.org/avl-tree-set-1-insertion/?ref=gcse
*/
int main(){
	struct node_t* root = init_node(8);

	insert(root, 15);
	insert(root, 4);
	insert(root, 5);
	struct node_t* inserted = insert(root, 7);
	printf("inserted: %d\n", inserted->value);


	printf("tree contains %d ? -> %d\n", 8, find(root, 8) != NULL);
	printf("tree contains %d ? -> %d\n", 16, find(root, 16) != NULL);
	printf("tree contains %d ? -> %d\n", 7, find(root, 7) != NULL);
	printf("tree contains %d ? -> %d\n", 5, find(root, 5) != NULL);
	printf("tree contains %d ? -> %d\n", 6, find(root, 6) != NULL);
	printf("tree contains %d ? -> %d\n", 4, find(root, 4) != NULL);

	int* sorted = malloc(sizeof(int) * 5);
	int pos = 0;
	populate_array_inorder_traversal(root, sorted, &pos);
	for (int i = 0; i<5; i++) {
		printf("%d ", sorted[i]);
	}
	printf("\n");

	inorder_traversal(root);

	return 0;
}
