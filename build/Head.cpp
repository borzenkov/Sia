#include "Head.h"


Head::Head()
{
	//Set default values
	s = 5;
	t = 15;
	u = 22;
	v = 6;
	w = 6;
	x = 13;
	y = -13;
	head_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	head_actor = vtkSmartPointer<vtkActor>::New();
}
Head::~Head()
{
}

void Head::Change_s(double _s){
	if (_s < t && _s > 0)
	{
		s = _s;
		MakeHead();
	}
}
void Head::Change_t(double _t){
	if (_t < u && _t > s && _t > 0)
	{
		t = _t;
		MakeHead();
	}
}
void Head::Change_u(double _u){
	if (_u > t && _u > s && _u > 0)
	{
		u = _u;
		MakeHead();
	}
}
void Head::Change_v(double _v){
	if (_v > 0)
	{
		v = _v;
		MakeHead();
	}
}
void Head::Change_w(double _w){
	if (_w > 0)
	{
		w = _w;
		MakeHead();
	}
}
void Head::Change_x(double _x){
	x = _x;
	MakeHead();
}
void Head::Change_y(double _y){
	y = _y;
	MakeHead();
}

double Head::Get_s(){
	return s;
}
double Head::Get_t(){
	return t;
}
double Head::Get_u(){
	return u;
}
double Head::Get_v(){
	return v;
}
double Head::Get_w(){
	return w;
}
double Head::Get_x(){
	return x;
}
double Head::Get_y(){
	return y;
}

