#include "Junction.h"


Junction::Junction()
{
	DS = vtkSmartPointer<IVtkTools_ShapeDataSource>::New();
	junction_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	junction_actor = vtkSmartPointer<vtkActor>::New();
}


Junction::~Junction()
{
}

void Junction::SetHead(Head* _head){
	head = _head;
}
void Junction::SetPlate(Plate* _plate){
	plate = _plate;
}
void Junction::MakeJunction(){
	MakeFirstJunctionContour();
	MakeSecondJunctionContour();
	MakeThirdJunctionContour();
	//כמפע
	BRepOffsetAPI_ThruSections loft(Standard_True, Standard_False, /*1.0e-06*/1);
	loft.UseSmoothing();
	loft.AddWire(FirstJunctionContour);
	loft.AddWire(SecondJunctionContour);
	loft.AddWire(ThirdJunctionContour);
	loft.Build();
	junction_shape = loft.Shape();

	IVtkOCC_Shape::Handle aShapeImpl = new IVtkOCC_Shape(junction_shape);
	DS->SetShape(aShapeImpl);
	junction_mapper->SetInputConnection(DS->GetOutputPort());
	junction_actor->SetMapper(junction_mapper);
}
void Junction::MakeFirstJunctionContour(){
	double D[3] = { plate->Get_l(), plate->Get_h(), 0 };
	double E[3] = { plate->Get_m(), plate->Get_h(), 0 };
	double G[3] = {plate->Get_m(), plate->Get_h(), plate->Get_r()};
	double H[3] = {plate->Get_l(), plate->Get_h(), plate->Get_r()};

	vtkSmartPointer<vtkTransform> transform =
		vtkSmartPointer<vtkTransform>::New();
	transform->SetMatrix(plate->GetActor()->GetMatrix());
	transform->TransformPoint(D, D);
	transform->TransformPoint(E, E);
	transform->TransformPoint(G, G);
	transform->TransformPoint(H, H);

	// Profile : Define Support Points
	gp_Pnt PntD(D[0], D[1], D[2]);
	gp_Pnt PntE(E[0], E[1], E[2]);
	gp_Pnt PntG(G[0], G[1], G[2]);
	gp_Pnt PntH(H[0], H[1], H[2]);

	// Profile : Define the Geometry
	Handle(Geom_TrimmedCurve) deSegment = GC_MakeSegment(PntD, PntE);
	Handle(Geom_TrimmedCurve) egSegment = GC_MakeSegment(PntE, PntG);
	Handle(Geom_TrimmedCurve) ghSegment = GC_MakeSegment(PntG, PntH);
	Handle(Geom_TrimmedCurve) hdSegment = GC_MakeSegment(PntH, PntD);
	// Profile : Define the Topology
	TopoDS_Edge deEdge = BRepBuilderAPI_MakeEdge(deSegment);
	TopoDS_Edge egEdge = BRepBuilderAPI_MakeEdge(egSegment);
	TopoDS_Edge ghEdge = BRepBuilderAPI_MakeEdge(ghSegment);
	TopoDS_Edge hdEdge = BRepBuilderAPI_MakeEdge(hdSegment);

	BRepBuilderAPI_MakeWire Wire0(deEdge, egEdge, ghEdge, hdEdge);

	FirstJunctionContour = Wire0;
}
void Junction::MakeSecondJunctionContour(){
	double delta = 3;
	//Calculate ctg's
	double ctgalpha1 = (plate->Get_m()) / (plate->Get_h() - plate->Get_d());
	double ctgalpha2 = (plate->Get_l() - plate->Get_a()) / (plate->Get_h() - plate->Get_i());
	//Calculate new Xes
	double new_ex = plate->Get_m() + delta * ctgalpha1;
	double new_dx = plate->Get_l() + delta * ctgalpha2;

	double D[3] = { new_dx, plate->Get_h() + delta, 0 };
	double E[3] = { new_ex, plate->Get_h() + delta, 0 };
	double G[3] = { new_ex, plate->Get_h() + delta, plate->Get_r() };
	double H[3] = { new_dx, plate->Get_h() + delta, plate->Get_r() };

	vtkSmartPointer<vtkTransform> transform =
		vtkSmartPointer<vtkTransform>::New();
	transform->SetMatrix(plate->GetActor()->GetMatrix());
	transform->TransformPoint(D, D);
	transform->TransformPoint(E, E);
	transform->TransformPoint(G, G);
	transform->TransformPoint(H, H);

	// Profile : Define Support Points
	gp_Pnt PntD(D[0], D[1], D[2]);
	gp_Pnt PntE(E[0], E[1], E[2]);
	gp_Pnt PntG(G[0], G[1], G[2]);
	gp_Pnt PntH(H[0], H[1], H[2]);

	// Profile : Define the Geometry
	Handle(Geom_TrimmedCurve) deSegment = GC_MakeSegment(PntD, PntE);
	Handle(Geom_TrimmedCurve) egSegment = GC_MakeSegment(PntE, PntG);
	Handle(Geom_TrimmedCurve) ghSegment = GC_MakeSegment(PntG, PntH);
	Handle(Geom_TrimmedCurve) hdSegment = GC_MakeSegment(PntH, PntD);
	// Profile : Define the Topology
	TopoDS_Edge deEdge = BRepBuilderAPI_MakeEdge(deSegment);
	TopoDS_Edge egEdge = BRepBuilderAPI_MakeEdge(egSegment);
	TopoDS_Edge ghEdge = BRepBuilderAPI_MakeEdge(ghSegment);
	TopoDS_Edge hdEdge = BRepBuilderAPI_MakeEdge(hdSegment);

	BRepBuilderAPI_MakeWire Wire0(deEdge, egEdge, ghEdge, hdEdge);

	SecondJunctionContour = Wire0;
}
void Junction::MakeThirdJunctionContour(){
	ThirdJunctionContour = *head->GetWire();
	double a11 = head->GetActor()->GetMatrix()->GetElement(0, 0);
	double a12 = head->GetActor()->GetMatrix()->GetElement(0, 1);
	double a13 = head->GetActor()->GetMatrix()->GetElement(0, 2);
	double a14 = head->GetActor()->GetMatrix()->GetElement(0, 3);
	double a21 = head->GetActor()->GetMatrix()->GetElement(1, 0);
	double a22 = head->GetActor()->GetMatrix()->GetElement(1, 1);
	double a23 = head->GetActor()->GetMatrix()->GetElement(1, 2);
	double a24 = head->GetActor()->GetMatrix()->GetElement(1, 3);
	double a31 = head->GetActor()->GetMatrix()->GetElement(2, 0);
	double a32 = head->GetActor()->GetMatrix()->GetElement(2, 1);
	double a33 = head->GetActor()->GetMatrix()->GetElement(2, 2);
	double a34 = head->GetActor()->GetMatrix()->GetElement(2, 3);
	
	gp_Trsf T;
	T.SetValues(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34);
	BRepBuilderAPI_Transform trans(ThirdJunctionContour, T);
	ThirdJunctionContour = TopoDS::Wire(trans.Shape());
}
TopoDS_Shape* Junction::GetShape(){
	return &junction_shape;
}
vtkSmartPointer<vtkActor> Junction::GetActor()
{
	return junction_actor;
}