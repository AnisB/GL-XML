GL-XML
======
Processeur XML - GL

Boost avec program options et regex est indispensable

cmake aussi

CMAKE:
Get cmake on non root session: http://www.cmake.org/cmake/resources/software.html\n
Puis ajouter un alias dans votre .bashrc\n


Il faut executer la commande suivante dans la racine\n
mkdir build && cd build && cmake ..\n
puis la commande:\n
make\n

Si vous voulez génerer les programmes de test, il faut ajouter l'option:\n
-Dtest=true\n
Si vous voulez générer la doc doxygen (suite à une modification des sources), l'option à ajouter est:\n
-Ddoc=true\n

puis pour compiler la doc, il suffit d'executer la commande suivante dans le dossier doc:\n
make doc
