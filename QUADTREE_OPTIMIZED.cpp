#include <stdio.h>
#include <string.h>

int preorder[100];
int inorder[100];
int pos = 0;

int memo[1000 + 1];

void printPost(int lower, int upper);
void reset();

int main()
{
    int nTest = 0;
    scanf("%d", &nTest);
    while (nTest-- > 0)
    {
        scanf("%d", &nNode);

        int i = 0, j = 0;
        while (i < nNode)
        {
            scanf("%d", &preorder[i]);
            i++;
        }
        while (j < nNode)
        {
            scanf("%d", &inorder[j]);
            memo[ inorder[j] ] = j;
            j++;
        }

        printPost(0, nNode);
        printf("\n");
        reset();
    }
}

void printPost(int lower, int upper)
{
    if (lower > upper) return;
    if (lower >= nNode) return;
    if (upper < 0) return;
    
    int root = preorder[pos++]; // 9
    int inorderIndex = memo[ root ]; // 3 -> 2 -> 0 -> 1 -> 5 -> 4 -> 6 // 0
    
    if (inorderIndex == lower) lower++;
    if (inorderIndex == upper) upper--;
    
    printPost(lower, inorderIndex);
    printPost(inorderIndex + 1, upper);
    
    printf("%d ", root);
}

void reset()
{
    nNode = 0;
    pos = 0;
    memset(used, 0, sizeof(used));
}