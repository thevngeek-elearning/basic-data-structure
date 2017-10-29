/* Cây nhị phân - Duyệt theo chiều rộng (Tham khảo mycodeschool)*/
#include<iostream>
#include<queue>
using namespace std;

/* 
Cấu tạo một node bất kỳ trong cây bao gồm ba phần
Phần dữ liệu data
Phần liên kết tới con bên trái
phần liên kết tới con bên phải
*/
struct Node {
	int data;
	Node *left;
	Node *right;
};

/* Hàm in ra các node trong cây theo mức */
void printLevelOrder(Node *root) {
	if(root == NULL) return;
	queue<Node*> bf_queue;
	bf_queue.push(root);  
	/* Vòng lặp kết thúc khi queue rỗng */
	while(!bf_queue.empty()) {
		Node* current = bf_queue.front();
		bf_queue.pop(); /* Lấy phần tử đầu tiên ra khỏi queue */
		cout<<current->data<<", ";
                  /* Enqueue con trái và con phải của current vào bf_queue.*/
		if(current->left != NULL) {
                      bf_queue.push(current->left);
                  }
		if(current->right != NULL) {
                      bf_queue.push(current->right);
                   }
	}
}

/* Hàm chènduwx liệu vào trong binary tree */
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left,data);
	else root->right = Insert(root->right,data);
	return root;
}

int main() {
	/* Tạo một cây như sau
	           50
			     /     \
			  30        80
			 /  \      /   \
			20   35   60    90
		/  \   /
	15   22 32
    */
	Node* root = NULL;
	root = Insert(root,50);
	root = Insert(root,30); 
	root = Insert(root,80); 
	root = Insert(root,20);
	root = Insert(root,35);
	root = Insert(root,60);
	root = Insert(root,90);
	root = Insert(root,15);
	root = Insert(root,22);
	root = Insert(root,32);
	/* In ra các node theo mức*/ 
	printLevelOrder(root);
}
