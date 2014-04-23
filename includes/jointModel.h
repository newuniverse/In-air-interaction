#ifndef JOINTMODEL_H_
#define JOINTMODEL_H_

#include "graphicalModel.h"

class JointModel : public GraphicalModel
{
public://methods
    JointModel() {
    	for (int i = 0; i < 4; ++i)
    	{
    		DH[i] = 0.0f;
    	}
    };
    template<class T>
    JointModel(vtkSmartPointer<T> t) : GraphicalModel(t) 
    {
    	for (int i = 0; i < 4; ++i)
    	{
    		DH[i] = 0.0f;
    	}
	}
    ~JointModel();
private://methods
	
public://members
	
private://members
	
protected: 
	float DH[4];
};
#endif