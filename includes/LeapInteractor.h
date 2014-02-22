//Leap listener class wrapper
#include "LeapListener.h"

#include "mainWindowController.h"


class LeapInteractor :public MainWindowController, public LeapListener
{
public:
	//LeapInteractor(QWidget *parent = 0);
private:
	void update(const Frame frame);

private slots:
	void on_leapActivateButton_clicked();

};
