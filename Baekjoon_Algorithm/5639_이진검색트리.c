#include <stdio.h>
typedef struct node* tree_ptr;
typedef struct node {
	int data;
	tree_ptr left;
	tree_ptr right;
};
void postorder(tree_ptr ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d", ptr->data);
	}
}
int main(void) {
	struct node node[100000];
	int root, in;
	int num;
	scanf_s("%d", &root);
	while (scanf_s("%d", &in) == 1) {
		num = root;
		while (1) {
			if (node < in) {
				if (node[num].right != 0) {
					num = node[num].right;
				}
				else {
					node[num].right = in;
					break;
				}
			}
			else {
				if (node[num].left != 0) {
					num = node[num].left;
				}
				else {
					node[num].left = in;
					break;
				}
			}
		}
	}
	postorder(node); printf("\n");
	return 0;
}