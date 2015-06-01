#ifndef Sia_H
#define Sia_H
 
#include <QMainWindow>
#include <QFile>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include <QListWidgetItem>

//added for opening STL
#include <vtkPolyData.h>
#include <vtkSTLReader.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>

//added for axes
#include <vtkAxesActor.h>
#include <vtkOrientationMarkerWidget.h>


////added for CGAL
//#define _SCL_SECURE_NO_WARNINGS //The program won't compile without this string
//#define _CRT_SECURE_NO_WARNINGS
//#include <CGAL/Cartesian.h>
//#include <CGAL/Polyhedron_3.h>
//#include <CGAL/IO/Polyhedron_iostream.h>
//#include <CGAL/parameterize.h>
//#include <CGAL/Simple_cartesian.h>
//#include <CGAL/AABB_tree.h>
//#include <CGAL/AABB_traits.h>
//#include <CGAL/AABB_polyhedron_triangle_primitive.h>
//#include <CGAL/aff_transformation_tags.h>
//#include <CGAL/Polyhedron_traits_with_normals_3.h>
//typedef CGAL::Cartesian<double> Kernel;
//typedef CGAL::Polyhedron_traits_with_normals_3<Kernel> Polyhedron_traits_with_normals_3;
//typedef CGAL::Polyhedron_3<Polyhedron_traits_with_normals_3/*Kernel*/> Polyhedron;
//typedef Polyhedron::Facet_iterator Facet_iterator;
//typedef Polyhedron::Vertex_iterator Vertex_iterator;
//typedef Polyhedron::Point_iterator Point_iterator;
//typedef Polyhedron::Edge_iterator Edge_iterator;
//typedef Polyhedron::Plane_iterator Plane_iterator;
//typedef Polyhedron::Halfedge_iterator Halfedge_iterator;
//typedef Polyhedron::Halfedge_around_facet_circulator Halfedge_facet_circulator;
//typedef Polyhedron::Halfedge_around_vertex_circulator Halfedge_around_vertex_circulator;
//typedef Kernel::Point_3 Point_3;
//typedef Kernel::Vector_3 Vector_3;
//typedef Polyhedron::HalfedgeDS HalfedgeDS;
//typedef Kernel::Ray_3 Ray;
//typedef CGAL::AABB_polyhedron_triangle_primitive<Kernel, Polyhedron> Primitive;
//typedef CGAL::AABB_traits<Kernel, Primitive> Traits;
//typedef CGAL::AABB_tree<Traits> Tree;
//typedef boost::optional< Tree::Intersection_and_primitive_id<Ray>::Type > Ray_intersection;
//typedef CGAL::Translation Translation;
//typedef CGAL::Aff_transformation_3<Kernel> Aff_transformation_3;
//typedef Kernel::Direction_3 Direction_3;

//added for vtk
#include <vtkCellArray.h>
#include <vtkTriangle.h>

//added for transformation matrix
#include <vtkMatrix4x4.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>

#include <vtkSelectPolyData.h>
#include <vtkClipPolyData.h>
#include <vtkLODActor.h>

//added for triangles selection
#include "MouseInteractorStyle.h"
#include <vtkSelectEnclosedPoints.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkDelaunay2D.h>

#include "Plate.h"
#include "Head.h"
#include "Junction.h"
#include "MakeAdhering.h"

// Forward Qt class declarations
class Ui_Sia;

//// A modifier creating a triangle with the incremental builder.
//template<class HDS>
//class polyhedron_builder : public CGAL::Modifier_base<HDS> {
//public:
//	std::vector<double> &coords;
//	std::vector<int>    &tris;
//	polyhedron_builder(std::vector<double> &_coords, std::vector<int> &_tris) : coords(_coords), tris(_tris) {}
//	void operator()(HDS& hds) {
//		typedef typename HDS::Vertex   Vertex;
//		typedef typename Vertex::Point Point;
//		// create a cgal incremental builder
//		CGAL::Polyhedron_incremental_builder_3<HDS> B(hds, true);
//		B.begin_surface(coords.size() / 3, tris.size() / 3);
//		// add the polyhedron vertices
//		for (int i = 0; i<(int)coords.size(); i += 3){
//			B.add_vertex(Point(coords[i + 0], coords[i + 1], coords[i + 2]));
//		}
//		//	 add the polyhedron triangles
//		for (int i = 0; i<(int)tris.size(); i += 3){
//			B.begin_facet();
//			B.add_vertex_to_facet(tris[i + 0]);
//			B.add_vertex_to_facet(tris[i + 1]);
//			B.add_vertex_to_facet(tris[i + 2]);
//			B.end_facet();
//		}
//		// finish up the surface
//		B.end_surface();
//	}
//};

class Object
{
public:
	Object(std::string name, vtkSmartPointer<vtkSTLReader> reader) :
		name(name),
		polyData(reader->GetOutput()),
		originalPolyData(reader->GetOutput()),
		mapper(vtkSmartPointer<vtkPolyDataMapper>::New()),
		actor(vtkSmartPointer<vtkActor>::New()),
		matrix(vtkSmartPointer<vtkMatrix4x4>::New())
	{
		mapper->SetInputData(polyData);
		actor->SetMapper(mapper);
	}

