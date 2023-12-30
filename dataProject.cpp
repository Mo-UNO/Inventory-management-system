#include <iostream>
#include <string>
using namespace std;

class sparepart
{
private:
    // data members.
    string spareoartName;
    int partNumber;
    double cost;
    string existingParts;

public:
    // Constructor to initialize spare part.
    sparepart(string name, int id, double Cost, string exParts)
    {
        spareoartName = name;
        partNumber = id;
        cost = Cost;
        existingParts = exParts;
    }

    // setter
    void setsparepartName(string name)
    {
        spareoartName = name;
    }
    void setID(int id)
    {
        partNumber = id;
    }

    void setCost(double Cost)
    {
        cost = Cost;
    }

    void setExistParts(string exParts)
    {
        existingParts = exParts;
    }

    // getter
    string getsparepartName()
    {
        return spareoartName;
    }
    int getID()
    {
        return partNumber;
    }

    double getCost()
    {
        return cost;
    }

    string getExParts()
    {
        return existingParts;
    }

    // function to input spare part details.
    void getdata()
    {
        cout << "Enter part name: ";
        getline(cin, spareoartName);
        cout << "Enter part number: ";
        cin >> partNumber;
        cout << "Enter cost: ";
        cin >> cost;
        cout << "Enter existing parts: ";
        cin.ignore(); // To handle whitespace in input.
        getline(cin, existingParts);
    }

    // Function to display spare part data but its name is put dk why.
    void putdata()
    {
        cout << "Part Name: " << spareoartName << endl;
        cout << "Part Number: " << partNumber << endl;
        cout << "Cost: " << cost << endl;
        cout << "Existing Parts: " << existingParts << endl;
    }

    // Function to modify spare part information.
    void modifydata()
    {
        cout << "Modify part name: ";
        cin >> spareoartName;
        cout << "Modify part number: ";
        cin >> partNumber;
        cout << "Modify cost: ";
        cin >> cost;
        cout << "Modify existing parts: ";
        cin.ignore();
        getline(cin, existingParts);
    }
};

class supplier
{
private:
    string supplierName;
    int supplierCode;
    string address;
    string telephone;
    string email;

public:
    supplier(string suppName, int code, string Address, string Telephone, string Email)
    {
        supplierName = suppName;
        supplierCode = code;
        address = Address;
        telephone = Telephone;
        email = Email;
    }

    // Setter
    void setSupplierName(string name)
    {
        supplierName = name;
    }

    void setSupplierCode(int code)
    {
        supplierCode = code;
    }

    void setAddress(string addr)
    {
        address = addr;
    }

    void setTelephone(string tel)
    {
        telephone = tel;
    }

    void setEmail(string mail)
    {
        email = mail;
    }

    // Getter
    string getSupplierName()
    {
        return supplierName;
    }

    int getSupplierCode()
    {
        return supplierCode;
    }

    string getAddress()
    {
        return address;
    }

    string getTelephone()
    {
        return telephone;
    }

    string getEmail()
    {
        return email;
    }

    void getdata()
    {
        cout << "Enter supplier name: ";
        cin >> supplierName;
        cout << "Enter supplier code: ";
        cin >> supplierCode;
        cout << "Enter address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter telephone: ";
        cin >> telephone;
        cout << "Enter email: ";
        cin >> email;
    }

    void putdata()
    {
        cout << "Supplier Name: " << supplierName << endl;
        cout << "Supplier Code: " << supplierCode << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone: " << telephone << endl;
        cout << "Email: " << email << endl;
    }

    void modifydata()
    {
        cout << "Modify supplier name: ";
        cin >> supplierName;
        cout << "Modify supplier code: ";
        cin >> supplierCode;
        cout << "Modify address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Modify telephone: ";
        cin >> telephone;
        cout << "Modify email: ";
        cin >> email;
    }
};
// nodes for linked list.
template <class T>
class suppNode
{
public:
    supplier *suppPtr;
    suppNode<T> *suppNext;
};

template <class T>
class partNode
{
public:
    sparepart *suppPtr;
    partNode<T> *partNext;
};

// tree nodes.
template <class T>
class sparePartTreeNode
{
public:
    T *data;
    sparePartTreeNode<T> *left;
    sparePartTreeNode<T> *right;
    partNode<T> *sparePartList; // Linked list pointer for spare parts
    suppNode<T> *supplierList;  // Linked list pointer for suppliers

    // Constructor
    sparePartTreeNode(int k, T *d) : data(d), left(nullptr), right(nullptr), sparePartList(nullptr), supplierList(nullptr) {}

