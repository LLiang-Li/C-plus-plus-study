#ifndef _PICTURE_H_

#define _PICTURE_H_

#include <iostream>
#include <cstring>

class P_Node;

class Picture
{
    public:
        Picture(){};
        Picture(const char* const *,int);
        Picture(const Picture &);
        
        ~Picture();
        Picture & operator=(const Picture&);
        //static int max(int m, int n);
    private:
        P_Node *p;
        Picture(P_Node *);
        int height() const;
        int width() const;
        void display(std::ostream&, int, int) const;
        // int height, width;
        // char *data;
        // char & position(int row, int col);
        // char position(int row,int col)const;
        // void init(int h, int w);
        // void clear(int, int, int, int);
        // void copyblock(int, int, const Picture &);
        friend std::ostream& operator<<(std::ostream &, const Picture &);
        friend Picture frame(const Picture&);
        friend Picture operator&(const Picture&, const Picture &);
        friend Picture operator|(const Picture&, const Picture &);
        friend class String_Pic;
        friend class Frame_Pic;
        friend class Vcat_Pic;
        friend class Hcat_Pic;
};  

class P_Node
{
    friend class Picture;
public:
    int max(int x, int y);
    int max(int x, int y)const;
protected:
    
    virtual int height() const = 0;
    virtual int width() const = 0;
    virtual void display(std::ostream&, int, int) const = 0;
    ~P_Node();
private:
    int use;
};

class String_Pic: public P_Node
{
    friend class Picture;
    String_Pic(const char *const *, int);
    int height() const;
    int width() const;
    void display(std::ostream&, int, int) const;
    ~String_Pic();
    char** data;
    int size;
};

class Frame_Pic: public P_Node
{
    friend Picture frame(const Picture&);
    Frame_Pic(const Picture&);
    int height() const;
    int width() const;
    void display(std::ostream&, int, int) const;
    Picture p;
};

class Vcat_Pic: public P_Node
{
    friend Picture operator&(const Picture&, const Picture &);
    Vcat_Pic(const Picture&, const Picture&);
    int height() const;
    int width() const;
    void display(std::ostream&, int, int) const;
    Picture top, bottom;
};

class Hcat_Pic: public P_Node
{
    friend Picture operator|(const Picture&, const Picture &);
    Hcat_Pic(const Picture&, const Picture&);
    int height() const;
    int width() const;
    void display(std::ostream&, int, int) const;
    Picture left, right;
};


#endif