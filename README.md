*Ce projet a été réalisé dans le cadre du cursus de 42 par isoulima.*

# pipex

![Language](https://img.shields.io/badge/Language-C-blue)
![Norminette](https://img.shields.io/badge/Norminette-OK-brightgreen)

## Description

pipex reproduit le comportement du pipe shell : `< file1 cmd1 | cmd2 > file2`.
Il crée deux processus enfants via `fork()`, les relie par un `pipe()`, et exécute
chaque commande avec `execve()` après résolution du chemin via la variable `PATH`.
Le projet introduit la programmation concurrente : c'est le premier projet 42 où
deux processus tournent simultanément. Le code de sortie retourné est celui de `cmd2`.

---

## Instructions

### Compilation

```bash
make
```

Un exécutable `pipex` est généré.

```bash
make clean    # supprime les .o
make fclean   # supprime les .o et pipex
make re       # recompile tout
```

### Utilisation

```bash
./pipex file1 "cmd1" "cmd2" file2
```

Équivalent shell :

```bash
< file1 cmd1 | cmd2 > file2
```

Exemple concret :

```bash
./pipex /etc/passwd "grep root" "wc -l" out.txt
```

---

## Fonctionnalités

- Résolution automatique des commandes via `PATH`
- Commandes avec arguments (`"grep -i pattern"`, `"sort -r"`)
- Chemins absolus acceptés (`"/bin/cat"`)
- `file1` inexistant : erreur sur stderr, `cmd2` reçoit une entrée vide
- Commande introuvable : `perror` sur stderr, `exit(127)`
- `file2` créé s'il n'existe pas, tronqué s'il existe (`O_TRUNC`)
- Code de sortie = code de sortie de `cmd2`

---

## Choix techniques

- **Deux forks séquentiels** — `child_one` et `child_two` sont lancés depuis le parent,
  qui ferme ensuite les deux extrémités du pipe avant d'attendre les enfants.
- **Fallback `/dev/null`** sur `file1` inexistant — permet à `cmd2` de s'exécuter
  avec une entrée vide plutôt que d'abandonner toute la commande.
- **Résolution PATH** : `get_env_path` extrait la variable `PATH` depuis `env[]`,
  `ft_split` la découpe sur `:`, `try_paths` teste chaque répertoire avec `access(X_OK)`.
- **Dépendance libft** : `ft_split`, `ft_strjoin`, `ft_strdup`, `ft_strncmp`, `ft_putstr_fd`.

---

## Ressources

- `man 2 pipe`
- `man 2 fork`
- `man 2 execve`
- `man 2 dup2`
- `man 2 waitpid`
- `man 2 access`
- Sujet officiel 42

---

## AI usage

L'IA a été utilisée uniquement pour :
- clarifier le fonctionnement de `pipe()`, `fork()` et `execve()`
- structurer ce README

L'implémentation, la logique et la compréhension du code ont été réalisées manuellement.

---

## Auteur

42 Lausanne
Login : isoulima
