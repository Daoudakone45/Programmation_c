#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max_size 100

/* Allocate memory for an array which can contain `size`
   integers. The returned C array has memory for an extra last
   integer labelling the end of the array. */
int* allocate_integer_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

/* Free an integer array */
void free_integer_array(int* tab){
  free(tab);
}

//EXERCICE 1

/*Implanter une fonction int array_size(int* array) qui retourne la longueur d’un tableau d’entier.*/
int array_size(int* array){
  int i = 0;
  while(array[i] != -1){
   i++;
  } return i;
}

/*Implanter une fonction void print_array(int* array) qui affiche le contenu d’un tableau sur la sortie standard.*/
/*
void print_array(int* array){
  int i = 0;
  printf("[");
  while(array[i] != -1){
    printf("%d ", array[i]);
    i++;
    printf(", ");
  
    
  }
  printf("-1");
  printf("]");
  printf("\n");
}

*/
void print_array(int* array) {
    printf("[");
    for (int i = 0; array[i] != -1; i++) {
        printf("%d", array[i]);
        if (array[i + 1] != -1) {
            printf(", ");
        }
    }
    printf("]\n");
}
/*Implanter une fonction int are_arrays_equal(int* first, int* second) qui retourne 1 si les deux tableaux ont le même contenu et 0 sinon.*/
int are_arrays_equal(int* first, int* second){
  
  int i = 0;

  while (first[i] != -1 && second[i] != -1){
    if(first[i] != second[i]){
      return 0;
    }
    i++;
  }
  if (first[i] == -1 && second[i] == -1){
    return 1;
  }

  return 0;
}   

/*Implanter une fonction int* copy_array(int* array) qui retourne une nouvelle copie
identique du tableau donné en argument. Attention, la copie doit utiliser une nouvelle
place mémoire, il ne s’agit pas ici de retourner exactement l’argument de la fonction.
*/

int* copy_array(int* array){

  static int copy[max_size];

  int i = 0;

  while (array[i] != -1 && i<max_size) {
    copy[i] = array[i];
    i++;
  }
  copy[i] = -1;

  return copy;
}

//FIN DE L'EXO1

//Exercice 2

int* fill_array(void) {
  int size;
  
  // Demande la taille du tableau
  printf("Entrez la taille du tableau : ");
  scanf("%d", &size);

  if (size <= 0) {
      printf("Taille invalide\n");
      return NULL;
  }

  // Allocation dynamique du tableau (+1 pour le -1)
  int* array = (int*)malloc((size + 1) * sizeof(int));
  if (array == NULL) {
      printf("Erreur d'allocation mémoire\n");
      return NULL;
  }

  // Remplissage du tableau par l'utilisateur
  printf("Entrez %d entiers positifs :\n", size);
  for (int i = 0; i < size; i++) {
      scanf("%d", &array[i]);
  }

  // Ajout du marqueur de fin -1
  array[size] = -1;

  return array;
}

//Tableau d'entiers aléatoires
int* random_array(int size, int max_entry) {
  if (size <= 0 || max_entry <= 0) {
      printf("Paramètres invalides\n");
      return NULL;
  }

  // Allocation dynamique du tableau (+1 pour le -1)
  int* array = (int*)malloc((size + 1) * sizeof(int));
  if (array == NULL) {
      printf("Erreur d'allocation mémoire\n");
      return NULL;
  }

  // Initialisation du générateur de nombres aléatoires
  srand(time(NULL));

  // Remplissage du tableau avec des nombres aléatoires
  for (int i = 0; i < size; i++) {
      array[i] = rand() % (max_entry + 1);  // Nombre entre 0 et max_entry
  }

  // Ajout du marqueur de fin -1
  array[size] = -1;

  return array;
}

//concatenation de deux tableaux 

int* concat_array(int* first, int* second) {
    int size1 = 0, size2 = 0;

    // Calcul de la taille des deux tableaux
    while (first[size1] != -1) {
        size1++;
    }
    while (second[size2] != -1) {
        size2++;
    }

    // Allocation dynamique pour le nouveau tableau (+1 pour -1)
    int* result = (int*)malloc((size1 + size2 + 1) * sizeof(int));
    if (result == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return NULL;
    }

    // Copie des éléments du premier tableau
    for (int i = 0; i < size1; i++) {
        result[i] = first[i];
    }

    // Copie des éléments du second tableau
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = second[i];
    }

    // Ajout du marqueur de fin -1
    result[size1 + size2] = -1;

    return result;
}





//EXERCICE 3

/* Implantation de ma foncton merge_sorted_array*/

int* merge_sorted_arrays(int* first, int* second){
  static int merged[max_size];  // Tableau statique pour le résultat fusionné
  int i = 0, j = 0, k = 0;

  // Fusionner les deux tableaux triés
  while (first[i] != -1 && second[j] != -1) {  // Tant que les deux tableaux ont des éléments
      if (first[i] < second[j]) {
          merged[k++] = first[i++];  // Ajouter l'élément de 'first'
      } else {
          merged[k++] = second[j++];  // Ajouter l'élément de 'second'
      }
  }

  // Ajouter les éléments restants de 'first' si il y en a
  while (first[i] != -1) {
      merged[k++] = first[i++];
  }

  // Ajouter les éléments restants de 'second' si il y en a
  while (second[j] != -1) {
      merged[k++] = second[j++];
  }  

  merged[k] = -1; // Mettre -1 à la fin du tableau

  return merged;  
}



