//
//  bai2.c
//  cautrucdulieuXcode
//
//  Created by USED on 16/12/24.
//
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct Node {
    int data;           // Giá trị của nút
    struct Node* left;  // Con trỏ đến nút con bên trái
    struct Node* right; // Con trỏ đến nút con bên phải
};

// Hàm tạo một nút mới với giá trị cho trước
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Cấp phát bộ nhớ cho nút mới
    newNode->data = value;        // Gán giá trị cho nút
    newNode->left = NULL;         // Ban đầu nút không có con trái
    newNode->right = NULL;        // Ban đầu nút không có con phải
    return newNode;               // Trả về con trỏ tới nút mới
}

// Hàm chèn một nút vào cây nhị phân tìm kiếm (BST)
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value); // Nếu cây trống, tạo và trả về nút mới
    }

    // Nếu giá trị cần chèn nhỏ hơn giá trị của nút hiện tại, chèn vào cây con bên trái
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Nếu giá trị cần chèn lớn hơn hoặc bằng giá trị của nút hiện tại, chèn vào cây con bên phải
    else {
        root->right = insert(root->right, value);
    }

    return root; // Trả về con trỏ tới cây đã thay đổi
}

// Hàm tìm các đỉnh ở lớp 2 (mức thứ hai từ gốc)
void findLevel2Nodes(struct Node* root) {
    if (root == NULL) {
        return; // Nếu cây trống, không làm gì
    }

    // Nếu lớp 2, in ra giá trị của nút
    if (root->left != NULL) {
        printf("%d ", root->left->data); // In giá trị của nút con trái
    }
    if (root->right != NULL) {
        printf("%d ", root->right->data); // In giá trị của nút con phải
    }

    // Duyệt cây con bên trái và bên phải của gốc để tìm các đỉnh ở lớp 2
    findLevel2Nodes(root->left);
    findLevel2Nodes(root->right);
}

int main() {
    struct Node* root = NULL; // Cây bắt đầu trống

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

    // Tìm và in các đỉnh ở lớp 2
    printf("\nCác đỉnh ở lớp 2: ");
    findLevel2Nodes(root);

    return 0;
}

