// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <string.h>

#define MAX 27

int preIndex;

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(char arr[], int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

struct Node* buildTree(char in[], char pre[], int inStart, int inEnd) {
    if (inStart > inEnd) {
        return NULL;
    }

    struct Node* tNode = newNode(pre[preIndex++]);

    if (inStart == inEnd) {
        return tNode;
    }

    int inIndex = search(in, inStart, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStart, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

void printPostorder(struct Node* node) {
    if (node == NULL) {
        return;
    }

    printPostorder(node->left);
    printPostorder(node->right);
    printf("%c", node->data);
}

int main() {
    char pre[MAX], in[MAX];

    while (scanf("%s %s", pre, in) != EOF) {
        int len = strlen(pre);
        preIndex = 0;
        struct Node* root = buildTree(in, pre, 0, len - 1);
        printPostorder(root);
        printf("\n");
    }

    return 0;
}
