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
    int n, nb, *tab_recopie;
    int stat[26]; //Dï¿½compte du nombre d'utilisation de chaque lettre de l'alphabet
    int spe;  //Nombre de caractï¿½res spï¿½ciaux
    void majstat();

public:
    MyString();
    MyString(char*);
    MyString(char,int);
    ~MyString();
    MyString(const MyString&);

    void affiche();
    void concatenation(MyString);
    void supprimer_un_carac(char);
    void dedouble(char);
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
    tab=new char[n+1];
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


MyString::MyString(const MyString& s)
{
    tab_recopie=new int[nb=s.nb];
    for(int i=0; i<nb; i++)tab[i]=s.tab[i];

}

void MyString::majstat()
{
    int i;
    char car;
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



void MyString::concatenation(MyString chaine)
{
    char* fusion;
    //ajout du contenu de l'entité "x" de x.concatenation
    strcpy(fusion,tab);
    //ajout du contenu de l'entité chaine présente en paramètre
    strcpy(fusion,chaine.tab);

}

void MyString::affiche()
{
    cout<<"chaine = "<<tab<<endl;
    cout<<"m = "<<n<<endl;
    cout<<"stat = "<<endl;
    for(int i=0; i<26; i++)
    {
        if(stat[i]!=0)
        {
            cout<<"nb car"<<(char)('A'+i)<<"="<<stat[i]<<endl;
        }
    }
}

void MyString::supprimer_un_carac(char carac_a_suppr)
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

void MyString::dedouble(char carac_a_doubler)
{
    int j=0, taille;
    char attente[100], *res;


    for (int i=0; tab[i]!='\0'; i++)
    {
        if(tab[i]==carac_a_doubler)
        {
            attente[j]=tab[i];
            j++;
            attente[j]=tab[i];
        }
        else
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
    cout<<"S1:"<<endl;
    MyString s1("aac"); s1.affiche();
    cout<<"S2:"<<endl;
    MyString s2(s1); s2.affiche();
    cout<<"S3:"<<endl;
    MyString s3('z',4); s3.affiche();



}
