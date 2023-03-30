/*
Class:UMLMaker
Author:Phillip McCullough
Date:3/4/2023
C/Cpp:11+ ANSI Standard
Last Updated:3/19/2023

IMPORTANT, see the diagramToFile() definition!!

This class is used to produce Unified Modeling Language (UML) diagrams.

    +-------------------------------------------------+
    |                    UMLMaker                     |
    +-------------------------------------------------+
    |  -class_name:string                             |
    |  -class_member_var:string                       |
    |  -class_method:string                           |
    |  -edge_sep_line:string                          |
    |  -MARGIN:const int                              |
    |  -chart_width:int                               |
    |  -class_variables:vector <string>               |
    |  -con_de_structors:vector <string>              |
    |  -class_methods:vector <string>                 |
    |  -chart_data:vector <string>                    |
    +-------------------------------------------------+
    |  +UMLMaker()                                    |
    |  +UMLMaker(class_name:string)                   |
    |  +~UMLMaker()                                   |
    +-------------------------------------------------+
    |  +setClassName(class_name:string):void          |
    |  +getClassName():string                         |
    |  +setClassVar(class_variable:string):void       |
    |  +setClassConstructor(constructor:string):void  |
    |  +setClassDestructor(destructor:string):void    |
    |  +setClassMethod(class_method:string):void      |
    |  +setWidth():void                               |
    |  +makeEdgeSepLine():void                        |
    |  +makeDiagram():void                            |
    |  +displayDiagram():void                         |
    |  +diagramToFile():void                          |
    +-------------------------------------------------+
-------10--------20--------30--------40--------50--------60--------70--------80
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class UMLMaker
{
private:
    string class_name;
    string class_member_var;
    string class_method;
    string edge_sep_line;
    const int MARGIN = 2;
    int chart_width;
    vector<string> class_variables, con_de_structors, class_methods, chart_data;

public:
    UMLMaker();
    UMLMaker(string class_name);
    ~UMLMaker();
    void setClassName(string class_name);
    string getClassName() const;
    void setClassVar(string class_variable);
    void setClassConstructor(string constructor);
    void setClassDestructor(string destructor);
    void setClassMethod(string class_method);
    void setWidth();
    void makeEdgeSepLine();
    void makeDiagram();
    void displayDiagram();
    void diagramToFile();
};

// ----------------------------------------------------------------------------