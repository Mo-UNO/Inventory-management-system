template <class T>
class SpareStack
{
private:
public:
    SpareNode<T> *TOP;
    SpareStack()
    {
        TOP = NULL;
    }

    void Push(T part)
    {
        SpareNode<T> *newnode = new SpareNode<T>(part);
        newnode->data = part;

        if (isEmpty())
        {
            newnode->next = NULL;
            TOP = newnode;
        }
        else
        {
            newnode->next = TOP;
            TOP = newnode;
        }
    }

    void PrintStack()
    {
        SpareNode<T> *temp = TOP;
        while (temp != NULL)
        {
            temp->data.putdata();
            cout << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    void Peek() // to see TOP element
    {
        if (!isEmpty())
        {
            TOP->data.putdata();
        }
        else
        {
            cout << "Stack is empty. Cannot peek.";
        }
    }

    bool isEmpty()
    {
        return (TOP == NULL);
    }

    bool isFound(int id)
    {
        SpareNode<T> *temp = TOP;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->data.getPartNumber() == id)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }

    int Count()
    {
        int counter = 0;
        SpareNode<T> *temp = TOP;

        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
};
