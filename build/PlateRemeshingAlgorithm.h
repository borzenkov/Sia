#pragma once
#include "Plate.h"
#include <BRepClass3d_SolidClassifier.hxx>
#include <vtkXMLPolyDataWriter.h>

class PlateRemeshingAlgorithm
{
public:
	PlateRemeshingAlgorithm();
	~PlateRemeshingAlgorithm();
	void SetPlate(Plate*);
	void SetStep(double);
	void SetTolerance(double);
	void Perform();
private:
	Plate* plate_to_remesh;
	double width, height, step, tolerance;
};