/*La fonction split_arrays*/

void split_arrays(int* array, int** first, int** second) {
    int size = 0;
    
    // Calculer la taille du tableau original (jusqu'à la sentinelle -1)
    while (array[size] != -1) {
        size++;
    }
    
    // Calculer la taille de chaque sous-tableau
    int half_size = (size + 1) / 2;  // La première moitié (plus un si taille impaire)
    
    // Vérifier si la taille ne dépasse pas la capacité maximale
    if (half_size > max_size) {
        printf("Erreur : la taille du tableau dépasse la capacité maximale.\n");
        return;
    }
    
    // Allouer de la mémoire pour les deux sous-tableaux
    static int first_array[max_size];  // Premier tableau
    static int second_array[max_size];  // Deuxième tableau
    
    // Placer les éléments dans les sous-tableaux
    int i;
    for ( i = 0; i < half_size; i++) {
        first_array[i] = array[i];
    }first_array[i] = -1;
    
    for ( i = half_size; i < size; i++) {
        second_array[i - half_size] = array[i];
    }second_array[i- half_size]= -1;
    
    // Placer les pointeurs dans les arguments
    *first = first_array;
    *second = second_array;
    
}

// Fonction récursive de tri fusion

int* merge_sort(int* array) {
    // Vérifier la taille du tableau
    int size = 0;
    while (array[size] != -1) {
        size++;
    }

    // Cas de base : un seul élément ou tableau vide
    if (size <= 1) {
        return copy_array(array);
    }

    // Déclaration des sous-tableaux
    int *left, *right;
    split_arrays(array, &left, &right);

    // Affichage pour le traçage
    printf("Split array in two parts:\n");
    print_array(left);
    print_array(right);

    // Tri récursif des sous-tableaux
    int* sorted_left = merge_sort(left);
    int* sorted_right = merge_sort(right);

    // Fusion des sous-tableaux triés
    int* sorted_array = merge_sorted_arrays(sorted_left, sorted_right);

    // Affichage pour le traçage
    printf("Merge the two following ones:\n");
    print_array(sorted_left);
    print_array(sorted_right);
    print_array(sorted_array);

    // Libération de la mémoire temporaire
    free(left);
    free(right);
    free(sorted_left);
    free(sorted_right);

    return sorted_array;
}




/* An empty main to test the compilation of the allocation and free
   functions. */
int main(int argc, char* argv[]){

  printf("Affiché le contenue d'un tableau\n");
  int array[] = {1, 2, 3, 4, -5, -1};
    printf("Le contenu du tableau est: ");
    print_array(array);
    //return 0;

  printf("Vérifie si les tableaux sont égaux\n");
    int tab1[] = {4, 7, 2, 9, 10, -1};  // Tableau 1
    int tab2[] = {4, 7, 2, 9, 10, -1};  // Tableau 2 (identique)
    int tab3[] = {4, 7, 2, 8, 10, -1};  // Tableau 3 (différent)
    int tab4[] = {4, 7, 2, 9, -1};      // Tableau 4 (longueur différente)

    printf("Comparaison tableau1 et tableau2 : %d\n", are_arrays_equal(tab1, tab2));  // 1 (identiques)
    printf("Comparaison tableau1 et tableau3 : %d\n", are_arrays_equal(tab1, tab3));  // 0 (différents)
    printf("Comparaison tableau1 et tableau4 : %d\n", are_arrays_equal(tab1, tab4));  // 0 (longueur différente)
    //return 0;
    

  printf("Faire la copie d'un tableau\n");
  int tableauc[] = {4, 7, 2, 9, 10, -1};  // Tableau d'origine avec la sentinelle -1

    // Appel de la fonction copy_array
    int* copie = copy_array(tableauc);

    // Affichage des deux tableaux
    printf("Tableau original : ");
    for (int i = 0; tableauc[i] != -1; i++) {
        printf("%d ", tableauc[i]);
    }
    printf("\n");

    printf("Tableau copié : ");
    for (int i = 0; copie[i] != -1; i++) {
        printf("%d ", copie[i]);
    }
    printf("\n");

    //return 0;



  printf("Faire la fusion de deux tableaux\n");
  int tableau1[] = {2, 5, 8, 12, -1};  // Tableau 1 trié
  int tableau2[] = {1, 3, 6, 9, 15, -1};  // Tableau 2 trié

  // Appel de la fonction merge_sorted_arrays
  int* fusionne = merge_sorted_arrays(tableau1, tableau2);

  // Affichage du tableau fusionné
  printf("Tableau fusionné : ");
  print_array(fusionne);

  //return 0;

  printf("Diviser deux tableaux\n");
  int tableau[] = {4, 7, 3, 9, 10, 3, -1};  // Tableau à diviser avec une taille impaire
    
    int* first;
    int* second;
    
    // Appel de la fonction split_arrays
    split_arrays(tableau, &first, &second);

    // Affichage des sous-tableaux
    printf("Premier sous-tableau : ");
    print_array(first);

    printf("Deuxième sous-tableau : ");
    print_array(second);

    return 0;

}

