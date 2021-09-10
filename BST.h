#ifndef BST_H
#define BST_H
#include <iostream>
#include <cstdlib>


using namespace std;

/**
*@brief a node of a tree
*/
template <typename T>
struct node
{
    ///data stored in node
    T data;
    ///pointer to the left
    node<T>* left=NULL;
    ///pointer to the right
    node<T>* right=NULL;
};


/**
*@brief BST.h template to build BST
*@author Manveer
*/
template <typename T>
class BST
{

private:

    node<T>* rootPtr=NULL;///root pointer
    /**
    *@brief create new node
    *@param T -data of new node
    *@return node<T>*
    */
    node<T>* CreateNewnode(T data);
    /**
    *@brief private function insert a node into the tree
    *@param data (T)
    *@param ptr (node<T>*) - node pointer
    *@return void
    */

    void PrivateInsertNode(T data,node<T>* ptr);

    /**
    *@brief private function to search for a data in the tree
    *@param data (T)
    *@param ptr (node<T>*)
    *@return bool
    */

    bool PrivateSearch(const T& data,const node<T>* ptr);
    /**
    *@brief private function to delete nodes of the tree
    *@param ptr (node<T>*&)
    *@return void
    */
    void PrivateDeleteTree(node<T>* &ptr);
    /**
    *@brief private function to traverse tree in order
    *@param ptr (node<T>*&)
    *@param void (*vist)(T&)
    *@return void
    */
    void inOrder(node<T>* ptr,void(*visit)(T & data));
    /**
    *@brief private function to traverse tree pre order
    *@param ptr (node<T>*&)
    *@param void (*vist)(T&)
    *@return void
    */
    void preOrder(node<T>* ptr,void(*visit)(T & data));
    /**
    *@brief private function to traverse tree post order
    *@param ptr (node<T>*&)
    *@param void (*vist)(T&)
    *@return void
    */
    void postOrder(node<T>* ptr,void(*visit)(T & data));
    /**
    *@brief function to copy data from one tree to another tree
    *@param current (node<T>*&)
    *@param data (T&)
    *@return void
    */
    void copyTree(node<T>*&current,node<T>*ptr);
    /**
        *@brief private function to return the data of a node that match data user is searching
        *@param data (T&)
        *@param ptr (node<T>*)
        *@return T
        */

    node<T>* getData(node<T>*ptr,T &data);


public:

    /**
    *@brief default constructor
    */
    BST();//call when creating a binary search tree
    /**
    *@brief public function to insert node in tree
    *@param data (T)
    *@return void
    */
    void InsertNode(T data);
    /**
    *@brief public search function
    *@param data (const T&)
    *@return bool
    */
    bool SearchNode(const T& data);
    /**
    *@brief public function to delete data in the tree
    *@return void
    */
    void DeleteTree();
    /**
    *@brief public function for inorder traversal
    *@param void (*vist)(T&)
    *@return void
    */
    void InOrder(void(*visit)(T & data));
    /**
    *@brief public function for preorder traversal
    *@param void (*vist)(T&)
    *@return void
    */
    void PreOrder(void(*visit)(T & data));
    /**
    *@brief public function for postorder traversal
    *@param void (*vist)(T&)
    *@return void
    */
    void PostOrder(void(*visit)(T & data));
    /**
    *@brief copy constructor
    *@param obj (BST<T>&)
    *@return BST
    */

    BST(BST<T>&obj);
    /**
    *@brief assignment operator overloading
    *@param obj (BST<T>&)
    *@return BST<T>&
    */
    BST<T>& operator=(BST<T>&obj);
    /**
    *@brief destructor
    */

    ~BST();

    /**
    *@brief public function to return the data of a node that match data user is searching
    *@param data (T&)
    *@return T
    */

    T getData(T &data);



};

template <typename T>
void BST<T>::copyTree(node<T>*&current,node<T>*ptr)
{

    if(ptr==nullptr)
    {
        current= nullptr;
    }
    else
    {
        current= new node<T>;
        current->data= ptr->data;
        copyTree(current->left, ptr->left);
        copyTree(current->right, ptr->right);
    }
}

template <typename T>
BST<T>::BST()
{

}

template <typename T>
BST<T>::~BST()
{
    PrivateDeleteTree(rootPtr);
}



template <typename T>
BST<T>::BST(BST<T>&obj)
{
    if(obj.rootPtr==nullptr)
    {
        rootPtr=nullptr;
    }
    else
    {
        copyTree(this->rootPtr,obj.rootPtr);
    }

}

