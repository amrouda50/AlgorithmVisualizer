#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Sorting.cpp"
#include "column.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   animationdelay = 0;
   ShowValues = false;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    MainWindow::drawColumns();
}

//clear the canvas (QGraphicsScene object)
void MainWindow::clearCanvas(){
    scene->clear();
}

//add a new column
void MainWindow::addColumn(int newColumnVal){ //add a new column
    this->columns.addColumn(newColumnVal);
}

//delete columns
void MainWindow::delColumns(){ //delete columns
    this->columns.delColumns();
}
//Get Columns object
Columns MainWindow::GetColumns(){
    return this->columns;
}
//Animation delay getter

float MainWindow::animationdelayGetter(){
    return this->animationdelay;
}

//draw all columns on the canvas (QGraphicsScene object)
void MainWindow::drawColumns(){
    //set the drawing tools we want to use
    QBrush blueBrush(Qt::blue);
    QPen blackpen(Qt::black);
    blackpen.setWidth(2);

    //draw one rectangle and one text for each column on the canvas (QGraphicsScene object)
    for(int i=0;i < this->columns.numberOfColumns();i++) {
        //the max height of a column on the canvas is 1000, which occurs when it's value is 100
        //the min height of a column on the canvas is 10, which occurs when it's value is 1

        //parameters: offsetX,offsetY,width,height,outline,color
        int offsetX = 20 * (i+1) + 10 * (i);
        int offsetY = 1000 - (this->columns.nthColumnVal(i) * 10);
        int width = 20;
        int height = 10 * this->columns.nthColumnVal(i);

        scene->addRect(offsetX,offsetY,width,height,blackpen,blueBrush);
        QGraphicsSimpleTextItem *newText = scene->addSimpleText( QString::number(this->columns.nthColumnVal(i)) );

        if(ShowValues == true){
            //parameters: offsetX,offsetY
            newText->setPos(5 + (20 * (i+1) + 10 * (i)) ,1000);
        }

    }
}


void MainWindow::swapColumns(int col1ind,int col2ind){
        if(col1ind >= this->columns.numberOfColumns() || col2ind >= this->columns.numberOfColumns() || col1ind < 0 || col2ind < 0 || col1ind == col2ind) {
            cerr << "Invalid column index" << endl;
        }
        else {

            //two columns next to each other have the distance of 30 pixels
            //we want to animate the two columns moving 5 pixels at a time into the opposite direction
            //lets calculate how much time it will take to swap the two columns with moving each with 1 pixels at a time
            int animationTime = (((col2ind+1) - (col1ind+1)) * 30);
            clearCanvas();
            qDebug() << 123;
            QBrush blueBrush(Qt::blue);
            QBrush redBrush(Qt::red);
            QPen blackpen(Qt::black);
            blackpen.setWidth(2);

            //ANIMATION = ALL COLUMNS ARE DRAWN THE SAME WAY
            //EXCEPT THE TWO WE ANIMATE
            //WE JUST ADD DIFFERENT OFFSETS TO THEM
            //AND REDRAW THE CANVAS
            for(int j=0;j< animationTime ;j++) {
                clearCanvas();
                int offsetX = 0;
                QBrush currentBrush;

                for(int i=0;i < this->columns.numberOfColumns();i++) {
                    if(i != col1ind && i != col2ind) {
                        offsetX = 20 * (i+1) + 10 * (i);
                        currentBrush = blueBrush;
                     }
                    else if(i == col1ind) {
                        offsetX = (20 * (i+1) + 10 * (i)) + (j+1);
                        currentBrush = redBrush;
                     }
                    else if(i == col2ind) {
                        offsetX = (20 * (i+1) + 10 * (i)) - (j+1);
                        currentBrush = redBrush;
                     }
                        int offsetY = 1000 - (this->columns.nthColumnVal(i) * 10);
                        int width = 20;
                        int height = 10 * this->columns.nthColumnVal(i);

                        scene->addRect(offsetX,offsetY,width,height,blackpen,currentBrush);
                        QGraphicsSimpleTextItem *newText = scene->addSimpleText( QString::number(this->columns.nthColumnVal(i)) );
                        newText->setPos(5 + offsetX ,1000);
                  }

                  delay(this->animationdelayGetter());

            }
            //after we finished with the animation, swap the actual two columns' data
            int pos1 = this->columns.nthColumnPos(col1ind);
            int pos2 = this->columns.nthColumnPos(col2ind);
            int val1 = this->columns.nthColumnVal(col1ind);
            int val2 = this->columns.nthColumnVal(col2ind);
            this->columns.setnthColumnPos(col1ind,pos2);
            this->columns.setnthColumnPos(col2ind,pos1);
            this->columns.setnthColumnVal(col1ind,val2);
            this->columns.setnthColumnVal(col2ind,val1);

            //and redraw every column with the blue brush
            delay(this->animationdelayGetter());
            clearCanvas();
            drawColumns();
      }
}

void  MainWindow::animationdelaySetter(int time){
    this->animationdelay = time;
}

void MainWindow::delay(int time)
{
    QTime dieTime= QTime::currentTime().addMSecs((100-time)/10);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


MainWindow::~MainWindow()
{
    delete ui;
}

//When the user clicks the "Add to dataset" button,
//read the user input and invoke the appropriate function
void MainWindow::on_addToDatasetButton_clicked()
{
    //read the number the user typed in
    QString number = ui->lineEdit->text();
    //clear the canvas
    clearCanvas();
    //convert the number to int type and invoke
    addColumn(number.toInt());
    //redraw the canvas
    drawColumns();
}

//When the user clicks the "Add to dataset" button,
//delete all columns
void MainWindow::on_clearDatasetButton_clicked()
{
    //clear the canvas
    clearCanvas();
    //delete the columns
    delColumns();

}

void MainWindow::on_pushButton_2_clicked()
{
    QString algorithmType = ui->comboBox->currentText() ;
     if ( algorithmType == "Insertion sort"){
         Sort *sorting = new InsertionSort();
         sorting->sort(this->columns.getColumns() , this);

     }

     else if(algorithmType == "Selection sort"){
         Sort *sorting = new SelectionSort();
         sorting->sort(this->columns.getColumns() , this);


     }
     else if(algorithmType == "Shell sort"){
            Sort *sorting = new ShellSort();
            sorting->sort(this->columns.getColumns() , this);

        }
        else if(algorithmType == "Bubble sort"){
            Sort *sorting = new BubbleSort();
            sorting->sort(this->columns.getColumns(), this);

        }
     else if(algorithmType == "Quick sort"){
         Sort *sorting = new QuickSort();
         sorting->sort(this->columns.getColumns() , this);
     }

     else if(algorithmType == "Shell sort"){
         Sort *sorting = new ShellSort();
         sorting->sort(this->columns.getColumns() , this);
     }
     else if(algorithmType == "Merge sort"){
         Sort *sorting = new MergeSort();
         sorting->sort(this->columns.getColumns() , this);
     }

     else{
          cerr << "Please select an algorithm" << endl;
     }


}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    this->animationdelaySetter(position);
}







void MainWindow::on_checkBox_clicked(bool checked)
{
    ShowValues = checked;
    clearCanvas();
    drawColumns();
}

