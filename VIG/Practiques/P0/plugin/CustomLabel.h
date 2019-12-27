
#include <QApplication>
#include <QLabel>
#include <QString>

class CustomLabel : public QLabel
{
	Q_OBJECT

public: 
	CustomLabel(const QString& text, QWidget *parent = 0);

public slots:
	void clear();
	void addRed();
	void addBlue();
	void addGreen();
	void addYellow();
};
