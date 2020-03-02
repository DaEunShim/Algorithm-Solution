#include<stdio.h>
typedef struct node* tree_ptr;
typedef struct node {
	int data;
	tree_ptr left;
	tree_ptr right;
};

void preorder(tree_ptr ptr) {
	if (ptr) {
		printf("%c", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void inorder(tree_ptr ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%c", ptr->data);
		inorder(ptr->right);
	}
}
void postorder(tree_ptr ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%c", ptr->data);
	}
}

int main(void) {
	struct node node[26];
	int N;
	char data, left, right;
	scanf_s("%d", &N); getchar();
	while(N--){
		scanf_s("%c", &data); getchar();
		node[data-'A'].data = data;
		scanf_s("%c", &left); getchar();
		if (left != '.') {
			node[left - 'A'].data = left;
			node[data - 'A'].left = &node[left - 'A'];
		}
		else node[data - 'A'].left = NULL;
		scanf_s("%c", &right); getchar();
		if (right != '.') {
			node[right - 'A'].data = right;
			node[data - 'A'].right = &node[right - 'A'];
		}
		else node[data - 'A'].right = NULL;
	}
	preorder(node); printf("\n");
	inorder(node); printf("\n");
	postorder(node); printf("\n");
	return 0;
}