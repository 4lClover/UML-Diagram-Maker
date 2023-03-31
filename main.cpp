/*
Program:UML Diagram Maker
Author:Phillip McCullough
Date:2/28/2023
C/Cpp:11+ ANSI Standard
Last Updated:3/29/2023

UML Diagram Maker produces UML diagrams.

    +---------------------------------------------------+
    |                 UML Diagram Maker                 |
    +---------------------------------------------------+
    |  +greeting():void                                 |
    |  +menu():void                                     |
    |  +nameClass():string                              |
    |  +makePrivateAttr(diagram:UMLMaker&):void         |
    |  +makePublicAttr(diagram:UMLMaker&):void          |
    |  +makePrivateConstructor(diagram:UMLMaker&):void  |
    |  +makePublicConstructor(diagram:UMLMaker&):void   |
    |  +makePrivateDestructor(diagram:UMLMaker&):void   |
    |  +makePublicDestructor(diagram:UMLMaker&):void    |
    |  +makePrivateMethod(diagram:UMLMaker&):void       |
    |  +makePublicMethod(diagram:UMLMaker&):void        |
    |  +diagramMaker():void                             |
    +---------------------------------------------------+
-------10--------20--------30--------40--------50--------60--------70--------80
*/
#include "UMLMaker.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void greeting();
void menu();
string nameClass();
void makePrivateAttr(UMLMaker &diagram);
void makePublicAttr(UMLMaker &diagram);
void makePrivateConstructor(UMLMaker &diagram);
void makePublicConstructor(UMLMaker &diagram);
void makePrivateDestructor(UMLMaker &diagram);
void makePublicDestructor(UMLMaker &diagram);
void makePrivateMethod(UMLMaker &diagram);
void makePublicMethod(UMLMaker &diagram);
void diagramMaker();

int main()
{

    greeting();
    menu();

    return 0;
}

// ----------------------------------------------------------------------------

void greeting()
{
    cout << "\n"
            "      Welcome to UML Diagram Maker\n"
            "  ------------------------------------\n"
            "  You can create UML (Unified Modeling Language) diagrams\n"
            "  by answering a series of yes or no questions. You will\n"
            "  be prompted for specific information needed to generate\n"
            "  a UML diagram with your specifications.\n";
}

// ----------------------------------------------------------------------------

void menu()
{
    string line;
    char option;
    do
    {
        cout << "\n"
                "  Options:\n"
                "  1)Make a UML Class Diagram.\n"
                "  2)Exit\n"
                "  Enter an option number: ";
        getline(cin, line);
        option = line[0];

        switch (option)
        {
        case '1':
            diagramMaker();
            break;
        case '2':
            line = "exit";
            break;
        default:
            cout << "\n"
                    "  Sorry, I didn't get that. Choose a valid option.\n";
        }
    } while (line != "exit");
}

// ----------------------------------------------------------------------------
/*
Creates a title for UML diagram generation. 
*/ 

string nameClass()
{
    string yes_no, class_name;
    do
    {
        cout << "\n"
                "  Enter the ClassName: ";
        getline(cin, class_name);

        cout << "\n"
                "  You entered: "
             << class_name << "\n"
                              "  Is this correct? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y");

    return class_name;
}

// ----------------------------------------------------------------------------
/*
Gathers information needed to create private attribute fields.
*/

