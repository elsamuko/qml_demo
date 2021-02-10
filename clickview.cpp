#include "clickview.hpp"

#include <QQuickItem>
#include <QMouseEvent>
#include <QDebug>
#include <QRegularExpression>

ClickView::ClickView( const QUrl& source, QWindow* parent ) : QQuickView( source, parent ) {}

void ClickView::mousePressEvent( QMouseEvent* ev ) {

    QObjectList children = this->findChildren<QObject*>( QRegularExpression( ".+" ) );

    for( QObject* child : children ) {

        // only search for QML types
        if( !strstr( child->metaObject()->className(), "_QMLTYPE_" ) ) { continue; }

        QVariant vX = child->property( "x" );
        QVariant vY = child->property( "y" );
        QVariant vW = child->property( "width" );
        QVariant vH = child->property( "height" );

        if( vX.isValid() && vY.isValid() && vW.isValid() && vH.isValid() ) {
            QRect rect( vX.toInt(), vY.toInt(), vW.toInt(), vH.toInt() );

            if( rect.contains( ev->pos() ) ) {
                qDebug() << child;
            }
        }
    }

    QQuickView::mousePressEvent( ev );
}
