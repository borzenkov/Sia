#include "Sia.h"

// This is included here because it is forward declared in
// Sia.h
#include "ui_Sia.h"

// Constructor
Sia::Sia() :
renderer(vtkSmartPointer<vtkRenderer>::New()),
axes(vtkSmartPointer<vtkAxesActor>::New()),
axesWidget(vtkSmartPointer<vtkOrientationMarkerWidget>::New()),
style(vtkSmartPointer<MouseInteractorStyle>::New()),
default_style(vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New())
{
	default_style->SetDefaultRenderer(renderer);
	
	this->ui = new Ui_Sia;
	this->ui->setupUi(this);

	this->ui->qvtkWidget->GetInteractor()->SetInteractorStyle(default_style);

	// VTK/Qt wedded
	this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(this->renderer);

	renderer->SetGradientBackground(true);
	renderer->SetBackground(156 / 256.0, 198 / 256.0, 180 / 256.0);
	renderer->SetBackground2(231 / 256.0, 241 / 256.0, 237 / 256.0);

	renderer->ResetCamera();
	this->ui->qvtkWidget->GetRenderWindow()->Render();

	axesWidget->SetOutlineColor(0.9300, 0.5700, 0.1300);
	axesWidget->SetOrientationMarker(axes);
	axesWidget->SetInteractor(this->ui->qvtkWidget->GetInteractor());
	axesWidget->SetViewport(0.0, 0.0, 0.4, 0.4);
	axesWidget->SetEnabled(1);
	axesWidget->InteractiveOff();
		
	QFile file("C:/DEV/StudyingProjects/Sia/SiaStyleSheet.css");
	if (file.open(QFile::ReadOnly))
	{
		QString styleSheet = QLatin1String(file.readAll());
		file.close();
		setStyleSheet(styleSheet);
	}

	connect(ui->make_plate, SIGNAL(clicked()),
		this, SLOT(MakePlate()));
	connect(ui->plate_a, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlate_a(double)));
	connect(ui->plate_d, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlate_d(double)));
	connect(ui->plate_h, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlate_h(double)));
	connect(ui->plate_i, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlate_i(double)));
	connect(ui->plate_k, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlate_k(double)));
	connect(ui->plate_l, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlate_l(double)));
	connect(ui->plate_m, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlate_m(double)));
	connect(ui->plate_n, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlate_n(double)));
	connect(ui->plate_r, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlate_r(double)));
	connect(ui->plate_actor_origin_x, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlateActor_dx(double)));
	connect(ui->plate_actor_origin_y, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlateActor_dy(double)));
	connect(ui->plate_actor_origin_z, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlateActor_dz(double)));
	connect(ui->plate_actor_angle_x, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlateActor_angle_x(double)));
	connect(ui->plate_actor_angle_y, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlateActor_angle_y(double)));
	connect(ui->plate_actor_angle_z, SIGNAL(valueChanged(double)),
		this, SLOT(ChangePlateActor_angle_z(double)));
	connect(ui->make_head, SIGNAL(clicked()),
		this, SLOT(MakeHead()));
	connect(ui->head_s, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHead_s(double)));
	connect(ui->head_t, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHead_t(double)));
	connect(ui->head_u, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHead_u(double)));
	connect(ui->head_v, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHead_v(double)));
	connect(ui->head_w, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHead_w(double)));
	connect(ui->head_x, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHead_x(double)));
	connect(ui->head_y, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHead_y(double)));
	connect(ui->head_actor_origin_x, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHeadActor_dx(double)));
	connect(ui->head_actor_origin_y, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHeadActor_dy(double)));
	connect(ui->head_actor_origin_z, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHeadActor_dz(double)));
	connect(ui->head_actor_angle_x, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHeadActor_angle_x(double)));
	connect(ui->head_actor_angle_y, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHeadActor_angle_y(double)));
	connect(ui->head_actor_angle_z, SIGNAL(valueChanged(double)),
		this, SLOT(ChangeHeadActor_angle_z(double)));
	connect(this->ui->plate_visibility, SIGNAL(stateChanged(int)),
		this, SLOT(ChangePlateActorVisibility(int)));
	connect(this->ui->is_plate_right_side, SIGNAL(stateChanged(int)),
		this, SLOT(ChangePlate_side(int)));
	connect(this->ui->open_lower_jaw, SIGNAL(clicked()),
		this, SLOT(OpenLowerJaw()));
	connect(this->ui->lower_jaw_visibility, SIGNAL(stateChanged(int)),
		this, SLOT(ChangeLowerJawVisibility(int)));
	connect(this->ui->adhering, SIGNAL(clicked()),
		this, SLOT(Adhering()));
	connect(this->ui->make_junction, SIGNAL(clicked()),
		this, SLOT(MakeJunction()));
}

