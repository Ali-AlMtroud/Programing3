#include <iostream>
#include <string.h>
#include <fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

#define printer1()  std::cout<<"year "<<"id  "<<"name_company  "<<"speed  "<<"property  "<<"type_of_transport   "<<"num_of_engines  "<<"length  "<<"num_sets   "<<"maximum_weight\n\n";
#define printer2()  std::cout<<"year "<<"id  "<<"name_company  "<<"speed  "<<"property  "<<"type_of_transport  "<<"num_of_engines  "<<"length  "<<"empty_weight  "<<"maximum_weight\n\n";
#define printer3()  std::cout<<"year "<<"id  "<<"name_company  "<<"speed  "<<"property  "<<"type_of_transport  "<<"wide_of_engine  "<<"length  "<<"num_sets  "<<"maximum_weight\n\n";
#define printer4()  std::cout<<"year "<<"id  "<<"name_company  "<<"speed  "<<"property  "<<"type_of_transport  "<<"wide_of_engine  "<<"length  "<<"num_gets  "<<"maximum_weight\n\n";
#define printer5()  std::cout<<"year "<<"id  "<<"name_company  "<<"speed  "<<"property  "<<"type_of_transport  "<<"wide_of_engine  "<<"length  "<<"empty_weight  "<<"maximum_weight  "<<"height\n\n";
#define printer6()  std::cout<<"year "<<"num_journey "<<"number_transport "<<"type_of_transport "<<"source "<<"goal "<<"weight\t"<<"total_weight "<<"warning\t\n"<<"reservation case\tweight\n\n";
int id_journy();
int id_transport();
static int i =id_transport() ;
static int mah =id_journy();
class date
{
    int d, m, y;
public:
    date()
    {
        this->d = 0;
        this->m = 0;
        this->y = 0;
    }
    date(int d, int m, int y)
    {
        this->d = d;
        this->m = m;
        this->y = y;
    }
    void input_date()
    {
        do
        {
            std::cout << "year:\n";
            std::cin >> this->y;
            fflush(stdin);
        }
        while ((this->y) < 2019);
        do
        {
            std::cout << "\nmonth:\n";
            std::cin >> this->m;
            fflush(stdin);
        }
        while ((this->m <= 0) || (this->m > 12));
        if ((this->m == 1) || (this->m == 3) || (this->m == 5) || (this->m == 7) || (this->m == 8) || (this->m == 10) || (this->m == 12))
        {
            do
            {
                std::cout << "\nday:\n";
                std::cin >> this->d;
                fflush(stdin);
            }
            while ((this->d <= 0) || (this->d > 31));
        }
        else if ((this->m == 2) && (this->y % 4 == 0))
        {
            do
            {
                std::cout << "\nday:\n";
                std::cin >> this->d;
                fflush(stdin);
            }
            while ((this->d <= 0) || (this->d > 29));
        }
        else if ((this->m == 2) && ((this->y) % 4 != 0))
        {
            do
            {
                std::cout << "\nday:\n";
                std::cin >> this->d;
                fflush(stdin);
            }
            while ((this->d <= 0) || (this->d > 28));
        }
        else
        {
            do
            {
                std::cout << "\nday:\n";
                std::cin >> this->d;
                fflush(stdin);
            }
            while ((this->d <= 0) || (this->d > 30));
        }
    }
    void display()
    {
        std::cout << y << "    " << m << "     " << d << "\t";
    }
    date(const date & k)
    {
        this->d = k.d;
        this->m = k.m;
        this->y = k.y;
    }
    int get_d()
    {
        return this->d;
    }
    int get_m()
    {
        return this->m;
    }
    int get_y()
    {
        return this->y;
    }
    int get_date()
    {
        int n;
        n = (this->y * 365) + (this->m * 30) + (this->d);
        return n;
    }
};
class transport
{
protected:
    int num_of_transport;
   char name_company[20];
    int made;
    int speed;
    char property[20];
   char type_of_transport[20];

public:
    transport()
    {
        this->num_of_transport = 0;
        strcpy(this->name_company ,"");
        this->speed = 0;
        strcpy(this->property ,"");
        strcpy(this->type_of_transport,"");
        this->made = 0;
    }

