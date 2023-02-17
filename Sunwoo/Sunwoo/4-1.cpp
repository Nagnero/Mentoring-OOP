#include <iostream>
#include <cstring>
using namespace std;

class Node
{
private:
    int value;
    Node* parent;
    Node* right;
    Node* left;
public:
    Node()
    {
        this->value = 0;
        this->parent = NULL;
        this->right = NULL;
        this->left = NULL;
    }
    void setValue(int value) { this->value = value; }
    int getValue() { return this->value; }

    void setParent(Node* parent) { this->parent = parent; }
    Node* getParent() { return this->parent; }

    void setLeftChild(Node* leftChild) { this->left = leftChild; }
    Node* getLeftChild() { return this->left; }

    void setRightChild(Node* rightChild) { this->right = rightChild; }
    Node* getRightChild() { return this->right; }
};


class Tree
{
private:
    Node* root;
    Node* parent;
    int size;
public:
    Tree()
    {
        this->root = NULL;
        this->parent = NULL;
        this->size = 0;
    }
    ~Tree()
    {

    }
    Node* getRoot() { return root; }
    void INSERT(Node* curNode, int integer);
    void DELETE(int integer);
    void FIND(Node* curNode, int integer);
    void PRINT_PREORDER(Node* curNode);
    void PRINT_INORDER(Node* curNode);
    void PRINT_POSTORDER(Node* curNode);
    void PRINT_LEAF(Node* curNode);
};

void Tree::INSERT(Node* curNode, int integer)
{
    if (root == NULL) // Root ��尡 ���� ��� �߰�
    {
        Node* newNode = new Node;
        newNode->setValue(integer);
        root = newNode;
        this->size++;
    }
    else // Root ��尡 �ְ�
    {
        if (curNode->getValue() > integer) // �Է°��� ���� ��忡 ����� ������ ���� ���
        {
            if (curNode->getLeftChild() == NULL) // ���� ����� ���ʿ� ����� ��尡 ���� ���
            { // ���ο� ��忡 �Է°��� �����ϰ� ���� ����� ���ʳ��� ����
                Node* newNode = new Node;
                newNode->setValue(integer);
                curNode->setLeftChild(newNode);
                this->size++;
            }
            else // ���ʿ� ����� ��尡 ���� ���
            {
                if (curNode->getLeftChild()->getValue() == integer) // �Է°��� ���� ��忡 ����� ���� ������
                    return; // �������� �ʰ� ����
                INSERT(curNode->getLeftChild(), integer);
            }
        }
        else if (curNode->getValue() < integer) // �Է°��� ���� ��忡 ����� ������ Ŭ ���
        {
            if (curNode->getRightChild() == NULL) // ���� ����� �����ʿ� ����� ��尡 ���� ���
            { // ���ο� ��忡 �Է°��� �����ϰ� ���� ����� �����ʳ��� ����
                Node* newNode = new Node;
                newNode->setValue(integer);
                curNode->setRightChild(newNode);
                this->size++;
            }
            else // �����ʿ� ����� ��尡 ���� ���
            {
                if (curNode->getRightChild()->getValue() == integer) // �Է°����� ������ ��忡 ����� ���� ������
                    return; // �������� �ʰ� ����
                INSERT(curNode->getRightChild(), integer);
            }
        }
    }

}

