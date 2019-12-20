# Ioa-Project
It's a project for Introducing to Algorithm

Project Defining :

Introduction to Algorithms Homework 1: CRAWLER  
In this homework you are going to write a (C / C++) program that will get a graph model as an argument.  
You must get this values from console while we are starting your application. (How will be shown in class  
this week.) Your program must write down all the possible word combination by using the graph model.  
Ex Input on Console to call your app: “yourapp.exe 5ABCD1BCD1CDE”  
After your application name, second word gives you information about the graph.  
- Notation: [STEPS][FROM1-TO1-TO2-...TOn]1[FROM2-TO1-TO2-...TOn]1 .....  
- [STEPS] First integer value ( 5 in our example) is the maximum word length to measure.  
- [FROM TO ... TO] blocks show connections in the graph. Each node is symbolized with one Upper  
Letter. First on is connections start position others are destinations. Each connection(link) is one  
way. So: “ABCD” means we have connection from A to B , A to C and A to D  
- The first node in the text is the start point for word creation.  

This input means you have a graph like:  

Desired Output:  
A  
AB  
AC  
AD  
ABD  
ABC  
ABCD  
ABCE  
ACD  
ACE  
IMPORTANT INFO ABOUT HOMEWORK DELIVERY  
Homework is collected by the system in google classroom website. Any other delivery method is not  
going to be accepted. While writing the code, students must obey the rules below.  

• At the beginning of your code file there must be a comment part giving information about you,  
compiler environment of your code and any other issue need to be taken into consideration to  
run the code file.  
Ex:  
// Halil Emin Çalışkan  
// 1306xxxxxx  
// Date: 02.12.2019  
// Development Environment: Visual Studio2019  
• The code file should be compiled either in Microsoft Visual Studio or under GCC.4.xx(CodeBlocks  
is using this also)  
• Only one code file is collected so do not try to send any other file or more than one file. If you  
upload your code file again the previous one replaced with this.  
• The code file must be named as “1306XXXXXX.cpp”  
• If your program includes extra header files such as “stdafx.h” it takes zero since I cannot compile  
your code. Be careful about it.  
