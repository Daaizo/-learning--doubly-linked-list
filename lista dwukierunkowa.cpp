#include <iostream>
#include "time.h"
using namespace std;

struct element
{
    int value;
    element *next;
    element *prev;
};

struct double_list
{
    element *tail;
    element *head;
};

void add_tail(double_list &, int );
void add_head(double_list &, int );
void add_at_position(double_list &, int ,int ); // numerowanie od 1

void delete_head(double_list &);
void delete_tail(double_list &);
void delete_at_position(double_list &, int);

bool is_Empty(double_list );
void print_list_backwards(double_list);
void print_list(double_list);

int main()
{
    double_list List;
    List.head = nullptr;
    List.tail = nullptr; // warunek stopu !
    srand(time(NULL));
    int choice = 1;
    while(choice != 15)
    {

        cout << " \n\n MENU \n1.sprawdzenie czy lista jest pusta\n2.dodanie elementu na koniec listy\n3.dodanie elementu na poczatek listy"<<
                "\n4.dodanie elementu na okreslona pozycje\n5.usuniecie elementu z konca listy\n6.usuniecie elementu z poczatku listy," <<
                "\n7.usuniecie elementu znajdujacego sie na okreslonej pozycji\n8.wyswietlenie calej listy" <<
                "\n9.wyswietlenie listy w odwrotnej kolejnosci\n10.usuwanie calej listy\n15.wyjscie\n";
             //   cout << "\n aktualna ilosc elementow to : " << l.counter << endl<<endl;
        cin >> choice;
        system("cls");
        srand(time(NULL));
        switch(choice)
        {
            case 1:
            {
                cout << (is_Empty(List) ? "lista jest pusta" : "lista nie jest pusta" );
                break;
            }
            case 2 :
            {

                int number = rand()%(50)+1;
                add_tail(List, number);
                cout << "na koniec listy dodano liczbe " << number;
                break;
            }
            case 3 :
            {

                int number = rand()%(50)+1;
                add_head(List, number);
                cout << "na poczatek list dodano liczbe " << number;
                break;
            }
            case 4:
            {
                int pos;
                cout << "Podaj pozycje na ktora ma zostac dodana liczba \n jesli podana liczba bedzie wieksza niz aktualny rozmiar listy liczba zostanie dodana na koniec ";
                cin >> pos;

                int number = rand()%(50)+1;
                add_at_position(List, number, pos);
                cout << " pomyslanie dodano liczbe " << number;
                break;
            }
            case 5:
            {
                delete_tail(List);
                break;
            }
            case 6:
            {
                delete_head(List);
                break;
            }
            case 7:
            {
                int pos;
                cout << "Podaj pozycje z ktorej ma zostac usunieta liczba\nW przypadku podania liczby wiekszej niz ilosc elementow zostanie usuniety ostatni element\n";
                cin >> pos;
                delete_at_position(List, pos);


                break;
            }

            case 8:
            {
                print_list(List);
                break;
            }
            case 9:
            {
                print_list_backwards(List);
                break;
            }
            case 10:
            {
                while(is_Empty(List) == false )
                {

                    delete_head(List);

                }

                break;
            }
            case 15:
                {

                    exit(1);
                }
            default:
                {
                    cout << "wprowadzono zly numer sporboj ponownie" ;break;
                }


        }



    }

    return 0 ;
}

void add_tail(double_list &List, int value_too_add)
{
    if(is_Empty(List) == true) // niepotrzebne ale mocno poprawa widocznoscie
    {
        element *el = new element;
        el->next = nullptr;
        el->prev = nullptr;
        el->value = value_too_add;
        List.head = el;
        List.tail = el;
    }
    else
    {

        element *el = List.tail;
        element *temp = new element;
        temp->value = value_too_add;
        temp->next = nullptr;
        temp->prev = el;
        el->next = temp;
        List.tail = temp;

    }
}
bool is_Empty(double_list List)
{
    return !List.tail;
}
void print_list_backwards(double_list List)
{

    cout << "\nlist printed backwards:\n";
    element *temp = List.tail;
    while(temp->prev != nullptr) // niepotrzebne ale mocno poprawa widocznosc
    {
        cout <<  temp->value <<  " " ;
        temp = temp->prev;


    }
    cout <<  temp->value <<  " " << endl;

}
void print_list(double_list List)
{
    cout << "\nlist :\n";
    element *temp = List.head;
    if(is_Empty(List) == false)
    {
        while(temp->next != nullptr) // niepotrzebne ale mocno poprawa widocznosc
        {
            cout <<  temp->value <<  " " ;
            temp = temp->next;
        }
        cout <<  temp->value <<  " " << endl;
    }
    else cout << " ";

}
void add_at_position(double_list &List, int value_too_add ,int position )
{

    if(is_Empty(List) == false)
    {
        int i = 1 ;
        element *temp = List.head;
        if(position <= 0 || position == 1)
        {
            add_head(List, value_too_add);
            i = position + 1;
        }
        while(i <= position )
        {

            if(i ==  position)
            {

                element *before = temp->prev;
                element *el = new element;
                el->value = value_too_add;
                el->next = temp;
                el->prev = before;
                temp->prev = el;
                before->next = el;
            }
            else if(temp->next == nullptr)
            {
                add_tail(List, value_too_add);
                break;
            }
            temp = temp->next;
            i++;
        }
    }
    else add_head(List , value_too_add);
}
void add_head(double_list &List, int value_too_add)
{
    if(is_Empty(List) == true) // niepotrzebne ale mocno poprawa widocznoscie
    {
        element *el = new element;
        el->next = nullptr;
        el->prev = nullptr;
        el->value = value_too_add;
        List.head = el;
        List.tail = el;
    }
    else
    {
        element *el = List.head;
        element *temp = new element;
        temp->value = value_too_add;
        temp->prev = nullptr;
        temp->next = el;
        el->prev = temp;
        List.head = temp;


    }
}
void delete_head(double_list &List)
{
    if(is_Empty(List) == false)
    {
        List.head = List.head->next;
        if(List.head == nullptr) List.tail = nullptr;
        cout << " pomyslnie usunieto pierwszy element \n";

    }
    else
    {
        cout << "\nlista jest juz pusta\n";
    }
 }
void delete_tail(double_list &List)
{
    if(is_Empty(List) == false)
    {

        List.tail = List.tail->prev;

        if(List.tail == nullptr) List.head = nullptr;
        else  List.tail->next = nullptr;
        cout << " pomyslnie usunieto ostatni element\n";
    }
    else
    {
        cout << "\nlista jest juz pusta\n";
    }

}
void delete_at_position(double_list &List, int position)
{
    if(is_Empty(List) == false)
    {
        int i = 1 ;
        element *temp = List.head;
        if(position <= 0 || position == 1)
        {
            delete_head(List);
            i = position + 1;
        }
        while(i <= position )
        {
            if(temp->next == nullptr)
            {
                delete_tail(List);
                break;
            }
            else if(i ==  position)
            {
                element *n = temp->next;
                element *p = temp->prev;
                n->prev = p ;
                p->next = n;
            }

            temp = temp->next;
            i++;
        }

    }
    else cout << "lista jest pusta" ;

}