void Tree::DELETE(int integer)
{
    Node* curNode = root;
    Node* delNode = NULL;
    Node* tempNode = NULL;

    while (1) // �ݺ����� ������ integer�� ���� value�� ���� ��带 ã�Ƽ� curNode�� ����
    {
        if (curNode == nullptr) // 
        {
            cout << "�����Ϸ��� ���� �����ϴ�." << endl;
            return;
        }
        if (curNode->getValue() < integer) // ���� ����� value���� ū ���̸�
        { // ���� ��� parent ���� �� ������ ���� curNode �̵�
            parent = curNode;
            curNode = parent->getRightChild();
        }
        else if (curNode->getValue() > integer) // ���� ����� value���� ���� ���̸�
        { // ���� ��� parent ���� �� ���� ���� curNode �̵�
            parent = curNode;
            curNode = parent->getLeftChild();
        }
        else // ���� ����� value�� integer�� ������ �ݺ��� Ż��
            break;
    }
    // �� �ݺ����� ���� curNode�� �����Ϸ��� ���� ���� ��尡 ��


    if (curNode->getLeftChild() == NULL && curNode->getRightChild() == NULL) // �ڽĳ�尡 ���� ���
    {
        if (curNode == root) // �ڽĳ�尡 ����, �����Ϸ��� ��尡 ��Ʈ ����� ���
        {
            delete root;
            root = NULL;
            this->size--;
        }
        else // �ڽĳ�尡 ����, �����Ϸ��� ��尡 ��Ʈ ��尡 �ƴ� ���
        {
            if (parent->getLeftChild() == curNode)
            {
                parent->setLeftChild(NULL);
                delete curNode;
                curNode = NULL;
                this->size--;
            }
            else
            {
                parent->setRightChild(NULL);
                delete curNode;
                curNode = NULL;
                this->size--;
            }
        }
    }

    else if (curNode->getLeftChild() == NULL || curNode->getRightChild() == NULL) // �ڽĳ�尡 �Ѱ��� �ִ� ���
    {
        if (curNode == root) // ������ ��尡 ��Ʈ ����� ���
        {
            if (curNode->getLeftChild() != NULL) // ���� �ڽĳ�常 �����ϴ� ���
            { 
                tempNode = curNode->getLeftChild();
                delete root;
                root = tempNode;
                this->size--;
                return;
            }
            else if (curNode->getRightChild() != NULL) // ������ �ڽĳ�常 �����ϴ� ���
            {
                tempNode = curNode->getRightChild();
                delete root;
                root = tempNode;
                this->size--;
                return;
            }
        }
        else // ������ ��尡 ��Ʈ ��尡 �ƴ� ���
        {
            delNode = curNode;

            if (curNode == parent->getLeftChild()) // ������ ��尡 �θ��� ���� �ڽ��� ��
            {
                if (curNode->getLeftChild() != NULL) // ������ ����� ���� �ڽ��� ���� ��
                {
                    parent->setLeftChild(curNode->getLeftChild());
                    delete delNode;
                    delNode = NULL;
                    return;
                }
                else if (curNode->getRightChild() != NULL) // ������ ����� ������ �ڽ��� ���� ��
                {
                    parent->setLeftChild(curNode->getRightChild());
                    delete delNode;
                    delNode = NULL;
                    return;
                }
            }
            else if (curNode == parent->getRightChild()) // ������ ��尡 �θ��� ������ �ڽ��� ��
            {
                if (curNode->getLeftChild() != NULL) // ������ ����� ���� �ڽ��� ���� ��
                {
                    parent->setRightChild(curNode->getLeftChild());
                    delete delNode;
                    delNode = NULL;
                    return;
                }
                else if (curNode->getRightChild() != NULL) // ������ ����� ������ �ڽ��� ���� ��
                {
                    parent->setRightChild(curNode->getRightChild());
                    delete delNode;
                    delNode = NULL;
                    return;
                }
            }
        }
    }

    else if (curNode->getLeftChild() != NULL && curNode->getRightChild() != NULL) // �ڽĳ�尡 �ΰ��� ���
    {
        Node* rightSmall = curNode->getRightChild();
        Node* rightSmallParent = rightSmall;

        if (rightSmall->getLeftChild() == NULL) // rightSmall�� ���� ��尡 ���� ���
        {
            curNode->setValue(rightSmall->getValue());
            curNode->setRightChild(rightSmall->getRightChild());
            delete rightSmall;
            rightSmall = NULL;
            this->size--;
        }
        else
        {
            while (rightSmall->getLeftChild() != NULL)
            {
                rightSmallParent = rightSmall;
                rightSmall = rightSmall->getLeftChild();
            }
            curNode->setValue(rightSmall->getValue());
            rightSmallParent->setLeftChild(NULL);
            delete rightSmall;
            rightSmall = NULL;
        }
    }
}

void Tree::FIND(Node* curNode, int integer)
{
    if (curNode == nullptr)
        return;

    cout << curNode->getValue();
    if (curNode->getLeftChild() != NULL || curNode->getRightChild() != NULL) // curNode�� reaf ����
    {
        if (curNode->getValue() == integer)
            return;
        else if (curNode->getValue() > integer)
        {
            cout << "->";
            FIND(curNode->getLeftChild(), integer);
        }
        else if (curNode->getValue() < integer)
        {
            cout << "->";
            FIND(curNode->getRightChild(), integer);
        }
    }
}

void Tree::PRINT_PREORDER(Node* curNode)
{
    if (curNode == nullptr)
        return;
    cout << curNode->getValue() << " ";
    PRINT_PREORDER(curNode->getLeftChild());
    PRINT_PREORDER(curNode->getRightChild());
}

void Tree::PRINT_INORDER(Node* curNode)
{
    if (curNode == nullptr)
        return;
    PRINT_INORDER(curNode->getLeftChild());
    cout << curNode->getValue() << " ";
    PRINT_INORDER(curNode->getRightChild());
}

void Tree::PRINT_POSTORDER(Node* curNode)
{
    if (curNode == nullptr)
        return;
    PRINT_POSTORDER(curNode->getLeftChild());
    PRINT_POSTORDER(curNode->getRightChild());
    cout << curNode->getValue() << " ";
}

void Tree::PRINT_LEAF(Node* curNode)
{
    if (curNode == nullptr)
        return;
    PRINT_LEAF(curNode->getLeftChild());
    if (curNode->getLeftChild() == NULL && curNode->getRightChild() == NULL)
        cout << curNode->getValue() << " ";
    PRINT_LEAF(curNode->getRightChild());
}


int main()
{
    Tree* tree = new Tree;
    int command = NULL, input;

    while (command != 8)
    {
        cout << "Enter Any Command(1:insert, 2:Delete, 3:Find, 4:Preorder, 5:Inorder, 6:Postorder, 7:Leaf node, 8:Exit): ";
        cin >> command;
        if (command == 1)
        {
            cin >> input;
            tree->INSERT(tree->getRoot(), input);
        }
        else if (command == 2)
        {
            cin >> input;
            tree->DELETE(input);
        }
        else if (command == 3)
        {
            cin >> input;
            cout << "Path : ";
            tree->FIND(tree->getRoot(), input);
            cout << endl;
        }
        else if (command == 4)
        {
            tree->PRINT_PREORDER(tree->getRoot());
            cout << endl;
        }
        else if (command == 5)
        {
            tree->PRINT_INORDER(tree->getRoot());
            cout << endl;
        }
        else if (command == 6)
        {
            tree->PRINT_POSTORDER(tree->getRoot());
            cout << endl;
        }
        else if (command == 7)
        {
            tree->PRINT_LEAF(tree->getRoot());
            cout << endl;
        }
        else if (command == 8)
            break;
    }
    return 0;
}