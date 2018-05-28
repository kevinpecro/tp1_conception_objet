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
    int n, nb;
    int stat[26]; //Decompte du nombre d'utilisation de chaque lettre de l'alphabet
    int spe;  //Nombre de caracteres speciaux
    void majstat();

public:
    MyString();
    MyString(char*);
    MyString(char,int);
    ~MyString();
    MyString(const MyString&);
    MyString& operator=(const MyString &);
    MyString operator+(MyString);

    void affiche();
    void concatenation(MyString);
    void supprimer_un_carac(char);
    void dedouble(char);
    void maj(char);
    //MyString& operator=(const MyString&);
    //MyString operator+(const)

};

MyString::MyString()
{
    tab=NULL;
    n=0;
    // Tableau des occurences 'stat'
    spe=0;
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
    i++;
    tab[i]='\0';
    majstat();
}

MyString::~MyString(){}


MyString::MyString(const MyString& s)
{
    tab=new char[nb=s.nb];
    for(int i=0; i<nb; i++)tab[i]=s.tab[i];

}

MyString& MyString::operator=(const MyString &b)
{
    if(this !=&b)
    {
        delete tab;
        tab = new char[nb = b.nb];
        for(char i=0; i<nb; i++)
            tab[i] = b.tab[i];
    }
    return *this;

}

MyString MyString::operator+(MyString b)
{
    MyString res;
    res.s3 = b.s2 + b.s1;

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
    //ajout du contenu de l'entite "x" de x.concatenation
    strcpy(fusion,tab);
    //ajout du contenu de l'entite chaine presente en parametre
    strcpy(fusion,chaine.tab);

}

void MyString::affiche()
{
    if (tab!=NULL)
    {
        cout<<"chaine = "<<tab<<endl;
    }
    else
    {
        cout<<"chaine = "<<endl;
    }
    cout<<"m = "<<n<<endl;
    cout<<"stat = "<<stat<<endl;
    for(int i=0; i<26; i++)
    {
        if(stat[i]!=0)
        {
            cout<<"nb car "<<(char)('A'+i)<<"="<<stat[i]<<endl;
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

void MyString::maj(char carac_a_maj)
{
    int i=0;
    char c;
    while (tab[i])
    {
        c=tab[i];
        putchar (toupper(c));
        i++;
    }

}


int main()
{
    cout<<"s:"<<endl;
    MyString s; s.affiche();
    cout<<"S1:"<<endl;
    MyString s1("aac"); s1.affiche();
    cout<<"S2:"<<endl;
    MyString s2(s1); s2.affiche();
    cout<<"S3:"<<endl;
    MyString s3('z',4); s3.affiche();



}

/*
supprime(char c)
{
    int i,j,cpt;
    char *tmp;

    for (i=0, cpt=0; i<n; i++)
        if(tab[i]==c)cpt++;
    for(i=0,j=0; i<=n;i++)
        if(tab[i]!=c)tmp[j++]=tab[i];
    n=n-cpt;
    delete tab; tab=tmp;
    majstat(); // ou stat[toupper(c)-'A']=0;
}

*/
