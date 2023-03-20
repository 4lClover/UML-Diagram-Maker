# UML-Diagram-Maker

![UML Diagram Maker Screenshot 3-12-2023](https://user-images.githubusercontent.com/61360844/225535032-a028529d-3fe2-4a98-91fa-cd44326d7298.png)


UML Diagram Maker is a terminal application utility that simplifies the process of building UML (Unified Modeling Language) ascii charts for documentation inside for and with your source code. UML Diagram Maker was built by a developer for developers. UML Diagram Maker is written in C/C++ but can be easily ported to other languages. 


The task of building ascii charts/diagrams is turned into a simple data entry process. As you will see with a little creativity UML Diagram Maker can be used to build diagrams for other items outside of classes. Also, the program is built with a forgiving solid design, after every data entry the input is displayed with a confirmation prompt. If a mistake is made you can easily reject that entry and enter the correct information. Diagrams are dynamically generated to accommodate the width of the data entry you provide with a two-space margin on each side. The margin is easily modified by changing the value of MARGIN in the UMLMaker.h file. 


UML Diagram Maker is designed to use UML standard formatting for C/C++ classes. However, it is remarkably simple to adjust output diagrams with language specific indicators. For example, if you are writing in Java and have a protected class field it only takes a second to change a private or public indicator from – or + to #. Data entry follows the convention of private first then public layout. The data entry is as follows. 


* ClassName 

* private class_atributes 

* public class_atributes 

* private Constructor 

* public Constructor 

* private Destructor 

* public Destructor 

* private class_methods 

* public class_methods 


You can have as many items of a type as you need, and you can decline to create any types that you do not need. Default no-arg constructors are quickly created and you can make as many constructors that take parameters as you want with as many parameters as you want. The same goes for destructors and methods.  


After your data entry is complete a copy of your diagram is displayed in the terminal. You can copy and paste that diagram if you do not want a copy in a text file. If you are happy with the diagram, you can output the diagram to a text file. If corrections need to be made you can make changes in the text file or start over and make corrections in the program. A convenient feature is the ability to publish your output to any path you like. See the chartToFile method at the bottom of UMLMaker.cpp and an example path is given. If you do not provide a path, by default your output files will be in the same directory as your executable. The name of your output files will take the class name followed by _UML_Diagram.txt, example, UMLMaker_UML_Diagram.txt. You can create as many different diagrams as you like in a single session if each diagram has a different class name. 