    void input_data()
    {
        int num;

        {

            this->num_of_transport = i + 1;
            i++;
        }

        std::cout << "\nplease,Enter the name of company:\n";
        std::cin >> this->name_company;
        do
        {
            std::cout << "\nEnter the made histoy:";
            cin >> this->made;
        }
        while (this->made > 2018);
        do
        {
            std::cout << "please,Enter the speed of transport:\n";
            std::cin >> this->speed;
        }
        while (this->speed < 0 && this->speed>220);
        do
        {
            std::cout << "please,Enter 1 if the property for you and 2 if the property for all and 3 if the property for government:\n";
            std::cin >> num;
            if (num == 1)
                strcpy(this->property,"for_me");
            else if (num == 2)
                strcpy(this->property,"for_all");
            else if (num == 3)
                strcpy(this->property,"for_government");
        }
        while (num > 3 || num <= 0);
        do
        {
            std::cout << "please,Enter 1 if the type of transport for tranz and 2 if the type of transport for passenger:\n";
            std::cin >> num;
            if (num == 1)
                strcpy(this->type_of_transport,"tranz");
            else if (num == 2)
                strcpy(this->type_of_transport ,"passenger");
        }
        while (num > 2 || num <= 0);
    }
    virtual void get_name() = 0;
    virtual bool warning() = 0;
    virtual void display() = 0;
    virtual string get_type()=0;
    void displayy()
    {
        std::cout << this->made << "\t";
        std::cout << this->num_of_transport << "\t";
        std::cout << this->name_company << "\t";
        std::cout << "  " << this->speed << "\t";
        std::cout << " " << this->property << "\t";
        std::cout << "    " << this->type_of_transport << "\t";

    }

};
class aerial_transports :public transport
{
protected:
    int num_of_engines;
    int length;
public:
    aerial_transports() :transport()
    {
        this->num_of_engines = 0;
        this->length = 0;
    }

    void input_data_aerial()
    {
        transport::input_data();
        do
        {
            std::cout << "please,Enter the number of engines:\n";
            std::cin >> this->num_of_engines;
        }
        while (this->num_of_engines < 0);
        do
        {
            std::cout << "please,Enter the length:\n";
            std::cin >> this->length;
        }
        while (this->length < 0);
    }
    void get_name()
    {
    }
    bool warning()
    {
        return true;
    }
    void display()
    {
        transport::displayy();
        std::cout << "      " << this->num_of_engines << "\t";
        std::cout << "  " << "  " << "  " << this->length << "\t";

    }
};
class tranz_plane :public aerial_transports
{
protected:
    int empty_weight;
    int maximum_weight;

public:
    tranz_plane() :aerial_transports()
    {
        this->empty_weight = 0;
        this->maximum_weight = 0;
    }
    void input_data_tranz_plane()
    {
        aerial_transports::input_data_aerial();
        do
        {
            std::cout << "please,Enter the weight of the empty plane:\n";
            std::cin >> this->empty_weight;
        }
        while (this->empty_weight < 0);
        do
        {
            std::cout << "please,Enter the maximum weight of the plane:\n";
            std::cin >> this->maximum_weight;
        }
        while (this->maximum_weight < 0);
    }
    bool warning(int weight)
    {
        if (this->maximum_weight < (this->empty_weight + weight))
        {
            return true;
        }
        return false;
    }
    void get_name()
    {
        std::cout << "\nthe type of transports is aerial_transport for tranz\n";
    }
    string get_type()
    {
        return "tranz_plane";
    }
    int get_max_weight()
    {
        return this->maximum_weight;
    }
    void display()
    {
        aerial_transports::display();
        std::cout << "  " << "  " << "  " << "  " << this->empty_weight << "\t";
        std::cout << "  " << "  " << "  " << "  " << this->maximum_weight << "\n";

    }
    int get_number()
    {
        return this->num_of_transport;
    }
    string get_type_of_transport()
    {
        return this->type_of_transport;
    }

