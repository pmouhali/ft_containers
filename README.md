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

### Sort

**list::sort** n'utilises pas **std::sort** mais implémentes le sien.

|    N ints     |  Bubblesort   |  Quicksort      |  Mergesort      | STL :crown:   |
| ------------: | :-----------: |:-------------:  |:-------------:  | :----------:  |
|       10      |    0.00 sec   |     0.00 sec    |     0.00 sec    |    0.00 sec   |
|     1000      |    3.65 sec   |     0.00 sec    |     0.00 sec    |    0.00 sec   |
|     3000      |  101.53 sec   |     0.00 sec    |     0.01 sec    |    0.00 sec   |
|    10000      |      X        |     0.01 sec    |     0.01 sec    |    0.01 sec   |
|   100000      |      X        |     0.21 sec    |     0.07 sec    |    0.05 sec   |
|  1000000      |      X        |    12.52 sec    | stack overflow  |    0.80 sec   |
| 10000000      |      X        | > 2272.76 sec   | stack overflow  |  134.14 sec   |

Notes :

Le temps a été calculé avec la commande **time**, il corresponds à N push + execution du tri.

Les valeurs ont été générées de manière random avec le range 0..3000. Donc les très longues listes comportaient énormément de doublons.

Mon quicksort est basique et non optimisé. Son code diffère de celui qu'on peut voir pour une liste doublement chainée puisque ici les nodes sont swappés directement, et non les valeurs, ce qui implique de mettre à jour les pointeurs sur node après chaque swap, etc. Il pourrait donc être plus rapide.

Le mergesort est exactement le même que celui ci : https://www.geeksforgeeks.org/merge-sort-for-doubly-linked-list/

Les performances sont meilleures que le quicksort, par contre, pour une liste d'un million d'int, ça pète la stack. Une implémentation hybride (récursive + itérative) ou entièrement itérative ne poserai pas ce problème, mais est ce que les perfs seraient bonnes ? Idk. 

## reverse_iterator

Est une classe template, qui prends un itérateur (list::iterator, vector::iterator, etc) en paramètre.

Un objet de type **reverse_iterator** va fonctionner comme un wrapper autour d'un objet de type **iterator**. Les méthodes proposées sont toutes implémentées avec les méthodes de l'itérateur à partir duquel l'objet est construit.

    from http://cplusplus.com/reference/iterator/reverse_iterator/operator++/
```
    reverse_iterator operator++(int) {
      reverse_iterator temp = *this;
      ++(*this);
      return temp;
    }
```
Commentaire intéressant from le code source :

The fundamental relation between a reverse_iterator and its corresponding iterator i is established by the identity:

    &*(reverse_iterator(i)) == &*(i - 1)

This mapping is dictated by the fact that while there is always a pointer past the end of an array, there might not be a valid pointer before the beginning of an array.

## RESSOURCES

code source de la libstdc++ :

https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01055_source.html

autres :

https://cs.calvin.edu/activities/books/c++/intro/3e/WebItems/Ch14-Web/STL-List-14.4.pdf

https://codefreakr.com/how-is-c-stl-list-implemented-internally/

https://stackoverflow.com/questions/5384358/how-does-a-sentinel-node-offer-benefits-over-null

https://codereview.stackexchange.com/questions/216444/c-linked-list-iterator-implementation

https://openclassrooms.com/fr/courses/1894236-programmez-avec-le-langage-c/1903301-utlisez-les-iterateurs-et-les-foncteurs

https://quuxplusone.github.io/blog/2018/12/01/const-iterator-antipatterns/

https://stackoverflow.com/questions/30287402/c-nested-class-in-class-template-declaration

https://42born2code.slack.com/archives/CMX2R5JSW/p1604438239334300

quicksort :

https://www.youtube.com/watch?v=0SkOjNaO1XY

https://www.geeksforgeeks.org/quick-sort/

https://www.geeksforgeeks.org/quicksort-for-linked-list/

reverse_iterator :

https://gcc.gnu.org/onlinedocs/gcc-6.4.0/libstdc++/api/a01623_source.html

http://cplusplus.com/reference/iterator/reverse_iterator/

mergesort :

https://www.chiark.greenend.org.uk/~sgtatham/algorithms/listsort.html

https://afteracademy.com/blog/sort-list-merge-sort
