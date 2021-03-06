#include "categoryselect.h"

CategorySelect::CategorySelect(QWidget *parent) : QWidget(parent)
{
    setLayout(&_layout);
    _layout.setMargin(0);
    _layout.setSpacing(0);
}

void CategorySelect::setElemListWidget(DragElemList *elemListWidget)
{
    _elemListWidget = elemListWidget;
    for(CategoryList::const_iterator category = _categoryList.begin(); category != _categoryList.end(); category++)
    {
        (*category)->setElemListWidget(_elemListWidget);
    }
}

void CategorySelect::show()
{
    int i = 0;
    for(CategoryList::const_iterator category = _categoryList.begin(); category != _categoryList.end(); ++category)
    {
        _layout.addWidget(*category, i/2, i % 2, 1, 1);
        ++i;
    }
    setFixedHeight((i/2)*18);
    QWidget::show();
}

void CategorySelect::paintEvent(QPaintEvent*)
{

}

CategorySelect::~CategorySelect()
{
}
