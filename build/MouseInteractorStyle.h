#pragma once

#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkVersion.h>
#include <vtkRendererCollection.h>
#include <vtkDataSetMapper.h>
#include <vtkUnstructuredGrid.h>
#include <vtkIdTypeArray.h>
#include <vtkCommand.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkCellPicker.h>
#include <vtkProperty.h>
#include <vtkSelectionNode.h>
#include <vtkSelection.h>
#include <vtkExtractSelection.h>
#include <vtkObjectFactory.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkIntersectionPolyDataFilter.h>
#include <vtkFeatureEdges.h>
#include <vtkGeometryFilter.h>
#include <vtkDoubleArray.h>
#include <vtkCellData.h>
#include <vtkMath.h>

class MouseInteractorStyle :
	public vtkInteractorStyleTrackballCamera
{
public:
	static MouseInteractorStyle* New();
	MouseInteractorStyle();
	virtual void OnLeftButtonDown();
	virtual void OnRightButtonDown();

	vtkSmartPointer<vtkPolyData> contour_to_project;
	vtkSmartPointer<vtkPolyData> surface_to_project_on;
	vtkSmartPointer<vtkDataSetMapper> selectedMapper;
	vtkSmartPointer<vtkActor> selectedActor;
	vtkSmartPointer<vtkCellPicker> picker;
	vtkSmartPointer<vtkIdTypeArray> ids;
	vtkSmartPointer<vtkSelectionNode> selectionNode;
	vtkSmartPointer<vtkSelection> selection;
	double projection_vector[3];
};

