/*
Class:UMLMaker
Author:Phillip McCullough
Date:3/4/2023
C/Cpp:11+ ANSI Standard
Last Updated:3/19/2023

IMPORTANT, see the diagramToFile() definition!!

This class is used to produce UML (Unified Modeling Language) diagrams.
UMLMaker.cpp holds UMLMaker class method definitions.
-------10--------20--------30--------40--------50--------60--------70--------80
*/

#include "UMLMaker.h"

// ----------------------------------------------------------------------------

UMLMaker::UMLMaker()
{
    UMLMaker::class_name = "";
    UMLMaker::class_member_var = "";
    UMLMaker::class_method = "";
    UMLMaker::edge_sep_line = "";
    UMLMaker::chart_width = 0;
}

// ----------------------------------------------------------------------------

UMLMaker::UMLMaker(string class_name)
{
    UMLMaker::class_name = class_name;
    UMLMaker::class_member_var = "";
    UMLMaker::class_method = "";
    UMLMaker::edge_sep_line = "";
    UMLMaker::chart_width = 0;
}

// ----------------------------------------------------------------------------

UMLMaker::~UMLMaker() {}

// ----------------------------------------------------------------------------

void UMLMaker::setClassName(string class_name)
{
    UMLMaker::class_name = class_name;
}

// ----------------------------------------------------------------------------

string UMLMaker::getClassName() const
{
    return UMLMaker::class_name;
}

// ----------------------------------------------------------------------------

void UMLMaker::setClassVar(string class_variable)
{
    UMLMaker::class_variables.push_back(class_variable);
}

// ----------------------------------------------------------------------------

void UMLMaker::setClassConstructor(string constructor)
{
    UMLMaker::con_de_structors.push_back(constructor);
}

// ----------------------------------------------------------------------------

void UMLMaker::setClassDestructor(string destructor)
{
    UMLMaker::con_de_structors.push_back(destructor);
}

// ----------------------------------------------------------------------------

void UMLMaker::setClassMethod(string class_method)
{
    UMLMaker::class_methods.push_back(class_method);
}

// ----------------------------------------------------------------------------

void UMLMaker::setWidth()
{
    int longest = UMLMaker::class_name.length();

    if (!UMLMaker::con_de_structors.empty())
        for (string con_des : UMLMaker::con_de_structors)
            if (con_des.length() > longest)
                longest = con_des.length();

    if (!UMLMaker::class_variables.empty())
        for (string var : UMLMaker::class_variables)
            if (var.length() > longest)
                longest = var.length();

    if (!UMLMaker::class_methods.empty())
        for (string method : UMLMaker::class_methods)
            if (method.length() > longest)
                longest = method.length();

    UMLMaker::chart_width = (longest + (UMLMaker::MARGIN * 2));
}

// ----------------------------------------------------------------------------

void UMLMaker::makeEdgeSepLine()
{
    UMLMaker::edge_sep_line = "+";
    for (int i = 0; i < UMLMaker::chart_width; i++)
        UMLMaker::edge_sep_line += '-';
    UMLMaker::edge_sep_line += "+";
}

// ----------------------------------------------------------------------------

void UMLMaker::makeDiagram()
{
    string line;

    UMLMaker::chart_data.push_back(UMLMaker::edge_sep_line);

    if (UMLMaker::class_name != "")
    {
        int leading_space = (chart_width - class_name.length()) / 2;
        int closing_space = (chart_width - class_name.length()) / 2.0 + 0.5;

        line = "|";
        for (int i = 0; i < leading_space; i++)
            line += ' ';
        line += class_name;
        for (int i = 0; i < closing_space; i++)
            line += ' ';
        line += "|";

        UMLMaker::chart_data.push_back(line);
    }
    else
    {
        cout << "\n"
                "  A class name is required, try again.\n";
    }

    if (!UMLMaker::class_variables.empty())
    {
        UMLMaker::chart_data.push_back(UMLMaker::edge_sep_line);

        for (string var : UMLMaker::class_variables)
        {
            line = "|";
            for (int i = 0; i < MARGIN; i++)
                line += ' ';
            line += var;
            for (int i = 0; i < (chart_width - var.length() - MARGIN); i++)
                line += ' ';
            line += "|";

            UMLMaker::chart_data.push_back(line);
        }
    }

    if (!UMLMaker::con_de_structors.empty())
    {
        UMLMaker::chart_data.push_back(UMLMaker::edge_sep_line);

        for (string con_des : UMLMaker::con_de_structors)
        {
            line = "|";
            for (int i = 0; i < MARGIN; i++)
                line += ' ';
            line += con_des;
            for (int i = 0; i < (chart_width - con_des.length() - MARGIN); i++)
                line += ' ';
            line += "|";

            UMLMaker::chart_data.push_back(line);
        }
    }

    if (!UMLMaker::class_methods.empty())
    {
        UMLMaker::chart_data.push_back(UMLMaker::edge_sep_line);

        for (string method : UMLMaker::class_methods)
        {
            line = "|";
            for (int i = 0; i < MARGIN; i++)
                line += ' ';
            line += method;
            for (int i = 0; i < (chart_width - method.length() - MARGIN); i++)
                line += ' ';
            line += "|";

            UMLMaker::chart_data.push_back(line);
        }
    }

    UMLMaker::chart_data.push_back(UMLMaker::edge_sep_line);
}

// ----------------------------------------------------------------------------

void UMLMaker::displayDiagram()
{
    cout << '\n';
    for (string line : UMLMaker::chart_data)
        cout << "  " << line << '\n';
}

// ----------------------------------------------------------------------------

void UMLMaker::diagramToFile()
{                     //"C:/Users/phill/Documents/"<~ Insert your output path!
    string file_name = (""
                        + UMLMaker::class_name + "_UML_Diagram.txt");

    ofstream to_file(file_name);
    if (to_file.is_open())
    {
        for (string line : UMLMaker::chart_data)
            to_file << line << '\n';
        to_file.close();
    }
    else
    {
        cout << "\n"
                "  Error: problem opening: "
             << file_name << '\n';
    }
}

// ----------------------------------------------------------------------------
