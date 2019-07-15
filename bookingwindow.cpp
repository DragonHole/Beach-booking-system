#include "bookingwindow.h"
#include "packagedisplaycell.h"

BookingWindow::BookingWindow()
{
    this->_itemTabWidget = new QTabWidget;

    this->_firstPage = new QWidget;
    this->_secondPage = new QWidget;
    this->_thirdPage = new QWidget;
    this->_fourthPage = new QWidget;
    this->_fifthPage = new QWidget;

    this->_categoryOneScrollArea = new QScrollArea;
    this->_categoryTwoScrollArea = new QScrollArea;
    this->_categoryThreeScrollArea = new QScrollArea;
    this->_categoryFourScrollArea = new QScrollArea;
    this->_categoryFiveScrollArea = new QScrollArea;

    this->_itemDisplayGridLayout_CategoryOne = new QGridLayout;
    this->_itemDisplayGridLayout_CategoryTwo = new QGridLayout;
    this->_itemDisplayGridLayout_CategoryThree = new QGridLayout;
    this->_itemDisplayGridLayout_CategoryFour = new QGridLayout;
    this->_itemDisplayGridLayout_CategoryFive = new QGridLayout;

    this->_backButton = new QPushButton("Back");
    _backButton->setMaximumWidth(100);

    // initialize the package cells
    // first category
    PackageDisplayCell *cell1 = new PackageDisplayCell(1, "Surfing", ":/resources/images/surfing.png");
    PackageDisplayCell *cell2 = new PackageDisplayCell(2, "Kite Surfing", ":/resources/images/kitesurfing.png");

    // second category..
    PackageDisplayCell *cell3 = new PackageDisplayCell(3, "Dinghie", ":/resources/images/dinghie.png");
    PackageDisplayCell *cell4 = new PackageDisplayCell(4, "Keelboats & yachts", ":/resources/images/keelboat.png");
    PackageDisplayCell *cell5 = new PackageDisplayCell(5, "Multi-hulls", ":/resources/images/multihulls.jpg");
    PackageDisplayCell *cell6 = new PackageDisplayCell(6, "Board-sailing", ":/resources/images/sailing.png");

    // third category
    PackageDisplayCell *cell7 = new PackageDisplayCell(7, "Paddle boarding", ":/resources/images/paddleboarding.jpg");
    PackageDisplayCell *cell8 = new PackageDisplayCell(8, "Sea Kayaking", ":/resources/images/seakayaking.jpg");

    // fourth category
    PackageDisplayCell *cell9 = new PackageDisplayCell(9, "Snorkeling", ":/resources/images/snorkel.jpg");
    PackageDisplayCell *cell10 = new PackageDisplayCell(10, "Scuba diving", ":/resources/images/scuba");
    PackageDisplayCell *cell11 = new PackageDisplayCell(11, "Deep sea diving", ":/resources/images/deepdiving.jpg");

    // add extra staffs to the pages
    this->_labelCategoryOne = new QLabel("Lets buy some sailing gears");
    this->_labelCategoryTwo = new QLabel("Lets buy some swimming gears");

//    _itemDisplayGridLayout_CategoryOne->addWidget(_labelCategoryTwo, 0, 1);
//    _itemDisplayGridLayout_CategoryOne->addWidget(_labelCategoryOne, 2, 0);
    _itemDisplayGridLayout_CategoryOne->addWidget(cell1, 0, 0);
    _itemDisplayGridLayout_CategoryOne->addWidget(cell2, 0, 1);

    _itemDisplayGridLayout_CategoryTwo->addWidget(cell3, 0, 0);
    _itemDisplayGridLayout_CategoryTwo->addWidget(cell4, 0, 1);
    _itemDisplayGridLayout_CategoryTwo->addWidget(cell5, 1, 0);
    _itemDisplayGridLayout_CategoryTwo->addWidget(cell6, 1, 1);

    _itemDisplayGridLayout_CategoryThree->addWidget(cell7, 0, 0);
    _itemDisplayGridLayout_CategoryThree->addWidget(cell8, 0, 1);

    _itemDisplayGridLayout_CategoryFour->addWidget(cell9, 0, 0);
    _itemDisplayGridLayout_CategoryFour->addWidget(cell10, 0, 1);
    _itemDisplayGridLayout_CategoryFour->addWidget(cell11, 1, 0);

    _firstPage->setLayout(_itemDisplayGridLayout_CategoryOne);
    _secondPage->setLayout(_itemDisplayGridLayout_CategoryTwo);
    _thirdPage->setLayout(_itemDisplayGridLayout_CategoryThree);
    _fourthPage->setLayout(_itemDisplayGridLayout_CategoryFour);
    _fifthPage->setLayout(_itemDisplayGridLayout_CategoryFive);

    _categoryOneScrollArea->setWidget(_firstPage);
    _categoryTwoScrollArea->setWidget(_secondPage);
    _categoryThreeScrollArea->setWidget(_thirdPage);
    _categoryFourScrollArea->setWidget(_fourthPage);
    _categoryFiveScrollArea->setWidget(_fifthPage);

    _itemTabWidget->addTab(_categoryOneScrollArea, "Surfing");
    _itemTabWidget->addTab(_categoryTwoScrollArea, "Sailing");
    _itemTabWidget->addTab(_categoryThreeScrollArea, "Paddling");
    _itemTabWidget->addTab(_categoryFourScrollArea, "Diving");
    _itemTabWidget->addTab(_categoryFiveScrollArea, "Special");

    this->_mLayout = new QVBoxLayout;
    _mLayout->addWidget(_backButton);
    _mLayout->addWidget(_itemTabWidget);

    setLayout(_mLayout);

    connect(_backButton, SIGNAL(clicked()), this, SLOT(backButtonClicked()));
}

void BookingWindow::backButtonClicked(){
    emit signalBackToHomePage();
}
