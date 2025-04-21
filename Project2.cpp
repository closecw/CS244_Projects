/**
 * Huffman Encoding project
 * Will encode an input string using David Huffman's algorithm.
 * I referenced this website {@link https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/} a lot,
 * as well as this website {@link https://www.geeksforgeeks.org/map-vs-unordered_map-c/?ref=header_outind}.
 * No code was directly copied, but I did use them as references when I was stuck and to help understand the algorithm.
 * @author Carter Close
 * @version 1.0
 */
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

/**
 * Struct for the Nodes of the tree
 */
struct Node
{
    char input;
    int frequency;
    Node *left, *right;
    Node(char c, int f) : input(c), frequency(f), left(nullptr), right(nullptr) {}
};

/**
 * Compares nodes to create the min heap tree
 */
struct TreeCompare
{
    bool operator()(Node *left, Node *right)
    {
        // Will generate the actual min-heap tree
        return left->frequency > right->frequency;
    }
};

/**
 * Generates the codes for the tree
 * 0's on the left, 1's on the right
 * @param root the root of the tree
 * @param input the resultant string for each encryption
 * @param huffmanCodes map of each key-value pair; keeps track of what chars have what value
 */
void codeTree(Node *root, string input, unordered_map<char, string> &huffmanCodes)
{
    if (root == nullptr)
        return;

    // If it's an actual node on the tree
    if (!root->left && !root->right)
    {
        huffmanCodes[root->input] = input;
    }

    codeTree(root->left, input + "0", huffmanCodes);        // Generate 0's on the left
    codeTree(root->right, input + "1", huffmanCodes);       // Generate 1's on the right
}

string encodeInput(string input, unordered_map<char, string> &huffmanCodes)
{
    string encodedInput;
    for (char c : input)
        // Loops through each character in the input string, adds its huffman code to encodedInput
        encodedInput += huffmanCodes[c];

    return encodedInput;
}

int main()
{
    string input;
    cout << "Enter an input string to be encrypted: " << endl;
    getline(cin, input);

    // 1st step: Find a frequency map for each character
    unordered_map<char, int> frequency_map;
    for (char c : input)
        frequency_map[c]++;

    // 2nd step: priority queue for the min heap and building the binary tree
    priority_queue<Node*, vector<Node*>, TreeCompare> pq;
    for (auto pair : frequency_map)
        pq.push(new Node(pair.first, pair.second));

    while (pq.size() > 1)
    {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        int total_frequency = left->frequency + right->frequency;
        Node* newNode = new Node('\0', total_frequency);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    Node* root = pq.top(); // Last node left in pq

    // 3rd step: Create the codes and map
    unordered_map<char, string> huffmanCodes;
    codeTree(root, string(""), huffmanCodes);

    // 4th step: Encrypt the string and display
    string encodedInput = encodeInput(input, huffmanCodes);
    cout << "Original string: " << input << endl;
    cout << "Huffman codes: " << endl;
    for (auto pair : huffmanCodes)
        cout << pair.first << ":" << pair.second << endl;
    cout << "Encoded string: " << encodedInput << endl;

    return 0;
}