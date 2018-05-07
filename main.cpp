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
    int stat[26]; //Decompte du nombre d'utilisation de chaque lettre de l'alphabet
    int spe;  //Nombre de caracteres speciaux
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
    //i++;
    tab[i]='\0';
    majstat();
}

MyString::~MyString(){}


MyString::MyString(const MyString& s)
{
    int i;
    n = s.n ;
    tab=new char[n];
    for(i=0; i<n; i++)
    {
        tab[i]=s.tab[i];
    }
    tab[i]='\0';
    majstat();
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
        else
            spe++;
    }
}



void MyString::concatenation(MyString chaine)
{
    char* fusion;
    int taille,i,j;
    taille = n+chaine.n+1;
    fusion =new char[taille];
    //ajout du contenu de l'entite chaine presente en parametre
    for( i=0; i < n ;i++)
    {
        fusion[i]=tab[i];
    }


    //ajout du contenu de l'entite "x" de x.concatenation
    for(j=0; j < chaine.n ;j++,i++)
    {
        fusion [i]=chaine.tab[j];
    }
    fusion[i]='\0';
    delete tab;
    tab=fusion;
    n = taille-1;
    majstat();

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
    cout<<"n = "<<n<<endl;
    cout<<"stat : "<<endl;
    for(int i=0; i<26; i++)
    {
        if(stat[i]!=0)
        {
            cout<<"nb de car "<<(char)('A'+i)<<"="<<stat[i]<<endl;
        }
    }
    cout<<"spe = "<<spe<<endl;
}

void MyString::supprimer_un_carac(char carac_a_suppr)
{
    int j=0, taille;
    char *res;
    taille=n;

    res=(char*)malloc((taille+1)*sizeof(char));

    for(int i=0; i < n ; i++)
    {
        if(tab[i]!=carac_a_suppr)
        {
            res[j]=tab[i];
            j++;
        }
        else
            n--;

    }
    res[j]='\0';
    delete tab;
    tab=res;
    n = taille;
    majstat();
}

void MyString::dedouble(char carac_a_doubler)
{
    int j=0, taille;
    char  *res;
    taille=strlen(tab)+1;

    res=(char*)malloc((taille+1)*sizeof(char));

    for (int i=0; i < n ; i++)
    {
        if(tab[i]==carac_a_doubler)
        {
            res[j]=tab[i];
            j++;
            res[j]=tab[i];
            j++;
        }
        else
        {
            res[j]=tab[i];
            j++;
        }
    }
    res[j]='\0';
    delete tab;
    tab=res;
    n = taille;
    majstat();
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

    s3.concatenation(s1);
    s3.affiche();
    s1.dedouble('c');
    cout<< "S1 : " << endl;
    s1.affiche();
    s1.supprimer_un_carac('c');
    s1.affiche();


}
