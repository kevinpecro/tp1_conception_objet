#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//https://github.com/kevinpecro/tp1_conception_objet.git

class MyString
{
private:
    char *tab;
    int n;
    int stat[26]; //Décompte du nombre d'utilisation de chaque lettre de l'alphabet
    int spe;  //Nombre de caractères spéciaux
public:
    MyString();
    MyString(char*);
    MyString(char,int);
    ~MyString();
    MyString(const MyString&);
    void affiche();
    void supprimer_un_carac(char,char);
    char* concatenation(char*,char*);
};

MyString::MyString()
{
    tab=NULL;
    n=0;

    // Tableau des occurences 'stat' à initialiser

    spe=0;
}

MyString::MyString(char* chaine)
{
    n=strlen(chaine);
    int i;
    tab=(char*)malloc((n+1)*sizeof(char));
    for ( i = 0; chaine[i]!='\0'; ++i)
    {
        tab[i]=chaine[i];
    }
    tab[i]='\0';

    // Tableau des occurences 'stat' à initialiser
}

MyString::MyString(char caractere, int x)
{
    n=x;
    int i;
    tab=(char*)malloc((n+1)*sizeof(char));
    for ( i = 0; i < x ; ++i)
    {
        tab[i]= caractere;
    }
    tab[i]='\0';

    // Tableau des occurences 'stat' à initialiser
}

MyString::~MyString(){}



char* MyString::concatenation(char* chaine1, char* chaine2)
{
    char* chaine3;
    strcpy(chaine3,chaine1);
    strcpy(chaine3,chaine2);

}

void MyString::affiche()
{
    for(int i=0; i<n; i++)
    {
        cout<<" "<<stat[i]<<endl;
    }

}

void MyString::supprimer_un_carac(char *tab, char carac_a_suppr)
{
    int j=0, taille;
    char attente[100], *res;

    for(int i=0; tab[i]!='\0'; i++)
    {
        if(tab[i]!=carac_a_suppr)
        {
            attente[j]=tab[i];
            j++;
        }

    }
    taille=strlen(attente)+1;

    res=(char*)malloc((taille+1)*sizeof(char));

    strcpy(res,attente);
}


MyString::MyString()
{
    tab=NULL;
    n=0;

    //stat a initialiser a 0

    spe=0;
}

MyString::MyString(char* chaine)
{
    n=strlen(chaine);
    tab=(char*)malloc((n+1)*sizeof(char));

}

int main()
{
    MyString s; s.affiche();
    MyString s1("aac"); s1.affiche();
    MyString s2(s1); s2.affiche();
    MyString s3('z',4);

    return 0;
}
