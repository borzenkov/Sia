#include "MakeAdhering.h"


MakeAdhering::MakeAdhering()
{
}


MakeAdhering::~MakeAdhering()
{
}

void MakeAdhering::SetPlate(Plate* _plate){
	plate = _plate;
}
void MakeAdhering::SetLowerJaw(vtkSmartPointer<vtkPolyData> _lowerJaw){
	lowerJaw = _lowerJaw;
}
void MakeAdhering::Perform(){
	width = plate->Get_l();
	height = plate->Get_h();
	BRepClass3d_SolidClassifier classifier;
	classifier.Load(*plate->GetShape());

	std::vector<gp_Pnt> points;

	double k = 0;
	double normal[3] = {0, 0, -1};

	if (plate->IsRightSide())
	{
		k = plate->Get_r();
		normal[0] = 0;
		normal[1] = 0;
		normal[2] = 1;
	}

	for (int i = 0; i <= width; i++)
	{
		for (int j = 0; j <= height; j++)
		{
			gp_Pnt pnt(i, j, k);
			classifier.Perform(pnt, 0.1);
			if (classifier.State() == TopAbs_State::TopAbs_ON)
			{
				points.push_back(pnt);
			}
		}
	}

	vtkSmartPointer<vtkTransform> transform =
		vtkSmartPointer<vtkTransform>::New();
	transform->SetMatrix(plate->GetActor()->GetMatrix());

	pointsOn = vtkSmartPointer<vtkPoints>::New();
	for (size_t i = 0; i < points.size(); i++)
	{
		double dpnt[3] = { points[i].X(), points[i].Y(), points[i].Z() };
		double tdpnt[3];
		transform->TransformPoint(dpnt, tdpnt);
		pointsOn->InsertNextPoint(tdpnt);
	}

	transform->TransformDoubleNormal(normal);

	vtkSmartPointer<vtkOBBTree> tree =
		vtkSmartPointer<vtkOBBTree>::New();
	tree->SetDataSet(lowerJaw);
	tree->BuildLocator();

	vtkSmartPointer<vtkPoints> closestIntersectPoints =
		vtkSmartPointer<vtkPoints>::New();

	for (int i = 0; i < pointsOn->GetNumberOfPoints(); i++)
	{
		double lineP0[3] = { pointsOn->GetPoint(i)[0], pointsOn->GetPoint(i)[1], pointsOn->GetPoint(i)[2] };
		double lineP1[3];
		lineP1[0] = pointsOn->GetPoint(i)[0] + 1000 * normal[0];
		lineP1[1] = pointsOn->GetPoint(i)[1] + 1000 * normal[1];
		lineP1[2] = pointsOn->GetPoint(i)[2] + 1000 * normal[2];
		vtkSmartPointer<vtkPoints> intersectPoints =
			vtkSmartPointer<vtkPoints>::New();
		tree->IntersectWithLine(lineP0, lineP1, intersectPoints, NULL);

		double intersection[3];
		std::vector<double> squared_distances;
		for (int i = 0; i < intersectPoints->GetNumberOfPoints(); i++)
		{
			intersectPoints->GetPoint(i, intersection);
			double squaredDistance = vtkMath::Distance2BetweenPoints(lineP0, intersection);
			squared_distances.push_back(squaredDistance);
		}

		int index_of_min_elem = std::min_element(squared_distances.begin(), squared_distances.end()) - squared_distances.begin();
		closestIntersectPoints->InsertNextPoint(intersectPoints->GetPoint(index_of_min_elem));
	}

	vtkSmartPointer<vtkPolyData> closestIntersectPointsPolyData =
		vtkSmartPointer<vtkPolyData>::New();
	closestIntersectPointsPolyData->SetPoints(closestIntersectPoints);

	// Triangulate the grid points
	vtkSmartPointer<vtkDelaunay2D> delaunay =
		vtkSmartPointer<vtkDelaunay2D>::New();
	delaunay->SetInputData(closestIntersectPointsPolyData);
	delaunay->Update();

	vtkSmartPointer<vtkSTLWriter> stlWriter =
		vtkSmartPointer<vtkSTLWriter>::New();
	stlWriter->SetFileName("adhering_surface.stl");
	stlWriter->SetInputConnection(delaunay->GetOutputPort());
	stlWriter->Write();

	// Create a mapper and actor
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(delaunay->GetOutputPort());

	vtkSmartPointer<vtkActor> actor =
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetColor(1, 0, 0);

	renderer->AddActor(actor);
}

vtkSmartPointer<vtkPoints> MakeAdhering::GetPoints(){
	return pointsOn;
}

void MakeAdhering::SetRenderer(vtkRenderer* _renderer)
{
	renderer = _renderer;
}
