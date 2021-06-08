#include <Canevas.h>
#include "FenTaille.h"



Canevas::Canevas(FenPrincipale *p) : QWidget()
{
    pere = p;

    xMax = 500;
    yMax = 500;
    label = new QLabel(this);
    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixmapListe.size()-1;
    pixmapListe[pixActuel]->fill();
    painter = new QPainter(pixmapListe[pixActuel]);

    label->setPixmap(*pixmapListe[pixActuel]);
}

void Canevas::paintEvent(QPaintEvent *event)
{


}

//Event souris
void Canevas::mouseMoveEvent(QMouseEvent *event)
{
    if(pere->getDrawEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        draw();


    }
    if(pere->getRectangleEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        drawProvisoirRectangle();
    }
    if(pere->getCercleEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        drawProvisoirCercle();
    }
    if(pere->getTraitEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        drawProvisoirTrait();
    }

}
void Canevas::mousePressEvent(QMouseEvent* event)
{
    if(pere->getRectangleEnable()||pere->getCercleEnable()
            ||pere->getRemplirEnable()||pere->getTraitEnable())
    {
        xPress = event->pos().x();
        yPress = event->pos().y();

    }
    if(pere->getDrawEnable())
    {
        pixmapListe.push_back(new QPixmap(xMax,yMax));
        pixActuel = pixActuel+1;
        pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);
        painter->end();
        delete painter;
        painter = new QPainter(pixmapListe[pixActuel]);
    }
    if(pere->getDrawEnable())
    {
        xPress = event->pos().x();
        yPress = event->pos().y();
        path = new QPainterPath(QPointF(xPress,yPress));
        path->moveTo(xPress,yPress);
    }

}
void Canevas::mouseReleaseEvent(QMouseEvent *event)
{
    if(pere->getRectangleEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawRectangle();

    }
    if(pere->getCercleEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawCercle();

    }
    if(pere->getTraitEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawTrait();

    }
    if(pere->getRemplirEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        remplir();

    }
    if(pere->getDrawEnable())
    {
        delete path;
    }

}
//Fonctions
void Canevas::draw()
{
    QPen pen;

    path->lineTo(xMove,yMove);
    pen.setColor(pere->getCouleur());
    pen.setWidth(pere->getVeleurSlider());
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPath(*path);

    label->setPixmap(*pixmapListe[pixActuel]);
}
void Canevas::drawRectangle()
{
    QPen pen;
    pen.setColor(pere->getCouleur());
    pen.setWidth(pere->getVeleurSlider());

    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixActuel+1;
    pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapListe[pixActuel]);

    painter->setPen(pen);
    painter->drawRect(xPress,yPress,xRelease-xPress,yRelease-yPress);

    label->setPixmap(*pixmapListe[pixActuel]);
}
void Canevas::drawProvisoirRectangle()
{
    QPen pen;
    pen.setColor(pere->getCouleur());
    pen.setWidth(pere->getVeleurSlider());

    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixActuel+1;
    pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapListe[pixActuel]);

    painter->setPen(pen);
    painter->drawRect(xPress,yPress,xMove-xPress,yMove-yPress);
    label->setPixmap(*pixmapListe[pixActuel]);
    pixmapListe.remove(pixActuel);
    pixActuel = pixmapListe.size()-1;
}

void Canevas::drawCercle()
{
    QPen pen;
    pen.setColor(pere->getCouleur());
    pen.setWidth(pere->getVeleurSlider());

    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixActuel+1;
    pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapListe[pixActuel]);

    painter->setPen(pen);
    painter->drawEllipse(xPress,yPress,xRelease-xPress,yRelease-yPress);
    label->setPixmap(*pixmapListe[pixActuel]);
}
void Canevas::drawProvisoirCercle()
{
    QPen pen;
    pen.setColor(pere->getCouleur());
    pen.setWidth(pere->getVeleurSlider());

    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixActuel+1;
    pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapListe[pixActuel]);

    painter->setPen(pen);
    painter->drawEllipse(xPress,yPress,xMove-xPress,yMove-yPress);
    label->setPixmap(*pixmapListe[pixActuel]);
    pixmapListe.remove(pixActuel);
    pixActuel = pixmapListe.size()-1;
}