    // order function
    void Inorder(sparePartTreeNode<T> *r)
    {
        if (r == nullptr)
            return;
        Inorder(r->left);
        cout << r->data << "\t";
        Inorder(r->right);
    }
    // insert function
    sparePartTreeNode<T> *insertNode(sparePartTreeNode<T> *root, int key, T *data)
    {
        if (root == nullptr)
            return new sparePartTreeNode<T>(key, data);

        if (key < root->key)
            root->left = insertNode(root->left, key, data);
        else if (key > root->key)
            root->right = insertNode(root->right, key, data);

        return root;
    }
    // search function
    sparePartTreeNode<T> *searchNode(sparePartTreeNode<T> *root, int key)
    {
        if (root == nullptr || root->key == key)
            return root;

        if (key < root->key)
            return searchNode(root->left, key);
        else
            return searchNode(root->right, key);
    }
    // delete function
    sparePartTreeNode<T> *deleteNode(sparePartTreeNode<T> *root, int key)
    {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == nullptr)
            {
                sparePartTreeNode<T> *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                sparePartTreeNode<T> *temp = root->left;
                delete root;
                return temp;
            }

            sparePartTreeNode<T> *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }
     void modifydataSparPart(sparePartTreeNode<T> *r, int sparePartcode) {
       sparePartTreeNode<T> *temp = r;

        while (temp != NULL) {
            if (temp->data.getID() == sparePartcode) {
                cout << "Supplier found. Enter the name of the attribute to edit:" << endl;
                cout << "1. Supplier Name" << endl;
                cout << "2. Address" << endl;
                cout << "3. Telephone" << endl;
                cout << "4. Email" << endl;

                int choice;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1: {
                        string newName;
                        cout << "Enter new sparepart Name: ";
                        cin.ignore();
                        getline(cin, newName);
                        temp->data.setsparepartName(newName);
                        break;
                    }

                    case 2: {
                        string newExist;
                        cout << "Enter new existing part: ";
                        cin.ignore();
                        getline(cin, newExist);
                        temp->data.setExistParts(newExist);
                        break;
                    }

                    case 3: {
                        double newCost;
                        cout << "Enter new cost: ";
                        cin >> newCost;
                        temp->data.setCost(newCost);
                        break;
                    }

                    default:
                        cout << "Invalid choice. No changes made." << endl;
                        return;
                }

                cout << "Supplier information edited successfully." << endl;
                return;
            }

            if (temp->data.getID() > sparePartcode) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        cout << "Supplier not found in the tree." << endl;
    }

    void modifydata(int sparePartcode) {
        modifydata(sparePartList, sparePartcode);
    }
};


template <class T>
class supplierTreeNode
{
public:
    T *data;
    supplierTreeNode<T> *left;
    supplierTreeNode<T> *right;
    partNode<T> *sparePartList; // Linked list pointer for spare parts
    suppNode<T> *supplierList;  // Linked list pointer for suppliers

    // Constructor
    supplierTreeNode(int k, T *d) : data(d), left(nullptr), right(nullptr), sparePartList(nullptr), supplierList(nullptr) {}

    void Inorder(supplierTreeNode<T> *r)
    {
        if (r == nullptr)
            return;
        Inorder(r->left);
        cout << r->data << "\t";
        Inorder(r->right);
    }
    // insert function
    supplierTreeNode<T> *insertNode(supplierTreeNode<T> *root, int key, T *data)
    {
        if (root == nullptr)
            return new supplierTreeNode<T>(key, data);

        if (key < root->key)
            root->left = insertNode(root->left, key, data);
        else if (key > root->key)
            root->right = insertNode(root->right, key, data);

        return root;
    }
    // search function
    supplierTreeNode<T> *searchNode(supplierTreeNode<T> *root, int key)
    {
        if (root == nullptr || root->key == key)
            return root;

        if (key < root->key)
            return searchNode(root->left, key);
        else
            return searchNode(root->right, key);
    }
    // delete function
    supplierTreeNode<T> *deleteNode(supplierTreeNode<T> *root, int key)
    {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == nullptr)
            {
                supplierTreeNode<T> *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                supplierTreeNode<T> *temp = root->left;
                delete root;
                return temp;
            }

