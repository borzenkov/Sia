#pragma once

#define WNT
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <TopoDS.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <GeomAPI_Interpolate.hxx>
#include <TColStd_HArray1OfBoolean.hxx>
#include <Geom_BSplineCurve.hxx>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkParametricSpline.h>
#include <vtkParametricFunctionSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkAppendPolyData.h>
#include <vtkProperty.h>
class Head
{
public:
	Head();
	~Head();
	void Change_s(double);
	void Change_t(double);
	void Change_u(double);
	void Change_v(double);
	void Change_w(double);
	void Change_x(double);
	void Change_y(double);
	double Get_s();
	double Get_t();
	double Get_u();
	double Get_v();
	double Get_w();
	double Get_x();
	double Get_y();
	void MakeHead();
	vtkSmartPointer<vtkActor> GetActor();
	TopoDS_Wire* GetWire();
private:
	double s, t, u, v, w, x, y, tang_ang_rad_x, tang_ang_rad_y;
	vtkSmartPointer<vtkPolyDataMapper> head_mapper;
	vtkSmartPointer<vtkActor> head_actor;
	TopoDS_Wire head_wire;
};

