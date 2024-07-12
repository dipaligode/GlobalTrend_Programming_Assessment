#include <iostream>
#include <sstream>
#include <string>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
    public:
        std::string serialize(TreeNode* root) 
        {
            if (!root) return "null";

            std::queue<TreeNode*> q;
            q.push(root);
            std::stringstream ss;

            while (!q.empty()) 
            {
                TreeNode* node = q.front();
                q.pop();
                if (node) 
                {
                    ss << node->val << " ";
                    q.push(node->left);
                    q.push(node->right);
                } else 
                    ss << "null ";
            }

            return ss.str();
        }

        TreeNode* deserialize(const std::string& data) 
        {
            if (data == "null") return nullptr;

            std::stringstream ss(data);
            std::string val;
            std::getline(ss, val, ' ');

            TreeNode* root = new TreeNode(std::stoi(val));
            std::queue<TreeNode*> q;
            q.push(root);

            while (!q.empty()) 
            {
                TreeNode* node = q.front();
                q.pop();

                if (std::getline(ss, val, ' ')) 
                {
                    if (val != "null") {
                        node->left = new TreeNode(std::stoi(val));
                        q.push(node->left);
                    }
                }

                if (std::getline(ss, val, ' ')) 
                {
                    if (val != "null") 
                    {
                        node->right = new TreeNode(std::stoi(val));
                        q.push(node->right);
                    }
                }
            }

            return root;
        }
};

void printTree(TreeNode* root) {
    if (!root) {
        std::cout << "null" << std::endl;
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            std::cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            std::cout << "null ";
        }
    }
    std::cout << std::endl;
}

int main() {
    Codec codec;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    std::string serializedData = codec.serialize(root);
    std::cout << "Serialized tree: " << serializedData << std::endl;

    TreeNode* deserializedRoot = codec.deserialize(serializedData);
    std::cout << "Deserialized tree: ";
    printTree(deserializedRoot);

    return 0;
}
