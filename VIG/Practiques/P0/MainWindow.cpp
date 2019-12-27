
#include <QApplication>
#include <QPushButton>
#include <QFrame>
#include <QLayout>
#include <QLineEdit>
#include <QLabel>
#include <QColor>
#include <QSlider>
#include <QSpacerItem>
#include <QPlastiqueStyle>

#include "CustomLabel.h"


int main(int argc, char **argv)
{
	QApplication a(argc, argv);
	QString fontFamily = "Arial";
	a.setFont(fontFamily);
	a.setStyle(new QPlastiqueStyle);
	
	QFrame F(0, NULL);
	F.setMinimumSize(QSize(330,260));
	QGridLayout* QG = new QGridLayout(&F);
	QGridLayout* QG_buttons = new QGridLayout(0);
	
	QPushButton* redbutton = new QPushButton("", &F);
	redbutton->setFixedSize(QSize(100,100));
	redbutton->move(QPoint(10,10));
	redbutton->setPalette(QPalette(QColor(255,0,0)));

	QPushButton* greenbutton = new QPushButton("", &F);
	greenbutton->setFixedSize(QSize(100,100));
	greenbutton->move(QPoint(10+100+10,10));
	greenbutton->setPalette(QPalette(QColor(0,255,0)));

	QPushButton* bluebutton = new QPushButton("", &F);
	bluebutton->setFixedSize(QSize(100,100));
	bluebutton->move(QPoint(10,10+100+10));
	bluebutton->setPalette(QPalette(QColor(0,0,255)));

	QPushButton* yellowbutton = new QPushButton("", &F);
	yellowbutton->setFixedSize(QSize(100,100));
	yellowbutton->move(QPoint(10+100+10,10+100+10));
	yellowbutton->setPalette(QPalette(QColor(255,255,0)));


	QPushButton* exitbutton = new QPushButton("&Exit", &F);
	exitbutton->setFixedSize(QSize(80,30));
	QG_buttons->addWidget(exitbutton, 1, 0, 1, 1, Qt::AlignBottom);

	QPushButton* initbutton = new QPushButton("&Initialize", &F);
	initbutton->setFixedSize(QSize(80,30));
	QG_buttons->addWidget(initbutton, 0, 0, 1, 1, Qt::AlignBottom);

	QG->addLayout(QG_buttons,3,4,1,1,0);
	QLabel *text = new QLabel("Sequence:", &F);
	QG->addWidget(text, 3, 1, 1, 1, Qt::AlignBottom);
	CustomLabel *seqtext = new CustomLabel("", &F);

	seqtext->setPalette(QPalette(QColor(0,255,255)));
	seqtext->setAutoFillBackground(true);
	QG->addWidget(seqtext, 3, 2, 1, 1, Qt::AlignBottom);
	QG->addItem(new QSpacerItem(0,0,QSizePolicy::Minimum,QSizePolicy::Expanding),2,4,1,1,Qt::AlignBottom);
	QG->addItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum), 3, 3, 1, 1, Qt::AlignBottom);
	QG->setColumnMinimumWidth(2,80);

	//connects
	a.connect(exitbutton, SIGNAL(clicked()), &F, SLOT(close()));
	a.connect(initbutton, SIGNAL(clicked()), seqtext, SLOT(clear()));

	a.connect(redbutton, SIGNAL(clicked()), seqtext, SLOT(addRed()));
	a.connect(bluebutton, SIGNAL(clicked()), seqtext, SLOT(addBlue()));
	a.connect(greenbutton, SIGNAL(clicked()), seqtext, SLOT(addGreen()));
	a.connect(yellowbutton, SIGNAL(clicked()), seqtext, SLOT(addYellow()));

	F.show();
	return a.exec();

}


