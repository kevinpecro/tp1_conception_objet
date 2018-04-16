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
    void majstat();

public:
    MyString();
    MyString(char*);
    MyString(char,int);
    ~MyString();
    MyString(MyString&);
    //accesseurs
    void affiche();
    void supprimer_un_carac(char*,char);
    void concatenation(MyString);
};

MyString::MyString()
{
    tab=NULL;
    n=0;
    // Tableau des occurences 'stat'
    majstat();
}

MyString::MyString(char* chaine)
{
    n=strlen(chaine);
    tab=new char[n+1]
    strcpy(tab,chaine);
    // Tableau des occurences 'stat'
    majstat();    
}

MyString::MyString(char caractere, int x)
{
    n=x;
    int i;
    tab=new char[n+1];
    for ( i = 0; i < x ; ++i)
    {
        tab[i]= caractere;
    }
    majstat();
}

MyString::~MyString(){}

MyString::majstat()
{
    int i; char car;
    spe=0;
    for (int i = 0; i < 26; ++i)
    {
        stat[i]=0;
    }
    for (int i = 0; i < n; ++i)
    {
        car=toupper(tab[i]);
        if ((car>='A')&&(car<='Z'))
        {
            stat[car-'A']++;
        }
        spe++;
    }
}



void MyString::concatenation(MyString chaine1)
{
    char* chaine2;
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


int main()
{
    MyString s; s.affiche();
    MyString s1("aac"); s1.affiche();
    MyString s2(s1); s2.affiche();
    /**/
    MyString s3('z',4);
    /**/

    return 0;
}
