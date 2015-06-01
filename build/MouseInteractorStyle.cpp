#include "MouseInteractorStyle.h"

MouseInteractorStyle::MouseInteractorStyle():
picker(vtkSmartPointer<vtkCellPicker>::New()),
ids(vtkSmartPointer<vtkIdTypeArray>::New()),
selection(vtkSmartPointer<vtkSelection>::New()),
selectionNode(vtkSmartPointer<vtkSelectionNode>::New())
{
	selectedMapper = vtkSmartPointer<vtkDataSetMapper>::New();
	selectedActor = vtkSmartPointer<vtkActor>::New();
	picker->SetTolerance(0.0005);
	ids->SetNumberOfComponents(1);
	selectionNode->SetFieldType(vtkSelectionNode::CELL);
	selectionNode->SetContentType(vtkSelectionNode::INDICES);
	selectionNode->SetSelectionList(ids);
	selection->AddNode(selectionNode);
}

void MouseInteractorStyle::OnLeftButtonDown()
{
	// Get the location of the click (in window coordinates)
	int* pos = this->GetInteractor()->GetEventPosition();

	// Pick from this location.
	picker->Pick(pos[0], pos[1], 0, this->GetDefaultRenderer()); 

	projection_vector[0] = picker->GetPickNormal()[0];
	projection_vector[1] = picker->GetPickNormal()[1];
	projection_vector[2] = picker->GetPickNormal()[2];

	vtkIdType cellId = picker->GetCellId();
	if (cellId != -1)
	{
		vtkActor* clickedActor = picker->GetActor();
		vtkPoints* pickedPoints = clickedActor->GetMapper()->GetInput()->GetCell(cellId)->GetPoints();
		double a[3] = {
			pickedPoints->GetPoint(0)[0],
			pickedPoints->GetPoint(0)[1],
			pickedPoints->GetPoint(0)[2]
		};
		double b[3] = {
			pickedPoints->GetPoint(1)[0],
			pickedPoints->GetPoint(1)[1],
			pickedPoints->GetPoint(1)[2]
		};
		double c[3] = {
			pickedPoints->GetPoint(2)[0],
			pickedPoints->GetPoint(2)[1],
			pickedPoints->GetPoint(2)[2]
		};
		for (int i = 0; i < clickedActor->GetMapper()->GetInput()->GetNumberOfCells(); i++)
		{
			vtkPoints* currentPoints = clickedActor->GetMapper()->GetInput()->GetCell(i)->GetPoints();
			double d[3] = {
				currentPoints->GetPoint(0)[0],
				currentPoints->GetPoint(0)[1],
				currentPoints->GetPoint(0)[2]
			};
			double e[3] = {
				currentPoints->GetPoint(1)[0],
				currentPoints->GetPoint(1)[1],
				currentPoints->GetPoint(1)[2]
			};
			double f[3] = {
				currentPoints->GetPoint(2)[0],
				currentPoints->GetPoint(2)[1],
				currentPoints->GetPoint(2)[2]
			};
			int isCoplanar = 0;
			double pnt1[3], pnt2[3];
			vtkIntersectionPolyDataFilter::TriangleTriangleIntersection(a, b, c, d, e, f, isCoplanar, pnt1, pnt2);
			if (isCoplanar)
			{
				ids->InsertNextValue(i);
			}
		}
		vtkSmartPointer<vtkExtractSelection> extractSelection =
			vtkSmartPointer<vtkExtractSelection>::New();

		vtkSmartPointer<vtkPolyData> Data = vtkPolyData::SafeDownCast(
			clickedActor->GetMapper()->GetInputAsDataSet());

		extractSelection->SetInputData(0, Data);
		extractSelection->SetInputData(1, selection);
		extractSelection->Update();

		// In selection
		vtkSmartPointer<vtkUnstructuredGrid> selected =
			vtkSmartPointer<vtkUnstructuredGrid>::New();
		selected->ShallowCopy(extractSelection->GetOutput());

		vtkSmartPointer<vtkGeometryFilter> geometryFilter =
			vtkSmartPointer<vtkGeometryFilter>::New();

		geometryFilter->SetInputData(selected);
		geometryFilter->Update();

		vtkSmartPointer<vtkFeatureEdges> featureEdges =
			vtkSmartPointer<vtkFeatureEdges>::New();
		featureEdges->SetInputData(geometryFilter->GetOutput());
		featureEdges->BoundaryEdgesOn();
		featureEdges->FeatureEdgesOff();
		featureEdges->ManifoldEdgesOff();
		featureEdges->NonManifoldEdgesOff();
		featureEdges->Update();

		contour_to_project = featureEdges->GetOutput();

		selectedMapper->SetInputConnection(featureEdges->GetOutputPort());
		selectedActor->SetMapper(selectedMapper);
		selectedActor->GetProperty()->SetColor(1, 0, 0);
		selectedActor->GetProperty()->SetOpacity(0.5);
		selectedActor->GetProperty()->SetLineWidth(3);

		this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(selectedActor);
	}
	// Forward events
	vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
}

void MouseInteractorStyle::OnRightButtonDown()
{
	// Get the location of the click (in window coordinates)
	int* pos = this->GetInteractor()->GetEventPosition();

	// Pick from this location.
	picker->Pick(pos[0], pos[1], 0, this->GetDefaultRenderer());

	vtkIdType cellId = picker->GetCellId();
	if (cellId != -1)
	{
		vtkActor* clickedActor = picker->GetActor();
		surface_to_project_on = vtkPolyData::SafeDownCast(
			clickedActor->GetMapper()->GetInputAsDataSet());
		clickedActor->GetProperty()->SetColor(0, 1, 0);
		clickedActor->GetProperty()->SetOpacity(0.5);
	}
	// Forward events
	vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
}

vtkStandardNewMacro(MouseInteractorStyle);