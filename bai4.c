//
//  bai4.c
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
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm chèn một giá trị vào cây nhị phân (cây nhị phân tự do)
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    // Chèn vào cây con bên trái nếu giá trị nhỏ hơn nút hiện tại
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Hàm tính chiều cao của cây nhị phân
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    // Tính chiều cao của cây con trái và cây con phải
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Chiều cao của cây là chiều cao lớn nhất giữa cây con trái và cây con phải cộng 1
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
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
        printf("Nhập giá trị %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value); 
    }

    // Tính và in ra chiều cao của cây
    printf("\nChiều cao của cây là: %d\n", height(root));

    return 0;
}

