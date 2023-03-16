/*
Program:UML Diagram Maker
Author:Phillip McCullough
Date:2/28/2023
C/Cpp:11+ ANSI Standard
Last Updated:3/15/2023

UML Diagram Maker produces UML diagrams.

    +-----------------------+
    |   UML Diagram Maker   |
    +-----------------------+
    |  +main():int          |
    |  +greeting():void     |
    |  +menu():static void  |
    |  +classMaker():void   |
    +-----------------------+
-------10--------20--------30--------40--------50--------60--------70--------80
*/
#include "UMLMaker.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

void greeting();
static void menu();
void classMaker();

int main()
{

    greeting();
    menu();

    return -1;
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

static void menu()
{
    string line = "";
    char option = '_';

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
        classMaker();
        menu();
        break;
    case '2':
        exit(EXIT_SUCCESS);
    default:
        cout << "\n"
                "  Sorry, I didn't get that. Choose a valid option.\n";
        menu();
    }
}

// ----------------------------------------------------------------------------

void classMaker()
{
    string yes_no, line, atribute, con_de_structor, method;

    yes_no = "";
    line = "";

    do
    {
        cout << "\n"
                "  Enter the ClassName: ";
        getline(cin, line);

        cout << "\n"
                "  You entered: "
             << line << "\n"
                        "  Is this correct? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y");

    // ----------------------------------------------------------------------------

    UMLMaker diagram = UMLMaker(line); // diagram == Instance class UMLMaker.

    // Atributes, private then public.
    atribute = "";

    do
    {
        cout << "\n"
                "  Create private class atribute? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    while (yes_no == "y")
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
    }

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create public class atribute? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    while (yes_no == "y")
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
    }

    // ----------------------------------------------------------------------------

    // Constructors, private then public.
    con_de_structor = "";

    do
    {
        cout << "\n"
                "  Create private constructor? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    while (yes_no == "y")
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
    }

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create public constructor? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    while (yes_no == "y")
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
    }

    // ----------------------------------------------------------------------------

    // Destructors, private then public.
    con_de_structor = "";

    do
    {
        cout << "\n"
                "  Create private destructor? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    while (yes_no == "y")
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
    }

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create public destructor? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    while (yes_no == "y")
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
    }

    // ----------------------------------------------------------------------------

    // Methods, private then public.
    method = "";

    do
    {
        cout << "\n"
                "  Create private method? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    while (yes_no == "y")
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

        method += "):" + line; // Method return type.

        diagram.setClassMethod(method);

        do
        {
            cout << "\n"
                    "  Create another private method? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");
    }

    // ----------------------------------------------------------------------------

    do
    {
        cout << "\n"
                "  Create public method? [yes/no]: ";
        getline(cin, yes_no);
        yes_no = tolower(yes_no[0]);

    } while (yes_no != "y" && yes_no != "n");

    while (yes_no == "y")
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

        method += "):" + line; // Method return type.

        diagram.setClassMethod(method);

        do
        {
            cout << "\n"
                    "  Create another public method? [yes/no]: ";
            getline(cin, yes_no);
            yes_no = tolower(yes_no[0]);

        } while (yes_no != "y" && yes_no != "n");
    }

    // ----------------------------------------------------------------------------

    diagram.setWidth();
    diagram.makeEdgeSepLine();
    diagram.makeChart();
    diagram.displayChart();

    cout << "\n"
            "  Write this diagram to file? [yes/no]: ";
    getline(cin, yes_no);
    yes_no = tolower(yes_no[0]);

    if (yes_no == "y")
        diagram.chartToFile();

    cout << "\n"
            "  Create another UML Diagram.";
}

// ----------------------------------------------------------------------------
