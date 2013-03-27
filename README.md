GL-XML
======
Processeur XML - GL

Boost avec program options et regex est indispensable

cmake aussi

CMAKE:
Get cmake on non root session: http://www.cmake.org/cmake/resources/software.html
Puis ajouter un alias dans votre .bashrc


Il faut executer la commande suivante dans la racine
mkdir build && cd build && cmake ..
puis la commande:
make

Si vous voulez génerer les programmes de test, il faut ajouter l'option:
-Dtest=true
Si vous voulez générer la doc doxygen (suite à une modification des sources), l'option à ajouter est:
-Ddoc=true