template <typename T>
BST<T>& BST<T>::operator=(BST<T>&obj)
{

    if(this !=&obj)
    {

        if(rootPtr!=nullptr)
            PrivateDeleteTree(rootPtr);

        if(obj.rootPtr==nullptr)
            rootPtr=nullptr;
        else
            copyTree(rootPtr,obj.rootPtr);
    }

    return *this;
}


template <typename T>
node<T>* BST<T>::CreateNewnode(T data)
{
    node<T>* newNode=new node<T>;//point to a new created node
    newNode->data=data;//set the data value inside node
    newNode->left=NULL;//make sure they point to null
    newNode->right=NULL;//make sure they point to null
    return newNode;//return a pointer pointing to newcreated node
}

template <typename T>
void BST<T>::InsertNode(T data)
{
    PrivateInsertNode(data,rootPtr);
}


template <typename T>
void BST<T>::PrivateInsertNode(T data,node<T>*ptr)
{

    if(rootPtr==NULL)
    {
        rootPtr=CreateNewnode(data);
    }
    else if(data < ptr->data)//check if the new data is greater or less than the current data
    {
        if(ptr->left!=NULL)
        {
            PrivateInsertNode(data,ptr->left);
        }
        else
        {
            ptr->left=CreateNewnode(data);
        }

    }
    else if(data>ptr->data)//check if the new data is greater or less than the current data
    {
        if(ptr->right!=NULL)
        {
            PrivateInsertNode(data,ptr->right);
        }
        else
        {
            ptr->right=CreateNewnode(data);
        }

    }
    else
    {

        // cout<<"The data"<<data<<"already exist in tree"<<endl;
    }


}

template <typename T>
bool BST<T>::SearchNode(const T& data) //change to bool
{
    return(PrivateSearch(data,rootPtr));
}

template <typename T>
bool BST<T>::PrivateSearch(const T& data,const node<T> *ptr)
{
    if(ptr==NULL)
        return false;
    else if(ptr->data==data)
        return true;
    else if(ptr->data<data)
        return PrivateSearch(data,ptr->right);
    else
        return PrivateSearch(data,ptr->left);

}


template <typename T>
void BST<T>::PrivateDeleteTree(node<T>* &ptr)
{


    if(ptr!=NULL)
    {



        PrivateDeleteTree(ptr->left);
        PrivateDeleteTree(ptr->right);
        delete ptr;
        ptr=NULL;
    }
}


template <typename T>
void BST<T>::DeleteTree()
{
    PrivateDeleteTree(rootPtr);
}


template <typename T>
void BST<T>::inOrder(node<T>* ptr,void(*visit)(T & data))
{
    if(ptr==NULL)
        return;
    inOrder(ptr->left,*visit);
    (*visit)(ptr->data);
    inOrder(ptr->right,*visit);

}


template <typename T>
void BST<T>::InOrder(void(*visit)(T & data))
{
    inOrder(rootPtr,*visit);
}


template <typename T>
void BST<T>::preOrder(node<T>* ptr,void(*visit)(T & data))
{

    if(ptr==NULL)
        return;

    (*visit)(ptr->data);
    preOrder(ptr->left,*visit);
    preOrder(ptr->right,*visit);
}

template <typename T>
void BST<T>::PreOrder(void(*visit)(T & data))
{

    preOrder(rootPtr,*visit);

}

template <typename T>
void BST<T>::postOrder(node<T>* ptr,void(*visit)(T & data))
{
    if(ptr==NULL)
        return;

    postOrder(ptr->left,*visit);
    postOrder(ptr->right,*visit);
    (*visit)(ptr->data);
}

template <typename T>
void BST<T>::PostOrder(void(*visit)(T & data))
{
    postOrder(rootPtr,*visit);
}

template<typename T>
node<T>* BST<T>::getData(node<T>*ptr,T &data)
{
    if(ptr != nullptr)
    {
        if(ptr->data== data)
        {
            return ptr;
        }
        if(data < ptr->data)
        {
            return getData(ptr->left,data);
        }
        else
            return getData(ptr->right, data);
    }
    else
        return nullptr;
}

template<typename T>
T BST<T>::getData(T &data)
{
    node<T>* tempnode = getData(rootPtr, data);
    if(tempnode != nullptr)
    {
        return tempnode->data;
    }

}



#endif // BST_H



