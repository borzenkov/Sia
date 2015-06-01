#pragma once
#include "Plate.h"
#include <BRepClass3d_SolidClassifier.hxx>
#include <vtkTransform.h>
#include <vtkOBBTree.h>
#include <vtkPoints.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkMath.h>
#include <vtkDelaunay2D.h>
#include <vtkSTLWriter.h>
#include <algorithm> // std::min_element
#include <iterator>  // std::begin, std::end
class MakeAdhering
{
public:
	MakeAdhering();
	~MakeAdhering();
	void SetPlate(Plate*);
	void SetLowerJaw(vtkSmartPointer<vtkPolyData>);
	void SetRenderer(vtkRenderer*);
	void Perform();
	vtkSmartPointer<vtkPoints> GetPoints();
private:
	Plate* plate;
	vtkSmartPointer<vtkPolyData> lowerJaw;
	double width, height;
	vtkSmartPointer<vtkPoints> pointsOn;
	vtkSmartPointer<vtkRenderer> renderer;
};

