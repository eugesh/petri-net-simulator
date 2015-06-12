#ifndef MATEJKOCANVAS_H
#define MATEJKOCANVAS_H

#include <QWidget>
#include "place.h"
#include "transition.h"
#include "arrow.h"


class MatejkoCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit MatejkoCanvas(QWidget *parent = 0);
    // TODO copy constructor

    QList<Element *> *places;
    QList<Element *> *transitions;
    QList<Arrow *> *arrows;
    Element *selectedElement();

    void clear();

    bool simulationModeOn() const;
    void setSimulationModeOn(bool simulationModeOn);

signals:
    void simulationModeOnChanged(bool simulationModeOn);

public slots:
    void showContextMenu(const QPoint &);
    void contextActionTriggered(QAction *);
    void onRemoveElementRequested();
    void onModifyElementRequested();
    void onElementClicked();
    void onSelectedElementDestroyed();

private:
    Arrow tmpArrow;
    Element *_selectedElement;
    bool _simulationModeOn;

    // Mouse
    void mouseReleaseEvent(QMouseEvent *event);

    enum ContextActionType {
        AddPlace,
        AddTransition
    };
    void constructArrow(Element *element);
    void paintEvent(QPaintEvent *event);
    void setupPalette();
    bool arrowConnectionExists(Element *place, Element *transition) const;
    bool buildArrow(Element *place, Element *transition, bool fromPlaceToTransition);
    void selectElement(Element *);
    void setSelectedElement(Element *element);
    int removeRelatedArrows(Element *element);
};

#endif // MATEJKOCANVAS_H