    int get_empty_weight()
    {
        return this->empty_weight;
    }
};
class passengers_plane :public aerial_transports
{
protected:
    int num_sets;
    int maximum_bag_weight;

public:
    passengers_plane() :aerial_transports()
    {
        this->num_sets = 0;
        this->maximum_bag_weight = 25;
    }
    void input_data_passengers_plane()
    {
        aerial_transports::input_data_aerial();
        do
        {
            std::cout << "please,Enter the number of the sets:\n";
            std::cin >> this->num_sets;
        }
        while (this->num_sets < 0);
    }
    void get_name()
    {
        std::cout << "\nthe type of transports is aerial_transport for passengers:\n";
    }
    bool warning(int weight)
    {
        if (weight > this->maximum_bag_weight)
        {
            return true;
        }
        return false;
    }
    void display()
    {
        aerial_transports::display();
        std::cout << "  " << "  " << "  " << "  " << this->num_sets << "\t";
        std::cout << "  " << "  " << "  " << "  " << this->maximum_bag_weight << "\n";

    }
    string get_type()
    {
        return "passenger_plane";
    }
    int get_number()
    {
        return this->num_of_transport;
    }
    string get_type_of_transport()
    {
        return this->type_of_transport;
    }

};
class wilderness_transports :public transport
{
protected:
    int wide_of_engine;
    int length;
public:
    wilderness_transports() :transport()
    {
        this->wide_of_engine = 0;
        this->length = 0;
    }
    void input_data_wilderness()
    {
        transport::input_data();
        do
        {
            std::cout << "please,Enter the wide of engine:\n";
            std::cin >> this->wide_of_engine;
        }
        while (this->wide_of_engine < 0);
        do
        {
            std::cout << "please,Enter the length:\n";
            std::cin >> this->length;
        }
        while (this->length < 0);
        this->warning();
    }
    bool warning()
    {
        return true;
    }
    void get_name()
    {

    }
    void display()
    {
        transport::displayy();
        std::cout << "   " << "   " << this->wide_of_engine << "\t";
        std::cout << "  " << "  " << "  " << this->length << "\t";

    }
};
class bus :public wilderness_transports
{
protected:
    int num_sets;
    int maximum_bag_weight;

public:
    bus() :wilderness_transports()
    {
        this->num_sets = 0;
        this->maximum_bag_weight = 25;
    }
    void input_data_bus()
    {
        wilderness_transports::input_data_wilderness();
        do
        {
            std::cout << "please,Enter the number of the sets in bus:\n";
            std::cin >> this->num_sets;
        }
        while (this->num_sets < 0);
    }
    bool warning(int weight)
    {
        if (weight > this->maximum_bag_weight)
        {
            return true;
        }
        return false;
    }
    void get_name()
    {
        std::cout << "\nthe type of transports is wilderness_transport <bus>\n";
    }
    void display()
    {
        wilderness_transports::display();
        std::cout << "  " << "  " << "  " << "  " << this->num_sets << "\t";
        std::cout << "  " << "  " << "  " << "  " << this->maximum_bag_weight << endl;

    }
    string get_type()
    {
        return "bus";
    }
    int get_number()
    {
        return this->num_of_transport;
    }
    string get_type_of_transport()
    {
        return this->type_of_transport;
    }

};
class car :public wilderness_transports
{
protected:
    int num_gets;
    int maximum_bag_weight;

public:
    car() :wilderness_transports()
    {
        this->num_gets = 0;
        this->maximum_bag_weight = 25;
    }
    void input_data_car()
    {
        wilderness_transports::input_data_wilderness();
        do
        {
            std::cout << "please,Enter the number of the gets in car:\n";
            std::cin >> this->num_gets;
        }
        while (this->num_gets < 0);
    }
    bool warning(int weight)
    {
        if (weight > this->maximum_bag_weight)
        {
            return true;
        }
        return false;
    }
    void get_name()
    {
        std::cout << "\nthe type of transports is wilderness_transport <car>\n";
    }
    void display()
    {
        wilderness_transports::display();
        std::cout << "  " << "  " << "  " << "  " << this->num_gets << "\t";
        std::cout << "  " << "  " << "  " << "  " << this->maximum_bag_weight << "\n";

    }
    string get_type()
    {
        return "car";
    }
    int get_number()
    {
        return this->num_of_transport;
    }
    string get_type_of_transport()
    {
        return this->type_of_transport;
    }

};
class tranz_track :public wilderness_transports
{
protected:
    int empty_weight;
    int maximum_weight;
    int height;

public:
    tranz_track() :wilderness_transports()
    {
        this->empty_weight = 0;
        this->maximum_weight = 0;
        this->height = 0;
    }
    void input_data_track()
    {
        wilderness_transports::input_data_wilderness();
        do
        {
            std::cout << "please,Enter the weight of the empty track:\n";
            std::cin >> this->empty_weight;
        }
        while (this->empty_weight < 0);
        do
        {
            std::cout << "please,Enter the maximum weight of the track:\n";
            std::cin >> this->maximum_weight;
        }
        while (this->maximum_weight < 0);
        do
        {
            std::cout << "please,Enter the height that you wish to insert it to the track:\n";
            std::cin >> this->height;
        }
        while (this->height < 0);
    }
    bool warning(int weight)
    {
        if (this->maximum_weight < (this->empty_weight + weight))
        {
            return true;
        }
        return false;
    }
    int get_max_weight()
    {
        return this->maximum_weight;
    }
    void get_name()
    {
        std::cout << "\nthe type of transports is wilderness_transport for tranz <track>\n";
    }
    void display()
    {
        wilderness_transports::display();
        std::cout << "  " << "  " << "  " << "  " << this->empty_weight << "\t";
        std::cout << "  " << "  " << "  " << "  " << this->maximum_weight << "\t";
        std::cout << "  " << "  " << "  " << "  " << this->height << endl;

    }
    string get_type()
    {
        return "track";
    }
    int get_number()
    {
        return this->num_of_transport;
    }
    int get_empty_weight()
    {
        return this->empty_weight;
    }
    string get_type_of_transport()
    {
        return this->type_of_transport;
    }

};
bool file_is_ok(fstream & name)
{
    if (name.is_open())
    {
        return true;
    }
    else{
    std::cout << "I can't open this file\n";
    exit(1);}
}
string get_kind(int);
class helper
{
private :
    char sign_helper;
public:
    helper()
    {
        this->sign_helper = ' ';
    }
    helper(char sign_helper)
    {
        this->sign_helper = sign_helper;
    }
    char get_sign_helper()
    {
        return this->sign_helper;

    }

};
template <class T>
class linked_list
{
protected:
    struct node
    {
        T item;
        node* next=NULL;
    } ;

