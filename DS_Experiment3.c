#include <stdio.h>
#include <stdlib.h>
typedef struct BiTree
{
    char date;
    struct BiTree *lchild;
    struct BiTree *rchild;
} TreeNode, *BiTreelist;
void createBiTree(BiTreelist *T)
{
    char ch = getchar();

    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTreelist)malloc(sizeof(TreeNode));
        (*T)->date = ch;
        createBiTree(&((*T)->lchild));
        createBiTree(&((*T)->rchild));
    }
}
// 先序遍历
void preOrderTraverse(BiTreelist T)
{
    if (T == NULL)
        return;
    printf("%c", T->date);
    preOrderTraverse(T->lchild);
    preOrderTraverse(T->rchild);
}
// 中序遍历
void InOrderTraverse(BiTreelist T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c", T->date);
    InOrderTraverse(T->rchild);
}
// 后序遍历
void PostOrderTraverse(BiTreelist T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->date);
}
// 统计叶子结点的个数
void CountLeaves(BiTreelist T, int *count)
{

    if (T == NULL)
    {
        return;
    }
    else
    {
        if (!T->lchild && !T->rchild)
        {
            (*count)++;
        }
        else
        {
            CountLeaves(T->lchild, count);
            CountLeaves(T->rchild, count);
        }
    }
}
void CountLefRig(BiTreelist T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        int childCount = 0;
        if (T->lchild)
            childCount++;
        if (T->rchild)
            childCount++;
        printf("%c结点的孩子数为:%d\n", T->date, childCount);
        CountLefRig(T->lchild);
        CountLefRig(T->rchild);
    }
}
int main()
{
    int count = 0;
    BiTreelist T;
    printf("输入二叉树的序列为:");
    createBiTree(&T);
    printf("先序遍历二叉树为: ");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历二叉树为: ");
    InOrderTraverse(T);
    printf("\n");
    printf("后序遍历二叉树为: ");
    PostOrderTraverse(T);
    printf("\n");
    printf("该二叉树叶子结点为: ");
    CountLeaves(T, &count);
    printf("%d", count);
    printf("\n");
    printf("每个结点的孩子数为: \n");
    CountLefRig(T);
    return 0;
}