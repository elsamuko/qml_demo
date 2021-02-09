#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QQuickView>
#include <QHBoxLayout>

#include "clickview.hpp"

MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow ) {

    ui->setupUi( this );

    qw1 = new ClickView( QUrl( "qrc:/first.qml" ) );
    qw2 = new ClickView( QUrl( "qrc:/second.qml" ) );

    QWidget* container1 = QWidget::createWindowContainer( qw1 );
    QWidget* container2 = QWidget::createWindowContainer( qw2 );

    QHBoxLayout* lo = ( QHBoxLayout* )centralWidget()->layout();
    lo->addWidget( container1 );
    lo->addWidget( container2 );

}

MainWindow::~MainWindow() {
    delete ui;
    delete qw1;
    delete qw2;
}

