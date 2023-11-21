#include <iostream>
#include <string>
using namespace std;

class Machine
{
public:
    // "dynamic state" made up of state and operand
    string state;
    string operand;
    string* head;

    Machine(string *tape) {
        state = "bgn";
        operand = "000";
        head = tape;
    }

    void updateState(string newState, string direction, string newOperand = "") {
        state = newState;

        if (direction == "<")
        {
            head--;
        }
        else if (direction == ">")
        {
            head++;
        }
        else if (direction == ">>")
        {
            // this might need some more thought
        }

        if (newOperand != "")
        {
            operand = newOperand;
        }
    }
};


string test()
{
    return "hello world!!";
}

// function pointer testing
string (*stateTransition())()
{
    return test;
}


void outputTape(string* cell, string* head)
{
    string line1 = "___";
    string line2 = "  |";
    string line3 = "   ";
    while (*cell != "" and *cell != "\0")
    {
        // line 1
        line1 += "____";

        // line 2
        // formats contents of each cell to be three characters
        string c;
        switch (cell->length())
        {
            case 1:
                c = " " + *cell + " ";
                break;
            case 2:
                c = " " + *cell;
                break;
            case 3:
                c = *cell;
                break;
        }
        line2 += c + "|";

        //line 3 - position of head
        if (cell == head)
        {
            line3 += " ^  ";
        }
        else
        {
            line3 += "    ";
        }

        cell++;
    }
    line1 += "___";
    cout << line1 << endl << line2 << endl << line3 << endl;

}

int main()
{
    string(*function)() = stateTransition();
    cout << function() << endl;


    // defining tape
    string tape[100] = {"   ","   ","   "};
    tape[99] = "\0";

    // tape input
    string input;
    getline(cin, input); // getline() used to take a whole line input as a string
    input += " ";
    int t = 3;
    int i = 0;
    while(t < 99 and i < input.length())
    {
        string cell;
        for (int n = 0; n < 3; n++)
        {
            if (input[i] != ' ') // needed to use '' idrk why tho
            {
                cell += input[i];
            }
            else
            {
                break;
            }
            i++;
        }

        tape[t] = cell;
        i++;
        t++;
    }

    Machine machine(&tape[3]);
    outputTape(tape, machine.head);
}