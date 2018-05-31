#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//https://github.com/kevinpecro/tp1_conception_objet.git

class MyString
{
private:
    char *tab,*d;
    int n,x,y;
    int stat[26]; //Decompte du nombre d'utilisation de chaque lettre de l'alphabet
    int spe;  //Nombre de caracteres speciaux
    void majstat();

public:
    MyString();
    MyString(char*);
    MyString(char,int);
    ~MyString();
    MyString(const MyString&);
    MyString &operator=(const MyString &);
    MyString operator+=(MyString &);
    friend ostream& operator<<(ostream& os, const MyString& st);
    void affiche();
    void concatenation(MyString);
    void supprimer_un_carac(char);
    void dedouble(char);
    void maj(char);
};

MyString::MyString()
{
    tab=NULL;
    n=0;
    spe=0;
    majstat();
}

MyString::MyString(char* chaine)
{
    n=strlen(chaine);
    tab=new char[n+1];
    strcpy(tab,chaine);
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

MyString& MyString::operator=(const MyString &b)
{
    int i;
    if(this !=&b)
    {
        delete tab;
        tab = new char[n = b.n];
        for( i=0; i<n; i++)
            tab[i] = b.tab[i];
    }
    tab[i]='\0';
    majstat();
    return *this;

}
ostream& operator<<(ostream& os, const MyString& st)
{
    os<< st.tab;
    return os;
}

MyString operator+(MyString st1, MyString st2)
{
    MyString res = st1;
    res.concatenation(st2);
    return res ;
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
        {
            if (car!='\0')
            {
                spe++;
            }
        }
    }
}



void MyString::concatenation(MyString chaine)
{
    char* fusion;
    int taille,i,j;
    taille = n+chaine.n+1;
    fusion =new char[taille];
    for( i=0; i < n ;i++)
    {
        fusion[i]=tab[i];
    }

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
    int j=0, taille, test=0;
    char *res;
    taille=strlen(tab)+1;

    res=(char*)malloc((taille+1)*sizeof(char));

    for(int i=0; i < n ; i++)
    {
        if((tab[i]!=carac_a_suppr) && (tab[i]!='\0'))
        {
            res[j]=tab[i];
            j++;
        }
    }
    res[j]='\0';
    delete tab;
    tab=res;
    n=0;
    for (int i = 0; tab[i]!='\0'; ++i)
    {
       n++;
    }
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
    n=0;
    for (int i = 0; tab[i]!='\0'; ++i)
    {
       n++;
    }
    majstat();
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
    MyString s; s.affiche();//Initialisation d'un objet MyString vierge
    cout<<"S1:"<<endl;
    MyString s1("aac"); s1.affiche();//Initialisation d'un objet MyString avec défition de la chaine
    cout<<"S2:"<<endl;
    MyString s2(s1); s2.affiche();//Initialisation d'un objet MyString via constructeur de recopie
    cout<<"S3:"<<endl;
    MyString s3('z',4); s3.affiche();
    //Initialisation d'un objet MyString comprenant 4 fois le caractère z

    s3.concatenation(s1); //ajout de la chaine s1 dans s3
    s3.affiche();
    s1.dedouble('c'); // Doublage du caractère c dans s1
    cout<< "S1 : " << endl;
    s1.affiche();
    s1.supprimer_un_carac('c');//Suppression des caractères c dans s1
    s1.affiche();
    
    MyString s4("abcdefghijklmnopqrtusvwxyz");
    s4.supprimer_un_carac('a');s4.supprimer_un_carac('i');
    cout << "S4 : " << endl;
    s4.affiche();
    s4.dedouble('e');
    s4.affiche();
    //vérifications de l'application de plusieurs méthodes a la suite les unes des autres

    s4 = s2; // Vérication de la surcharge d'opérateur =
    s4.affiche();

    cout << "Operateur +" <<endl;
    cout << s4 << endl;// Vérication de la surcharge d'opérateur <<
    MyString s5;
    s5 = s2+s2; // Vérication de la surcharge d'opérateur +
    cout << s5 <<endl;

}
