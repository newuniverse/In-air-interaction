#include <QtGui>
#include "LeapInteractor.h"


void LeapInteractor::on_leapActivateButton_clicked()
{
	switchListener();
	if (getStatus() == 1) { //running
		leapActivateButton->setText(QString("Disable Leap Motion"));
		statusbar->showMessage(QString("FPS: ") + QString::number(getFPS()));
	} else {	//stop
		leapActivateButton->setText(QString("Enable Leap Motion"));
	}
}

/*main update function*/
void LeapInteractor::update(const Leap::Frame frame)
{
    currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeSpan =  std::chrono::duration_cast< std::chrono::duration<double> > (currentTime - lastTime);
	if (timeSpan.count() < DELTATIME) {
		return;
	}

    renderMutex.lock();
    if(!frame.isValid())
        return;
    calcDataFPS();
    
    getHandInfo(frame);
    
    setMode(frame);
    
    switch (mode) {
        case SELECTION:
            //updateRayHitObject(frame);
            break;
        case MANIPULATION:
            updateParameters(frame);
            break;
        case PHYSICS:
            //updateGestures(frame);
            break;
    }
    //renderMutex.unlock();
}