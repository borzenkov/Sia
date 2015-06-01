#pragma once

#define WNT
#include <gp_Pnt.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <GC_MakeSegment.hxx>
#include <gp_Pln.hxx>
#include <ChFi2d_FilletAPI.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <IVtkTools_ShapeDataSource.hxx>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>

class Plate
{
public:
	Plate();
	~Plate();
	void Change_a(double);
	void Change_d(double);
	void Change_h(double);
	void Change_i(double);
	void Change_k(double);
	void Change_l(double);
	void Change_m(double);
	void Change_n(double);
	void Change_r(double);
	double Get_a();
	double Get_d();
	double Get_h();
	double Get_i();
	double Get_k();
	double Get_l();
	double Get_m();
	double Get_n();
	double Get_r();
	void MakePlate();
	vtkSmartPointer<vtkActor> GetActor();
	TopoDS_Shape* GetShape();
	int IsRightSide();
	//1 is for right, 0 is for left
	void ChangeSide(int);
	vtkSmartPointer<vtkPolyData> GetPolyData();
private:
	double a, d, h, i, k, l, m, n, r;
	int isRightSide;
	vtkSmartPointer<IVtkTools_ShapeDataSource> DS;
	vtkSmartPointer<vtkPolyData> plate_polydata;
	vtkSmartPointer<vtkPolyDataMapper> plate_mapper;
	vtkSmartPointer<vtkActor> plate_actor;
	TopoDS_Shape plate;
};

