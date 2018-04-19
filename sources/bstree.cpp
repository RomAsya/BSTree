#include "BSTree.hpp"
using namespace BSTree;
Tree:: Tree ()
    :root {nullptr}
{}
Node:: Node (int val): data {val}, right {nullptr}, left {nullptr} {
}

auto Tree:: empty ( ) const  -> bool {
    return (root==nullptr? true : false);
}

auto Tree:: insert (int value) -> bool {
if (root == nullptr) {
root = new Node {value};
return true;
}
Node * parent= root;
               Node * curr= root;
while ( curr != nullptr) {
if (curr->data==value) return false;
    if (curr->data < value) curr= curr->right;
    else curr= curr->left;
    if (curr!=nullptr) parent= curr;
}
if (parent->data< value) parent->right = new Node {value};
else parent->left = new Node {value};
    return true;
    }

    auto Tree:: print_elements (Node * curr, int  space) const ->void {
        if (curr!=nullptr) {
            if (curr->right!=nullptr) print_elements (curr->right, space+1);
            for (int i=0; i< space; i++) {
                std::cout<< "   ";
            }
            if ((curr->data)!=(root->data))
                std::cout<< "--";
            std::cout<< curr->data << std::endl;
            if (curr->left!=nullptr)  print_elements (curr->left, space+1);
        }
        else std::cout<<"Tree is empty"<< std::endl;
    }

auto Tree:: print () const -> void {
    print_elements (root, 0);
}

auto Tree:: deleting (Node *& curr) -> void {
    if (curr==nullptr) return;
    if (curr->right!=nullptr)
        deleting (curr->right);
        if (curr-> left!= nullptr) deleting (curr->left);
            delete curr;
            curr = nullptr;
        }

        auto Tree:: straight_detour (Node * curr) const -> void {
            std::cout<< curr->data<< " ";
            if (curr->left!=nullptr) straight_detour (curr->left);
            if (curr->right!=nullptr) straight_detour (curr->right);
        }

auto Tree:: straight () const ->void {
    straight_detour (root);
}

auto Tree:: back_detour (Node * curr) const -> void {
    if (curr->left!=nullptr) back_detour (curr->left);
    if (curr->right!=nullptr) back_detour (curr->right);
    std::cout<< curr->data<<" ";
}

auto Tree:: back () const -> void {
    back_detour (root);
}

auto Tree:: transverse_detour (Node * curr) const -> void {
    if (curr->left!=nullptr) transverse_detour (curr->left);
    std::cout<< curr->data<<" ";
    if (curr->right!=nullptr) transverse_detour (curr->right);
}

auto Tree:: transverse () const -> void {
    transverse_detour (root);
}

Tree:: ~Tree() {
    deleting (root);
}

auto Tree:: add_node (int value) -> void {
    if (!(this->insert (value)))
{
std::cerr << "This Node is already exist!!!" << std::endl;
}
}

auto Tree:: delete_node (int value) -> bool {
    if ((root->right==nullptr)&& (root->left==nullptr) && (root->data==value)) {
        delete root;
        root= nullptr;
        return true;
    }
    Node * parent= root;
    Node * curr= root;
    Node * parent_del =root;
    int value_new;
    while (curr!=nullptr) {
        if (curr->data==value) break;
        parent_del= curr;
        if (curr->data> value) curr= curr->left;
        else {
            if (curr->data< value) curr= curr->right;
        }
    } // нашли удаляемый узел и его родителя
    if (curr==nullptr)
        return false; //узел не существует в дереве
    if (curr->left!=nullptr) {
        parent = curr;
        curr= curr->left;
        while (1) {
            if (curr->right != nullptr) {
                parent= curr;
                curr = curr->right;
            }
            if (curr->right==nullptr)  break;
        }
        value_new= curr->data;
        if ((parent->left!=nullptr) && (parent->left->data==value_new)) {
            delete parent->left;
            parent->left=nullptr;
        }
        else {
            delete parent->right;
            parent->right= nullptr;
        }
    }
    else {
        if (curr->right!=nullptr) {
            parent = curr;
            curr= curr->right;
            while (1) {
                if (curr->left != nullptr) {
                    parent= curr;
                    curr = curr->left;
                }
                if (curr->left==nullptr)  break;
            }
            value_new= curr->data;
            std:: cout<< value_new<< std::endl;
            if ((parent->right!=nullptr) && (parent->right->data==value_new)) {
                delete parent->right;
                parent->right=nullptr;
            }
            else {
                delete parent->left;
                parent->left= nullptr;
            }
        }
        else {
            if (parent_del->data> value) {
                delete parent_del->left;
                parent_del->left=nullptr;
                return true;
            }
            delete parent_del->right;
            parent_del->right=nullptr;
            return true;
        }
    }
    std::cout<< parent_del->data<< std:: endl;
    if (parent_del->data> value)
        parent_del->left->data = value_new;
    if (parent_del->data < value)
        parent_del->right->data = value_new;
    if (parent_del->data==value)
        root->data= value_new;
    return true;
}

auto Tree:: save_tree_to_the_file_recursion (Node * curr, int  space, std::ostream &File) ->void {
    if (curr!=nullptr) {
        if (curr->right!=nullptr)  save_tree_to_the_file_recursion (curr->right, space+1, File);
        for (int i=0; i< space; i++) {
            File<< "   ";
        }
        if ((curr->data)!=(root->data))
            File<< "--";
        File<< curr->data << std::endl;
        if (curr->left!=nullptr)  save_tree_to_the_file_recursion (curr->left, space+1, File);
    }
}

auto Tree:: save_tree_to_the_file_straight_detour (Node * curr, std::ostream &File) -> void {
    File<< curr->data<< " ";
    if (curr->left!=nullptr) save_tree_to_the_file_straight_detour (curr->left,File);
    if (curr->right!=nullptr) save_tree_to_the_file_straight_detour (curr->right,File);
}

auto Tree:: save_tree_to_the_file (std::string file_name) -> bool {
    std::ofstream File(file_name);
    std::string decision ="yes";
    if (!File.is_open()) {
        std::cout << "Do you want to rewrite file? (yes/ no)" << std::endl;
        std::cin >> decision;
    }
    File.close();
    File.open (file_name);
    if ((decision == "y") || (decision == "yes") || (decision == "Y") ||
            (decision == "Yes") || (decision == "YES"))
    {
        save_tree_to_the_file_straight_detour (root,File);
        File<< std::endl;
        save_tree_to_the_file_recursion (root, 0, File);
    }
    File.close();
    return true;
}

auto Tree:: download_tree_from_the_file (std::string file_name)->bool {
    std::ifstream File(file_name);
    if (!File.is_open()) return false;
    std::string tree_string;
    getline (File,tree_string);
    int elements_count=0;
    for (int i=0; i< tree_string.length(); i++) {
        if (tree_string[i]==' ') elements_count++;
    }
    File.close();
    File.open(file_name);
    for (int i=0; i<elements_count; i++) {
        File >> tree_string;
        this->insert (atoi( tree_string.c_str()));
    }
    return true;
}
