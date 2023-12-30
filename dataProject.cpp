#include <iostream>
#include <limits>
#include <list>
#include <stack>
#include <queue>
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
    sparepart(string newname, int newPartnumber, double newCost, string newExparts)
    {
        spareoartName = newname;
        partNumber = newPartnumber;
        cost = newCost;
        existingParts = newExparts;
    }

    // setter
    void setsparepartName(string newname)
    {
        spareoartName = newname;
    }
    void setpartNumber(int newPartnumber)
    {
        partNumber = newPartnumber;
    }

    void setCost(double newCost)
    {
        cost = newCost;
    }

    void setExistParts(string newExparts)
    {
        existingParts = newExparts;
    }

    // getter
    string getsparepartName()
    {
        return spareoartName;
    }
    int getpartNumber()
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
    list<int> sparePartsProvidedBySupplier;

public:
    supplier(string NewsuppName, int newcode, string newAddress, string newTelephone, string newEmail)
    {
        supplierName = NewsuppName;
        supplierCode = newcode;
        address = newAddress;
        telephone = newTelephone;
        email = newEmail;
    }

    // Setter
    void setSupplierName(string NewsuppName)
    {
        supplierName = NewsuppName;
    }

    void setSupplierCode(int newcode)
    {
        supplierCode = newcode;
    }

    void setAddress(string newAddress)
    {
        address = newAddress;
    }

    void setTelephone(string newTelephone)
    {
        telephone = newTelephone;
    }

    void setEmail(string newEmail)
    {
        email = newEmail;
    }

    // Getter
    string getSupplierName()
    {
        return supplierName;
    }

    int getsupplierCode()
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

    list<int> getSparePartsProvidedBySupplier() { return sparePartsProvidedBySupplier; }
    void setSparePartsProvidedBySupplier(list<int> parts) { sparePartsProvidedBySupplier = parts; }

    void addSparePart(int partNumber)
    {
        sparePartsProvidedBySupplier.push_back(partNumber);
    }

    void getdata()
    {
        while (true)
        {
            cout << "Enter Supplier Name: ";
            cin >> supplierName;

            if (cin.fail())
            {
                cin.clear();                                         // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
            else
            {
                break;
            }
        }

        while (true)
        {
            cout << "Enter Supplier Code: ";
            cin >> supplierCode;

            if (cin.fail())
            {
                cin.clear();                                         // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
            else
            {
                break;
            }
        }

        while (true)
        {
            cout << "Enter Address: ";
            cin >> address;

            if (cin.fail())
            {
                cin.clear();                                         // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
            else
            {
                break;
            }
        }

        while (true)
        {
            cout << "Enter The Telephone Number: ";
            cin >> telephone;

            if (cin.fail())
            {
                cin.clear();                                         // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
            else
            {
                break;
            }
        }

        while (true)
        {
            cout << "Enter The Email: ";
            cin >> email;

            if (cin.fail())
            {
                cin.clear();                                         // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
            else
            {
                break;
            }
        }
        while (true)
        {
            cout << "Spare Parts Provided By Supplier (enter -1 to stop): ";

            int partsupplier;
            cin >> partsupplier;

            if (partsupplier == -1)
            {
                break;
            }

            // Add the partNumber to the sparePartsProvidedBySupplier list
            sparePartsProvidedBySupplier.push_back(partsupplier);

            if (cin.fail())
            {
                cin.clear();                                         // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
        }

        cout << endl;
    }

    void putdata()
    {
        cout << "Supplier Name: " << supplierName << endl;
        cout << "Supplier Code: " << supplierCode << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone Number: " << telephone << endl;
        cout << "Email: " << email << endl;
        cout << "Spare Parts Provided By Supplier: ";
        for (auto &partsupplier : sparePartsProvidedBySupplier)
        {
            cout << partsupplier << " ";
        }
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl;
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


template <class T>
class Node{
public:

    T data;
    Node<T>* next;
    Node<T>* right;
    Node<T>* left;

    Node( T& value) : data(value), next(NULL), right(NULL), left(NULL) {}


    //Setter and Getter
    T getdata() { return data; }
    void setdata( T Value) { data = Value; }

    Node<T>* getnext() { return next; }
    void setnext( Node<T>* nextnode) { next = nextnode; }

    Node<T>* getLeft() const { return left; }
    void setLeft(Node<T>* leftNode) { left = leftNode; }

    Node<T>* getRight() const { return right; }
    void setRight(Node<T>* rightNode) { right = rightNode; }

};

// tree nodes.
template <class T>
class SparePartBinaryTree {
private:
    Node<T>* root;

    // Recursive function to insert a spare part into the binary tree
    Node<T>* insert(Node<T>* node, T& value) {
        if (node == NULL) {
            return new Node<T>(value);
        }

        if (value.getpartNumber() < node->data.getpartNumber()) {
            node->left = insert(node->left, value);
        }
        else if (value.getpartNumber() > node->data.getpartNumber()) {
            node->right = insert(node->right, value);
        }
        else{
            cout<< "Duplicate is not allowed. Part Number: "<< value.getpartNumber() <<" already exists."<<endl;
        }

        return node;
    }

    // Recursive function to search for a spare part by part number
    Node<T>* search(Node<T>* node, int partNumber) {
        if (node == NULL || node->data.getpartNumber() == partNumber) {
            return node;
        }

        if (node->data.getpartNumber() < partNumber) {
            return search(node->left, partNumber);
        }

        return search(node->right, partNumber);
    }

    // Recursive function to find the node with the minimum part number
    Node<T>* findMin(Node<T>* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    // Recursive function to delete a spare part by part number
    Node<T>* deleteNode(Node<T>* root, int partNumber) {
        if (root == NULL) {
            return root;
        }

        if (partNumber < root->data.getpartNumber()) {
            root->left = deleteNode(root->left, partNumber);
        }

        else if (partNumber > root->data.getpartNumber()) {
            root->right = deleteNode(root->right, partNumber);
        } else {
            if (root->left == NULL) {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }

            Node<T>* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data.getpartNumber());
        }
        return root;
    }

    // Recursive function to perform in-order traversal
    void inOrderTraversal(Node<T>* node) {
        if (node != NULL) {
            inOrderTraversal(node->left);
            node->data.putdata();
            inOrderTraversal(node->right);
        }
    }

public:
    SparePartBinaryTree() : root(NULL) {}


    // Public function to insert a spare part into the binary tree
    void insert( T& value) {
        root = insert(root, value);
    }

    // Public function to search for a spare part by part number
    Node<T>* search(int partNumber) {
        return search(root, partNumber);
    }

    // Public function to delete a spare part by part number
    void deleteValue(int partNumber) {
        root = deleteNode(root, partNumber);
    }

    // Public function to display all spare parts using in-order traversal
    void display() {
        inOrderTraversal(root);
        if (root == NULL) {
            cout<<"there is nothing to display."<<endl;
        }
    }
};
template <class T>
class SparePartBinaryTree1 {
private:
    Node<T>* root;

    // Recursive function to insert a spare part into the binary tree
    Node<T>* insert(Node<T>* node, T& value) {
        if (node == NULL) {
            return new Node<T>(value);
        }

        if (value.getpartNumber() < node->data.getpartNumber()) {
            node->left = insert(node->left, value);
        }
        else if (value.getpartNumber() > node->data.getpartNumber()) {
            node->right = insert(node->right, value);
        }
        else{
            cout<< "Duplicate is not allowed. Part Number: "<< value.getpartNumber() <<" already exists."<<endl;
        }

        return node;
    }

    // Recursive function to search for a spare part by part number
    Node<T>* search(Node<T>* node, int partNumber) {
        if (node == NULL || node->data.getpartNumber() == partNumber) {
            return node;
        }

        if (node->data.getpartNumber() < partNumber) {
            return search(node->left, partNumber);
        }

        return search(node->right, partNumber);
    }

    // Recursive function to find the node with the minimum part number
    Node<T>* findMin(Node<T>* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    // Recursive function to delete a spare part by part number
    Node<T>* deleteNode(Node<T>* root, int partNumber) {
        if (root == NULL) {
            return root;
        }

        if (partNumber < root->data.getpartNumber()) {
            root->left = deleteNode(root->left, partNumber);
        }

        else if (partNumber > root->data.getpartNumber()) {
            root->right = deleteNode(root->right, partNumber);
        } else {
            if (root->left == NULL) {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }

            Node<T>* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data.getpartNumber());
        }
        return root;
    }

    // Recursive function to perform in-order traversal
    void inOrderTraversal(Node<T>* node) {
        if (node != NULL) {
            inOrderTraversal(node->left);
            node->data.putdata();
            inOrderTraversal(node->right);
        }
    }

public:
    SparePartBinaryTree1() : root(NULL) {}


    // Public function to insert a spare part into the binary tree
    void insert( T& value) {
        root = insert(root, value);
    }

    // Public function to search for a spare part by part number
    Node<T>* search(int partNumber) {
        return search(root, partNumber);
    }

    // Public function to delete a spare part by part number
    void deleteValue(int partNumber) {
        root = deleteNode(root, partNumber);
    }

    // Public function to display all spare parts using in-order traversal
    void display() {
        inOrderTraversal(root);
        if (root == NULL) {
            cout<<"there is nothing to display."<<endl;
        }
    }
};
template <class T>
class SupplierBinaryTree {
private:
    Node<T>* root;

    // Recursive function to insert a supplier into the binary tree
    Node<T>* insert(Node<T>* node, T& value) {
        if (node == NULL) {
            return new Node<T>(value);
        }

        if (value.getsupplierCode() < node->data.getsupplierCode()) {
            node->left = insert(node->left, value);
        }
        else if (value.getsupplierCode() > node->data.getsupplierCode()) {
            node->right = insert(node->right, value);
        }
        else{
            cout<< "Duplicate is not allowed. Supplier Code: "<< value.getsupplierCode() <<"already exists."<<endl;
        }

        return node;
    }

    // Recursive function to search for a supplier by supplier code
    Node<T>* search(Node<T>* node, int supplierCode) {
        if (node == NULL || node->data.getsupplierCode() == supplierCode) {
            return node;
        }

        if (supplierCode < node->data.getsupplierCode()) {
            return search(node->left, supplierCode);
        }

        return search(node->right, supplierCode);
    }

    // Recursive function to find the node with the minimum supplier code
    Node<T>* findMin(Node<T>* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    // Recursive function to delete a supplier by supplier code
    Node<T>* deleteNode(Node<T>* root, int supplierCode) {
        if (root == NULL) {
            return root;
        }

        if (supplierCode < root->data.getsupplierCode()) {
            root->left = deleteNode(root->left, supplierCode);
        } else if (supplierCode > root->data.getsupplierCode()) {
            root->right = deleteNode(root->right, supplierCode);
        } else {
            if (root->left == NULL) {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }

            Node<T>* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data.getsupplierCode());
        }
        return root;
    }

    // Recursive function to perform in-order traversal
    void inOrderTraversal(Node<T>* node) {
        if (node != NULL) {
            inOrderTraversal(node->left);
            node->data.putdata(); // Assuming Supplier has a display function
            inOrderTraversal(node->right);
        }
    }

public:
    SupplierBinaryTree() : root(NULL) {}

    // Public function to insert a supplier into the binary tree
    void insert(T& value) {
        root = insert(root, value);
    }

    // Public function to search for a supplier by supplier code
    Node<T>* search(int SupplierCode) {
        return search(root, SupplierCode);
    }

    // Public function to delete a supplier by supplier code
    void deleteValue(int supplierCode) {
        root = deleteNode(root, supplierCode);
    }

    // Public function to display all suppliers using in-order traversal
    void display() {
        inOrderTraversal(root);
        if(root == NULL){
            cout<<"there is nothing to display."<<endl;
        }
    }
};


// QUEUE
template <class T>
class SparePartQueue
{
public:
    Node<T> *Front;
    Node<T> *Rear;

    SparePartQueue()
    {
        Front == NULL;
        Rear == NULL;
    }
    // is the queue is empty
    bool isEmpty()
    {
        return Front == NULL;
    }
    // is found
    bool isFound(T &element)
    {
        Node<T> *temp = Front;
        while (temp != NULL)
        {
            if (temp->data == element)
                return true;
            temp = temp->next;
        }
        return false;
    }
    // Queue countner
    int CountQueue()
    {
        int counter = 0;
        Node<T> *temp = Front;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    // enqueue
    void enqueue(T &item)
    {
        Node<T> *newnode = new Node<T>(item);
        if (isEmpty())
        {
            Front = Rear = newnode;
        }
        else
        {
            Rear->next - newnode;
            Rear = newnode;
        }
    }
    // dequeue
    T dequeue()
    {
        T delete_value;
        if (isEmpty())
        {
            cout << "Queue is Empty\n"
                 << endl;
            delete_value = T();
        }
        else if (Front == Rear)
        {
            delete_value = Front->data;
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
        if (isEmpty())
        {
            cout << "Queue is Empty\n"
                 << endl;
        }
        else
        {
            while (!isEmpty())
            {
                cout << dequeue() << endl;
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
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    sparepart part1("Engine", 1001, 500.0, "Bolts, Gaskets");
    sparepart part2("Tires", 1002, 200.0, "Rims, Tubes");
    sparepart part3("Headlights", 1003, 150.0, "Bulbs, Wires");

    supplier supplier1("ABC Suppliers", 2001, "123 Main St", "123-456-7890", "abc@suppliers.com");
    supplier supplier2("XYZ Suppliers", 2002, "456 Oak St", "987-654-3210", "xyz@suppliers.com");

    // Creating binary trees for spare parts and suppliers
    SparePartBinaryTree<sparepart> partsTree;
    partsTree.insert(part1);
    partsTree.insert(part2);
    partsTree.insert(part3);

    SupplierBinaryTree<supplier> suppliersTree;
    suppliersTree.insert(supplier1);
    suppliersTree.insert(supplier2);

    // Displaying all spare parts and suppliers
    cout << "All Spare Parts:" << endl;
    partsTree.display();

    cout << "All Suppliers:" << endl;
    suppliersTree.display();

    // Searching for a spare part and a supplier by their respective IDs
    int searchPartNumber = 1002;
    Node<sparepart>* foundPart = partsTree.search(searchPartNumber);
    if (foundPart != NULL) {
        cout << "Found Part: ";
        foundPart->data.putdata();
    } else {
        cout << "Part with ID " << searchPartNumber << " not found." << endl;
    }

    int searchSupplierCode = 2001;
    Node<supplier>* foundSupplier = suppliersTree.search(searchSupplierCode);
    if (foundSupplier != NULL) {
        cout << "Found Supplier: ";
        foundSupplier->data.putdata();
    } else {
        cout << "Supplier with Code " << searchSupplierCode << " not found." << endl;
    }

    return 0;
}
