#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
} Node;

Node *createNode(int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node *insert(Node *root, int data)
{
	if (root == NULL)
	{
		return createNode(data);
	}
	if (data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root;
}

Node* deleteMax(Node* root, int* maxValue)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->right == NULL)
	{
		*maxValue = root->data;
		return root->left;
	}
	root->right = deleteMax(root->right, maxValue);
	return root;
}

int getMax(Node *root)
{
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root->data;
}

int getMin(Node *root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
}

Node* deleteMin(Node *root, int *minValue)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->left == NULL)
	{
		*minValue = root->data;
		return root->right;
	}
	root->left = deleteMin(root->left, minValue);
	return root;
}

/*
这是一个二叉搜索树的删除节点的函数。输入参数包括一个二叉搜索树的根节点和待删除的数据。函数返回删除节点后的根节点。
首先，判断根节点是否为空，如果为空，则返回空。
如果待删除的数据小于根节点的数据，则递归地在左子树中删除该数据。
如果待删除的数据大于根节点的数据，则递归地在右子树中删除该数据。
如果待删除的数据等于根节点的数据，则需要进行删除操作：

如果根节点没有左子树，则将根节点的右子树作为新的根节点。

如果根节点没有右子树，则将根节点的左子树作为新的根节点。

如果根节点既有左子树又有右子树，则需要找到左子树中的最大值作为新的根节点，并删除该最大值节点。具体做法是，将根节点的数据替换为左子树中最大值节点的数据，然后递归地在左子树中删除该最大值节点。
最后，返回删除节点后的根节点。
*/
Node* delete(Node* root, int data)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (data < root->data)
	{
		root->left = delete(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = delete(root->right, data);
	}
	else
	{
		if (root->left == NULL)
		{
			Node* tmp = root->right;
			free(root);
			return tmp;
		}
		else if (root->right == NULL)
		{
			Node *tmp = root->left;
			free(root);
			return tmp;
		} 
		else
		{
			root->data = getMax(root->left);
			root->left = deleteMax(root->left, &root->data);
		}
		
	}
	return root;
}

void inorderTraversal(Node* root) {
	if (root != NULL) {
		inorderTraversal(root->left);
		printf("%d ", root->data);
		inorderTraversal(root->right);
	}
}
int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    printf("Inorder traversal of the original tree:\n");
    inorderTraversal(root);
    printf("\n");
 
    root = delete(root, 20);
    printf("Inorder traversal after deleting 20:\n");
    inorderTraversal(root);
    printf("\n");
 
    root = delete(root, 30);
    printf("Inorder traversal after deleting 30:\n");
    inorderTraversal(root);
    printf("\n");
 
    root = delete(root, 50);
    printf("Inorder traversal after deleting 50:\n");
    inorderTraversal(root);
    printf("\n");
 
    return 0;
}