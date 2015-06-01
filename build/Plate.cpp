#include "Plate.h"


Plate::Plate()
{
	//Set default values
	a = 26;
	d = 45;
	h = 57;
	i = 49;
	k = 17;
	l = 28;
	m = 11;
	n = 1;
	r = 5;
	isRightSide = 0;

	DS = vtkSmartPointer<IVtkTools_ShapeDataSource>::New();
	plate_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	plate_actor = vtkSmartPointer<vtkActor>::New();
}


Plate::~Plate()
{
}

void Plate::MakePlate()
{
	gp_Pnt pnt_a(0, 0, 0);
	gp_Pnt pnt_b(a, k, 0);
	gp_Pnt pnt_c(a, i, 0);
	gp_Pnt pnt_d(l, h, 0);
	gp_Pnt pnt_e(m, h, 0);
	gp_Pnt pnt_f(0, d, 0);

	Handle(Geom_TrimmedCurve) abSegment = GC_MakeSegment(pnt_a, pnt_b);
	Handle(Geom_TrimmedCurve) bcSegment = GC_MakeSegment(pnt_b, pnt_c);
	Handle(Geom_TrimmedCurve) cdSegment = GC_MakeSegment(pnt_c, pnt_d);
	Handle(Geom_TrimmedCurve) deSegment = GC_MakeSegment(pnt_d, pnt_e);
	Handle(Geom_TrimmedCurve) efSegment = GC_MakeSegment(pnt_e, pnt_f);
	Handle(Geom_TrimmedCurve) faSegment = GC_MakeSegment(pnt_f, pnt_a);

	TopoDS_Edge abEdge = BRepBuilderAPI_MakeEdge(abSegment);
	TopoDS_Edge bcEdge = BRepBuilderAPI_MakeEdge(bcSegment);
	TopoDS_Edge cdEdge = BRepBuilderAPI_MakeEdge(cdSegment);
	TopoDS_Edge deEdge = BRepBuilderAPI_MakeEdge(deSegment);
	TopoDS_Edge efEdge = BRepBuilderAPI_MakeEdge(efSegment);
	TopoDS_Edge faEdge = BRepBuilderAPI_MakeEdge(faSegment);

	/*Fillets*/
	gp_Pln aPlane(gp::XOY());
	//скругление в точке A
	ChFi2d_FilletAPI filletAlg(faEdge, abEdge, aPlane);
	filletAlg.Perform(n);
	TopoDS_Edge A_fillet = filletAlg.Result(pnt_a, faEdge, abEdge);

	//скругление в точке B
	ChFi2d_FilletAPI filletAlg2(abEdge, bcEdge, aPlane);
	filletAlg2.Perform(n);
	TopoDS_Edge B_fillet = filletAlg2.Result(pnt_b, abEdge, bcEdge);

	//скругление в точке C
	ChFi2d_FilletAPI filletAlg3(bcEdge, cdEdge, aPlane);
	filletAlg3.Perform(n);
	TopoDS_Edge C_fillet = filletAlg3.Result(pnt_c, bcEdge, cdEdge);

	//скругление в точке F
	ChFi2d_FilletAPI filletAlg4(faEdge, efEdge, aPlane);
	filletAlg4.Perform(n);
	TopoDS_Edge F_fillet = filletAlg4.Result(pnt_f, faEdge, efEdge);

	BRepBuilderAPI_MakeWire Wire0(abEdge, B_fillet, bcEdge, C_fillet);
	Wire0.Add(cdEdge);
	Wire0.Add(deEdge);
	Wire0.Add(efEdge);
	Wire0.Add(F_fillet);
	Wire0.Add(faEdge);
	Wire0.Add(A_fillet);
	TopoDS_Wire Wire = Wire0;

	TopoDS_Face myFaceProfile = BRepBuilderAPI_MakeFace(Wire);
	gp_Vec aPrismVec(0, 0, r);
	plate = BRepPrimAPI_MakePrism(myFaceProfile, aPrismVec);
	IVtkOCC_Shape::Handle aShapeImpl = new IVtkOCC_Shape(plate);
	DS->SetShape(aShapeImpl);
	plate_mapper->SetInputConnection(DS->GetOutputPort());
	plate_actor->SetMapper(plate_mapper);
	plate_polydata = vtkSmartPointer<vtkPolyData>::New();
	plate_polydata = vtkPolyData::SafeDownCast(plate_mapper->GetInputAsDataSet());
}

TopoDS_Shape* Plate::GetShape()
{
	return &plate;
}

void Plate::Change_a(double _a)
{
	if (_a > m && _a < l && _a > 0)
	{
		a = _a;
		MakePlate();
	}
}
void Plate::Change_d(double _d){
	if (_d < i && _d > k && _d > 0)
	{
		d = _d;
		MakePlate();
	}
}
void Plate::Change_h(double _h){
	if (h >= i && h > 0)
	{
		h = _h;
		MakePlate();
	}
	else
	{
		h = i;
		MakePlate();
	}
}
void Plate::Change_i(double _i){
	if (_i > d && _i < h && _i > 0)
	{
		i = _i;
		MakePlate();
	}
}
void Plate::Change_k(double _k){
	if (_k < d && _k > 0)
	{
		k = _k;
		MakePlate();
	}
}
void Plate::Change_l(double _l){
	if (_l > m && _l > a && _l > 0)
	{
		l = _l;
		MakePlate();
	}
}
void Plate::Change_m(double _m){
	if (_m < l && _m < a && _m > 0)
	{
		m = _m;
		MakePlate();
	}
}
void Plate::Change_n(double _n){
	if (_n > 0 && _n < a / 2.0)
	{
		n = _n;
		MakePlate();
	}
}
void Plate::Change_r(double _r){
	if (_r > 0)
	{
		r = _r;
		MakePlate();
	}
}

vtkSmartPointer<vtkActor> Plate::GetActor()
{
	return plate_actor;
}

double Plate::Get_a()
{
	return a;
}
double Plate::Get_d(){
	return d;
}
double Plate::Get_h(){
	return h;
}
double Plate::Get_i(){
	return i;
}
double Plate::Get_k(){
	return k;
}
double Plate::Get_l(){
	return l;
}
double Plate::Get_m(){
	return m;
}
double Plate::Get_n(){
	return n;
}
double Plate::Get_r(){
	return r;
}

int Plate::IsRightSide()
{
	return isRightSide;
}

void Plate::ChangeSide(int x){
	isRightSide = x;
}

vtkSmartPointer<vtkPolyData> Plate::GetPolyData()
{
	return plate_polydata;
}