# ft_containers

## LIST

### Structure

La liste est composée de nodes. C'est une liste doublement chaînée.

Le node est un objet composé de trois membres : un element de type T (template) pour stocker une valeur, un pointeur sur le node suivant, un pointeur sur le node précédent.

L'objet liste est composé d'un pointeur sur node **dummy** et d'un type numérique pour stocker la taille de la liste.

Qu'est ce qu'un dummy node ? Quelle utilité ?

Ce node est initialisé à la création d'un objet liste, il ne contient aucune valeur. Une liste vide possède donc au moins ce node. Mais il n'est pas compté dans la taille. C'est un node fantôme. Le pointeur **next** de ce node pointe sur le premier node (élément) de la liste. Le pointeur **prev** de ce node pointe sur le dernier node de la liste.

Le dummy node marque la fin de la liste (contexte d'itération).

Il permet une implémentation simple du bidirectional iterator. Il permet de ne pas utiliser de pointeurs **head** et **tail**.

![list with dummy node schema](https://i.stack.imgur.com/nlX1F.png)

### Iterators

Les iterateurs sont des objets qui permettent d'itérer sur un container de manière simple, on peut les utiliser comme des pointeurs (increment, dereference, etc).

L'itérateur de list est de type bidirectional. On peut l'incrémenter et le décrémenter donc.

**iterator** et **const_iterator** sont deux classes (objets) différents.

La différence est que le **const_iterator** pointe sur un objet const, on ne peut donc pas modifier la valeur des elements du conteneur via ce type d'itérateur.

Un **iterator** doit pouvoir être converti implicitement en **const_iterator**. Pour ça, il suffit d'implémenter un constructeur par copie qui prends un **iterator** en paramètre pour le **const_iterator**.

Un **const_iterator** ne peut pas être converti en **iterator**.

Les **iterator** et **const_iterator** peuvent être comparés. Il faut donc fournir les overloads en question (== et !=).

Si l'objet list est const qualified, alors les fonctions **begin()** et **end()** vont retourner un **const_iterator**. D'où leur overload avec **const_iterator** en return type.

## RESSOURCES

code source de la libstdc++ :

https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01055_source.html

autres :

https://codefreakr.com/how-is-c-stl-list-implemented-internally/

https://stackoverflow.com/questions/5384358/how-does-a-sentinel-node-offer-benefits-over-null

https://codereview.stackexchange.com/questions/216444/c-linked-list-iterator-implementation

https://openclassrooms.com/fr/courses/1894236-programmez-avec-le-langage-c/1903301-utlisez-les-iterateurs-et-les-foncteurs

https://quuxplusone.github.io/blog/2018/12/01/const-iterator-antipatterns/

https://stackoverflow.com/questions/30287402/c-nested-class-in-class-template-declaration

https://42born2code.slack.com/archives/CMX2R5JSW/p1604438239334300
