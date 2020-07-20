#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "box.hpp"
#include "sphere.hpp"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

//Aufgabe 5.2 - Konstruktoren Box und Sphere
TEST_CASE("box und sphere initialisierung", "[Box, Sphere]"){
  Sphere s1;
  Sphere s2 {{1.0f,2.0f,3.0f},5.0f};
  Box b1;
  Box b2{{0.0f, 0.0f, 0.0f},{3.0f, 2.0f, 4.0f}};
}
 
//Task 5.1 
TEST_CASE("box area and volume", "[Box::area, Box::volume]"){
  Box b1{{1.0f, 2.0f, 3.0f},{9.0f, 6.0f, 7.0f}};
  REQUIRE(b1.area() == Approx(160.0f));
  REQUIRE(b1.volume() == Approx(128.0f));
  Box b2{{0.0f, 0.0f, 0.0f},{4.0f, 2.0f, 3.0f}};
  REQUIRE(b2.area() == 4*2*2 + 2*3*4 + 2*3*2);
  REQUIRE(b2.volume() == 24);
  Box b3{{7.3f, 1.1f, 9.55f},{23.9f, 22.0f, 43.0f}};
  REQUIRE(b3.area() == Approx(3202.63f));
  REQUIRE(b3.volume() == Approx(11605.1430f));
  Box b4{{0.0f, 100.0f, 20.0f},{33.0f, 333.0f, 20.01f}};
  REQUIRE(b4.area() == Approx(15383.32f));
  REQUIRE(b4.volume() == Approx(76.891f));
}

TEST_CASE("sphere area and volume", "[Sphere::area, Sphere::volume]"){
  Sphere s1{{1.0f,2.0f,3.0f},5.0f};
  REQUIRE(s1.area() == Approx(314.1592654f));
  REQUIRE(s1.volume() == Approx(523.59882f));
  Sphere s2{{4.0f,7.0f,3.0f},2.3f};
  REQUIRE(s2.area() == Approx(66.47610055f));
  REQUIRE(s2.volume() == Approx(50.96501f)); 
  Sphere s3{{4.0f,7.0f,3.0f},79.8f};
  REQUIRE(s3.area() == Approx(80023.15073f));
  REQUIRE(s3.volume() == Approx(2128615.809f)); 
  Sphere s4{{7.4f,1.0f,543.3f},11.2f};
  REQUIRE(s4.area() == Approx(1576.325530f));
  REQUIRE(s4.volume() == Approx(5884.948646f)); 
}

//task 5.6
TEST_CASE("intersect_ray_sphere", "[intersect]") {
  // Ray
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
  // ray direction has to be normalized !
  // you can use:
  // v = glm::normalize(some_vector)
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};

  // Sphere
  glm::vec3 sphere_center{0.0f ,0.0f, 5.0f};
  float sphere_radius{1.0f};
  float distance = 0.0f;
  auto result = glm::intersectRaySphere(
                ray_origin, ray_direction,
                sphere_center,
                sphere_radius * sphere_radius, // squared radius !!!
                distance);
  REQUIRE(distance == Approx(4.0f));
}

//testing task 5.6 with different spheres
TEST_CASE("interect sphere", "[intersect]") {
  //Sphere 1 - no intersection done
  Sphere sphere1{{6,1,1},2,"Sphere1",{1,1,1}};
  Ray ray{{22,1,2},{2,0,0}};
  HitPoint result = sphere1.intersect(ray,4);
  REQUIRE(result.intersection_done == false);

  //Sphere 2 - intersection done
  Sphere sphere2{{0,0,10},2.0f,"Sphere2",{1,1,1}};
  Ray ray2{{0,0,0},{0,0,1}};
  HitPoint result2 = sphere2.intersect(ray2,2);
  REQUIRE(result2.intersection_done == true);
  REQUIRE(result2.t == 8.0f);
  REQUIRE(result2.name == "Sphere2");
  REQUIRE(result2.color.r == 1.0f);
  REQUIRE(result2.color.g == 1.0f);
  REQUIRE(result2.color.b == 1.0f);
  REQUIRE(result2.intersection_point.x == 0.0f);
  REQUIRE(result2.intersection_point.y == 0.0f);
  REQUIRE(result2.intersection_point.z == 8.0f);
  REQUIRE(result2.direction.x == 0.0f);
  REQUIRE(result2.direction.y == 0.0f);
  REQUIRE(result2.direction.z == 1.0f);

  //Sphere 3 - intersection done
  Sphere sphere3{{0,0,0},10.0f,"Sphere3",{5,5,2}};
  Ray ray3{{1,1,1},{0,0,-4.0}};
  HitPoint result3 = sphere3.intersect(ray3,10);
  REQUIRE(result3.intersection_done == true);
  REQUIRE(result3.t == Approx(10.8995f));
  REQUIRE(result3.name == "Sphere3");
  REQUIRE(result3.color.r == 5.0f);
  REQUIRE(result3.color.g == 5.0f);
  REQUIRE(result3.color.b == 2.0f);
  REQUIRE(result3.intersection_point.x == 1.0f);
  REQUIRE(result3.intersection_point.y == 1.0f);
  REQUIRE(result3.intersection_point.z == Approx(-42.59798f));
  REQUIRE(result3.direction.x == 0.0f);
  REQUIRE(result3.direction.y == 0.0f);
  REQUIRE(result3.direction.z == -4.0f);
}

//task 5.8
TEST_CASE("Konstruktor Destruktor Reihenfolge", "[Konstruktor, Destruktor]") {
  std::cout<<"\n _____________start task 5.8______________________ \n";
  Color red{255, 0, 0};
  glm::vec3 position{0.0f, 0.0f, 0.0f};
  //changed order of parameters to fit my conscructor
  Sphere* s1 = new Sphere{position, 1.2f, "sphere0", red}; 
  Shape* s2 = new Sphere{position, 1.2f, "sphere1", red};
  s1->print(std::cout); 
  s2->print(std::cout);
  delete s1; 
  delete s2; //this would not work if destruktor is non-virtual!
  std::cout<<"_____________end task 5.8______________________ \n";
}

int main(int argc, char *argv[])
{

  Sphere s1{{1.0f,2.0f,3.0f},5.0f};
  Sphere s2{{4.0f,7.0f,3.0f},2.3f,"Heinz",{3,6,7}};
  Box b1{{1.0f, 2.0f, 3.0f},{9.0f, 6.0f, 7.0f},"Udo",{6,7,8}};
  Box b2{{0.0f, 100.0f, 20.0f},{33.0f, 333.0f, 20.01f},"Anette",{2.0,4.0,6.3}};
  std::cout<<s1<<"\n";
  std::cout<<s2<<"\n";
  std::cout<<b1<<"\n";
  std::cout<<b2<<"\n";
  return Catch::Session().run(argc, argv);

 
}
