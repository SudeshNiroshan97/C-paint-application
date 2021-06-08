
#ifndef CANEVAS
#define CANEVAS
#include <QtWidgets>
#include <FenPrincipale.h>



class Pile{
public:
    Pile(int a,int b) : x(a),y(b) {}
    ~Pile();
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

private:
    int x;
    int y;
};

class Canevas : public QWidget
{
 Q_OBJECT

public :

    Canevas(FenPrincipale *p);
    //~Canevas();

    void draw();
    void drawRectangle();
    void drawProvisoirRectangle();
    void drawCercle();
    void drawProvisoirCercle();
    void drawTrait();
    void drawProvisoirTrait();
    void remplir();
    int remplissage4(int x,int y,QRgb colcible, QRgb colrep);

    void paintEvent(QPaintEvent* event);

    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
public slots:
    void nouveauCanevas();
    void sauvegarderCanevas();
    void ouvrirCanevas();
    void retourCanevas();

private :

    int xMove;
    int yMove;
    int xPress;
    int yPress;
    int xRelease;
    int yRelease;

    int pixActuel;
    int xMax;
    int yMax;

    QPainter *painter;
    QLabel *label;
    FenPrincipale *pere;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QImage *image;
    QVector<QPixmap*> pixmapListe;
    QPainterPath *path;
};

#endif
