<!--
 * @Author: ThearchyHelios
 * @Date: 2022-09-15 20:18:54
 * @LastEditTime: 2022-09-15 20:24:15
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /APP1/Facon_de_reussir.md
-->


## Question 2:
### À partir des pistes de réflexion élaborées durant la séance 1, tirez au clair la méthode générale de résolution du problème que vous allez suivre.
Nous devons déterminer la position relative de la troisième lettre après celle-ci sur l'ascii et déterminer si nous devons faire un pas en avant.

## Question 3:
### Déduisez-en la structure de l’algorithme : identifiez les fonctions dont vous aurez besoin, et pour chacune précisez en quelques lignes sa signature (types des paramètres et de la valeur de retour) et ce qu’elle fait.

```c
#include <stdio.h>

int main(void)
{
    char lettreLue;
    char lettreSuivante3;

    printf("Donner une lettre \n");
    scanf("%c", &lettreLue);

    lettreSuivante3 = lettreLue + 3;
    if (lettreSuivante3 > 'z')
    {
        lettreSuivante3 = lettreSuivante3 - 'z' + 'a' - 1;
    }

    printf("\n%c\n", lettreSuivante3);

    return 0;
}
```
