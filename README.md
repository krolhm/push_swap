# push_swap
Ce projet vous demande de trier des données sur une pile, avec un set d’instructions limité, en moins de coups possibles. Pour le réussir, vous devrez manipuler différents algorithmes de tri et choisir la (ou les ?) solution la plus appropriée pour un classement optimisé des données.

## OPERATIONS

✅ sa : swap a - permutez les 2 premiers éléments en haut de la pile a. Ne rien faire s'il y a est seulement un ou aucun élément).

✅ sb : swap b - permutez les 2 premiers éléments en haut de la pile b. Ne rien faire s'il y a est seulement un ou aucun élément).

✅ ss : sa et sb en même temps.

✅ pa : push a - prenez le premier élément en haut de b et placez-le en haut de a. Fais rien si b est vide.

✅ pb : push b - prenez le premier élément en haut de a et placez-le en haut de b. Fais rien si a est vide.

✅ ra : rotation a - décale tous les éléments de la pile a de 1. Le premier élément devient le dernier.

✅ rb : rotation b - décale tous les éléments de la pile b de 1. Le premier élément devient le dernier.

✅ rr : ra et rb en même temps.

✅ rra: rotation inverse a - décale tous les éléments de la pile a de 1. Le dernier élément devient le premier.

✅ rrb: rotation inverse b - décale tous les éléments de la pile b de 1. Le dernier élément devient le premier.

✅ rrr: rra et rrb en même temps.

## BONUS FLAGS

./checker -n $ARG : Nombre d'op
./checker -c $ARG : Couleurs

## BONUS AUTRE

./test.sh         : Testeur