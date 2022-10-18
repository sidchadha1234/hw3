To compile the first and second part:
cd hw3
make 
./llrec-test llrec-test1.in


To compile the third part into an exceutable:
g++ -g -Wall stacktest.cpp -o test

The fourth part is attached

To compile the fifth part:
cd hw3
cd heap-test
make
make test

To compile and run the sixth part:
cd hw3
cd logicsim
make all
./logicsim single_or.txt > my_or.uml
java -jar plantuml.jar my_or.uml


replace the "or" in single_or and my_or in the above statements if you would like to run and or not
