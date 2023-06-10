#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int data;
    struct BST *left, *right;
};

struct BST *root = NULL;

struct BST *createNode(int item)
{
    struct BST *temp = (struct BST *) malloc(sizeof(struct BST));

    if(temp == NULL)
    {
        printf("\nNode can't be allocated");
        return NULL;
    }

    temp -> data = item;
    temp -> left = NULL;
    temp -> right = NULL;

    return temp;
}

struct BST *insert(struct  BST *root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }
    if(root -> data < value)
    {
        root -> right = insert(root -> right, value);
    }
    if(root -> data >= value)
    {
        root -> left = insert(root -> left , value);
    }

    return root;
}
struct BST *deletion(struct BST *root, int value)
{

}
struct BST *search(struct  BST *root, int key)
{
    if(root == NULL)
        return NULL;
    else if(root -> data == key)
        return root;
    else if(root -> data > key)
        return search(root -> left , key);
    else
        return search(root -> right , key);

}

void preorder(struct BST *root)
{
    if(root != NULL)
    {
        printf("%d ", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(struct BST *root)
{
    if(root != NULL)
    {
        inorder(root -> left);
        printf("%d ", root -> data);
        inorder(root -> right);
    }
}

void postorder(struct BST *root)
{
    if(root != NULL)
    {
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ", root -> data);
    }
}
int getData()
{
    int data;
    printf("Enter the number: ");
    scanf("%d",&data);

    return data;
}

int menu()
{
    int ch;
    printf("\n 1. Inset");
    printf("\n 2. Delete");
    printf("\n 3. Search");
    printf("\n 4. Print preorder");
    printf("\n 5. Print inorder");
    printf("\n 6. Print postorder");
    printf("\n 7. Exit");

    printf("\n\nEnter your choice: ");
    scanf("%d",&ch);

    return ch;
}
int main()
{
    int value, key, flag;
    while(1)
    {
        switch (menu())
        {
        case 1:
            value = getData();
            root = insert(root, value) ;
            break;
        case 2:

            break;
        case 3:
            key = getData();
            flag = search(root, key);
            if(flag)
            {
                printf("Fount");
            }
            else{
                printf("Not fount");
            }
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            inorder(root);
            break;
        case 6:
            postorder(root);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    }
    return 0;
}
