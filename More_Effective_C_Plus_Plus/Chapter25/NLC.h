#ifndef _NLC_
    #include <iostream>
    #include <string>
    #include <list>

    class NLComponent
    {
        public:
            NLComponent(){};
            virtual ~NLComponent(){}
            virtual NLComponent* clone() const = 0;
            virtual void disp()const = 0;
    };

    class TextBlock: public NLComponent
    {
        public:
            TextBlock(){}
            ~TextBlock(){}
            void disp()const
            {
                std::cout << "TextBlock\n";
            }
            TextBlock* clone() const
            {
                return new TextBlock(*this);
            }
    };

    class Graphic: public NLComponent
    {
        public:
            Graphic(){}
            ~Graphic(){}
            void disp()const
            {
                std::cout << "Graphic\n";
            }
            Graphic* clone() const
            {
                return new Graphic(*this);
            }
    };

    class NewLetter
    {
        public:
            NewLetter(std::istream& os)
            {
                int num;
                std::cout << "Please input 0,1,2\n" 
                          << "1 : TextBlock\n"
                          << "2 : Graphe\n"
                          << "0 : exit\n";
                while (std::cin >> num)
                {
                    switch (num)
                    {
                    case 0:
                        std::cout << "compelte!";
                        break;
                    case 1:
                        this->components.emplace_back(new TextBlock);
                        break;
                    case 2:
                        this->components.emplace_back(new Graphic);
                        break;
                    default:
                        std::cout << "Input error\n";
                        break;
                    }
                    if( 0 == num)
                        break;
                }
            }
            void disp()
            {
                for (auto &it : this->components)
                {
                    it->disp();
                }
            }
            ~NewLetter()
            {
                for (auto &it : this->components)
                {
                    delete it;
                }
                this->components.clear();
            }
        private:
            std::list<NLComponent*> components;
    };

#endif