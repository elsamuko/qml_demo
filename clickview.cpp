#include "clickview.hpp"

#include <QQuickItem>
#include <QMouseEvent>
#include <QDebug>

ClickView::ClickView( const QUrl& source, QWindow* parent ) : QQuickView( source, parent ) {}

void dump( QList<QQuickItem*> items, size_t level = 1 ) {
    for( const QQuickItem* item : items ) {
        qDebug() << QString( level * 4, ' ' ) << item << item->objectName();
        dump( item->childItems(), level + 1 );
    }
}

void ClickView::mousePressEvent( QMouseEvent* ev ) {
    QPointF pos = this->rootObject()->mapToItem( this->rootObject(), ev->pos() );

    QQuickItem* child = this->rootObject()->childAt( pos.x(), pos.y() );
    qDebug() << "childAt" << pos << child << child->objectName();

    qDebug() << "children : ";
    dump( this->rootObject()->childItems() );

    qDebug() << "";
    QQuickView::mousePressEvent( ev );
}
