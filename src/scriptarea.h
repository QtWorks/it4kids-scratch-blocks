#ifndef SCRIPTAREA_H
#define SCRIPTAREA_H

#include <vector>

#include <QWidget>
#include <QPainter>

class DragableElement;
class DockingArea;
class Sprite;

typedef std::vector<DockingArea*> HitTestVector;
typedef std::vector<DragableElement*> DragElemVector;

class ScriptArea : public QWidget
{
    Q_OBJECT

    Sprite* _currentSprite;

    void hideElements();
    void showElements();

public:
    explicit ScriptArea(QWidget *parent = 0);

    ~ScriptArea();

public slots:
    void setCurrentSprite(Sprite* sprite);

protected:
    virtual void hideEvent(QHideEvent*);
    virtual void showEvent(QShowEvent*);
    void paintEvent(QPaintEvent* event);
};

#endif // SCRIPTAREA_H
