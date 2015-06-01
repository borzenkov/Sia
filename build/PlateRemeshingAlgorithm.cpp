#include "PlateRemeshingAlgorithm.h"


PlateRemeshingAlgorithm::PlateRemeshingAlgorithm()
{
}


PlateRemeshingAlgorithm::~PlateRemeshingAlgorithm()
{
}

void PlateRemeshingAlgorithm::SetStep(double _step)
{
	step = _step;
}

void PlateRemeshingAlgorithm::SetTolerance(double _tolerance)
{
	tolerance = _tolerance;
}

void PlateRemeshingAlgorithm::SetPlate(Plate* plate)
{
	plate_to_remesh = plate;
}

void PlateRemeshingAlgorithm::Perform()
{
	width = plate_to_remesh->Get_l();
	height = plate_to_remesh->Get_h();

	BRepClass3d_SolidClassifier classifier;
	classifier.Load(*plate_to_remesh->GetShape());

	std::vector<gp_Pnt> points;

	double k = 0;

	if (plate_to_remesh->IsRightSide())
	{
		k = plate_to_remesh->Get_r();
	}

	for (double i = 0; i <= width; i += step)
	{
		for (double j = 0; j <= height; j += step)
		{
			gp_Pnt pnt(i, j, k);
			classifier.Perform(pnt, tolerance);
			if (classifier.State() == TopAbs_State::TopAbs_ON)
			{
				points.push_back(pnt);
			}
		}
	}

	vtkSmartPointer<vtkPoints> pointsOn = vtkSmartPointer<vtkPoints>::New();
	for (size_t i = 0; i < points.size(); i++)
	{
		pointsOn->InsertNextPoint(points[i].X(), points[i].Y(), points[i].Z());
	}
	// Create a polydata object and add the points to it.
	vtkSmartPointer<vtkPolyData> polydata =
		vtkSmartPointer<vtkPolyData>::New();
	polydata->SetPoints(pointsOn);

	
}
