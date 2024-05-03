#include <iostream>


class Product{   //   Изделие
    protected:
        char* developer; 
        char* material;
        int weight;
    public: 
        static Product** products; // массив указателей
        static int max_size;
        static int size;
        static int r;

        virtual ~Product(){
            delete[] developer;
            delete[] material;
        }

        Product& operator=(const Product&);

        Product(){}

        virtual void show() = 0;
        
        virtual void add();
        
};

class Knot: public Product{  // Узел
    protected:
        int iznos;
    public: 
        
        void show() override;

        ~Knot(){};

        Knot(char* , char*, int, int);

        Knot& operator=(const Knot&);
        Knot(const Knot&);
};

class Mechanism: public Knot{  // Механизм
    protected:
        int complexity;
    public: 
        void show() override;

        ~Mechanism(){};

        Mechanism(char* , char*, int, int, int);

        Mechanism& operator=(const Mechanism&);
        Mechanism(const Mechanism&);
};

class Detail: public Knot{  // Деталь
    protected:
        char* proveril; 
    public: 
        void show() override;

        ~Detail();

        Detail(char* , char*, int, int, char* );

        Detail& operator=(const Detail& );
        Detail(const Detail&);
};
