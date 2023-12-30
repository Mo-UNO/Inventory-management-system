class InteractionStack
{
private:
    stack<Interaction> interactions;

public:
    // Push a new interaction onto the stack
    void pushInteraction(string message)
    {
        interactions.push(Interaction(message));
    }

    // Display all interactions in the stack
    void displayInteractions()
    {
        cout << "Interaction History:" << endl
             << "====================" << endl;

        while (!interactions.empty())
        {
            interactions.top().display();
            interactions.pop();
        }
    }
};
