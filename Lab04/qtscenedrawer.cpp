#include "qtscenedrawer.h"

QtSceneDrawer::QtSceneDrawer(QWidget* parent) : QWidget(parent)
{
    this->scene = 0;
}

void QtSceneDrawer::draw(const Scene& scene)
{
    this->scene = &scene;
    repaint();
}

void QtSceneDrawer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, width() - 1, height() - 1);
    if (this->scene == 0)
    {
        return;
    }
    painter.setPen(Qt::black);
    for (std::shared_ptr<obj3d::Figure> figure : this->scene->figures())
    {
        for (obj3d::Edge& edge : figure->edges())
        {
            obj3d::Point begin = project(figure->transform(edge.begin().position()));
            obj3d::Point end = project(figure->transform(edge.end().position()));
            painter.drawLine(begin.X() + width() / 2, height() / 2 - begin.Z(), end.X() + width() / 2, height() / 2 - end.Z());
        }
        for (obj3d::Vertex& vertex : figure->vertices())
        {
            obj3d::Point point = project(figure->transform(vertex.position()));
            painter.drawEllipse(point.X() + width() / 2 - 2, height() / 2 - point.Z() - 2, 4, 4);
        }
    }
}
