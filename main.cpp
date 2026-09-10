#include <fstream>
#include <iostream>

struct force {
  // Measured in regular SI units
  float displacement = 1.0;
  float velocity = 0;
  float k = 5;
  float mass = 100;
  float dt = 0.5;
  float elapsed = 0;
  int iteration = 5;
};

int springMass() {
  force pointMass;
  std::ofstream outFile;
  outFile.open("results.txt");
  for (int i = 0; pointMass.iteration > i; i++) {
    float F = pointMass.displacement * -pointMass.k;
    float acc = F / pointMass.mass;
    pointMass.elapsed = pointMass.elapsed + pointMass.dt;
    pointMass.velocity = pointMass.velocity + (acc * pointMass.dt);
    pointMass.displacement =
        pointMass.displacement + (pointMass.velocity * pointMass.dt);
    std::cout << "Displacement: " << pointMass.displacement << std::endl;
    std::cout << "Velocity: " << pointMass.velocity << std::endl;
    outFile << pointMass.elapsed << ", " << pointMass.displacement << std::endl;
  }
  outFile.close();

  return 0;
}

int main() {
  springMass();

  return 0;
}