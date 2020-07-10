#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "box.hpp"
#include "sphere.hpp"

//Aufgabe 5.2 - Konstruktoren Box und Sphere
TEST_CASE("box und sphere initialisierung", "[Box, Sphere]"){
  Sphere s1;
  Sphere s2 {{1.0f,2.0f,3.0f},5.0f};
  //TODO: test konstruktor
  Box b1;
  Box b2{{0.0f, 0.0f, 0.0f},{3.0f, 2.0f, 4.0f}};
  //TODO: test konstruktor
  //REQUIRE(s1.center_.x == 0.0f);
}

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


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
