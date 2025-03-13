#ifndef VISIOR_H
#define VISIOR_H

class Media;
class Libro;
class Rivista;
class Film;
class Canzone;
class Album;


// da implementare nelle classi figlie
class Visitor {
public:
    virtual void visit(Libro *libro) = 0;
    virtual void visit(Rivista *rivista) = 0;
    virtual void visit(Film *film) = 0;
    virtual void visit(Canzone *canzone) = 0;
    virtual void visit(Album *album) = 0;
};

#endif // VISIOR_H