            supplierTreeNode<T> *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }
    // modify function
    void modifysupplierData(supplierTreeNode<T> *r, int supplierCode) {
        supplierTreeNode<T> *temp = r;

        while (temp != NULL) {
            if (temp->data.getSupplierCode() == supplierCode) {
                cout << "Supplier found. Enter the name of the attribute to edit:" << endl;
                cout << "1. Supplier Name" << endl;
                cout << "2. Address" << endl;
                cout << "3. Telephone" << endl;
                cout << "4. Email" << endl;

                int choice;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1: {
                        string newName;
                        cout << "Enter new Supplier Name: ";
                        cin.ignore();
                        getline(cin, newName);
                        temp->data.setSupplierName(newName);
                        break;
                    }

                    case 2: {
                        string newAddress;
                        cout << "Enter new Address: ";
                        cin.ignore();
                        getline(cin, newAddress);
                        temp->data.setAddress(newAddress);
                        break;
                    }

                    case 3: {
                        string newTelephone;
                        cout << "Enter new Telephone: ";
                        cin.ignore();
                        getline(cin, newTelephone);
                        temp->data.setTelephone(newTelephone);
                        break;
                    }

                    case 4: {
                        string newEmail;
                        cout << "Enter new Email: ";
                        cin.ignore();
                        getline(cin, newEmail);
                        temp->data.setEmail(newEmail);
                        break;
                    }

                    default:
                        cout << "Invalid choice. No changes made." << endl;
                        return;
                }

                cout << "Supplier information edited successfully." << endl;
                return;
            }

            if (temp->data.getSupplierCode() > supplierCode) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        cout << "Supplier not found in the tree." << endl;
    }

    void modifydata(int supplierCode) {
        modifydata(supplierList, supplierCode);
    }
};
// node for queue
template <class T>
class Node {
public:
    T data;
    Node<T> *next;
    Node(T &value) : data(value), next(NULL) 
    {
        data = value;
        next = NULL;
    }
};
//QUEUE
template <class T>
class SparePartQueue {
public:
    Node<T> *Front;
    Node<T> *Rear;

    SparePartQueue()
    {
        Front == NULL;
        Rear == NULL;
    }
//is the queue is empty 
    bool isEmpty()
    {
        return Front == NULL;
    }
//is found
    bool isFound(T &element)
    {
        Node<T> *temp = Front;
        while(temp!=NULL)
        {
            if(temp->data == element)
                return true;
            temp =temp->next;
        }
        return false;
    }
// Queue countner
    int CountQueue()
    {
        int counter=0;
        Node<T> *temp= Front;
        while(temp!=NULL)
        {
            counter++;
            temp=temp->next;
        }
        return counter;
    }
// enqueue
    void enqueue(T &item)
    {
        Node<T> *newnode= new Node<T>(item);
        if(isEmpty())
        {
            Front = Rear =newnode;
        }
        else
        {
            Rear->next- newnode;
            Rear=newnode;
        }
    }
// dequeue
    T dequeue()
    {
        T delete_value;
        if(isEmpty())
        {
            cout<<"Queue is Empty\n"<<endl;
            delete_value=T();
        }
        else if(Front == Rear)
        {
            delete_value= Front->data;
            delete Front;
            Front = Rear = NULL;
        }
        else
        {
            Node<T> *delptr = Front;
            Front = Front->next;
            delete_value = delptr->data;
            delete delptr;
        }
        return delete_value;
    }
// display queue
    void Display_Queue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty\n"<<endl;
        }
        else 
        {
            while(!isEmpty())
            {
                cout<<dequeue()<<endl;
            }
        
        }
    }
    T getQueueFront()
    {
        return Front->data;
    }
    T getQueueRear()
    {
        return Rear->data;
    }
// clear the queue
    void clearQueue()
    {
        while(!isEmpty())
        {
            dequeue();
        }
    }
};




int main()
{
    // Creating a sparepart object
    sparepart part1("Engine", 12345, 2500.0, "Piston, Gasket, Spark Plug");

    cout << "Spare Part Data:" << endl;
    part1.putdata();

    // Modifying sparepart data
    cout << "\nModify Spare Part Data:" << endl;
    part1.modifydata();

    // Displaying modified sparepart data
    cout << "\nModified Spare Part Data:" << endl;
    part1.putdata();

    // Creating a supplier object
    supplier supplier1("ABC Supplier", 1234, "123 Main Street", "01554223311", "abc@supplier.com");

    // Displaying supplier data
    cout << "\nSupplier Data:" << endl;
    supplier1.putdata();

    // Modifying supplier data
    cout << "\nModify Supplier Data:" << endl;
    supplier1.modifydata();

    // Displaying modified supplier data
    cout << "\nModified Supplier Data:" << endl;
    supplier1.putdata();

    return 0;
}