#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Queue {
    int* arr;
    int front, back, capacity, size;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        size = 0;
        back = capacity - 1;
    }

    void enqueue(int item) {
        if (size == capacity) {
            cout << "Queue is full\n";
            return;
        }
        back = (back + 1) % capacity;
        arr[back] = item;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }
};

class Stack {
    int* arr;
    int top, capacity;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }

    void push(int item) {
        if (top == capacity - 1) {
            cout << "Stack is full\n";
            return;
        }
        arr[++top] = item;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        return arr[top--];
    }
};



struct TreeNode {
    int value;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int v) : value(v), right(nullptr), left(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = recursiveInsert(root, value);
    }

    bool search(int value) {
        return recursiveSearch(root, value);
    }

    void inOrderPrint() {
        inOrderPrint(root);
    }

    void PreOrderPrint() {
        PreOrderPrint(root);
    }

    void PostOrderPrint() {
        PostOrderPrint(root);
    }

void BFS(Node* root) {
    if (root == nullptr) {
        return;
    }

    Queue nodes(100);  // Asume un tamaño máximo de 100 para la cola
    nodes.enqueue(root);

    while (nodes.size != 0) {
        Node* current = nodes.dequeue();

        cout << current->value << ", ";

        if (current->left != nullptr) {
            nodes.enqueue(current->left);
        }

        if (current->right != nullptr) {
            nodes.enqueue(current->right);
        }
    }
}

    void DFS(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    Stack nodes(100);  // Asume un tamaño máximo de 100 para la pila
    nodes.push(root);

    while (nodes.top != -1) {
        Node* current = nodes.pop();

        cout << current->value << ", ";

        if (current->right != nullptr) {
            nodes.push(current->right);
        }

        if (current->left != nullptr) {
            nodes.push(current->left);
        }
    }
    }

private:
    TreeNode* recursiveInsert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = recursiveInsert(node->left, value);
        }
        else if (value > node->value) {
            node->right = recursiveInsert(node->right, value);
        }

        return node;
    }

    bool recursiveSearch(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->value) {
            return true;
        }
        else if (value < node->value) {
            return recursiveSearch(node->left, value);
        }
        else {
            return recursiveSearch(node->right, value);
        }

    }

    void inOrderPrint(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inOrderPrint(node->left);
        cout << node->value << ", ";
        inOrderPrint(node->right);
    }

    void PreOrderPrint(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->value << ", ";
        PreOrderPrint(node->left);
        PreOrderPrint(node->right);
    }

    void PostOrderPrint(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        PostOrderPrint(node->left);
        PostOrderPrint(node->right);
        cout << node->value << ", ";
    }

};

int main() {

    BinaryTree tree;

    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    tree.insert(14);
    tree.insert(13);

    cout << "PreOrder: ";
    tree.PreOrderPrint();
    cout << endl;
    cout << "inOrder: ";
    tree.inOrderPrint();
    cout << endl;
    cout << "PostOrder: ";
    tree.PostOrderPrint();



    return 0;
}