	~Object()
	{}

	vtkSmartPointer<vtkActor> GetActor()
	{
		return actor;
	}

	std::string GetName()
	{
		return name;
	}

	void SetMatrix(vtkMatrix4x4* new_matrix)
	{
		matrix->DeepCopy(new_matrix);
	}
	
	void TransformPolyData()
	{
		vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
		transform->SetMatrix(matrix);

		vtkSmartPointer<vtkTransformPolyDataFilter> filter = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
		filter->SetTransform(transform);
		filter->SetInputData(polyData);
		filter->Update();

		polyData->DeepCopy(filter->GetOutput());
		actor->GetMatrix()->Identity();
	}

	vtkSmartPointer<vtkPolyData> GetPolyData()
	{
		return polyData;
	}

	vtkSmartPointer<vtkPolyData> GetOriginalPolyData()
	{
		return originalPolyData;
	}

	vtkSmartPointer<vtkCellArray> GetCells()
	{
		cells = polyData->GetPolys();
		return cells;
	}

	vtkSmartPointer<vtkMatrix4x4> GetMatrix()
	{
		return matrix;
	}

private:
	std::string name;
	vtkSmartPointer<vtkPolyData> polyData;
	vtkSmartPointer<vtkPolyData> originalPolyData;
	vtkSmartPointer<vtkPolyDataMapper> mapper;
	vtkSmartPointer<vtkActor> actor;
	vtkSmartPointer<vtkMatrix4x4> matrix;
	vtkSmartPointer<vtkCellArray> cells;
};

class Sia : public QMainWindow
{
	Q_OBJECT
public:
	// Constructor/Destructor
	Sia(); 
	~Sia(){};
 
public slots:
	//void OpenSTL();
	//void ConnectCGALpolyhedronWithVtkActor(/*Polyhedron &, vtkSmartPointer<vtkActor>*/);
	//void ShowObject();
	//void HideObject();
	//void listWidgetItemClicked(QListWidgetItem *);
	//void ChangeOriginX(double);
	//void ChangeOriginY(double);
	//void ChangeOriginZ(double);
	//void ChangeAngleX(double);
	//void ChangeAngleY(double);
	//void ChangeAngleZ(double);
	//void Scale(double);
	//void AcceptTransformations();
	//void ReverseTransformations();
	//void SelectPlaneToProject();
	//void ConvertVtkPolyDataToCgalPolyhedron(vtkPolyData*, Polyhedron&);
	//void project_point_onto_surface(Point_iterator &, Tree &, Vector_3 &);
	//void CreateAdheringSurface(Vector_3, Polyhedron &,
	//	Polyhedron &, Polyhedron &);
	//void AcceptSelectedProjectingObjects();
	//void Project();
	//void FormPointsCloud();

	void MakePlate();
	void ChangePlate_a(double);
	void ChangePlate_d(double);
	void ChangePlate_h(double);
	void ChangePlate_i(double);
	void ChangePlate_k(double);
	void ChangePlate_l(double);
	void ChangePlate_m(double);
	void ChangePlate_n(double);
	void ChangePlate_r(double);
	void ChangePlate_side(int);
	void ChangePlateActor_dx(double);
	void ChangePlateActor_dy(double);
	void ChangePlateActor_dz(double);
	void ChangePlateActor_angle_x(double);
	void ChangePlateActor_angle_y(double);
	void ChangePlateActor_angle_z(double);
	void ChangePlateActorVisibility(int);

	void MakeHead();
	void ChangeHead_s(double);
	void ChangeHead_t(double);
	void ChangeHead_u(double);
	void ChangeHead_v(double);
	void ChangeHead_w(double);
	void ChangeHead_x(double);
	void ChangeHead_y(double);
	void ChangeHeadActor_dx(double);
	void ChangeHeadActor_dy(double);
	void ChangeHeadActor_dz(double);
	void ChangeHeadActor_angle_x(double);
	void ChangeHeadActor_angle_y(double);
	void ChangeHeadActor_angle_z(double);

	void OpenLowerJaw();
	void ChangeLowerJawVisibility(int);
	void Adhering();

	void MakeJunction();

private:
	// Designer form
	Ui_Sia *ui;

	std::vector<Object> objectsList;
	vtkSmartPointer<vtkAxesActor> axes;
	vtkSmartPointer<vtkRenderer> renderer;
	QListWidgetItem *selectedItem;
	vtkSmartPointer<vtkOrientationMarkerWidget> axesWidget;
	vtkSmartPointer<MouseInteractorStyle> style;
	vtkSmartPointer<vtkInteractorStyleTrackballCamera> default_style;
	vtkSmartPointer<vtkPolyData> contour_to_project;
	vtkSmartPointer<vtkPolyData> surface_to_project_on;
	vtkSmartPointer<vtkPolyData> points_to_project;
	Plate plate;
	Head head;
	Junction junction;
	vtkSmartPointer<vtkPolyData> lower_jaw_polydata;
	vtkSmartPointer<vtkActor> lower_jaw_actor;
	MakeAdhering mk_adhering;
};

#endif
