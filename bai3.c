//
//  bai3.c
//  cautrucdulieuXcode
//
//  Created by USED on 16/12/24.
//

#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong cây nhị phân tìm kiếm
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

// Hàm chèn một giá trị vào cây nhị phân tìm kiếm (BST)
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    // Nếu giá trị cần chèn nhỏ hơn giá trị của nút hiện tại, chèn vào cây con bên trái
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Nếu giá trị cần chèn lớn hơn giá trị của nút hiện tại, chèn vào cây con bên phải
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Hàm tìm kiếm giá trị trong cây nhị phân tìm kiếm (BST)
int search(struct Node* root, int value) {
    if (root == NULL) {
        return 0; // Nếu cây trống, không tìm thấy giá trị
    }

    // Nếu giá trị tìm thấy trong nút hiện tại
    if (root->data == value) {
        return 1; // Tìm thấy giá trị
    }

    // Nếu giá trị cần tìm nhỏ hơn giá trị của nút hiện tại, tìm trong cây con bên trái
    if (value < root->data) {
        return search(root->left, value);
    }

    // Nếu giá trị cần tìm lớn hơn giá trị của nút hiện tại, tìm trong cây con bên phải
    return search(root->right, value);
}

int main() {
    struct Node* root = NULL;

    // Nhập giá trị và chèn vào cây nhị phân
    int n, value, searchValue;
    printf("Nhập số lượng phần tử trong cây: ");
    scanf("%d", &n);

    printf("Nhập các giá trị vào cây:\n");
    for (int i = 0; i < n; i++) {
        printf("Nhập giá trị %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Nhập giá trị cần tìm kiếm
    printf("\nNhập giá trị cần tìm: ");
    scanf("%d", &searchValue);

    // Tìm kiếm giá trị trong cây và in kết quả
    if (search(root, searchValue)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}
