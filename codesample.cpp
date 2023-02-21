void Tree::deleteNode(Node *& gone)
{
        Node * temp;
        if(!gone->left && !gone->right) //checks if the node has no children
        {
                delete gone;
                gone = nullptr;
        }
        else if(!gone->left) //checks if the node only has a right child
        {
                temp = gone;
                gone = gone->right;
                delete temp;
                temp = nullptr;
        }
        else if(!gone->right) //checks if the node only has a left child
        {
                temp = gone;
                gone = gone->left;
                delete temp;
                temp = nullptr;
        }
        else //checks if it has 2 children
        {
                //find the inorder successor
                Node * prev = nullptr;
                Node * curr = gone->right;
                if(!curr->left)
                {
                        *(gone->data) = *(curr->data);
                        gone->right = curr->right;
                        delete curr;
                        curr = nullptr;
                }
                else
                {
                        while(curr->left)
                        {
                                prev = curr;
                                curr = curr->left;
                        }
                        *(gone->data) = *(curr->data);
                        prev->left = curr->right;
                        delete curr;
                        curr = nullptr;
                }
        }
}

