*Ce projet a été réalisé dans le cadre du cursus de 42 par isoulima.*

# Libft

<img src="score.png" width="150" alt="Score 125/100">

![Language](https://img.shields.io/badge/Language-C-blue)
![Norminette](https://img.shields.io/badge/Norminette-OK-brightgreen)

## Description

Libft est le tout premier projet du cursus 42. Il consiste à recoder une bibliothèque de fonctions C standard, puis à l'enrichir avec des fonctions utilitaires supplémentaires. Le projet permet de comprendre en profondeur le fonctionnement des fonctions de la libc, la gestion de la mémoire dynamique et la manipulation de chaînes de caractères. La partie bonus introduit les listes chaînées.

---

## Instructions

### Compilation

```bash
make        # compile la bibliothèque libft.a
make bonus  # compile avec les fonctions bonus (listes chaînées)
make clean  # supprime les .o
make fclean # supprime les .o et libft.a
make re     # recompile tout
```

### Utilisation

Inclure le header et compiler avec la bibliothèque :

```bash
cc main.c libft.a
```

```c
#include "libft.h"

int main(void)
{
    char *s = ft_strdup("Hello 42");
    ft_putstr_fd(s, 1);
    free(s);
    return (0);
}
```

---

## Fonctionnalités

### Fonctions libc

| Fonction | Description |
|----------|-------------|
| `ft_isalpha` | vérifie si c'est une lettre |
| `ft_isdigit` | vérifie si c'est un chiffre |
| `ft_isalnum` | vérifie si c'est alphanumérique |
| `ft_isascii` | vérifie si c'est un caractère ASCII |
| `ft_isprint` | vérifie si c'est imprimable |
| `ft_strlen` | longueur d'une chaîne |
| `ft_memset` | remplit une zone mémoire |
| `ft_bzero` | met une zone mémoire à zéro |
| `ft_memcpy` | copie une zone mémoire |
| `ft_memmove` | copie avec gestion du chevauchement |
| `ft_strlcpy` | copie sécurisée de chaîne |
| `ft_strlcat` | concaténation sécurisée |
| `ft_toupper` | convertit en majuscule |
| `ft_tolower` | convertit en minuscule |
| `ft_strchr` | cherche un caractère dans une chaîne |
| `ft_strrchr` | cherche un caractère en partant de la fin |
| `ft_strncmp` | compare deux chaînes sur n caractères |
| `ft_memchr` | cherche un octet dans une zone mémoire |
| `ft_memcmp` | compare deux zones mémoire |
| `ft_strnstr` | cherche une sous-chaîne |
| `ft_atoi` | convertit une chaîne en entier |
| `ft_calloc` | allocation mémoire initialisée à zéro |
| `ft_strdup` | duplique une chaîne |

### Fonctions supplémentaires

| Fonction | Description |
|----------|-------------|
| `ft_substr` | extrait une sous-chaîne |
| `ft_strjoin` | concatène deux chaînes |
| `ft_strtrim` | supprime des caractères en début/fin |
| `ft_split` | découpe une chaîne selon un délimiteur |
| `ft_itoa` | convertit un entier en chaîne |
| `ft_strmapi` | applique une fonction à chaque caractère (nouveau) |
| `ft_striteri` | applique une fonction à chaque caractère (en place) |
| `ft_putchar_fd` | écrit un caractère sur un fd |
| `ft_putstr_fd` | écrit une chaîne sur un fd |
| `ft_putendl_fd` | écrit une chaîne + newline sur un fd |
| `ft_putnbr_fd` | écrit un nombre sur un fd |

### Bonus (listes chaînées)

| Fonction | Description |
|----------|-------------|
| `ft_lstnew` | crée un nouvel élément |
| `ft_lstadd_front` | ajoute au début |
| `ft_lstsize` | compte les éléments |
| `ft_lstlast` | renvoie le dernier élément |
| `ft_lstadd_back` | ajoute à la fin |
| `ft_lstdelone` | supprime un élément |
| `ft_lstclear` | supprime tous les éléments |
| `ft_lstiter` | applique une fonction à chaque élément |
| `ft_lstmap` | applique une fonction et crée une nouvelle liste |

---

## Choix techniques

- Bibliothèque statique (`libft.a`) compilée avec `ar -rc`
- Flags de compilation stricts : `-Wall -Wextra -Werror`
- Aucune variable globale
- Gestion mémoire rigoureuse avec `malloc` / `free`
- Header unique `libft.h` inclus via le flag `-include` du compilateur
- Les fonctions bonus sont compilées séparément via `make bonus`

---

## Ressources

- `man 3` des fonctions libc correspondantes
- Documentation sur les listes chaînées en C
- Sujet officiel 42

---

## AI usage

L'IA a été utilisée uniquement pour :
- clarifier certains points du sujet
- structurer ce README

L'implémentation, la logique et la compréhension du code ont été réalisées manuellement.

---

## Auteur

42 Lausanne
Login : isoulima
