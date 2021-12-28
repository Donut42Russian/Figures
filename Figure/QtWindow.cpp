#include "QtWindow.h"
#include "ui_qtwindow.h"
#include "DrawFigures.h"
#include <QFormLayout>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QSvgGenerator>
#include <QGraphicsView>
#include <QtWidgets>

QtWindow::QtWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtWindow)
{  
        ui->setupUi(this);

        setWindowTitle("FigureDrawer");

        toolbar = addToolBar("toolbar");

        QPixmap deletePicture(":/images/delete.png");
        QAction* A_delete_ = toolbar->addAction(QIcon(deletePicture), "Удаление");
        connect(A_delete_, SIGNAL(triggered()), this, SLOT(Delete()));

        QPixmap circlePicture(":/images/circle.png");
        QAction* A_createCircle = toolbar->addAction(QIcon(circlePicture), "Круг");
        connect(A_createCircle, SIGNAL(triggered()), this, SLOT(CreateCircle()));

        QPixmap trianglePicture(":/images/triangle.png");
        QAction* A_createTriangle = toolbar->addAction(QIcon(trianglePicture), "Треугольник");
        connect(A_createTriangle, SIGNAL(triggered()), this, SLOT(CreateTriangle()));

        QPixmap rectanglePicture(":/images/rectangle.png");
        QAction* A_createRectangle = toolbar->addAction(QIcon(rectanglePicture), "Прямоугольник");
        connect(A_createRectangle, SIGNAL(triggered()), this, SLOT(CreateRectangle()));

        scene = new QGraphicsScene();
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setSceneRect(ui->graphicsView->rect());
        setCentralWidget(ui->graphicsView);

        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scene->setItemIndexMethod(QGraphicsScene::NoIndex);
        ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

QtWindow::~QtWindow()
{
    qDeleteAll(scene->items());
    delete ui;
    delete toolbar;
    delete scene;
}

void QtWindow::CreateCircle()
{
    bool ok;
    int r = QInputDialog::getInt(this,"Круг", "Радиус", 0, 1, 1000, 1, &ok);
    if(ok)
    {
        CircleDraw* circleDraw = new CircleDraw(Circle(r), QPoint(0, 0));
        scene->addItem(circleDraw);
    }
}


void QtWindow::CreateTriangle()
{
    QDialog* dialog = new QDialog();
    dialog->setWindowTitle("Треугольник");
    QFormLayout* formLayout = new QFormLayout();
    QSpinBox* X1 = new QSpinBox();
    X1->setMinimum(0);
    X1->setMaximum(1000);
    QSpinBox* Y1 = new QSpinBox();
    Y1->setMinimum(0);
    Y1->setMaximum(1000);
    QSpinBox* X2 = new QSpinBox();
    X2->setMinimum(0);
    X2->setMaximum(1000);
    QSpinBox* Y2 = new QSpinBox();
    Y2->setMinimum(0);
    Y2->setMaximum(1000);
    QSpinBox* X3 = new QSpinBox();
    X3->setMinimum(0);
    X3->setMaximum(1000);
    QSpinBox* Y3 = new QSpinBox();
    Y3->setMinimum(0);
    Y3->setMaximum(1000);
    formLayout->addRow("x1:", X1);
    formLayout->addRow("y1:", Y1);
    formLayout->addRow("x2:", X2);
    formLayout->addRow("y2:", Y2);
    formLayout->addRow("x3:", X3);
    formLayout->addRow("y3:", Y3);
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));
    formLayout->addWidget(buttonBox);
    dialog->setLayout(formLayout);
    int result = dialog->exec();
    if(result == QDialog::Accepted)
    {
        try
        {
            TriangleDraw* triangleDraw = new TriangleDraw(Triangle(X1->value(), Y1->value(),X2->value(), Y2->value(),X3->value(), Y3->value()), QPoint(0, 0));
            scene->addItem(triangleDraw);
        }
        catch(...) {}
    }
    delete X1;
    delete Y1;
    delete X2;
    delete Y2;
    delete X3;
    delete Y3;
    delete formLayout;
    delete buttonBox;
    delete dialog;
}

void QtWindow::CreateRectangle()
{
    QDialog* dialog = new QDialog();
    dialog->setWindowTitle("Прямоугольник");
    QFormLayout* formLayout = new QFormLayout();
    QSpinBox* x1 = new QSpinBox();
    x1->setMinimum(0);
    x1->setMaximum(1000);
    QSpinBox* y1 = new QSpinBox();
    y1->setMinimum(0);
    y1->setMaximum(1000);
    QSpinBox* x2 = new QSpinBox();
    x2->setMinimum(0);
    x2->setMaximum(1000);
    QSpinBox* y2 = new QSpinBox();
    y2->setMinimum(0);
    y2->setMaximum(1000);
    /*QSpinBox* x3 = new QSpinBox();
    x2->setMinimum(0);
    x2->setMaximum(1000);
    QSpinBox* y3 = new QSpinBox();
    y2->setMinimum(0);
    y2->setMaximum(1000);
    QSpinBox* x4 = new QSpinBox();
    x2->setMinimum(0);
    x2->setMaximum(1000);
    QSpinBox* y4 = new QSpinBox();
    y2->setMinimum(0);
    y2->setMaximum(1000);*/

    formLayout->addRow("x1:", x1);
    formLayout->addRow("y1:", y1);
    formLayout->addRow("x2:", x2);
    formLayout->addRow("y2:", y2);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));
    formLayout->addWidget(buttonBox);
    dialog->setLayout(formLayout);
    int result = dialog->exec();
    if(result == QDialog::Accepted)
    {
        try
        {
            RectangleDraw* rectangleDraw = new RectangleDraw(Rectangle(x1->value(),y1->value(),x2->value(),y2->value()), QPoint(0, 0));
            scene->addItem(rectangleDraw);
        }
        catch(...) {}
    }
    delete x1;
    delete y1;
    delete x2;
    delete y2;
    delete x3;
    delete y3;
    delete x4;
    delete y4;

    delete formLayout;
    delete buttonBox;
    delete dialog;
}

void QtWindow::Delete()
{
    qDeleteAll(scene->selectedItems());
}
