#ifndef CLICKVIEW_HPP
#define CLICKVIEW_HPP

#include <QQuickView>

class ClickView : public QQuickView {
        Q_OBJECT
    public:
        explicit ClickView( const QUrl& source, QWindow* parent = nullptr );

    signals:

    protected:
        virtual void mousePressEvent( QMouseEvent* ) override;
};

#endif // CLICKVIEW_HPP