void makePrivateAttr(UMLMaker &diagram)
{
    string yes_no, line, atribute;

    do
    {
        atribute = "-"; // Atribute == Private

        do
        {
            cout << "\n"
                    "  Enter atribute name: ";
            getline(cin, line);

            cout << "\n"
                    "  You entered: "
                 << line << "\n"
                            "  Is this correct? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y");

        atribute += line; // Atribute has name.

        do
        {
            cout << "\n"
                    "  Enter atribute type: ";
            getline(cin, line);

            cout << "\n"
                    "  You entered: "
                 << line << "\n"
                            "  Is this correct? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y");

        atribute += ":" + line; // Atribute has type.

        diagram.setClassVar(atribute);

        do
        {
            cout << "\n"
                    "  Create another private class artibute? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

    } while (yes_no == "y");
}

// ----------------------------------------------------------------------------
/*
Gathers information needed to create public attribute fields.
*/

void makePublicAttr(UMLMaker &diagram)
{
    string yes_no, line, atribute;

    do
    {
        atribute = "+"; // Atribute == Public

        do
        {
            cout << "\n"
                    "  Enter atribute name: ";
            getline(cin, line);

            cout << "\n"
                    "  You entered: "
                 << line << "\n"
                            "  Is this correct? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y");

        atribute += line; // Atribute has name.

        do
        {
            cout << "\n"
                    "  Enter atribute type: ";
            getline(cin, line);

            cout << "\n"
                    "  You entered: "
                 << line << "\n"
                            "  Is this correct? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y");

        atribute += ":" + line; // Atribute has type.

        diagram.setClassVar(atribute);

        do
        {
            cout << "\n"
                    "  Create another public class artibute? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

    } while (yes_no == "y");
}

// ----------------------------------------------------------------------------
/*
Gathers information needed to create private constructors.
*/

void makePrivateConstructor(UMLMaker &diagram)
{
    string yes_no, line, con_de_structor;

    do
    {
        con_de_structor = "-";                     // Constructor == Private
        con_de_structor += diagram.getClassName(); // Constructor has name.
        con_de_structor += "(";

        do
        {
            cout << "\n"
                    "  Add parameter? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

        while (yes_no == "y")
        {
            do
            {
                cout << "\n"
                        "  Enter parameter name: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            con_de_structor += line; // Parameter has name.

            do
            {
                cout << "\n"
                        "  Enter parameter type: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            con_de_structor += ":" + line; // Parameter has type.

            do
            {
                cout << "\n"
                        "  Add another parameter? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

                if (yes_no == "y")
                    con_de_structor += ",";

            } while (yes_no != "y" && yes_no != "n");
        }

        con_de_structor += ")";

        diagram.setClassConstructor(con_de_structor);

        do
        {
            cout << "\n"
                    "  Create another private constructor? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

    } while (yes_no == "y");
}

// ----------------------------------------------------------------------------
/*
Gathers information needed to create public constructors.
*/

void makePublicConstructor(UMLMaker &diagram)
{
    string yes_no, line, con_de_structor;

    do
    {
        con_de_structor = "+";                     // Constructor == Public
        con_de_structor += diagram.getClassName(); // Constructor has name.
        con_de_structor += "(";

        do
        {
            cout << "\n"
                    "  Add parameter? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

        while (yes_no == "y")
        {
            do
            {
                cout << "\n"
                        "  Enter parameter name: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            con_de_structor += line; // Parameter has name.

            do
            {
                cout << "\n"
                        "  Enter parameter type: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            con_de_structor += ":" + line; // Parameter has type.

            do
            {
                cout << "\n"
                        "  Add another parameter? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

                if (yes_no == "y")
                    con_de_structor += ",";

            } while (yes_no != "y" && yes_no != "n");
        }

        con_de_structor += ")";

        diagram.setClassConstructor(con_de_structor);

        do
        {
            cout << "\n"
                    "  Create another public constructor? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

    } while (yes_no == "y");
}

// ----------------------------------------------------------------------------
/*
Gathers information needed to create private destructors.
*/

void makePrivateDestructor(UMLMaker &diagram)
{
    string yes_no, line, con_de_structor;

    do
    {
        con_de_structor = "-";                           // Destructor == Private
        con_de_structor += "~" + diagram.getClassName(); // Destructor has name.
        con_de_structor += "(";

        do
        {
            cout << "\n"
                    "  Add parameter? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

        while (yes_no == "y")
        {
            do
            {
                cout << "\n"
                        "  Enter parameter name: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            con_de_structor += line; // Parameter has name.

            do
            {
                cout << "\n"
                        "  Enter parameter type: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            con_de_structor += ":" + line; // Parameter has type.

            do
            {
                cout << "\n"
                        "  Add another parameter? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

                if (yes_no == "y")
                    con_de_structor += ",";

            } while (yes_no != "y" && yes_no != "n");
        }

        con_de_structor += ")";

        diagram.setClassDestructor(con_de_structor);

        do
        {
            cout << "\n"
                    "  Create another private destructor? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

    } while (yes_no == "y");
}

// ----------------------------------------------------------------------------
/*
Gathers information needed to create public destructors.
*/

void makePublicDestructor(UMLMaker &diagram)
{
    string yes_no, line, con_de_structor;

    do
    {
        con_de_structor = "+";                           // Destructor == Public
        con_de_structor += "~" + diagram.getClassName(); // Destructor has name.
        con_de_structor += "(";

        do
        {
            cout << "\n"
                    "  Add parameter? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

        while (yes_no == "y")
        {
            do
            {
                cout << "\n"
                        "  Enter parameter name: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            con_de_structor += line; // Parameter has name.

            do
            {
                cout << "\n"
                        "  Enter parameter type: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            con_de_structor += ":" + line; // Parameter has type.

            do
            {
                cout << "\n"
                        "  Add another parameter? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

                if (yes_no == "y")
                    con_de_structor += ",";

            } while (yes_no != "y" && yes_no != "n");
        }

        con_de_structor += ")";

        diagram.setClassDestructor(con_de_structor);

        do
        {
            cout << "\n"
                    "  Create another public destructor? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

    } while (yes_no == "y");
}

// ----------------------------------------------------------------------------
/*
Gathers information needed to create private methods.
*/

void makePrivateMethod(UMLMaker &diagram)
{
    string yes_no, line, method;

    do
    {
        method = "-"; // Method == Private

        do
        {
            cout << "\n"
                    "  Enter method name: ";
            getline(cin, line);

            cout << "\n"
                    "  You entered: "
                 << line << "\n"
                            "  Is this correct? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y");

        method += line; // Method has name.
        method += "(";

        do
        {
            cout << "\n"
                    "  Add parameter? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

        while (yes_no == "y")
        {
            do
            {
                cout << "\n"
                        "  Enter parameter name: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            method += line; // Parameter has name.

            do
            {
                cout << "\n"
                        "  Enter parameter type: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            method += ":" + line; // Parameter has type.

            do
            {
                cout << "\n"
                        "  Add another parameter? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

                if (yes_no == "y")
                    method += ",";

            } while (yes_no != "y" && yes_no != "n");
        }

        do
        {
            cout << "\n"
                    "  Enter method return type: ";
            getline(cin, line);

            cout << "\n"
                    "  You entered: "
                 << line << "\n"
                            "  Is this correct? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y");

        method += "):" + line; // Method has return type.

        diagram.setClassMethod(method);

        do
        {
            cout << "\n"
                    "  Create another private method? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

    } while (yes_no == "y");
}

// ----------------------------------------------------------------------------
/*
Gathers information needed to create public methods.
*/

void makePublicMethod(UMLMaker &diagram)
{
    string yes_no, line, method;

    do
    {
        method = "+"; // Method == Public

        do
        {
            cout << "\n"
                    "  Enter method name: ";
            getline(cin, line);

            cout << "\n"
                    "  You entered: "
                 << line << "\n"
                            "  Is this correct? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y");

        method += line; // Method has name.
        method += "(";

        do
        {
            cout << "\n"
                    "  Add parameter? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

        while (yes_no == "y")
        {
            do
            {
                cout << "\n"
                        "  Enter parameter name: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            method += line; // Parameter has name.

            do
            {
                cout << "\n"
                        "  Enter parameter type: ";
                getline(cin, line);

                cout << "\n"
                        "  You entered: "
                     << line << "\n"
                                "  Is this correct? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

            } while (yes_no != "y");

            method += ":" + line; // Parameter has type.

            do
            {
                cout << "\n"
                        "  Add another parameter? [yes/no]: ";
                getline(cin, yes_no);
                yes_no = tolower(yes_no[0]);

                if (yes_no == "y")
                    method += ",";

            } while (yes_no != "y" && yes_no != "n");
        }

        do
        {
            cout << "\n"
                    "  Enter method return type: ";
            getline(cin, line);

            cout << "\n"
                    "  You entered: "
                 << line << "\n"
                            "  Is this correct? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);
        } while (yes_no != "y");

        method += "):" + line; // Method has return type.

        diagram.setClassMethod(method);

        do
        {
            cout << "\n"
                    "  Create another public method? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");

    } while (yes_no == "y");
}

// ----------------------------------------------------------------------------

void diagramMaker()
{
/*
diagramMaker prompts the user for items to be included in the creation of
a UML diagram. Items to be included are passed to methods that create the
desired items. diagramMaker also handles the additional tasks required for
the generation of a UML diagram. diagramMaker lastly presents the user with
a UML diagram that can be copied from the terminal or written to a
UML_Diagram.txt file.
*/
    string yes_no, line;
    UMLMaker diagram = UMLMaker(nameClass()); // Initialized class with name.

// ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create private class atribute? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    if (yes_no == "y")
        makePrivateAttr(diagram);

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create public class atribute? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    if (yes_no == "y")
        makePublicAttr(diagram);

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create private constructor? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    if (yes_no == "y")
        makePrivateConstructor(diagram);

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create public constructor? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    if (yes_no == "y")
        makePublicConstructor(diagram);

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create private destructor? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    if (yes_no == "y")
        makePrivateDestructor(diagram);

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create public destructor? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    if (yes_no == "y")
        makePublicDestructor(diagram);

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create private method? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    if (yes_no == "y")
        makePrivateMethod(diagram);

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create public method? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    if (yes_no == "y")
        makePublicMethod(diagram);

    // ----------------------------------------------------------------------------

    diagram.setWidth();
    diagram.makeEdgeSepLine();
    diagram.makeDiagram();
    diagram.displayDiagram();

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Write this diagram to file? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

        if (yes_no == "y")
            diagram.diagramToFile();

    } while (yes_no != "y" && yes_no != "n");

    cout << "\n" // Statement for UI as control is passed back to the menu.
            "  Would you like to create another UML diagram?";
}

// ----------------------------------------------------------------------------
