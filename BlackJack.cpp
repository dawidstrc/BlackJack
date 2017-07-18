#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;
void main2();

char mieszanie(char talia[], vector <char> &kolory_kart)
{
 int wiel = 16;
 int wiel2 = wiel;
 int a;
 for(int i = 0; i<wiel2; i++)
 {
     a = rand()%wiel;
     kolory_kart.push_back(talia[a]);
     for(int i = a; i<wiel; i++) talia[i]=talia[i+1];
     talia[wiel-1]=0;
     wiel--;
 }

}
int krupier(int sumakr, int h[], vector <char> &kolory_kart)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    char c[13]={'2','3','4','5','6','7','8','9','T','J','D','K','A'};
    cout<<"\nlOSOWANIE KRUPIERA\nSuma poczatkowa "<<sumakr<<endl;
    int a, b, i=1;
    do
    {
        a=rand()%13;
        if(a==12&&h[a]+sumakr>21)sumakr++;
        else
        sumakr+=h[a];
        cout<<i<<" losowanie karta "<<c[a]<<kolory_kart.back()<<endl;
        kolory_kart.pop_back();
        cout<<"Suma krupiera "<<sumakr<<endl;
        cout<<endl;
        i++;

    }while(sumakr<=16);
    b=sumakr;
    return b;
}
int gracz(int sumagr, int h[], vector <char> &kolory_kart)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
      char i='1';
      int j, b;
      char c[13]={'2','3','4','5','6','7','8','9','T','J','D','K','A'};
         while(i=='1')
      {
          j=rand()%13;
          if(j==12&&h[j]+sumagr>21)sumagr++;
          else
          sumagr+=h[j];
          cout<<"Gracz wylosowal karte "<<c[j]<<kolory_kart.back()<<"\nSuma gracza "<<sumagr<<"\n"<<endl;
          kolory_kart.pop_back();
          if(sumagr>=21)
          {
              cout<<"Juz nie mozesz dobierac kart\n"<<endl;
              i='0';
          }
          else
          {
             cout << "Czy chcesz nadal dobierac karty 1.TAK 0.NIE" << endl;
             i=getch();
             cout<<endl;
          }

      }
    b=sumagr;
    return b;
}

