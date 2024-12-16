//
//  bai1.c
//  cautrucdulieuXcode
//
//  Created by USED on 16/12/24.
//

#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Hàm tạo một nút mới với giá trị cho trước
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Cấp phát bộ nhớ cho nút mới
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm chèn một nút vào cây nhị phân tìm kiếm (BST)
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    // Nếu giá trị cần chèn nhỏ hơn giá trị của nút hiện tại, chèn vào cây con bên trái
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Nếu giá trị cần chèn lớn hơn hoặc bằng giá trị của nút hiện tại, chèn vào cây con bên phải
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Hàm duyệt cây theo tiền thứ tự (Pre-order)
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Hàm duyệt cây theo trung thứ tự (In-order)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Hàm duyệt cây theo hậu thứ tự (Post-order)
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL; 

    // Nhập giá trị và chèn vào cây nhị phân
    int n, value;
    printf("Nhập số lượng phần tử trong cây: ");
    scanf("%d", &n);

    printf("Nhập các giá trị vào cây:\n");
    for (int i = 0; i < n; i++) {
        printf("Nhập giá trị %d: ", i+1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // In các giá trị của cây theo các kiểu duyệt khác nhau
    printf("\nDuyệt cây theo tiền thứ tự (Pre-order): ");
    preOrder(root);

    printf("\nDuyệt cây theo trung thứ tự (In-order): ");
    inOrder(root);

    printf("\nDuyệt cây theo hậu thứ tự (Post-order): ");
    postOrder(root);

    return 0;
}
