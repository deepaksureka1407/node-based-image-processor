#include "mainwindow.h"
#include "nodes/NodeItem.h"
#include "nodes/ConnectionItem.h"
#include "nodes/NodeScene.h"
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the graphics scene
    scene = new NodeScene(this);
    scene->setSceneRect(0, 0, 1000, 800);

    // Create Blur node
    NodeItem *blurNode = new NodeItem("Blur Node");
    scene->addItem(blurNode);
    blurNode->setPos(100, 150);
    blurNode->addSlider("Radius", 1, 20, 5);

    // Create Threshold node
    NodeItem *thresholdNode = new NodeItem("Threshold Node");
    scene->addItem(thresholdNode);
    thresholdNode->setPos(400, 150);

    // Draw connection between nodes
    ConnectionItem *conn = new ConnectionItem(
        blurNode->outputPort(),
        thresholdNode->inputPort());
    scene->addItem(conn);

    // Create the view and set it as central widget
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(view);

    // Load image
    cv::Mat image = cv::imread("sample.jpg");

    // Run through the graph
    blurNode->setInputImage(image);
    cv::Mat blurred = blurNode->getOutputImage();
    thresholdNode->setInputImage(blurred);
    cv::Mat final = thresholdNode->getOutputImage();

    // Show in window
    cv::cvtColor(final, final, cv::COLOR_BGR2RGB);
    QImage qimg(final.data, final.cols, final.rows, final.step, QImage::Format_RGB888);
    QLabel *preview = new QLabel;
    preview->setPixmap(QPixmap::fromImage(qimg));
    preview->show();

    inputNode->loadImage("sample.jpg");

    cv::Mat img1 = inputNode->getOutputImage();
    blurNode->setInputImage(img1);
    cv::Mat img2 = blurNode->getOutputImage();
    outputNode->setInputImage(img2);
    // Link connections
    inputNode->addOutput(blurNode);
    blurNode->addInput(inputNode);
    blurNode->addOutput(outputNode);
    outputNode->addInput(blurNode);

    // Run the flow
    executeGraph(outputNode); // starts from the last node

    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // File Menu
    QMenu *fileMenu = menuBar->addMenu("File");

    QAction *openAct = new QAction("Open Image", this);
    QAction *saveAct = new QAction("Save Output", this);

    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);

    connect(openAct, &QAction::triggered, [=]()
            {
    QString path = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.jpg *.png *.bmp)");
    if (!path.isEmpty() && inputNode) {
        inputNode->loadImage(path);
    } });

    connect(saveAct, &QAction::triggered, [=]()
            {
    if (outputNode) {
        cv::imwrite("output.jpg", outputNode->getOutputImage());
        QMessageBox::information(this, "Saved", "Image saved as output.jpg");
    } });
}

void MainWindow::runGraph()
{
    // 1. Clear all existing input/output links
    for (QGraphicsItem *item : scene->items())
    {
        if (auto *node = dynamic_cast<NodeItem *>(item))
        {
            node->inputs.clear();
            node->outputs.clear();
        }
    }

    // 2. Reconstruct links from connections
    for (QGraphicsItem *item : scene->items())
    {
        if (auto *conn = dynamic_cast<ConnectionItem *>(item))
        {
            conn->from->addOutput(conn->to);
            conn->to->addInput(conn->from);
        }
    }

    // 3. Find final node (OutputNode) and execute from there
    for (QGraphicsItem *item : scene->items())
    {
        if (auto *node = dynamic_cast<NodeItem *>(item))
        {
            if (node->outputs.empty())
            {
                executeGraph(node); // Start from sink
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete view;
    delete scene;
    QPushButton *runBtn = new QPushButton("Run Pipeline");
    connect(runBtn, &QPushButton::clicked, this, &MainWindow::runGraph);

    runBtn->setParent(view); // Add it to the view for now
    runBtn->move(10, 10);
    runBtn->show();
}