void nowa_gra()
{
    system("color 14");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    vector <char> kolory_kart;
    int a, c, d, e, g, sumagr, sumagr2, sumakr, kasa, stawka;
    char ok, f;
    char b[13]={'2','3','4','5','6','7','8','9','T','J','D','K','A'};
    int h[13]={2,3,4,5,6,7,8,9,10,10,10,10,11};
    cout<<"Ile chcesz miec gotowki"<<endl;
    cin>>kasa;
    do
    {
    char talia[16]={'C', 'W', 'D', 'Z', 'D', 'Z', 'W', 'C', 'C', 'W', 'D', 'Z', 'D', 'C', 'Z', 'W'};
    system("cls");
    system("color 14");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    c=rand()%13;
    d=rand()%13;
    e=rand()%13;
    sumagr=0;
    sumakr=0;
    cout<<"Ile stawiasz kasy min 10"<<endl;
    cin>>stawka;
    kolory_kart.clear();
    mieszanie(talia, kolory_kart);
    if(stawka>=10&&kasa>=stawka)
    {
    cout<<"Krupier wylosowal ci karty "<<b[c]<<kolory_kart.back();
    kolory_kart.pop_back();
    cout<<" i "<<b[d]<<kolory_kart.back()<<endl;
    kolory_kart.pop_back();
    cout<<"Karta krupca to " <<b[e]<<kolory_kart.back()<<endl;
    kolory_kart.pop_back();
    sumakr+=h[e];
    sumagr+=h[c];
    if(d==12&&h[d]+sumagr>21)sumagr++;
    else
    sumagr+=h[d];
    char k='1';
    do
    {
    cout<<"JAKI RUCH WYKONASZ: \n 1.Hit 2.Stand 3.Double 4.Split 5.Insurance\n" << endl;
    f=getch();
    if(f=='3'&&kasa<stawka*2){f='0'; cout<<"Nie masz wymaganej kwoty\n"<<endl;}
    else if(f=='4'&&b[c]!=b[d]){f='0'; cout<<"Karty nie sa identyczne\n"<<endl;}
    else if(f=='5'&&b[e]!='A')
        {
            f='0';cout<<"\nNie mozesz uzyc tej opcji krupier nie ma wymaganej karty\n"<<endl;
        }
    else if(f=='5'&&kasa<stawka+stawka/2){f='0';cout<<"\nNie mozesz uzyc tej opcji nie masz wymaganej kwoty do wykonania tego ruchu\n"<<endl;}
    else if(f=='5')
    {
         do
          {
           cout<<"\nStawiasz dodatkowa stawke?: 1.TAK 2.NIE: "<<endl;
           k=getch();
          }while(k>'2'||k<'1');
    }
    }while(f=='0'||f<'1'||f>'5'||k!='1');

    switch(f)
    {
    case '1':
      sumagr=gracz(sumagr, h, kolory_kart);
      if(sumagr<=21)sumakr=krupier(sumakr, h, kolory_kart);
       else cout<<"Przykro mi masz wiecej niz 21 punktow!\n"<<endl;
        break;

    case '2':
        sumakr=krupier(sumakr, h, kolory_kart);
        break;

    case '3':
            stawka*=2;
            int j;
            j=rand()%13;
            if(j==12&&h[j]+sumagr>21)sumagr++;
            else
            sumagr+=h[j];
            cout<<"\nGracz wylosowal karte "<<b[j]<<kolory_kart.back()<<"\nSuma gracza "<<sumagr<<"\n"<<endl;
            kolory_kart.pop_back();
            if(sumagr<=21)sumakr=krupier(sumakr, h, kolory_kart);
             else cout<<"Przykro mi masz wiecej niz 21 punktow!\n"<<endl;
        break;

    case '4':
        cout<<"Dobieranie do 1 karty:\n"<<endl;
        sumagr-=h[c];
        sumagr2=sumagr;
        sumagr=gracz(sumagr, h, kolory_kart);
        cout<<"Dobieranie do 2 karty:\n"<<endl;
        sumagr2=gracz(sumagr2, h, kolory_kart);
        sumakr=krupier(sumakr, h, kolory_kart);
       break;

    case '5':
            stawka+=stawka/2;
            int p;
            p=rand()%13;
            if(h[p]==10)cout<<"Ubezpieczenie wraca do Ciebie\n"<<endl;
            else
            {kasa-=stawka; cout<<"Tracisz ubezpieczenie z suma podstawowa krupier nie mial karty o wartosci 10\n"<<endl;}
            break;

        }

    }
    else
    {
    cout<<"NIE MASZ WYSTARCZAJACEJ KWOTY \nKONIEC GRY" << endl;
    if(kasa>=10)
    {
        cout<<"Sprobuj jeszcze raz\n"<<endl;
        f='5';
    }
     else
    {
      Sleep(1000);
      main2();
    }
    }
    if(f!='5')
    {
    cout << "WYNIKI" << endl;
    cout << "suma gracza " << sumagr << " suma krupiera " << sumakr << endl;
    if(sumakr<=21&&sumakr>sumagr||sumakr<=21&&sumagr>21)
    {
        cout<<"Przegrales"<<endl;
        kasa-=stawka;
    }
    else if(sumagr<=21&&sumagr>sumakr||sumagr<=21&&sumakr>21)
    {
        cout<<"Wygrales"<<endl;
        kasa+=stawka;
    }
    else
    {
        cout << "Remis" << endl;
    }
    }
    if(f=='4')
    {
    cout << "\nWYNIKI 2" << endl;
    cout << "duga suma gracza " << sumagr2 << " druga suma krupiera " << sumakr << endl;
    if(sumakr<=21&&sumakr>sumagr2||sumakr<=21&&sumagr2>21)
    {
        cout<<"Przegrales"<<endl;
        kasa-=stawka;
    }
    else if(sumagr2<=21&&sumagr2>sumakr||sumagr2<=21&&sumakr>21)
    {
        cout<<"Wygrales"<<endl;
        kasa+=stawka;
    }
    else
    {
        cout << "Remis" << endl;
    }
    }


    cout << "Twoja kwota: " << kasa << " zl" << endl;
    cout << "Grasz dalej? T|N: " << endl;
    ok=getch();
    if(ok=='N'||ok=='n'){system("cls"); main2();}
    }while(ok=='T'||ok=='t');
    cout<<endl;
    cout<<"KONIEC"<<endl;

}
void reguly()
{
    char a;
    system("color 17");
    cout << " **************************      1.Zasady      **************************" << endl;
    cout<<"Blackjack kasynowa gra karciana, w ktorej gracz stara sie pokonac krupiera \n"
        <<"poprzez uzyskanie sumy jak najblizszej "
        <<"21 punktow w kartach jednak nie \nprzekraczajac 21. "
        <<"Najwyzszym ukladem kart jest tzw. "
        <<"Blackjack, czyli as i \n "
        <<"10 lub figura, za ktory gracz dostaje 150% zakladu (np. 15 zl za 10 zl).\n\n"
        <<"Punktacja kart w blackjacku\n"
        <<"Karty 2 do 9 maja wartosc rowna wartosci karty (3 karo ma wartosc 3 itd)."
        <<"10, \nWalet, Dama i Krol maja wartosc rowna 10 punktow."
        <<" As ma wartosc rowna 1 lub \n"
        <<"11, w zaleznosci, co jest lepsze dla gracza. \n \n"
        <<"RUCHY:\n"
        <<"W Blackjacka gra sie przeciwko krupierowi. \nGracz stawia zaklad na specjalnym stole uzywajac zetonow.\n"
        <<"Nastepnie gracz i krupier dostaja po dwie karty.\n"
        <<"Obydwie karty gracza sa odkryte, natomiast tylko jedna karta\nkrupiera jest pokazana graczowi.\n"
        <<"Gracz teraz moze podjac decyzje o swoim nastepnym ruchu. Gracz \nma nastepujace mozliwosci:\n"
        <<"Dobrac karte (hit).\n"
        <<"Nie dobierac kart (stand).\n"
        <<"Podwoic stawke (double down), mozliwe tylko przy pierwszych dwoch kartach, \ngracz wtedy dostanie tylko jedna karte.\n"
        <<"Rozdwoic karty (split), gdy dwie pierwsze karty gracza sa tej \nsamej wartosci np. dwie osemki. Gracz wtedy doklada druga stawke \n"
        <<"(rowna wartosci pierwszej stawki)\ni moze dobierac karty po rozdwojeniu.\n"
        <<"Ubezpieczenie (insurance) jest dodatkowa stawka mozliwa tylko, \ngdy odkryta karta krupiera jest as.\n"
        <<"Gracz moze postawic dodatkowa stawke, ze druga (zakryta) karta\nkrupiera jest 10 lub figura (krupier ma Blackjacka).\n"
        <<"Gdy krupier ma blackjacka, gracz przegrywa\nstawke podstawowa, a za ubezpieczenie wygrywa 2 do 1. Poniewaz stawka\n"
        <<"ubezpieczenia jest polowa stawki podstawowej,\n"
        <<"wiec za wygrana gracz otrzymuje \nsume pieniedzy przegranych w stawce podstawowej (stad nazwa ubezpieczenie).\n\n\n"
        <<" ************************** OZNACZENIA **************************\n"
        <<"1.)SYMBOLE: T-dziesiatka J-walet D-dama K-krol\n\n\n"
        <<"2.)KOLORY: C=czerwien W-wino D-dzwonek Z-zoladz\n\n\n"

        <<endl;
        cout<<"KLIKNIJ T jesli chcesz zaczac gre lub N jesli chcesz powrocic do menu glownego"<<endl;
        cout<<"Lub wcisnij inny klawisz aby wyjsc z gry"<<endl;
        a=getch();
        system("cls");
        if(a=='T'||a=='t')nowa_gra();
        else if(a=='N'||a=='n')main2();
        else cout<<"WYJSCIE Z GRY"<<endl;
        Sleep(1000);
        exit(0);


}
void main2()
{
    system("cls");
    system("color 16");
    char los[10]={'~', '-', '+', '>', '<', '#', '@', '$', '&', '*'};
    int l;
    srand(time(NULL));
    int o = 0;
    cout<<" ";
     for(int i = 0; i<149; i++)
    {
        o++;
        if(o==50)
        {
            cout<<endl;
            o=0;
        }
        Sleep(10);
        l=rand()%10;
        cout<<los[l]<<" ";
    }
    char a;
    cout<<"\n\n\n\n\n"<<endl;
    string n="\t******* Witaj w GRZE BlackJack ******** ";
    for(int i = 0; i<n.size(); i++)
    {
        Sleep(10);
        cout<<n[i]<<" ";
    }
    cout<<endl;
    cout << "\t -----------------------------------------------------------------------------" << endl;
    cout<<endl;
    cout << "\t  **************************   Wybierz opcje gry    **************************" << endl;
    cout << "\t  **************************      1.NOWA GRA        **************************" << endl;
    cout << "\t  **************************      2.Reguly          **************************" << endl;
    cout << "\t  **************************      3.Wyjscie         **************************" << endl;
    a=getch();
    switch(a)
    {
    case '1':
        system("cls");
        nowa_gra(); break;
    case '2':
        system("cls");
        reguly(); break;
    case '3':
        cout<<endl;
        cout << "\t\t\t\t\t-WYJSCIE Z GRY-" << endl; exit(0); break;
    default: cout<<"Nic nie wybrano, wiec koncze program" << endl;
    }
}
int main()
{
    main2();
    return 0;
}
