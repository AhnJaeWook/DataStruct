#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
	int data;
	struct TreeNode* left, *right;
};

TreeNode* new_node(int key){
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));	
	node->data = key;
	node->left = node->right = NULL;
	return node;
}

TreeNode* insert_node(TreeNode* node, int key){
	if(node == NULL) return new_node(key);

	if(key < node->data){
		node->left = insert_node(node->left, key);
	}
	else if(key > node->data){
		node->right = insert_node(node->right, key);
	}
	return node;
}

void Insert_node(TreeNode** root){
	TreeNode* temp = *root;
	int key =0;
	printf("insert data: ");
	scanf("%d",&key);
	*root = insert_node(temp, key);
}

TreeNode* min_value_node(TreeNode* node){
	TreeNode* temp = node;
	
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

TreeNode* delete_node(TreeNode* root, int key){
	if(root == NULL) return root;
	if(key < root->data){
		root->left = delete_node(root->left, key);
	}
	else if(key > root->data){
		root->right = delete_node(root->right, key);
	}
	else{
		if(root->left == NULL){
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);

		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}
	return root;
}

void Delete_node(TreeNode** root){
	TreeNode* temp = *root;
	int key = 0;
	printf("delete data: ");
	scanf("%d",&key);
	*root = delete_node(temp, key);
}

TreeNode* search(TreeNode* node, int key){
	if(node==NULL) return NULL;
	if(key == node->data) return node;
	else if(key < node->data){
		return search(node->left, key);
	}
	else{
		return search(node->right, key);
	}
}

void Search_node(TreeNode** root){
	TreeNode* temp = *root;
	int key = 0;
	printf("search data : ");
	scanf("%d",&key);
	if(search(temp, key) != NULL){
		printf("find data\n");
	}
	else{
		printf("not data\n");
	}
}

void inorder(TreeNode *root){
	if(root){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void Inorder(TreeNode** root){
	TreeNode* temp = *root;
	printf("Inorder : ");
	inorder(temp);
	printf("\n");
}

void print_menu(){
	printf("1 : insert node\n");
 	printf("2 : delete node\n");
	printf("3 : search node\n");
	printf("4 : inorder\n");
	printf("5 : exit\n");
}	

int main(int argc, char* argv[]){
	TreeNode* root = NULL;
	int num = 0, loop = 1;	

	while(loop){
		print_menu();
		printf("input : ");
		scanf("%d",&num);
		switch(num){
			case 1 : Insert_node(&root); break;
			case 2 : Delete_node(&root); break; 
		  case 3 : Search_node(&root); break;
			case 4 : Inorder(&root); break;	 
			case 5 : loop=0; break;

			default : printf("not command\n"); break;
		}
	}	
	return 0;
}