void Head::MakeHead(){
	//головка-тело, полученное вращением вокруг оси симметрии
	//сплайна из 4 точек
	gp_Pnt Pnt1(0, 0, 0);
	gp_Pnt Pnt2(s, 0, v);
	gp_Pnt Pnt3(t, 0, w);
	gp_Pnt Pnt4(u, 0, 0);

	gp_Vec Vec(u, 0, 0); //¬ектор, задающий ось вращени¤ контура
	gp_Dir Dir(Vec);
	gp_Ax1 HeadAxis(Pnt4, Dir);

	tang_ang_rad_x = (x * M_PI) / 180;
	tang_ang_rad_y = (y * M_PI) / 180;
	gp_Vec Vec1(0, 0, 1); //¬-р, задающий касательное направление в первой точке сплайна
	gp_Vec Vec2(cos(tang_ang_rad_x), 0, sin(tang_ang_rad_x));
	gp_Vec Vec3(cos(tang_ang_rad_y), 0, sin(tang_ang_rad_y));
	gp_Vec Vec4(-Vec1); //¬-р, задающий касаткльное направление в последней точке сплайна

	TColgp_Array1OfPnt CurvePoles(1, 4);
	CurvePoles(1) = Pnt1;
	CurvePoles(2) = Pnt2;
	CurvePoles(3) = Pnt3;
	CurvePoles(4) = Pnt4;

	TColgp_Array1OfVec tang(1, 4);
	tang(1) = Vec1;
	tang(2) = Vec2;
	tang(3) = Vec3;
	tang(4) = Vec4;

	Handle(TColgp_HArray1OfPnt) points = new TColgp_HArray1OfPnt(1, 4);
	points->SetValue(1, Pnt1);
	points->SetValue(2, Pnt2);
	points->SetValue(3, Pnt3);
	points->SetValue(4, Pnt4);
	GeomAPI_Interpolate curve(points, Standard_False, 1.0e-7);
	curve.Perform();
	Handle(TColStd_HArray1OfBoolean) bools = new TColStd_HArray1OfBoolean(1, 4);
	bools->SetValue(1, Standard_True);
	bools->SetValue(2, Standard_True);
	bools->SetValue(3, Standard_True);
	bools->SetValue(4, Standard_True);
	curve.Load(tang, bools);
	curve.Perform();

	Handle(Geom_BSplineCurve) C = curve.Curve();
	TopoDS_Edge E = BRepBuilderAPI_MakeEdge(C);//не работает без хэндла!!!

	head_wire = BRepBuilderAPI_MakeWire(E);

	//Creating the contour to be used in making loft
	TopoDS_Wire aWire(head_wire);
	gp_Trsf aTrsf;
	aTrsf.SetMirror(gp::OX());
	BRepBuilderAPI_Transform aBRepTrsf(aWire, aTrsf);
	TopoDS_Shape aMirroredShape = aBRepTrsf.Shape();
	TopoDS_Wire aMirroredWire = TopoDS::Wire(aMirroredShape);

	BRepBuilderAPI_MakeWire mkWire;
	mkWire.Add(aWire);
	mkWire.Add(aMirroredWire);
	head_wire = mkWire.Wire();

	gp_Pnt gpPnt;
	double dPnt[3];
	vtkSmartPointer<vtkPoints> pointsOnCurve = vtkSmartPointer<vtkPoints>::New();
	for (double i = C->FirstParameter(); i <= C->LastParameter(); i += 1)
	{
		C->D0(i, gpPnt);
		dPnt[0] = gpPnt.X();
		dPnt[1] = gpPnt.Y();
		dPnt[2] = gpPnt.Z();
		pointsOnCurve->InsertNextPoint(dPnt);
	}
	vtkSmartPointer<vtkParametricSpline> spline =
		vtkSmartPointer<vtkParametricSpline>::New();
	spline->SetPoints(pointsOnCurve);

	vtkSmartPointer<vtkParametricFunctionSource> functionSource =
		vtkSmartPointer<vtkParametricFunctionSource>::New();
	functionSource->SetParametricFunction(spline);
	functionSource->Update();

	vtkSmartPointer<vtkTransform> rotation =
		vtkSmartPointer<vtkTransform>::New();
	rotation->RotateX(180);

	vtkSmartPointer<vtkTransformPolyDataFilter> transformFilter =
		vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	transformFilter->SetInputConnection(functionSource->GetOutputPort());
	transformFilter->SetTransform(rotation);
	transformFilter->Update();

	//Append the two meshes 
	vtkSmartPointer<vtkAppendPolyData> appendFilter =
		vtkSmartPointer<vtkAppendPolyData>::New();
	appendFilter->AddInputConnection(functionSource->GetOutputPort());
	appendFilter->AddInputConnection(transformFilter->GetOutputPort());
	appendFilter->Update();

	vtkSmartPointer<vtkTransform> rotation2 =
		vtkSmartPointer<vtkTransform>::New();
	rotation2->RotateX(90);
	vtkSmartPointer<vtkTransformPolyDataFilter> transformFilter2 =
		vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	transformFilter2->SetInputConnection(appendFilter->GetOutputPort());
	transformFilter2->SetTransform(rotation2);
	transformFilter2->Update();

	//Append the two meshes 
	vtkSmartPointer<vtkAppendPolyData> appendFilter2 =
		vtkSmartPointer<vtkAppendPolyData>::New();
	appendFilter2->AddInputConnection(appendFilter->GetOutputPort());
	appendFilter2->AddInputConnection(transformFilter2->GetOutputPort());
	appendFilter2->Update();

	vtkSmartPointer<vtkTransform> rotation3 =
		vtkSmartPointer<vtkTransform>::New();
	rotation3->RotateX(45);
	vtkSmartPointer<vtkTransformPolyDataFilter> transformFilter3 =
		vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	transformFilter3->SetInputConnection(appendFilter2->GetOutputPort());
	transformFilter3->SetTransform(rotation3);
	transformFilter3->Update();

	//Append the two meshes 
	vtkSmartPointer<vtkAppendPolyData> appendFilter3 =
		vtkSmartPointer<vtkAppendPolyData>::New();
	appendFilter3->AddInputConnection(appendFilter2->GetOutputPort());
	appendFilter3->AddInputConnection(transformFilter3->GetOutputPort());
	appendFilter3->Update();

	vtkSmartPointer<vtkTransform> rotation4 =
		vtkSmartPointer<vtkTransform>::New();
	rotation4->RotateX(22.5);
	vtkSmartPointer<vtkTransformPolyDataFilter> transformFilter4 =
		vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	transformFilter4->SetInputConnection(appendFilter3->GetOutputPort());
	transformFilter4->SetTransform(rotation4);
	transformFilter4->Update();

	//Append the two meshes 
	vtkSmartPointer<vtkAppendPolyData> appendFilter4 =
		vtkSmartPointer<vtkAppendPolyData>::New();
	appendFilter4->AddInputConnection(appendFilter3->GetOutputPort());
	appendFilter4->AddInputConnection(transformFilter4->GetOutputPort());
	appendFilter4->Update();

	head_mapper->SetInputConnection(appendFilter4->GetOutputPort());
	head_actor->SetMapper(head_mapper);
	head_actor->GetProperty()->SetLineWidth(3);
}

vtkSmartPointer<vtkActor> Head::GetActor(){
	return head_actor;
}

TopoDS_Wire* Head::GetWire(){
	return &head_wire;
}