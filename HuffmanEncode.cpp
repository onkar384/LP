#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

// Node structure
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;  
    }
};

// Comparator for min-heap
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq; 
    }
};

// Recursive function to generate Huffman codes
void generateCodes(Node* root, string code, unordered_map<char, string> &huffmanCode) {
    if (!root)
        return;

    // Found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Build Huffman tree
void huffmanEncoding(unordered_map<char, int> &freq) {
    // FIXED: vector should be lowercase, not Vector
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    // Combine two smallest nodes until only one node left
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        Node* newNode = new Node('\0', sum);  

        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    Node* root = pq.top();

    // Generate Huffman codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);  

    cout << "\nHuffman Codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << " : " << pair.second << "\n";
}

// MAIN FUNCTION
int main() {
    unordered_map<char, int> freq;  
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter each character followed by its frequency:\n";
    for (int i = 0; i < n; i++) {
        char ch;
        int f;
        cin >> ch >> f;  
        freq[ch] = f;
    }

    huffmanEncoding(freq);  

    return 0;
}
