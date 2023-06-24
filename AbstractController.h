#ifndef Asdas_h
#define Asdas_h

class AbstractController
{
protected:

public:
    AbstractController()=default;
    virtual int move() = 0;
    virtual ~AbstractController();
};

#endif
