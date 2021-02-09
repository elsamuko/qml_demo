#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QQuickView;

class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        MainWindow( QWidget* parent = nullptr );
        ~MainWindow();

    private:
        Ui::MainWindow* ui;
        QQuickView* qw1;
        QQuickView* qw2;
};
#endif // MAINWINDOW_HPP