void Canevas::drawTrait()
{
    QPen pen;
    pen.setColor(pere->getCouleur());
    pen.setWidth(pere->getVeleurSlider());

    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixActuel+1;
    pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapListe[pixActuel]);

    painter->setPen(pen);
    painter->drawLine(xPress,yPress,xRelease,yRelease);
    label->setPixmap(*pixmapListe[pixActuel]);

}
void Canevas::drawProvisoirTrait()
{
    QPen pen;
    pen.setColor(pere->getCouleur());
    pen.setWidth(pere->getVeleurSlider());

    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixActuel+1;
    pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapListe[pixActuel]);

    painter->setPen(pen);
    painter->drawLine(xPress,yPress,xMove,yMove);
    label->setPixmap(*pixmapListe[pixActuel]);
    pixmapListe.remove(pixActuel);
    pixActuel = pixmapListe.size()-1;
}

void Canevas::remplir()
{
    painter->end();
    delete painter;
    QRgb couleurCible,couleurReproduit;
    QColor couleurBuff;

    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixActuel+1;
    pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);


    image = new QImage(xMax,yMax,QImage::Format_RGB32);
    *image = pixmapListe[pixActuel]->toImage();
    couleurCible = image->pixel(xPress,yPress);
    couleurReproduit = pere->getCouleur().rgb();
    remplissage4(xPress,yPress,couleurCible,couleurReproduit);




    pixmapListe[pixActuel]->convertFromImage(*image);
    painter = new QPainter(pixmapListe[pixActuel]);

    delete image;


    label->setPixmap(*pixmapListe[pixActuel]);
}
//Algorithme de remplissage d'une surface
int Canevas::remplissage4(int x,int y,QRgb colcible, QRgb colrep)
{
    int a,b,i;
    int lastPosition;
    QVector<Pile*> listePosition;

    if(image->pixel(x,y)!= colcible)
    {
        return 1;
    }
    if(x<0||y<0||x>(xMax-1)||y>(yMax-1)||colcible==colrep)
    {
        return 0;
    }

    listePosition.push_back(new Pile(x,y));

    while(listePosition.empty()==0)
    {


        a = listePosition[listePosition.size()-1]->getX();
        b = listePosition[listePosition.size()-1]->getY();

        if(a==1||b==1||a==(xMax-1)||b==(yMax-1))
        {
            for(i=0;i<xMax;i++)
            {
               image->setPixel(i,0,colrep);
               image->setPixel(i,yMax-1,colrep);
            }
            for(i=0;i<yMax;i++)
            {
               image->setPixel(0,i,colrep);
               image->setPixel(xMax-1,i,colrep);
            }
        }
        lastPosition = listePosition.size()-1;
        listePosition.remove(lastPosition);

        image->setPixel(a,b,colrep);

        if(image->pixel(a,b-1)==colcible)
        {
            listePosition.push_back(new Pile(a,b-1));
        }

        if(image->pixel(a,b+1)==colcible)
        {
            listePosition.push_back(new Pile(a,b+1));
        }
        if(image->pixel(a+1,b)==colcible)
        {
            listePosition.push_back(new Pile(a+1,b));
        }
        if(image->pixel(a-1,b)==colcible)
        {
            listePosition.push_back(new Pile(a-1,b));
        }
    }
    return 1;
}

//Fonction slots
void Canevas::sauvegarderCanevas()
{
    QString fichier = QFileDialog::getSaveFileName(0, "Enregistrer l'image", QString(), "Images (*.png *.gif *.jpg *.jpeg)");

    pixmapListe[pixActuel]->save(fichier);
}

void Canevas::ouvrirCanevas()
{
    QString fichier = QFileDialog::getOpenFileName(0,"Ouvrir image",QString(),"Images (*.png *.gif *.jpg *.jpeg)");
    painter->end();
    delete painter;
    pixmapListe.remove(pixActuel);
    pixmapListe.push_back(new QPixmap(fichier));
    painter = new QPainter(pixmapListe[pixActuel]);
    label->setPixmap(*pixmapListe[pixActuel]);

}

void Canevas::nouveauCanevas()
{
    painter->end();
    delete painter;
    pixmapListe.erase(pixmapListe.begin(),pixmapListe.end());
    delete label;
    xMax = FenTaille::getLongueur();
    yMax = FenTaille::getHauteur();

    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixmapListe.size()-1;
    pixmapListe[pixActuel]->fill();

    label = new QLabel(this);
    label->setPixmap(*pixmapListe[pixActuel]);
    label->show();
    painter = new QPainter(pixmapListe[pixActuel]);
}
void Canevas::retourCanevas()
{
    if(pixActuel ==0) return;
    pixmapListe.remove(pixActuel);
    pixActuel = pixmapListe.size()-1;
    painter->end();
    delete painter;
    painter = new QPainter(pixmapListe[pixActuel]);
    label->setPixmap(*pixmapListe[pixActuel]);

}
