#pragma once
#include "Head.h"
#include "Plate.h"
#include "BRepOffsetAPI_ThruSections.hxx"
#include "BRepBuilderAPI_Transform.hxx"
class Junction
{
public:
	Junction();
	~Junction();
	void SetHead(Head*);
	void SetPlate(Plate*);
	void MakeJunction();
	TopoDS_Shape* GetShape();
	vtkSmartPointer<vtkActor> GetActor();
private:
	Head* head;
	Plate* plate;
	void MakeFirstJunctionContour();
	TopoDS_Wire FirstJunctionContour;
	void MakeSecondJunctionContour();
	TopoDS_Wire SecondJunctionContour;
	void MakeThirdJunctionContour();
	TopoDS_Wire ThirdJunctionContour;
	TopoDS_Shape junction_shape;
	vtkSmartPointer<vtkActor> junction_actor;
	vtkSmartPointer<IVtkTools_ShapeDataSource> DS;
	vtkSmartPointer<vtkPolyDataMapper> junction_mapper;
};

