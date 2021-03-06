#include "find_widget.h"
#include <QGridLayout>

FindWidget::FindWidget(QWidget *parent) : QWidget(parent)
{
    QWidget::setFixedSize(QSize(360, 240));
    setWindowTitle("Найти запись");

    m_generalLbl    = new QLabel("Найти запись");
    m_generalLbl -> setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    m_idLbl      = new QLabel("ИД: ");
    m_idLineEdit = new QLineEdit(this);;
    m_okBtn      = new QPushButton("&Ок");
    m_okBtn      -> setShortcut(Qt::Key_Return);
    m_cancelBtn  = new QPushButton("&Назад");

    QHBoxLayout *gen_label = new QHBoxLayout;
    gen_label -> addWidget(m_generalLbl,  Qt::Alignment(Qt::AlignHCenter | Qt::AlignVCenter));

    QGridLayout* main_layout = new QGridLayout;
    main_layout -> addItem(gen_label, 0, 1);
    main_layout -> addWidget(m_idLbl, 1, 0, Qt::AlignRight);
    main_layout -> addWidget(m_idLineEdit, 1, 1);
    main_layout -> addWidget(m_okBtn, 2, 1);
    main_layout -> addWidget(m_cancelBtn, 3, 1);
    main_layout -> setHorizontalSpacing(2);
    main_layout -> setVerticalSpacing(2);
    main_layout -> setContentsMargins(30, 0, 40, 0);

    connect(m_okBtn, SIGNAL(clicked()), this, SLOT(slot_ok_clicked()));
    connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(slot_cancel_clicked()));
    setLayout(main_layout);
}

void FindWidget::slot_ok_clicked()
{
    m_ID = m_idLineEdit -> text();

    emit find_ok_clicked();
}
void FindWidget::slot_cancel_clicked()
{
    emit find_cancel_clicked();
}

void FindWidget::setError(const QString& error_str)
{
    m_generalLbl -> setText(error_str);
    if (error_str != "Найти запись")
    {
        m_generalLbl -> setStyleSheet("color: red");
    }

    if (error_str == "Найти запись")
    {
        m_generalLbl -> setStyleSheet("color: rgb(200, 200, 200)");
    }
}

bool FindWidget::isEmptyLine()
{
    if (m_ID.isEmpty())
        return true;
    return false;
}

void FindWidget::clearLines()
{
    m_idLineEdit -> clear();
}