//void Sia::OpenSTL()
//{
//	QString fileName = QFileDialog::getOpenFileName(this,
//		tr("Open STL"), "", tr("STL Files (*.stl)"));
//
//	vtkSmartPointer<vtkSTLReader> reader =
//		vtkSmartPointer<vtkSTLReader>::New();
//	reader->SetFileName(fileName.toStdString().c_str());
//	reader->Update();
//
//	Object new_obj(fileName.toStdString(), reader);
//
//	objectsList.push_back(new_obj);
//
//	renderer->AddActor(objectsList[objectsList.size() - 1].GetActor());
//
//	renderer->ResetCamera();
//
//	this->ui->objectsList->addItem(fileName);
//}
//
//void Sia::ConnectCGALpolyhedronWithVtkActor(/*Polyhedron &a, vtkSmartPointer<vtkActor> b*/)
//{
//	Point_3 p(1.0, 0.0, 0.0);
//	Point_3 q(0.0, 1.0, 0.0);
//	Point_3 r(0.0, 0.0, 1.0);
//	Point_3 s(0.0, 0.0, 0.0);
//	Polyhedron P;
//	P.make_tetrahedron(p, q, r, s);
//
//	vtkSmartPointer<vtkPoints> points =
//		vtkSmartPointer<vtkPoints>::New();	
//	vtkSmartPointer<vtkTriangle> triangle =
//		vtkSmartPointer<vtkTriangle>::New();
//	vtkSmartPointer<vtkCellArray> triangles =
//		vtkSmartPointer<vtkCellArray>::New();
//	vtkIdType id = 0;
//	vtkIdType i;
//	
//	for (Facet_iterator fi = P.facets_begin(); fi != P.facets_end(); fi++)
//	{
//		i = 0;
//		Halfedge_facet_circulator fc = fi->facet_begin();
//		do
//		{
//			points->InsertNextPoint(fc->vertex()->point().x(), fc->vertex()->point().y(), fc->vertex()->point().z());
//			triangle->GetPointIds()->SetId(i, id);
//			id++;
//			i++;
//		} while (++fc != fi->facet_begin());
//		triangles->InsertNextCell(triangle);
//	}
//
//	// Create a polydata object
//	vtkSmartPointer<vtkPolyData> polyData =
//		vtkSmartPointer<vtkPolyData>::New();
//
//	// Add the geometry and topology to the polydata
//	polyData->SetPoints(points);
//	polyData->SetPolys(triangles);
//
//	// Setup actor and mapper
//	vtkSmartPointer<vtkPolyDataMapper> mapper =
//		vtkSmartPointer<vtkPolyDataMapper>::New();
//	mapper->SetInputData(polyData);
//
//	vtkSmartPointer<vtkActor> actor =
//		vtkSmartPointer<vtkActor>::New();
//	actor->SetMapper(mapper);
//
//	// Setup render window, renderer, and interactor
//	vtkSmartPointer<vtkRenderer> renderer =
//		vtkSmartPointer<vtkRenderer>::New();
//	renderer->AddActor(actor);
//
//	// VTK/Qt wedded
//	this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
//	this->ui->qvtkWidget->update();
//}
//
//void Sia::ShowObject()
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToShowName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToShowName)
//			{
//				objectsList[i].GetActor()->SetVisibility(true);
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}
//
//void Sia::HideObject()
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToHideName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToHideName)
//			{
//				objectsList[i].GetActor()->SetVisibility(false);
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}
//
//void Sia::listWidgetItemClicked(QListWidgetItem *item)
//{
//	if (item == selectedItem)
//	{
//		this->ui->objectsList->clearSelection();
//		this->ui->objectsList->clearFocus();
//		selectedItem = 0;
//	}
//	if (item->isSelected())
//	{
//		selectedItem = item;
//	}
//	else
//	{
//		selectedItem = 0;
//	}
//}
//
//void Sia::ChangeOriginX(double dx)
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToMoveName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToMoveName)
//			{
//				objectsList[i].GetActor()->SetPosition(dx, objectsList[i].GetActor()->GetPosition()[1], objectsList[i].GetActor()->GetPosition()[2]);
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}
//
//void Sia::ChangeOriginY(double dy)
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToMoveName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToMoveName)
//			{
//				objectsList[i].GetActor()->SetPosition(objectsList[i].GetActor()->GetPosition()[0], dy, objectsList[i].GetActor()->GetPosition()[2]);
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}
//void Sia::ChangeOriginZ(double dz)
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToMoveName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToMoveName)
//			{
//				objectsList[i].GetActor()->SetPosition(objectsList[i].GetActor()->GetPosition()[0], objectsList[i].GetActor()->GetPosition()[1], dz);
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}
//void Sia::ChangeAngleX(double delta_angle_around_x)
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToMoveName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToMoveName)
//			{
//				objectsList[i].GetActor()->SetOrientation(delta_angle_around_x, objectsList[i].GetActor()->GetOrientation()[1], objectsList[i].GetActor()->GetOrientation()[2]);
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}
//void Sia::ChangeAngleY(double delta_angle_around_y)
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToMoveName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToMoveName)
//			{
//				objectsList[i].GetActor()->SetOrientation(objectsList[i].GetActor()->GetOrientation()[0], delta_angle_around_y, objectsList[i].GetActor()->GetOrientation()[2]);
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}
//void Sia::ChangeAngleZ(double delta_angle_around_z)
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToMoveName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToMoveName)
//			{
//				objectsList[i].GetActor()->SetOrientation(objectsList[i].GetActor()->GetOrientation()[0], objectsList[i].GetActor()->GetOrientation()[1], delta_angle_around_z);
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}
//
//void Sia::Scale(double scale)
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToMoveName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToMoveName)
//			{
//				objectsList[i].GetActor()->SetScale(scale);
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}
//
//void Sia::AcceptTransformations()
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToTransformName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToTransformName)
//			{
//				objectsList[i].SetMatrix(objectsList[i].GetActor()->GetMatrix());
//				objectsList[i].TransformPolyData();
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}
//
//void Sia::ReverseTransformations()
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToTransformName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToTransformName)
//			{
//				vtkSmartPointer<vtkMatrix4x4> invert_matrix = vtkSmartPointer<vtkMatrix4x4>::New();
//				vtkMatrix4x4::Invert(objectsList[i].GetMatrix(), invert_matrix);
//				objectsList[i].SetMatrix(invert_matrix);
//				objectsList[i].TransformPolyData();
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}
//
//void Sia::SelectPlaneToProject()
//{
//	style->SetDefaultRenderer(renderer);
//	this->ui->qvtkWidget->GetInteractor()->SetInteractorStyle(style);
//	this->ui->qvtkWidget->update();
//}
//
//void Sia::ConvertVtkPolyDataToCgalPolyhedron(vtkPolyData* polydata, Polyhedron& polyhedron)
//{
//	std::vector<double> coordinates;
//	double *point;
//	for (int i = 0; i < polydata->GetNumberOfPoints(); i++)
//	{
//		point = polydata->GetPoint(i);
//		coordinates.push_back(point[0]);
//		coordinates.push_back(point[1]);
//		coordinates.push_back(point[2]);
//	}
//
//	std::vector<int> tris;
//	for (int i = 0; i < polydata->GetNumberOfCells(); i++)
//	{
//		tris.push_back(polydata->GetCell(i)->GetPointId(0));
//		tris.push_back(polydata->GetCell(i)->GetPointId(1));
//		tris.push_back(polydata->GetCell(i)->GetPointId(2));
//	}
//
//	polyhedron_builder<HalfedgeDS> builder(coordinates, tris);
//	polyhedron.delegate(builder);
//}
//
//void Sia::project_point_onto_surface(Point_iterator &pi, Tree &surface_geometry_tree, Vector_3 &projection_vector)
//{
//	Ray ray(*pi, projection_vector);
//	std::vector<Ray_intersection> all_intersections;
//	std::vector<Point_3> all_intersection_points;
//	std::vector<double> distances;
//	if (surface_geometry_tree.do_intersect(ray))
//	{
//		surface_geometry_tree.all_intersections(ray, std::back_inserter(all_intersections));
//		for (int i = 0; i < all_intersections.size(); i++)
//		{
//			all_intersection_points.push_back(*boost::get<Point_3>(&(all_intersections[i]->first)));
//		}
//
//		for (int i = 0; i < all_intersection_points.size(); i++)
//		{
//			distances.push_back(pow(all_intersection_points[i].x() - pi->x(), 2) +
//				pow(all_intersection_points[i].y() - pi->y(), 2) +
//				pow(all_intersection_points[i].z() - pi->z(), 2));
//		}
//
//		int index_of_closest_point = std::min_element(distances.begin(), distances.end()) - distances.begin();
//		Vector_3 translation_vector(*pi, all_intersection_points[index_of_closest_point]);
//		Aff_transformation_3 translation(CGAL::TRANSLATION, translation_vector);
//		Point_iterator end = pi;
//		end++;
//		std::transform(pi, end, pi, translation);
//	}
//}
//
//void Sia::CreateAdheringSurface(Vector_3 projection_vector, Polyhedron &prothesis_mesh,
//	Polyhedron &jaw_mesh, Polyhedron &adhering_triangles)
//{
//	// constructs AABB tree
//	Tree jaw_geometry_tree(jaw_mesh.facets_begin(), jaw_mesh.facets_end());
//	jaw_geometry_tree.accelerate_distance_queries();
//	std::cout << "AB started" << std::endl;
//	jaw_geometry_tree.build();
//	std::cout << "AB ended" << std::endl;
//	for (Point_iterator pi1 = adhering_triangles.points_begin(); pi1 != adhering_triangles.points_end(); pi1++)
//	{
//		for (Point_iterator pi2 = prothesis_mesh.points_begin(); pi2 != prothesis_mesh.points_end(); pi2++)
//		{
//			if (pi1->x() == pi2->x() && pi1->y() == pi2->y() && pi1->z() == pi2->z())
//			{
//				project_point_onto_surface(pi2, jaw_geometry_tree, projection_vector);
//			}
//		}
//	}
//}
//
//void Sia::AcceptSelectedProjectingObjects()
//{
//	this->ui->qvtkWidget->GetInteractor()->SetInteractorStyle(default_style);
//}
//
//void Sia::Project()
//{
//	surface_to_project_on = style->surface_to_project_on;
//	Vector_3 projection_vector(
//		style->projection_vector[0],
//		style->projection_vector[1], 
//		style->projection_vector[2]);
//	Polyhedron jaw;
//	ConvertVtkPolyDataToCgalPolyhedron(surface_to_project_on, jaw);
//	Tree jaw_geometry_tree(jaw.facets_begin(), jaw.facets_end());
//	jaw_geometry_tree.build();
//	vtkSmartPointer<vtkPoints> projectedPoints =
//		vtkSmartPointer<vtkPoints>::New();
//
//	for (int i = 0; i < points_to_project->GetNumberOfPoints(); i++)
//	{
//		std::cout << points_to_project->GetPoint(i)[0] << std::endl;
//		double* point = points_to_project->GetPoint(i);
//		Point_3 pnt(point[0], point[1], point[2]);
//		Ray ray(pnt, projection_vector);
//		std::vector<Ray_intersection> all_intersections;
//		std::vector<Point_3> all_intersection_points;
//		std::vector<double> distances;
//		if (jaw_geometry_tree.do_intersect(ray))
//		{
//			jaw_geometry_tree.all_intersections(ray, std::back_inserter(all_intersections));
//			for (int i = 0; i < all_intersections.size(); i++)
//			{
//				all_intersection_points.push_back(*boost::get<Point_3>(&(all_intersections[i]->first)));
//			}
//
//			for (int i = 0; i < all_intersection_points.size(); i++)
//			{
//				distances.push_back(pow(all_intersection_points[i].x() - pnt.x(), 2) +
//					pow(all_intersection_points[i].y() - pnt.y(), 2) +
//					pow(all_intersection_points[i].z() - pnt.z(), 2));
//			}
//
//			int index_of_closest_point = std::min_element(distances.begin(), distances.end()) - distances.begin();
//			Point_3 the_point = all_intersection_points[index_of_closest_point];
//			projectedPoints->InsertPoint(i, the_point.x(), the_point.y(), the_point.z());
//		}
//	}
//
//
//	vtkSmartPointer<vtkPolyData> projectedPolyData =
//		vtkSmartPointer<vtkPolyData>::New();
//	projectedPolyData->SetPoints(projectedPoints);
//
//	vtkSmartPointer<vtkVertexGlyphFilter> vertexFilter =
//		vtkSmartPointer<vtkVertexGlyphFilter>::New();
//	vertexFilter->SetInputData(projectedPolyData);
//	vertexFilter->Update();
//
//	vtkSmartPointer<vtkPolyDataMapper> mapper =
//		vtkSmartPointer<vtkPolyDataMapper>::New();
//	mapper->SetInputData(vertexFilter->GetOutput());
//
//	vtkSmartPointer<vtkActor> actor =
//		vtkSmartPointer<vtkActor>::New();
//	actor->SetMapper(mapper);
//	actor->GetProperty()->SetPointSize(1);
//	renderer->AddActor(actor);
//}
//
//void Sia::FormPointsCloud()
//{
//	if (this->ui->objectsList->isItemSelected(this->ui->objectsList->currentItem()))
//	{
//		std::string objectToTransformName = this->ui->objectsList->currentItem()->text().toStdString();
//
//		for (size_t i = 0; i < objectsList.size(); i++)
//		{
//			if (objectsList[i].GetName() == objectToTransformName)
//			{
//				vtkSmartPointer<vtkPoints> points =
//					vtkSmartPointer<vtkPoints>::New();
//
//				double step = 60.0 / 100.0;
//
//				for (double x = 0; x < 100; x += step)
//				{
//					for (double y = 0; y < 100; y += step)
//					{
//						points->InsertNextPoint(x, y, 3.0);
//					}
//				}
//
//				vtkSmartPointer<vtkPolyData> pointsPolydata =
//					vtkSmartPointer<vtkPolyData>::New();
//				pointsPolydata->SetPoints(points);
//
//				// Points inside test
//				vtkSmartPointer<vtkSelectEnclosedPoints> selectEnclosedPoints =
//					vtkSmartPointer<vtkSelectEnclosedPoints>::New();
//				selectEnclosedPoints->SetInputData(pointsPolydata);
//				selectEnclosedPoints->SetSurfaceData(objectsList[i].GetOriginalPolyData());
//				selectEnclosedPoints->Update();
//
//				vtkSmartPointer<vtkPoints> pointsInside =
//					vtkSmartPointer<vtkPoints>::New();
//				for (int i = 0; i < points->GetNumberOfPoints(); i++)
//				{
//					if (selectEnclosedPoints->IsInside(i))
//						pointsInside->InsertNextPoint(points->GetPoint(i));
//				}
//				/*for (int i = 0; i < objectsList[i].GetOriginalPolyData()->GetNumberOfPoints(); i++)
//				{
//					if (objectsList[i].GetOriginalPolyData()->GetPoint(i)[2] <= 0.001)
//						pointsInside->InsertNextPoint(objectsList[i].GetOriginalPolyData()->GetPoint(i));
//				}*/
//
//				vtkSmartPointer<vtkPolyData> pointsInsidePolydata =
//					vtkSmartPointer<vtkPolyData>::New();
//				pointsInsidePolydata->SetPoints(pointsInside);
//
//				points_to_project = pointsInsidePolydata;
//
//				vtkSmartPointer<vtkVertexGlyphFilter> vertexFilter =
//					vtkSmartPointer<vtkVertexGlyphFilter>::New();
//				vertexFilter->SetInputData(points_to_project);
//				vertexFilter->Update();
//
//				vtkSmartPointer<vtkPolyDataMapper> mapper =
//					vtkSmartPointer<vtkPolyDataMapper>::New();
//				mapper->SetInputData(vertexFilter->GetOutput());
//
//				vtkSmartPointer<vtkActor> actor =
//					vtkSmartPointer<vtkActor>::New();
//				actor->SetMapper(mapper);
//				actor->GetProperty()->SetPointSize(1);
//				renderer->AddActor(actor);
//
//				this->ui->qvtkWidget->update();
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "No selected item." << std::endl;
//	}
//}

