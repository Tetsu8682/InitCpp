#ifndef SEANCE3_HPP
    #define SEANCE3_HPP

class Point{
    public:
        Point();
        Point(float x, float y);
        float getX(void) const;
        float getY(void) const;
        void setX(float nouveauX);
        void setY(float nouveauY);
        void affichage(void) const;
        bool egalite(Point p2) const;
        float distance(Point p2) const;
    private:
        float x;
        float y;
};

class Segment{
    public:
        Segment(Point p1, Point p2);
        void affichage(void) const;
        void translation(Point new_origine);
        float longueur(void) const;
    private:
        Point origine;
        Point extremite;
};

class Polygone{
    public:
        Polygone(int nbPoint, Point tab_point[]);
        Polygone(int nbPoint);
        ~Polygone();
        void affichage() const;
        float perimetre(void) const;
        Polygone enveloppeConvexe(void) const;
    private:
        int nbPointExtreme;
        Point* tab;
};
#endif