    node* head;
public:
    linked_list()
    {
        head = NULL;

    }
    void insert_object(T x, char g)
    {
        node* temp = new (node);
        if (head == NULL)
        {
            temp->item = x;
            temp->next = NULL;
            head = temp;
        }
        else
        {
            temp->item = x;
            temp->next = head;
            head = temp;
        }
        //T f;

        fstream file;
        fstream helper_file;

        helper o(g);
        if (g !='j' )
        {
            helper_file.open("temp.dat", ios::binary | ios::app);

            file.open("transport.dat", ios::binary | ios::app);
            if (file_is_ok(file)&& file_is_ok(helper_file))
            {
                helper_file.write((char*)& o, sizeof(helper));
                file.write((char*)& x, sizeof(x));

                file.close();
                helper_file.close();
            }
        }
        else
        {
            file.open("journey.dat", ios::binary | ios::app);

            if (file_is_ok(file))
            {

                file.write((char*)&x, sizeof(x));
                file.close();
            }

        }





    }
    bool list_is_empty()
    {
        if (head == NULL)
            return true;
        return false;
    }
    void print()
    {
        node* temp = head;
        while (temp != NULL)
        {
            temp->item.display();
            temp = temp->next;
        }
    }
    bool search_id(int id)
    {
        node* temp = head;

        while (temp != NULL)
        {
            if (temp->item.get_number() == id)
            {
                std::cout << "the transport is found ^_^\n";
                temp->item.get_name();
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    T search_idd(int idd)
    {
        node* temp = head;

        while (temp != NULL)
        {
            if (temp->item.get_number() == idd)
            {
                return temp->item;

            }
            temp = temp->next;
        }
        T q;
        return q ;
    }
    void search_so_go()
    {
        node* temp = head;
        string sourcee;
        string goall;
        string name_transport;
        int transport_wanted;
        std::cout << "enter the name of transport which you want print number of it journyes:\nplease,Enter the num of transport for input informations of transport:\n<1-passenger_plane || 2-tranz_plane || 3-bus || 4-car || 5-track> \n ";
        std::cin >> transport_wanted;
        if (transport_wanted == 1)
        {
            name_transport ="passenger_plane";
        }
        else if (transport_wanted == 2)
        {
            name_transport = "tranz_plane";
        }
        else if (transport_wanted == 3)
        {
            name_transport = "bus";
        }
        else if (transport_wanted == 4)
        {
            name_transport = "car";
        }
        else if (transport_wanted == 5)
        {
            name_transport = "track";
        }
        std::cout << "please,Enter the source city:\n";
        std::cin >> sourcee;
        std::cout << "please,Enter the goal city:\n";
        std::cin >> goall;
        std::cout << "id of journeys which leaved of " << sourcee << " to " << goall << " is:";
        string s;
        cout << "{\t";
        while (temp != NULL)
        {
            s = get_kind(transport_wanted);

            if ((temp->item.get_kind_transport_at_journey()==name_transport) &&( (temp->item.get_source() == sourcee) && (temp->item.get_goal() == goall)))
            {
                std::cout << temp->item.get_num_journey() << "\t";

            }
            temp = temp->next;
        }
        cout << "\t}";
        system("pause");
    }
    void sum_passenger()
    {
        node* temp = head;
        string name_transport;
        int sum = 0;
        int transport_wanted;
        std::cout << "enter the name of transport which you want travel by it:\n<1-passenger_plane || 3-bus || 4-car > \n ";
        std::cin >> transport_wanted;
        date a;
        a.input_date();
        date b;
        b.input_date();
        if (transport_wanted == 1)
        {
            name_transport = "passenger_plane";
        }
        else if (transport_wanted == 3)
        {
            name_transport = "bus";
        }
        else if (transport_wanted == 4)
        {
            name_transport = "car";
        }
        while (temp != NULL)
        {
            if (temp->item.get_kind_transport_at_journey() == name_transport)
            {
                if ((a.get_date() <= temp->item.get_travel().get_date()) && (b.get_date() >= temp->item.get_travel().get_date()))
                {
                    sum = sum + temp->item.get_number_real_passenger();
                }
            }
            temp = temp->next;
        }
        std::cout << "the number of passenger from ";
        a.display();
        std::cout << " to ";
        b.display();
        std::cout << " is: < " << sum << " > by " << name_transport << endl;
        system("pause");
    }
    void print_special_transport()
    {
        node* temp = head;
        string name_transport;
        int transport_wanted;
        std::cout << "enter the name of transport which you want print data of it journeys which you travel by special transport:\nplease,Enter the num of transport for input informations of transport:\n<1-passenger_plane ||2-tranz_plane || 3-bus || 4-car || 5-track> \n ";
        std::cin >> transport_wanted;
        if (transport_wanted == 1)
        {
            name_transport = "passenger_plane";
        }
        else if (transport_wanted == 2)
        {
            name_transport = "tranz_plane";
        }
        else if (transport_wanted == 3)
        {
            name_transport = "bus";
        }
        else if (transport_wanted == 4)
        {
            name_transport = "car";
        }
        else if (transport_wanted == 5)
        {
            name_transport = "track";
        }
        while (temp != NULL)
        {

            if (temp->item.get_kind_transport_at_journey() == name_transport)
            {

                temp->item.display();
            }
            temp = temp->next;
        }
        system("pause");
    }
    void insert_object_from_file(T x)
    {

        node* temp = new (node);
        if (head == NULL)
        {
            temp->item = x;
            temp->next = NULL;
            head = temp;

        }
        else
        {
            temp->item = x;
            temp->next = head;
            head = temp;

        }

    }
};
linked_list <passengers_plane>y;
linked_list <tranz_plane>y2;
linked_list <car>y4;
linked_list <bus>y3;
linked_list < tranz_track>y5;

bool found(int id, int d)
{
    if (d == 1)
    {
        if (y.search_id(id))
        {
            return true;
        }
        else if (d==2)
        {
            if (y2.search_id(id))
            {
                return true;
            }
        }
        else if (d==3)
        {
            if (y3.search_id(id))
            {
                return true;
            }
        }
        else if (d==4)
        {
            if (y4.search_id(id))
            {
                return true;
            }
        }
        else if (d==5)
        {
            if (y5.search_id(id))
            {
                return true;
            }
        }
        else
        {
            cout << "this transport not found:\n";
            return false;
        }

    }

}
string return_type_transport(int number_transport, int d)
{
    passengers_plane x1;
    tranz_plane x2;
    bus x3;
    car x4;
    tranz_track x5;

    if (d == 1)
    {
        x1=y.search_idd(number_transport);
        return x1.get_type_of_transport();
    }
    else if (d == 2)
    {
        x2 = y2.search_idd(number_transport);
        return x2.get_type_of_transport();
    }
    else if (d == 3)
    {
        x3 = y3.search_idd(number_transport);
        return x3.get_type_of_transport();
    }
    else if (d == 4)
    {
        x4 = y4.search_idd(number_transport);
        return x4.get_type_of_transport();
    }
    else if (d == 5)
    {
        x5 = y5.search_idd(number_transport);
        return x5.get_type_of_transport();
    }
    else
        return " ";


}
int return_empty_weight_of_transport(int number_transport, int num)
{
    tranz_plane x2;
    tranz_track x5;
    if (num == 2)
    {
        x2 = y2.search_idd(number_transport);
        return x2.get_empty_weight();
    }


    else if (num == 5)
    {
        x5 = y5.search_idd(number_transport);
        return x5.get_empty_weight();
    }
    else
        return 0;

}
int return_maximum_weight_of_transport(int number_transport, int num)
{
    tranz_plane x2;
    tranz_track x5;
    if (num == 2)
    {
        x2 = y2.search_idd(number_transport);
        return x2.get_max_weight();
    }


    else if (num == 5)
    {
        x5 = y5.search_idd(number_transport);
        return x5.get_max_weight();
    }
    else
        return 0;



}
class booking_record
{
   int weight;
    int book;
public:
    booking_record()
    {
        weight=0;
        book=0;
    }
    void set_bookingrecord()
    {
        cout<<"enter the weight of the baggage "<<endl;
        cin>>weight;
        book=1;
    }
    void output()
    {
        cout<<this->weight;
    }
    float get_weight()
    {
        return weight;
    }
    int get_book()
    {
        return book;
    }
};
class journey
{
private:
    int num_journey;
    int number_transport;
    char type_of_transport[20];
    date travel;
   char source[20];
    char goal[20];
    booking_record bo[200];
    int weight;
    int total_weight;
    bool warning_1;
    int number_of_passenger;
int default_weight;
    int num;
    int num_real_passenger;
public:
    journey():travel()
    {
        for(int i=0;i<200;i++)
            bo[i];
            this->default_weight=0;
        this->num_journey = 0;
        this->number_transport = 0;
        strcpy(this->type_of_transport,"");
        strcpy(this->source ,"");
        strcpy(this->goal,"");
        this->weight = 0;
        this->total_weight = 0;
        this->warning_1 = true;
        this->num = 0;
        this->num_real_passenger = 0;
        this->number_of_passenger = 0;


    }

    bool warning(int weight)
    {
        if (num == 1 || num == 3 || num == 4)
        {
            if (this->weight > (25 * this->number_of_passenger))
            {
               return true;
            }

            return false;
        }
        else if (num == 2 || num == 5)
        {
            if (this->total_weight > return_maximum_weight_of_transport(this->number_transport, this->num))
                return true;
            return false;
        }
        else
            return true;



    }
    void input_booking_record()
    {
        this->num_real_passenger = 0;

        if (num == 1 || num == 3)
        {
            std::cout << "please,Enter the number of passengers:\n";
            std::cin >> this->number_of_passenger;
        }
        else if (this->num == 4)
        {
            do
            {
                std::cout << "\nPLEASE,Enter the num of passenger who they can enter in the plane:\n";
                std::cin >> this->number_of_passenger;
            }
            while (this->number_of_passenger < 0 || this->number_of_passenger>5);
        }

        for (int i = 0; i < number_of_passenger; i++)
        {
           this->bo[i].set_bookingrecord();

        }
        this->weight = 0;
        for (int i = 0; i < number_of_passenger; i++)
        {
            this->weight = this->weight + bo[i].get_weight();
        }


        this->warning_1 = warning(this->weight);
         for (int i = 0; i < number_of_passenger; i++)
        {
            if( bo[i].get_book()==1)
            {
                this->num_real_passenger++;
            }
        }
    }
    void input_data_journey()
    {

        bool zz;


        do
        {
            std::cout << "\nplease,Enter the num of transport for input informations of transport:\n<1-passenger_plane || 2-tranz_plane || 3-bus || 4-car || 5-track> \n";
            std::cin >> this->num;
            if (num == 1)
                y.print();
            if (num == 2)
                y2.print();
            if (num == 3)
                y3.print();
            if (num == 4)
                y4.print();
            if (num == 5)
                y5.print();

            std::cout << "please enter the number of transport:\n";
            std::cin >> this->number_transport;
            zz = found(this->number_transport, this->num);



        }
        while (this->num < 0 || this->num>5 || zz == false);

        this->num_journey=mah+1;
        mah++;
        if (this->num == 1 || this->num == 3 || this->num == 4)
        {
            string m=return_type_transport(this->number_transport, this->num);
            int k=m.length();
             char l[20];
             int f=0;
             while(m[f]!='\0')
             {

               l[f]=m[f];
               f++;
             }
            strcpy(this->type_of_transport ,l);

        }
        std::cout << "please,Enter the source city:\n";
        std::cin >> this->source;
        std::cout << "please,Enter the goal city:\n";
        std::cin >> this->goal;
        travel.input_date();
        if (this->num == 1 || this->num == 3 || this->num == 4)
            input_booking_record();
        else if (this->num == 2||this->num==5)
        {
            std::cout << "PLEASE,Enter the weight of goods:\n";
            std::cin >> this->weight;
            this->warning_1 =warning(this->weight);
        }


        if (this->num == 1||this->num==3||this->num==4)
        {
            std::cout << "enter the default empty weight for passenger plane:\n";
            std::cin >> this->default_weight;
            this->total_weight = this->weight + this->default_weight;
        }
        else if (num == 2||this->num==5)
        {
            this->total_weight = this->weight + return_empty_weight_of_transport(this->number_transport, this->num);
        }

    }
    void display()
    {
        travel.display();
        std::cout << this->num_journey << "\t";
        std::cout << this->number_transport << "\t";
        std::cout << this->type_of_transport << "\t";
        std::cout << this->source << "\t";
        std::cout << this->goal << "\t";
        std::cout << this->weight << "\t";
        std::cout << this->total_weight << "\t";
        if (this->warning_1 == true)
        {
            std::cout << "##note:there is a passenger Irregular.\t";
        }
        else
        {
            std::cout << "##note:all passengers are Regular.\t";
        }

        for (int i = 0; i < this->num_real_passenger; i++)
        {

             cout << endl;
                cout<<"the ["<<i+1<<"] passenger had ";
                 bo[i].output() ;
                 cout<<" kg\t";


        }

        std::cout << "\n-----------------------------\n";
    }
    string get_source()
    {
        return this->source;
    }
    string get_goal()
    {
        return this->goal;
    }
    int get_num_journey()
    {
        return this->num_journey;
    }

    int get_number_passenger()
    {
        return this->number_of_passenger;
    }

    date get_travel()
    {
        return this->travel;
    }
    int get_number_real_passenger()
    {
        return this->num_real_passenger;
    }
     string get_type()
     {
      return "";
     }
     string get_kind_transport_at_journey()
{
    string j;
    if (this->num == 1)
    {
        j = "passenger_plane";
        return j;
    }
    else if (this->num == 2)
    {
        j = "tranz_plane";
        return j;
    }
    else if (this->num == 3)
    {
        j = "bus";
        return j;
    }
    else if (this->num == 4)
    {
        j = "car";
        return j;
    }
    else if (this->num == 5)
    {
        j = "track";
        return j;
    }
    else
        return " ";
}


};
linked_list <journey>y6;

string get_kind(int h)
{
    string j;
    if (h == 1)
    {
        j = "passenger_plane";
        return j;
    }
    else if (h == 2)
    {
        j = "tranz_plane";
        return j;
    }
    else if (h == 3)
    {
        j = "bus";
        return j;
    }
    else if (h == 4)
    {
        j = "car";
        return j;
    }
    else if (h == 5)
    {
        j = "track";
        return j;
    }
    else
        return " ";
}
void initialze()
{
    fstream file;
    fstream helper_file;

    helper o;
    file.open("transport.dat", ios::binary | ios::in);
    helper_file.open("temp.dat", ios::binary | ios::in);
    if ((file.is_open()) && (helper_file.is_open()))
    {

        while (helper_file.read((char*)&o,sizeof(helper)))
        {

            if (o.get_sign_helper() == 'c')
            {
                car c;
                file.read((char*)&c, sizeof(car));
                y4.insert_object_from_file(c);

            }
            else if (o.get_sign_helper() == 'u')
            {

                tranz_track u;
                file.read((char*)&u, sizeof(tranz_track));
                y5.insert_object_from_file(u);

            }
            else if (o.get_sign_helper() == 't')
            {
                tranz_plane t;
                file.read((char*)&t, sizeof(tranz_plane));
                y2.insert_object_from_file(t);

            }
            else if (o.get_sign_helper() == 'b')
            {
                bus b;
                file.read((char*)&b, sizeof(bus));
                y3.insert_object_from_file(b);

            }
            else if (o.get_sign_helper() == 'p')
            {
                passengers_plane p;
                file.read((char*)& p, sizeof(passengers_plane));
                y.insert_object_from_file(p);

            }





        }
        file.close();
        helper_file.close();
    }

}
void initialze_journey()
{
    fstream jfile;
    journey b;
    jfile.open("journey.dat", ios::binary | ios::in);


    if((jfile.is_open()))
    {

        while (jfile.read((char*)& b, sizeof(b)))
        {

            y6.insert_object_from_file(b);

        }

        jfile.close();

    }


}
int id_journy()
{
    fstream jfile;
  int x=0;
  journey n;
   jfile.open("journey.dat", ios::binary | ios::in);
   if((jfile.is_open()))
   {
       while(jfile.read((char*)&n,sizeof(journey)))
       {
           x++;
       }
       jfile.close();
       return x;
   }
   return 0;


}
int id_transport()
{
    fstream jfile;
  int y=0;
 helper o;
   jfile.open("temp.dat", ios::binary | ios::in);
   if((jfile.is_open()))
   {
        while (jfile.read((char*)&o,sizeof(helper)))
       {
           y++;
       }
       jfile.close();
       return y;
   }

   return 0;


}
int main()
{

    passengers_plane x1;
    tranz_plane x2;
    bus x3;
    car x4;
    tranz_track x5;
    journey x6;

    std::cout << "\n----\a-----------------^_^----------------------PROGECT----------OF--------PROGRAMING3--------------------\a--^_^------------------------\n";

    char x;
    int m, n, k;
    initialze();
   initialze_journey();


    do
    {

star:

        system("cls");

        std::cout << " press (1) to add object of transport:\n";
        std::cout << " press (2) to search of transport by<id>:\n";
        std::cout << " press (3) to add object of journey\n";
        std::cout << " press (4) to print ids of journeys for special transport between two cities:\n";
        std::cout << " press (5) to calculate number of passenger who travel by special transport through special period of time:\n";
        std::cout << " press (6) to print data of all journeys for special transport:\n";
        std::cout << " press (7) to print objects of transports and journeys from file:\n";

        std::cout << " press (8) to EXIT:\n";

        std::cout << "\n----\a-----------------^_^----------------------WELCOME----------IN--------MY_PROGRAMME-------------------\a--^_^------------------------\n";
        std::cout << " enter your choice:";
        std::cin >> x;
        switch (x)
        {
        case '1':
        {
            system("cls");
            do
            {
                std::cout << "\n press (1) to add object of passenger plane :\n";
                std::cout << " press (2) to add object of tranz plane :\n";
                std::cout << " press (3) to add object of bus:\n";
                std::cout << " press (4) to add object of car:\n";
                std::cout << " press (5) to add object of tranz track:\n";
                std::cout << " press (6) to exit:\n";

                std::cin >> m;
                switch (m)
                {
                case 1:
                {
                    system("cls");
                    x1.input_data_passengers_plane();
                    y.insert_object(x1,'p');
                    break;
                }
                case 2:
                {
                    system("cls");
                    x2.input_data_tranz_plane();
                    y2.insert_object(x2,'t');
                    break;
                }
                case 3:
                {
                    system("cls");
                    x3.input_data_bus();
                    y3.insert_object(x3,'b');
                    break;
                }
                case 4:
                {
                    system("cls");
                    x4.input_data_car();
                    y4.insert_object(x4,'c');
                    break;
                }
                case 5:
                {
                    system("cls");
                    x5.input_data_track();
                    y5.insert_object(x5,'u');
                    break;
                }
                default:
                {
                    system("cls");
                    std::cout << "\n### your choice is wrong ###\n";
                    break;
                }
                case 6:
                    goto star;

                }
            }
            while (1 > 0);
        }





        case '2':
        {
            system("cls");
            do
            {
                std::cout << "\n press (1) to search of passenger plane :\n";
                std::cout << " press (2) to search of tranz plane:\n";
                std::cout << " press (3) to search of bus:\n";
                std::cout << " press (4) to search of car:\n";
                std::cout << " press (5) to search of tranz track:\n";
                std::cout << " press (6) to exit:\n";
                std::cin >> n;
                switch (n)
                {
                case 1:
                {
                    system("cls");
                    int id;
                    cout << "enter id to search it:\n";
                    cin >> id;
                    std::cout << y.search_id(id);
                    break;
                }
                case 2:
                {
                    system("cls");
                    int id;
                    cout << "enter id to search it:\n";
                    cin >> id;
                    std::cout << y2.search_id(id);
                    break;
                }
                case 3:
                {
                    system("cls");
                    int id;
                    cout << "enter id to search it:\n";
                    cin >> id;
                    std::cout << y3.search_id(id);
                    break;

                }
                case 4:
                {
                    system("cls");
                    int id;
                    cout << "enter id to search it:\n";
                    cin >> id;
                    std::cout << y4.search_id(id);
                    break;

                }
                case 5:
                {
                    system("cls");
                    int id;
                    cout << "enter id to search it:\n";
                    cin >> id;
                    std::cout << y5.search_id(id);
                    break;
                }
                default:
                {
                    system("cls");
                    std::cout << "\n### your choice is wrong ###\n";
                    break;
                }
                case 6:
                {
                    goto star;
                }
                }
            }
            while (1 > 0);
        }

        case '3':
        {
            system("cls");
            x6.input_data_journey();
            y6.insert_object(x6, 'j');
            break;
        }
        case '4':
        {
            system("cls");
            y6.search_so_go();
            break;
        }
        case '5':
        {
            system("cls");
            y6.sum_passenger();
            break;
        }
        case '6':
        {
            system("cls");
            printer6();
            y6.print_special_transport();
            break;
        }
        case '7':
        {
            system("cls");
            do
            {
                std::cout << "\n press (1) to print objects of passenger plane from linked list:\n";
                std::cout << " press (2) to print objects of tranz plane from linked list:\n";
                std::cout << " press (3) to print objects of bus from linked list:\n";
                std::cout << " press (4) to print objects of car from linked list:\n";
                std::cout << " press (5) to print objects of tranz track from linked list:\n";
                std::cout << " press (6) to print objects of journey from linked list:\n";
                std::cout << " press (7) to exit:\n";

                std::cin >> k;
                switch (k)
                {
                case 1:
                {
                    system("cls");
                    printer1();

                    y.print();

                    break;
                }
                case 2:
                {
                    system("cls");
                    printer2();
                    y2.print();

                    break;
                }
                case 3:
                {
                    system("cls");
                    printer3();
                    y3.print();
                    break;

                }
                case 4:
                {
                    system("cls");
                    printer4();
                    y4.print();
                    break;

                }
                case 5:
                {
                    system("cls");
                    printer5();
                    y5.print();
                    break;
                }
                case 6:
                {
                    system("cls");
                    printer6();
                    y6.print();
                    break;
                }


                default:
                {
                    system("cls");
                    std::cout << "\n### your choice is wrong ###\n";
                    break;
                }
                case 7:
                {
                    goto star;
                }

                }
            }
            while (1 > 0);

        }


        default:
        {
            system("cls");
            std::cout << "\nwrong choice:\n";
            break;
        }
        case '8':
        {
            exit(1);
            break;
        }
        }
    }
    while (1 > 0);
    return 0;
}

