void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }

    // Visit left subtree
    inorder(root->left, result, index);

    // Visit root
    result[(*index)++] = root->val;

    // Visit right subtree
    inorder(root->right, result, index);
}

int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int n = countNodes(root);

    *returnSize = n;

    int* result = malloc(n * sizeof(int));

    int index = 0;

    inorder(root, result, &index);

    return result;
}