void Sia::MakePlate()
{
	plate.MakePlate();
	renderer->AddActor(plate.GetActor());
	renderer->ResetCamera();
	this->ui->qvtkWidget->update();
	ui->plate_a->setValue(plate.Get_a());
	ui->plate_d->setValue(plate.Get_d());
	ui->plate_h->setValue(plate.Get_h());
	ui->plate_i->setValue(plate.Get_i());
	ui->plate_k->setValue(plate.Get_k());
	ui->plate_l->setValue(plate.Get_l());
	ui->plate_m->setValue(plate.Get_m());
	ui->plate_n->setValue(plate.Get_n());
	ui->plate_r->setValue(plate.Get_r());
}

void Sia::ChangePlate_a(double _a)
{
	plate.Change_a(_a);
	ui->plate_a->setValue(plate.Get_a());
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlate_d(double _d){
	plate.Change_d(_d);
	ui->plate_d->setValue(plate.Get_d());
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlate_h(double _h){
	plate.Change_h(_h);
	ui->plate_h->setValue(plate.Get_h());
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlate_i(double _i){
	plate.Change_i(_i);
	ui->plate_i->setValue(plate.Get_i());
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlate_k(double _k){
	plate.Change_k(_k);
	ui->plate_k->setValue(plate.Get_k());
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlate_l(double _l){
	plate.Change_l(_l);
	ui->plate_l->setValue(plate.Get_l());
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlate_m(double _m){
	plate.Change_m(_m);
	ui->plate_m->setValue(plate.Get_m());
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlate_n(double _n){
	plate.Change_n(_n);
	ui->plate_n->setValue(plate.Get_n());
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlate_r(double _r){
	plate.Change_r(_r);
	ui->plate_r->setValue(plate.Get_r());
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlate_side(int x){
	plate.ChangeSide(x);
}

void Sia::ChangePlateActor_dx(double dx){
	plate.GetActor()->SetPosition(dx, plate.GetActor()->GetPosition()[1], plate.GetActor()->GetPosition()[2]);
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlateActor_dy(double dy){
	plate.GetActor()->SetPosition(plate.GetActor()->GetPosition()[0], dy, plate.GetActor()->GetPosition()[2]);
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlateActor_dz(double dz){
	plate.GetActor()->SetPosition(plate.GetActor()->GetPosition()[0], plate.GetActor()->GetPosition()[1], dz);
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlateActor_angle_x(double delta_angle_x){
	plate.GetActor()->SetOrientation(delta_angle_x, plate.GetActor()->GetOrientation()[1], plate.GetActor()->GetOrientation()[2]);
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlateActor_angle_y(double delta_angle_y){
	plate.GetActor()->SetOrientation(plate.GetActor()->GetOrientation()[0], delta_angle_y, plate.GetActor()->GetOrientation()[2]);
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlateActor_angle_z(double delta_angle_z){
	plate.GetActor()->SetOrientation(plate.GetActor()->GetOrientation()[0], plate.GetActor()->GetOrientation()[1], delta_angle_z);
	this->ui->qvtkWidget->update();
}

void Sia::MakeHead()
{
	head.MakeHead();
	renderer->AddActor(head.GetActor());
	renderer->ResetCamera();
	this->ui->qvtkWidget->update();
	ui->head_s->setValue(head.Get_s());
	ui->head_t->setValue(head.Get_t());
	ui->head_u->setValue(head.Get_u());
	ui->head_v->setValue(head.Get_v());
	ui->head_w->setValue(head.Get_w());
	ui->head_x->setValue(head.Get_x());
	ui->head_y->setValue(head.Get_y());
}

void Sia::ChangeHead_s(double _s){
	head.Change_s(_s);
	ui->head_s->setValue(head.Get_s());
	this->ui->qvtkWidget->update();
}
void Sia::ChangeHead_t(double _t){
	head.Change_t(_t);
	ui->head_t->setValue(head.Get_t());
	this->ui->qvtkWidget->update();
}
void Sia::ChangeHead_u(double _u){
	head.Change_u(_u);
	ui->head_u->setValue(head.Get_u());
	this->ui->qvtkWidget->update();
}
void Sia::ChangeHead_v(double _v){
	head.Change_v(_v);
	ui->head_v->setValue(head.Get_v());
	this->ui->qvtkWidget->update();
}
void Sia::ChangeHead_w(double _w){
	head.Change_w(_w);
	ui->head_w->setValue(head.Get_w());
	this->ui->qvtkWidget->update();
}
void Sia::ChangeHead_x(double _x){
	head.Change_x(_x);
	ui->head_x->setValue(head.Get_x());
	this->ui->qvtkWidget->update();
}
void Sia::ChangeHead_y(double _y){
	head.Change_y(_y);
	ui->head_y->setValue(head.Get_y());
	this->ui->qvtkWidget->update();
}

void Sia::ChangeHeadActor_dx(double dx){
	head.GetActor()->SetPosition(dx, head.GetActor()->GetPosition()[1], head.GetActor()->GetPosition()[2]);
	this->ui->qvtkWidget->update();
}
void Sia::ChangeHeadActor_dy(double dy){
	head.GetActor()->SetPosition(head.GetActor()->GetPosition()[0], dy, head.GetActor()->GetPosition()[2]);
	this->ui->qvtkWidget->update();
}
void Sia::ChangeHeadActor_dz(double dz){
	head.GetActor()->SetPosition(head.GetActor()->GetPosition()[0], head.GetActor()->GetPosition()[1], dz);
	this->ui->qvtkWidget->update();
}
void Sia::ChangeHeadActor_angle_x(double delta_angle_x){
	head.GetActor()->SetOrientation(delta_angle_x, head.GetActor()->GetOrientation()[1], head.GetActor()->GetOrientation()[2]);
	this->ui->qvtkWidget->update();
}
void Sia::ChangeHeadActor_angle_y(double delta_angle_y){
	head.GetActor()->SetOrientation(head.GetActor()->GetOrientation()[0], delta_angle_y, head.GetActor()->GetOrientation()[2]);
	this->ui->qvtkWidget->update();
}
void Sia::ChangeHeadActor_angle_z(double delta_angle_z){
	head.GetActor()->SetOrientation(head.GetActor()->GetOrientation()[0], head.GetActor()->GetOrientation()[1], delta_angle_z);
	this->ui->qvtkWidget->update();
}
void Sia::ChangePlateActorVisibility(int x){
	plate.GetActor()->SetVisibility(x);
	this->ui->qvtkWidget->update();
}

void Sia::OpenLowerJaw()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open STL"), "", tr("STL Files (*.stl)"));

	vtkSmartPointer<vtkSTLReader> reader =
		vtkSmartPointer<vtkSTLReader>::New();
	reader->SetFileName(fileName.toStdString().c_str());
	reader->Update();

	lower_jaw_polydata = vtkSmartPointer<vtkPolyData>::New();
	lower_jaw_polydata = reader->GetOutput();

	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::New();
	mapper->SetInputData(lower_jaw_polydata);

	lower_jaw_actor = vtkActor::New();
	lower_jaw_actor->SetMapper(mapper);

	renderer->AddActor(lower_jaw_actor);
	renderer->ResetCamera();
}

void Sia::ChangeLowerJawVisibility(int x){
	lower_jaw_actor->SetVisibility(x);
	this->ui->qvtkWidget->update();
}

void Sia::Adhering()
{
	mk_adhering.SetPlate(&plate);
	mk_adhering.SetLowerJaw(lower_jaw_polydata);
	mk_adhering.SetRenderer(renderer);
	mk_adhering.Perform();
}

void Sia::MakeJunction(){
	junction.SetHead(&head);
	junction.SetPlate(&plate);
	junction.MakeJunction();
	renderer->AddActor(junction.GetActor());
	this->ui->qvtkWidget->update();
}